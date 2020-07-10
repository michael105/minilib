#!/bin/perl -w
# (modified) BSD 3-clause (c) 2019 Michael misc Myer misc.myer@zoho.com;
# www.github.com/michael105; BSD-Licensing terms attached
#
#
# somethere I've to start to docu this thing.
# although most possibly I'm going to pull parts of the code out of here, which is not specific to the minilib,
# and do it more generic - this script works out quite useful,
# and is good enough for a project on its own. 
# (Albite. well. got little bit spaghetti. but works. so..)
#
# This script gets callen with the target dir (mlibdir) as first param,
# then the files it should scan. (*.h / *.c; invoked by "make header" in the case of minilib)
#
# Its purpose is to generate: 
#		minilib.conf; genconf.sh; minilib.h; compat/*.h
#
# in minilib.conf the possible switches are defined, with whom the compilation
#   of the functions can be enabled/disabled.
# minilib.h bundles all other headers, as well as the sources when invoked with a defined "INCLUDESRC",
#  and is to be included in every source file, using the minilib. (Only once with "INCLUDESRC")
# genconf.sh gets callen by mini-gcc; it generates minilib.conf.h out of minilib.conf 
#  (or whatever else name is supplied via --config )
#  compat/*.h contains the ansi-c/posix-c (sort of "subsetcompatible") headers.
#
# This script scans for "tags":
# each tag consists (for the moment, this should also get more generic)
# of this pattern: (linestart)"//+tag"
#	
#	
#	(replace / with minilib's maindir )
#	files in /; /templates; /compat; /compat/templates; are parsed into the resulting header files.
#	Always: header.tmpl.top, "the headers name".top, header.in; "header's name".in; and -.out 
#		..  TODO its sort of ungeneric and not stringent. so here I gave the direction,
#		but won't document exactly; since it's a subject to change.
#
#---
#
# "tag" can be one of:
#
# - def: the next line keeps a definition (function definition)
#
# - macro: either in the same line, or in the next line is a macro defined.
# 	the macros are collected and go into the corresponding header files;
# 	as well as the definitions (+def)
# 	Either into the headers, defined by the posic-c /ansi-c standard, or 
# 	into the header file, supplied via the tag header
#
# - header "name": the definitions and macros defined in this header file go into 
#  								the header file "name". "header" can be defined several times within 
#  								one file, each time the definitions below are put into name, until the 
#  								next "header" tag is read
#
#	- depends "name1" "name2" .. :	the following definitions are selected automatically, when the following def or macro 
#						is selected via the #define in the configfile. TODO example.
#
#	- needs "name1" "name2" .. : the headerfiles "name1", .. are included before the current header file.
#
#	- doc: TODO needs implementing
# - test: TODO (testing framework) -> most possibly best to define just a few calls to the implemented functions;
# 																		and just compare the output to stdout/stderr. (Framework already implemented in /test)
# 																		little hard to catch e.g. filecreation. But possible. ALso possibly
# 																		just put some inline perl scripts into a "test" tag.
#




my $fhhash;
BEGIN{
# Where to put the generated ansi/posix headers and look for templates
$mlibdir = shift;
push @INC, "$mlibdir/scripts/perl";
}

# minilib headerfile
#my $minilibheader = shift;
my $headerdir="$mlibdir/compat";
my $minilibheader = "$mlibdir/minilib.h";
my $miniconf = "$mlibdir/miniconf.h";

my $funchash;
my $mlfunchash; # Non standard functions
my $allfunchash; # Allfuncs.
my $headerhash;
my $depends;
my $rdepends; # depends in reverse.

my $syscalldefs;
my $syscallsysdefs;
my $syscallstubs=0; # Saves the name of the header "syscall_stubs.h",
										# for later processing

my $globalintemplate = << "TMPL_IN";

// Header generated by the script tools/genheaders.pl
// Put changes into filename.in 

TMPL_IN

# Only for debuggging
use Data::Dumper::Simple;


# globally enable/disable debug
$debug = 0;
$debugovw =1;
sub dbg{

	 	return if (!($debug || $debugovw));
		while ( my $s = shift ){
				print $s;
		}
		print "\n";

}


sub dbgdump{
		my $r = shift;
	 	return if (!($debug || $debugovw));
		print Dumper($r);
}



