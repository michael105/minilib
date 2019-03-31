#!/bin/perl -w
# (modified) BSD 3-clause (c) 2019 Michael misc Myer misc.myer@zoho.com;
# www.github.com/michael105; BSD-Licensing terms attached
#
#
# somethere I've to start to docu this thing.
# althoug most possibly I'm going to pull the code out of here, which is not specific to the minilib,
# and do it more generic - this script works out quite useful,
# and is good enough for a project on its own,
# I guess.
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
# Where to put the generated ansi/posix headers and look for templates
my $mlibdir = shift;
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

my $syscalldefs;
my $syscallstubs=0; # Saves the name of the header "syscall_stubs.h",
										# for later processing

my $globalintemplate = << "TMPL_IN";

// Header generated by the script tools/genheaders.pl
// Put changes into filename.in 

TMPL_IN

# Only for debuggging
use Data::Dumper::Simple;


# globally enable/disable debug
$debug = 1;

sub dbg{
	 	return if (!$debug);
		while ( my $s = shift ){
				print $s;
		}
		print "\n";

}


sub dbgdump{
	 	return if (!$debug);
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
				print {$fhhash->{fh}->{$header}} "#ifndef included_$h\n#define included_$h\n\n";
				copytemplates( $fhhash->{fh}->{$header}, $path, "header.in", "$header.in" );			
		}
		return( $fhhash->{fh}->{$header} );
}

# iterate over commandline args
while ( my $file = shift ){
		open (F, "<", $file) or die;

		if ( $file =~ /syscall_stubs.h/ ){
				$syscallstubs = $file;
		}

		my $header = 0;
		my $line = 0;
		while ( my $l= <F>){
				my $f;
				my $tag = 0;
				my $func = 0;
				$line++;
				$f->{file} = $file;
				if ( $l =~ /^DEF_syscall(ret)*.(.*?),/ ){
						$func = $2;
						$syscalldefs->{$func}->{def} = $l;
				}

				if ($l=~ /^\/\/\+/){
						do {
								dbg ( "$M l: $l $N\n" );
								$l=~ /^\/\/\+(\S*)\s?(.*)?$/;
								$tag = $1;
								my $c = $2 || 0;
								dbg("tag: $tag c: $c\n");

								if ( $tag eq 'header' ){   # tag parsing. should change this.
										dbg("l: $l");
										#$l =~ /^\/\/\+header (\S*)/;
										$header = $c or die;
								} elsif ( $tag eq 'def' ){
										$f->{def} = <F>;
										$line++;
										dbg("def: $f->{def} $file: $l");
										if ( $f->{def} =~ /^DEF_syscall(ret)*.(.*?),/ ){
												$func = $2;
										} else {
												$f->{def} =~ /.* \**(\S*)\(.+?\)\{.*$/;
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
								} elsif( $tag eq 'inc' ){
										print {headerfh($header,$headerdir)} "// file: $file\n#include \"$file\"\n";
										$f->{inc} = 1;
								} elsif( $tag eq 'macro' ){
										if ( $l =~ /^\/\/\+macro\s*(\S+)/ ){
												$l =~ s/^\/\/\+macro\s*//;
												$f->{def} = "#define $l";
												$l =~ /(\S*?)\(/;
												$func = $1;
												dbg("$LR macro: $f->{def}  -  func: $func $N");
										} else {
												$f->{def} = <F>;
												$line++;
												dbg("def+ $f->{def}");
												$f->{def} =~ s/^\/\///;
												dbg("def+ $f->{def}");

												$f->{def} =~ /#define\s*(\S*?)\(/;
												$func = $1;
												dbg("$LR macro: $f->{def}   -   func: $func $N");
										}
								}
								$l = <F>;
										$line++;
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
										$f->{header} = "miniextras.h";
								} else {
										$f->{header} = $header;
								}
						}
						$headerhash->{$f->{header}}->{$func}=1;
						$funchash->{$func} = $f;
						$f->{line} = $line;
						if ( exists($f->{dep} )){
								$depends->{$func} = $f->{dep};
						}
						if ( exists($syscalldefs->{$func}) ){
								$syscalldefs->{$func}->{f} = $f
						}

						if ( $f->{header} && $f->{def} ){
								dbg("header: $f->{header}\n def: $f->{def}\n");
								print {headerfh($f->{header},$headerdir)} "// file: $f->{file}\n$f->{def}\n";
								$fhhash->{sources}->{$f->{header}}->{$file} = 1;
						}
				}

		}
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


# write 

dbg( $funchash );
dbg( $depends );

my $includefirst;

# define functions, which are dependencies, when needed
sub printdepend{
		my $fh = shift;
		my $d = shift;

		print $fh "\n#ifdef mini_$d\n";
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
				print $fh "#include \"$funchash->{$i}->{file}\"\n";
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

foreach my $i ( keys(%{$includefirst}) ){
		headerinclude( $ml, $i );
}

foreach my $i ( keys(%{$funchash}) ){
		headerinclude( $ml, $i );
}

print $ml <<TMPL_END;


#ifdef INCLUDESRC
#include "minilib.c"
#endif

#endif
TMPL_END

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
		print $fh "#ifdef mini_$i\n";
		print $fh "#include \"$funchash->{$i}->{file}\"\n";
		print $fh "#endif\n";
}

foreach my $f ( keys(%{$funchash}) ){
		if ( $funchash->{$f}->{file} =~ /\S\.c$/ ){
				sourceinclude( $mc, $f );
		}
}

dbg( $fhhash );
dbg( $funchash );
dbg( $headerhash );

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
						#dbg "def: $def, $a, $b\n";
				}
				$a=1; $b=3;
			 #while ( $def =~ s/(^DEF_syscallret\(.*\((?:.*?,){$b}.*?[\*]*)(\S*)\s*?([,)])/$1 a$a $3/ ){
				while ( $def =~ s/(^DEF_syscallret\((?:.*?,){$b}.*?[\*]*)(\S*)\s*?([,)])/$1a$a$3/ ){
						$a++; $b++;
				}


				print $fh "/* $syscalldefs->{$k}->{f}->{file}, line: $syscalldefs->{$k}->{f}->{line} */\n";
				dbg ("/* $syscalldefs->{$k}->{f}->{file}, line: $syscalldefs->{$k}->{f}->{line} */");
				$def =~ s/^DEF/define/;
				print $fh "REAL_$def\n";
				$def =~ s/(.*?)\((.*?),/$1( $Y$2 $N,/; 
				dbg ("REAL_$def\n");
		}
		return(1);
}


template( $syscallstubs, "generated-macros", { syscalldefs=>\&syscalldefine } );


dbg( "$LB ====  genheaders done ==== $N" );

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