BEGIN{
		use File::Basename;
		($name,$path,$suffix) = fileparse ($0);
		push @INC, "$path";
}



require "cref.pm";
require "template.pm";

# ansicolors
#define AC_BLACK "\033[0;30m"
$R=$AC_R="\033[0;31m";
$G= "\033[32;0m"; # Green
#define AC_BROWN "\033[0;33m"
#define AC_BLUE "\033[0;34m"
$C = "\033[0;35m"; # Cyan
$M = "\033[0;36m"; # Marine
#define AC_LGREY "\033[0;37m"
$N= "\033[0;38m"; # White

#define AC_GREY "\033[1;30m" 
$LR = "\033[1;31m"; # Light red
$LG = "\033[1;32m"; # Light green
$Y = "\033[1;33m"; # Yellow
$LB = "\033[1;34m"; # Light blue
#define AC_LMAGENTA "\033[1;35m"
#define AC_LMARINE "\033[1;36m"
#define AC_LWHITE "\033[1;37m"


# Looks for templates and copies them into dest fh (arg1)
# args: filehandler (destination)
# 	path of the header
# namelist of templates
sub copytemplates{
		my $fh = shift;
		my $path = shift;
		my @fn = @_;
		foreach my $p ( "$path", "$path/templates" ){ 
				foreach my $f ( @fn ){
						if ( -e "$p/$f" ){
								open(FSOURCE,"<", "$p/$f" ) or die;
								while ( <FSOURCE> ){
										print $fh $_;
								}
								close FSOURCE;
						} 
				}
		}
}



# gets callen for each header referenced
# if the file isn't open yet,
# creates and returns a new filehandle
# Copies also header.h.in at the beginning.
sub headerfh{
		my $header = shift;
		my $path = shift;
		dbg ("Header: $header\n");
		if ( ! exists($fhhash->{fh}->{$header}) ){
				open( $fhhash->{fh}->{$header}, ">", "$path/$header" ) or die;
				copytemplates( $fhhash->{fh}->{$header}, "$mlibdir", "header.tmpl.top", "$header.top" );			
				my $h = $header;
				$h =~ s/\./_/g;
				$h =~ s/\//_/g;
				print {$fhhash->{fh}->{$header}} "#ifndef included_$h\n#define included_$h\n\n";
				copytemplates( $fhhash->{fh}->{$header}, $path, "header.in", "$header.in" );			
		}
		return( $fhhash->{fh}->{$header} );
}

# iterate over commandline args
while ( my $file = shift ){
		open (F, "<", $file) or die;
		my @fa = <F>;
		close( F );

		if ( $file =~ /syscall_stubs.h/ ){
				$syscallstubs = $file;
		}

		my $header = 0;
		my $line = 0;
		my $included = 0;
		while ( my $l= $fa[$line]){
				my $f;
				my $tag = 0;
				my $func = 0;
				$f->{file} = $file;
				$f->{inc} = $included;
				if ( $l =~ /^DEF_syscall(ret)*.(.*?),/ ){
						$func = $2;
						$syscalldefs->{$func}->{def} = $l;
				}
				if ( $l =~ /^SYSDEF_syscall(ret)*.(.*?),/ ){
						$func = $2;
						$syscallsysdefs->{$func}->{def} = $l;
				}


				if ($l=~ /^\/\/\+/){
						do {
								print ( "$M l: $l $N\n" );
								$l=~ /^\/\/\+(\S*)\s?(.*)?$/;
								$tag = $1 if ( $1 ); # 
								my $c = $2 || 0;
								dbg("tag: $tag c: $c\n");

								if ( $tag eq 'header' ){   # tag parsing. should change this.
										dbg("l: $l");
										#$l =~ /^\/\/\+header (\S*)/;
										$header = $c or die;
								} elsif ( 0 && $tag eq 'inline' ) { # commented out. Need to parse the header file
										$l = $fa[$line+=1];
										#$line++;
										$l =~ /.* \**(\S*)\(.+?\)\{.*$/;
										$func = $1;
										$f->{def} = $l;
										do {
												$l = $fa[$line+=1];
												#$l = <F>;
												#$line++;
												$f->{def} .= $l;
										} while ( !($l =~ /^}/ ) );
										dbg( "dbg: $f->{def}" );
										$f->{file} = '';
										
								}elsif ( $tag eq 'def' | $tag eq 'inline'){
										#$f->{def} = <F>;
										#$line++;
										$f->{def} = $fa[$line+=1];
										dbg("def: $f->{def} $file: $l");
										if ( $f->{def} =~ /^DEF_syscall(ret)*.(.*?),/ ){
												$func = $2;
										} else {
												dbg("f-def: $f->{def}");
												$f->{def} =~ /.* \**(\S*)\(.*?\)\{.*$/;
												$func = $1;
										}
										dbg("func: $LR $func $N\n");
										$f->{def} =~ s/\{.*$/;/;
										dbg( "def: $Y $f->{def} $N l: $l");
								} elsif ( $tag eq 'needs' ){
										#$l =~ /^\/\/\+needs\s?(\S*)/;
										$f->{needs} = $c;
										dbg("$LG needs: $f->{needs} $N\n");
								} elsif ( $tag eq 'depends' ){
										$f->{dep} = $c;
										dbg("$LG depends: $f->{dep} $N\n");
								} elsif ( $tag eq 'after' ){
										$f->{after} = $c; # e.g. printf after atoi (when defined atoi)
								} elsif ( $tag eq 'doc' ){
										if ( !exists $f->{doc} ){
												$f->{doc} = $c;
										} else {
												$f->{doc} .= $c;
										}
										while( $fa[$line+1] =~ /^\/\/(\+?)(.*)/ && !($1) ){
												$line++;
												$f->{doc} .= "\n" . $2;
												dbg("dbg doc: $2");
										}
								} elsif ( $tag eq 'inc' | $tag eq 'include'){
										print {headerfh($header,$headerdir)} "// file: $file\n#include \"$file\"\n";
										dbg "// file: $file\n#include \"$file\"\n";
										$f->{inc} = 1;
										$included = 1;
								} elsif( $tag eq 'macro' ){
										if ( $l =~ /^\/\/\+macro\s*(\S+)/ ){
												$l =~ s/^\/\/\+macro\s*//;
												$f->{def} = "#define $l";
												$l =~ /(\S*?)\(/;
												$func = $1;
												dbg("$LR macro: $f->{def}  -  func: $func $N");
										} else {
												#$f->{def} = <F>;
												#$line++;
												$f->{def} = $fa[$line+=1];
												dbg("def+ $f->{def}");
												$f->{def} =~ s/^\/\///;
												dbg("def+ $f->{def}");

												$f->{def} =~ /#define\s*(\S*?)\(/;
												$func = $1;
												dbg("$LR macro: $f->{def}   -   func: $func $N");
										}
										$f->{macro} = 1;
								}
								#$l = <F>;
								#		$line++;
								$l = $fa[$line+=1];
								$tag = 0;
						} while (defined($l) && ($l=~ /^\/\/\+(\S*)/) );
				}
				if ( $func ){
						if ( exists( $functiondict->{$func} ) && ( length($functiondict->{$func})>3) ){ # standard function.
								$f->{header} = $functiondict->{$func}->{header};
								#$header} = $functiondict->{$func}->{header};
								$functiondict->{$func}->{implementation} = $file;
						} else { 
								#$mlfunchash->{$func}= $f; # no standard function
								#print "Header::: XXXX $f->{header}\n";
								if ( !$header ){
										if ( exists( $syscallsysdefs->{$func} ) ){
												$f->{header} = "mini_ksyscalls";
										} else {
												$f->{header} = "mini_addons.h";
										}
								} else {
										$f->{header} = $header;
								}
						}
						$headerhash->{$f->{header}}->{$func}=1;
						$funchash->{$func} = $f;
						$f->{line} = $line;
						if ( exists($f->{dep} )){ # no. problems.
								$depends->{$func} = $f->{dep};
								foreach my $dpd ( split ( " ", $f->{dep} ) ){
										#push @{$rdepends->{$dpd}},$func; waere gut fuer die defines
										push @{$rdepends->{$func}},$dpd; 
										dbg("$func depends: $f->{dep}, $dpd");
								}
						}
						if ( exists($syscalldefs->{$func}) ){
								$syscalldefs->{$func}->{f} = $f
						}
						if ( exists($syscallsysdefs->{$func}) ){
								$syscallsysdefs->{$func}->{f} = $f
						}


						if ( $f->{header} && $f->{def} && !($included)){
								dbg("header: $f->{header}\n def: $f->{def}\n");
								print {headerfh($f->{header},$headerdir)} "// file: $f->{file}\n$f->{def}\n";
								$fhhash->{sources}->{$f->{header}}->{$file} = 1;
						}
				}

				$line++;
		} # while $fa[$line]
}

# write the #include "source.c" directives
# iterate over each header include filehandler
foreach my $key ( keys(%{$fhhash->{fh}}) ){
		dbg("key: $key\n");
		print {$fhhash->{fh}->{$key}} "\n\n#include \"include/minilib_global.h\"\n";
		print {$fhhash->{fh}->{$key}} "\n\n#ifdef mini_INCLUDESRC\n\n";
		foreach my $s ( keys(%{$fhhash->{sources}->{$key}}) ){
				dbg("source key: $s\n");
				print {$fhhash->{fh}->{$key}} "#include \"$s\"\n";
		}
		print {$fhhash->{fh}->{$key}} "\n// Need global included. Doesn't matter by which file.\n#include \"src/minilib_global.c\"\n";
		print {$fhhash->{fh}->{$key}} "\n// Need start.c included. Doesn't matter by which file.\n#include \"asm/start.c\"\n\n";
		print {$fhhash->{fh}->{$key}} "#endif\n\n";

		print {$fhhash->{fh}->{$key}} "#endif\n";
		close( $fhhash->{fh}->{$key} );
}

# fulldepends
sub rdep{
		my $d = shift;
		
		return( $d ) if ( ! exists( $depends->{$d} ) );
		my $r="";
				foreach my $dd ( split(" ",$depends->{$d} )) {
						next if ( $dd =~ /^_/ );
						print "rdep: $dd\n";
								$r.=" ".rdep($dd);
				}
		return($r);
}
print("rcu fulldep\n");
my $fulldepends;
foreach my $d ( keys(%{$depends}) ){
		my $dd = rdep( $d );
		foreach my $df( split(" ",$dd) ){
				$fulldepends->{$d}->{$df} = 1;
		}
}
dbg("fulldepends");
dbgdump( %{$fulldepends} );
dbg("xxx depends");
dbgdump( %{$depends} );
dbg("yyy dep");

# write doc
open( FDOC, ">", "$mlibdir/doc/minilib.txt" ) or die;
#*FDOC = *STDOUT;

copytemplates( FDOC, $mlibdir, "minilib.txt.top" );

foreach my $k ( sort(keys(%{$headerhash})) ){
		print FDOC "\n\n==========\n$k\n==========\n\n";
		foreach my $f ( sort( keys(%{$headerhash->{$k}} ) ) ){
				if ( exists($syscallsysdefs->{$f} ) ){
						printf FDOC "ksys%-15s",$f;
				} else {
						printf FDOC "%-15s",$f;
				}

				$funchash->{$f}->{file}=~/minilib\/(.*)/;
				my $docdef="";
				if ( exists($funchash->{$f}->{def}) ){
						if ( exists( $syscallsysdefs->{$f} ) ){
								print FDOC "sys$funchash->{$f}->{def}";
								$docdef= "sys$funchash->{$f}->{def}";
						} else {
								print FDOC "$funchash->{$f}->{def}";
								$docdef= "$funchash->{$f}->{def}";
						};
						} elsif ( exists($syscalldefs->{$f} ) && exists($syscalldefs->{$f}->{def} ) ){
						my $s = "$syscalldefs->{$f}->{def}";
						#$s=~s/SYSDEF_syscall.(\S*),\s*\d*\s*,/sys$1(/;
						$s=~s/DEF_syscall.(\S*),\s*\d*\s*,/$1(/;
						$s=~s/DEF_syscallret.(\S*),\s*(\S*)\s*,\s*\d*\s*,/$1(/;
						#$s=~s/^_/sys_/;
						$docdef=$s;
						print FDOC $s;
						print FDOC "               Returns: $2\n" if ( $2 );
				}
				if ( $docdef ){
						$docdef =~ s/(static)|(inline)|(volatile)|(__attribute__\(.*?\))//g;
						$funchash->{$f}->{docdef} = $docdef;
				}
				if ( exists($depends->{$f}) ){  
						print FDOC "               Defines: ".join(" ",keys(%{$fulldepends->{$f}})),"\n";
				}

				print FDOC "               ($1: $funchash->{$f}->{line})\n";
				if ( exists($funchash->{$f}->{doc} ) ){
						print FDOC "               ",join("\n             ", split( "\n", $funchash->{$f}->{doc}) ),"\n";
						#print FDOC "               $funchash->{$f}->{doc}\n";
				}
				print FDOC "\n";
		}
}

close FDOC;

open F, ">", "$mlibdir/test/generated/functions.txt";
foreach my $f ( keys( %{$funchash} ) ){
		my $s = "";
		if ( exists($funchash->{$f}->{docdef}) ){
				$s=$funchash->{$f}->{docdef},"\n";
		} elsif ( exists($funchash->{$f}->{def}) ) {
				$s=$funchash->{$f}->{def},"\n";
		}
		if ( $s && $s!~/^#/ ){
				print F "$f:$s\n";
		}
}
close F;

require "index.pm"; # bsd manpage index
print "XXXXX";
dbgdump( $bsdmanpage );

# write doc
open( FDOC, ">", "$mlibdir/doc/mlfunctions-shortref.asc" ) or die;
#*FDOC = *STDOUT;

copytemplates( FDOC, $mlibdir, "mlfunctions-shortref.asc.top" );

foreach my $k ( sort(keys(%{$headerhash})) ){
		print FDOC "\n\n";

		#		print FDOC '[['.$k.']]'."\n";
		print FDOC " $k\n";
		print FDOC "-"
				for ( 1..length($k)+2 ); 
		print FDOC "\n\n"; #$k\n==========\n\n";
		#print FDOC "\n\n==========\n$k\n==========\n\n";
		foreach my $f ( sort( keys(%{$headerhash->{$k}} ) ) ){
				if ( exists($syscallsysdefs->{$f} ) ){
						printf FDOC "ksys%s::\n\n ",$f;
				} else {
						printf FDOC "%s::\n\n ",$f;
				}
				$funchash->{$f}->{file}=~/minilib\/(.*)/;
				if ( exists($funchash->{$f}->{def}) ){
								print FDOC " $funchash->{$f}->{def} +\n ";
						} elsif ( exists($syscalldefs->{$f} ) && exists($syscalldefs->{$f}->{def} ) ){
						my $s = "$syscalldefs->{$f}->{def}";
						#$s=~s/SYSDEF_syscall.(\S*),\s*\d*\s*,/$1(/;
						$s=~s/DEF_syscall.(\S*),\s*\d*\s*,/$1(/;
						$s=~s/DEF_syscallret.(\S*),\s*(\S*)\s*,\s*\d*\s*,/$1(/;
						print FDOC " $s +\n";
						print FDOC " Returns: $2 +\n" if ( $2 );
				}
				if ( exists($depends->{$f}) ){  
						print FDOC " Defines: ".join(" ",keys(%{$fulldepends->{$f}}))," +\n";
				}

				print FDOC " (link:../"."$1"."[../$1]"." l.$funchash->{$f}->{line}) ";
				if ( exists($bsdmanpage{$f}) ){
						print FDOC "manpage: link:manpages/$bsdmanpage{$f}.rst"."[$f] +\n";
				}	else {
						print FDOC " +\n";
				}
				if ( exists($funchash->{$f}->{doc} ) ){
						print FDOC "",join(" +\n ", split( "\n", $funchash->{$f}->{doc}) )," +\n ";
						#print FDOC "               $funchash->{$f}->{doc}\n";
				}
				print FDOC "\n\n";
		}
}

close FDOC;

# write doc
open( FDOC, ">", "$mlibdir/doc/mlfunctions-shortref-lf.html" ) or die;
#*FDOC = *STDOUT;

copytemplates( FDOC, $mlibdir, "mlfunctions-shortref-lf.html.top" );

print FDOC '<html><body><table><colgroup><col><col><col width="150"></colgroup>';

foreach my $f ( sort( keys(%{$funchash} ) ) ){
				print FDOC "<tr valign=\"top\"><td><small>";
		if ( exists($bsdmanpage{$f}) ){
				printf FDOC "<a target=\"right\" href=\"manpages/$bsdmanpage{$f}.rst.html\">$f</a>";
		} else {
				if ( exists($syscallsysdefs->{$f} ) ){
						printf FDOC "ksys_$f";
				} else {
						printf FDOC "$f";
				}
		}
		print FDOC "</small></td><td><small>";

		print FDOC "   <a href=\"../$1\" target=\"right\">../$1</a>  $funchash->{$f}->{line} ";

		print FDOC "</small></td><td><small>";
		$funchash->{$f}->{file}=~/minilib\/(.*)/;

		if(1){if ( exists($funchash->{$f}->{docdef}) ){
				print FDOC " $funchash->{$f}->{docdef}";
		}
		#		print FDOC " </small></td><td><small>\n";
		#if ( exists($depends->{$f}) ){  
		#		print FDOC " Defines: ".join(" ",keys(%{$fulldeqpends->{$f}})),"\n";
		#}
}

		if ( exists($funchash->{$f}->{doc} ) ){
				print FDOC "</small></td></tr><tr><td></td><td colspan=\"2\"><small>";
				print FDOC "",join("\n ", split( "\n", $funchash->{$f}->{doc}) ),"\n ";
		
				#print FDOC "               $funchash->{$f}->{doc}\n";
		}
		print FDOC "</small></td></tr>\n";
}

		print FDOC "</table>";
print FDOC '</body></html>';
close FDOC;



# write doc
open( FDOC, ">", "$mlibdir/doc/minilib.md" ) or die;
#*FDOC = *STDOUT;

copytemplates( FDOC, $mlibdir, "minilib.md.top" );

foreach my $k ( sort(keys(%{$headerhash})) ){
		print FDOC "\n\n==========\n$k\n==========\n\n";
		foreach my $f ( sort( keys(%{$headerhash->{$k}} ) ) ){
				if ( exists($syscallsysdefs->{$f} ) ){
						printf FDOC "ksys%-15s\n",$f;
				};

				if ( exists( $funchash->{$f}->{def} ) ){
						printf FDOC "%-15s",$f;

				print FDOC "$funchash->{$f}->{def}\n";
				if ( exists($funchash->{$f}->{doc} ) ){
						print FDOC "               ",join("\n             ", split( "\n", $funchash->{$f}->{doc}) ),"\n";
						#print FDOC "               $funchash->{$f}->{doc}\n";
				}
				$funchash->{$f}->{file}=~/minilib\/(.*)/;
				print FDOC  "               ($1: $funchash->{$f}->{line})\n";

				print FDOC "\n";
		}
		}
}

close FDOC;


#exit 0;
# write 

dbgdump( $funchash );
dbg("depends");
dbgdump( $depends );

my $includefirst;

# define functions, which are dependencies, when needed
sub printdepend{
		my $fh = shift;
		my $d = shift;

		print $fh "\n#ifdef mini_$d\n//dep\n";
		foreach my $on ( split( " ", $depends->{$d} ) ){
				print $fh "#ifndef mini_$on\n#define mini_$on\n#endif\n";
				$includefirst->{$on} = 1;
		}
		print $fh "#endif\n"
}

# include the header files first, on which we depend,
# or define the needed functions.
sub headerinclude{
		my $fh = shift;
		my $i = shift;
		print $fh "\n// $funchash->{$i}->{file}\n";
		print $fh "#ifdef mini_$i\n";
		if ( $funchash->{$i}->{file} =~ /\S\.h$/ ){
				if ( exists($funchash->{$i}->{needs}) ){
						foreach my $c ( split( " ", $funchash->{$i}->{needs} ) ){
								if ( ! exists( $alreadyincluded->{$c} ) ){ # already incuded before. e.g. syscall.h
										print $fh "#include \"$c\"\n";
								}
						}
				}
				if ( exists( $funchash->{$i}->{macro} ) ){
						print $fh $funchash->{$i}->{def}."";
				} else {
						print $fh "#include \"$funchash->{$i}->{file}\"\n";
				}
		} else {
				print $fh $funchash->{$i}->{def}."";
		}
		print $fh "#endif\n";
}

# Writing minilib.h starts here


my $ml = headerfh( "minilib.h", $mlibdir );


foreach my $d ( keys (%{$depends}) ){
		printdepend($ml, $d);
}

print $ml "// Start incfirst\n";

foreach my $i ( keys(%{$includefirst}) ){
		headerinclude( $ml, $i );
}

print $ml "// End incfirst\n";

foreach my $i ( keys(%{$funchash}) ){
		if ( !exists( $includefirst->{$i} ) ){
				headerinclude( $ml, $i );
		}
}

print $ml <<TMPL_END;
#ifdef INCLUDESRC
#ifndef included_minilib_c
#include "minilib.c"
#endif
#endif

#endif

// ifndef LDSCRIPT
#else

TMPL_END

# minilib.h ends here.
# ldscripts

foreach my $script ( qw/default onlytext text_and_bss/ ){
		my $s = $script;
		$s =~ s/\./_/g;
		print $ml "#ifdef LDSCRIPT_$s\n\n";
		print $ml `cat $mlibdir/ldscripts/ld.script.$script`;
		print $ml "#endif\n\n";
}

print $ml "#endif\n\n";

close($ml);

# end header file here..
dbg("$C"."==================$N");

$debug=0;


# write minilib.c
my $mc = headerfh( "minilib.c", $mlibdir );


sub sourceinclude{
		my $fh = shift;
		my $i = shift;

		print $fh "\n// $funchash->{$i}->{file}\n";
		#if ( ! exists( $depends->{$i} ) ){
		print $fh "#ifdef mini_$i\n";
		print $fh "#include \"$funchash->{$i}->{file}\"\n";
		print $fh "#endif\n";
		#} else {
		#		print $fh "\n// mini_$i depends on $depends->{$i}. Included below/above\n";
		#}
}

foreach my $f ( keys(%{$funchash}) ){
	 if ( $f eq "0"){
			 delete($funchash->{"0"});
			 next;
	 }

		dbg("kkk: $f ");

		if ( exists( $funchash->{$f}->{file} ) ){
		dbg(" - $funchash->{$f}->{file} \n");

		if ( $funchash->{$f}->{file} =~ /\S\.c$/ ){
				sourceinclude( $mc, $f );
		}
		}
}

dbg(" xxxxx sourceinclude");
dbg( $fhhash );
dbg("xx funchash");
dbgdump( $funchash );
dbg("xx headerhash");
dbg( $headerhash );
dbg("zz headerhash");

print $mc "\n#endif\n";

close( $mc );

#= headerfh( "minilib.conf", $mlibdir );
sub confighandler{
		my $fh = shift;
		foreach my $header ( keys(%{$headerhash}) ){
				print  $fh "\n# === $header\n\n";
				foreach my $f ( keys( %{$headerhash->{$header}}) ){ 
						printf $fh "# mini_$f\n";
				}
				print $fh "\n";
		}
		return(1);
}

dbg("$AC_R XXXXXX $N\n");

template( "minilib.conf", "minilib_config", { Buildswitches=>\&confighandler } );


sub configallhandler{
		my $fh = shift;
		foreach my $header ( keys(%{$headerhash}) ){
				print  $fh "\n# === $header\n";
				dbg "\n# === $header\n";
				foreach my $f ( keys( %{$headerhash->{$header}}) ){ 
						printf $fh "mini_$f\n";
						dbg  "mini_$f\n";
				}
				print $fh "\n";
		}
		return(1);
}



template( "minilib.conf.all", "minilib_config", { Allswitches=>\&configallhandler } );

#print $conf "\n\n#endif\n\n";
#close($conf);

sub configscripthandler{
		my $fh = shift;
		foreach my $func ( keys(%{$funchash}) ){
						printf $fh "mini_$func(){ 
  echo \"#define mini_$func $1\" 
}\n";
				}
		return(1);
}

template( "scripts/genconfig.sh", "define_functions", { generate=>\&configscripthandler } );


sub genconfighandler{
		my $fh = shift;
		foreach my $func ( keys(%{$funchash}) ){
						printf $fh "#define $func(...) _M_MLIB_$func"."_M_(__VA_ARGS__)\n";
				}
		return(1);
}

template( "minilib.genconf.h", "define_macros", { generate=>\&genconfighandler } );




dbg ( Dumper( $syscalldefs ) );

dbg( "stubs: $syscallstubs\n" );


sub syscalldefine{
		my $fh = shift;
		foreach my $k ( keys( %{$syscalldefs} ) ){
				my $def = $syscalldefs->{$k}->{def};
				my $a = 1;
				my $b = 2;
				while ( $def =~ s/(^DEF_syscall\((?:.*?,){$b}.*?[\*]*)(\S*)\s*?([,)])/$1a$a$3 / ){
						$a++; $b++;
						dbg "def: $def, $a, $b\n";
				}
				$a=1; $b=3;
			 #while ( $def =~ s/(^DEF_syscallret\(.*\((?:.*?,){$b}.*?[\*]*)(\S*)\s*?([,)])/$1 a$a $3/ ){
				while ( $def =~ s/(^DEF_syscallret\((?:.*?,){$b}.*?[\*]*)(\S*)\s*?([,)])/$1a$a$3/ ){
						$a++; $b++;
				}


				print $fh "/* $syscalldefs->{$k}->{f}->{file}, line: $syscalldefs->{$k}->{f}->{line} */\n";
				dbg ("/* $syscalldefs->{$k}->{f}->{file}, line: $syscalldefs->{$k}->{f}->{line} */");
				$def =~ s/^DEF/define/;

				$def =~ /^\S*?,(\d*)/;
				if ( $1 >= 4 ){
						$def =~ s/define_syscall/define_syscall_noopt/;
				}
				print $fh "REAL_$def\n";
				$def =~ s/(.*?)\((.*?),/$1( $Y$2 $N,/; 
				dbg ("REAL_$def\n");
		}

		if ( 1 ) { # syscalldefs (without wrapper) are written here.
				print $fh "#ifdef mini_ksyscalls\n\n";
		foreach my $k ( keys( %{$syscallsysdefs} ) ){
				my $def = $syscallsysdefs->{$k}->{def};
				my $a = 1;
				my $b = 2;
				chomp $def;

				print $fh "// $syscallsysdefs->{$k}->{f}->{file}, line: $syscallsysdefs->{$k}->{f}->{line}\n";
				print $fh "// $def\n";
				while ( $def =~ s/(^SYSDEF_syscall\((?:.*?,){$b}.*?[\*]*)(\S*)\s*?([,)])/$1a$a$3 / ){
						$a++; $b++;
						#dbg "def: $def, $a, $b\n";
				}
				$a=1; $b=3;
			 #while ( $def =~ s/(^DEF_syscallret\(.*\((?:.*?,){$b}.*?[\*]*)(\S*)\s*?([,)])/$1 a$a $3/ ){
				while ( $def =~ s/(^SYSDEF_syscallret\((?:.*?,){$b}.*?[\*]*)(\S*)\s*?([,)])/$1a$a$3/ ){
						$a++; $b++;
				}

				#dbg ("/* $syscallsysdefs->{$k}->{f}->{file}, line: $syscallsysdefs->{$k}->{f}->{line} */");
				$def =~ s/^SYSDEF/define/;
				$def =~ /^\S*?,(\d*)/;
				if ( $1 >= 4 ){
						$def =~ s/define_syscall/define_syscall_noopt/;
				}

				print $fh "SYSREAL_$def\n\n";
				$def =~ s/(.*?)\((.*?),/$1( $Y$2 $N,/; 
				dbg ("SYSREAL_$def\n");
		}
				print $fh "#endif\n\n";
		}
		return(1);
}


template( $syscallstubs, "generated-macros", { syscalldefs=>\&syscalldefine } );


dbg( "$LB ====  genheaders done ==== $N" );

dbgdump($rdepends);

exit(0);


#Licensing terms of this script.
$LICENSE = << 'ENDLICENSE';

Copyright (c) 2012-2019, Michael (Misc) Myer 
(misc.myer@zoho.com, www.github.com/michael105)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
   the file NOTICE, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   the file NOTICE, this list of conditions and the following disclaimer in 
   the documentation and/or other materials provided with the distribution.
 * Neither the name of the minilib nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL Michael Myer BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

ENDLICENSE

