#!/bin/perl -w
#
my $fhhash;
# Where to put the generated ansi/posix headers
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

my $globalintemplate = << "TMPL_IN";

// Header generated by the script tools/genheaders.pl
// Put changes into filename.in 

TMPL_IN

# Only for debuggging
use Data::Dumper::Simple;

sub dgb{
		my $r = shift;
		#print Dumper($${$r});
}



BEGIN{
		use File::Basename;
		($name,$path,$suffix) = fileparse ($0);
		print "path: $path";
		push @INC, "$path";
}



require "cref.pm";


# ansicolors
#define AC_BLACK "\033[0;30m"
#define AC_RED "\033[0;31m"
$G= "\033[32;0m"; # Green
#define AC_BROWN "\033[0;33m"
#define AC_BLUE "\033[0;34m"
$C = "\033[0;35m"; # Cyan
$M = "\033[0;36m"; # Marine
#define AC_LGREY "\033[0;37m"
$N= "\033[0;38m"; # White

#define AC_GREY "\033[1;30m" 
$LR = "\033[1;31m"; # Light red
$LG =  "\033[1;32m"; # Light green
$Y =  "\033[1;33m"; # Yellow
#define AC_LBLUE "\033[1;34m"
#define AC_LMAGENTA "\033[1;35m"
#define AC_LMARINE "\033[1;36m"
#define AC_LWHITE "\033[1;37m"


sub dbg{
		while ( my $s = shift ){
				print $s;
		}
		print "\n";
}


# Looks for templates and copies them
sub copytemplates{
		my $fh = shift;
		my @fn = @_;
		foreach my $p ( "$headerdir", "$headerdir/templates", "$mlibdir/templates", "$mlibdir" ){ 
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
		print ("Header: $header\n");
		if ( ! exists($fhhash->{fh}->{$header}) ){
				open( $fhhash->{fh}->{$header}, ">", "$path/$header" ) or die;
				copytemplates( $fhhash->{fh}->{$header}, "header.tmpl.top", "$header.top" );			
				my $h = $header;
				$h =~ s/\./_/g;
				print {$fhhash->{fh}->{$header}} "#ifndef included_$h\n#define included_$h\n\n";
				copytemplates( $fhhash->{fh}->{$header}, "header.in", "$header.in" );			
		}
		return( $fhhash->{fh}->{$header} );
}

# iterate over commandline args
while ( my $file = shift ){
		open (F, "<", $file) or die;

		my $header = 0;

		while ( my $l= <F>){
				my $f;
				my $tag = 0;
				my $func = 0;
				$f->{file} = $file;
				if ( $l =~ /^DEF_syscall(ret)*.(.*?),/ ){
						$func = $2;
				}

				if ($l=~ /^\/\/\+/){
						do {
								print ( "$M l: $l $N\n" );
								$l=~ /^\/\/\+(\S*)\s?(.*)?$/;
								$tag = $1;
								my $c = $2 || 0;
								print "tag: $tag c: $c\n";

								if ( $tag eq 'header' ){
										print "l: $l";
										#$l =~ /^\/\/\+header (\S*)/;
										$header = $c or die;
								} elsif ( $tag eq 'def' ){
										$f->{def} = <F>;
										print "def: $f->{def} $file: $l";
										if ( $f->{def} =~ /^DEF_syscall(ret)*.(.*?),/ ){
												$func = $2;
										} else {
												$f->{def} =~ /.* \**(\S*)\(.+?\)\{.*$/;
												$func = $1;
										}
										print "func: $LR $func $N\n";
										$f->{def} =~ s/\{.*$/;/;
										print "def: $Y $f->{def} $N l: $l";
								} elsif ( $tag eq 'needs' ){
										#$l =~ /^\/\/\+needs\s?(\S*)/;
										$f->{needs} = $c;
										print "$LG needs: $f->{needs} $N\n";
								} elsif ( $tag eq 'depends' ){
										$f->{dep} = $c;
										print "$LG depends: $f->{dep} $N\n";
								} elsif ( $tag eq 'after' ){
										$f->{after} = $c; # e.g. printf after atoi (when defined atoi)
								} elsif( $tag eq 'inc' ){
										print {headerfh($header,$headerdir)} "// file: $file\n#include \"$file\"\n";
										$f->{inc} = 1;
								}
								$l = <F>;
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
						if ( exists($f->{dep} )){
								$depends->{$func} = $f->{dep};
						}

						if ( $f->{header} && $f->{def} ){
								print "header: $f->{header}\n def: $f->{def}\n";
								print {headerfh($f->{header},$headerdir)} "// file: $f->{file}\n$f->{def}\n";
								$fhhash->{sources}->{$f->{header}}->{$file} = 1;
						}
				}

		}
}

# write the #include "source.c" directives
# iterate over each header include filehandler
foreach my $key ( keys(%{$fhhash->{fh}}) ){
		print "key: $key\n";
		print {$fhhash->{fh}->{$key}} "\n\n#include \"include/minilib_global.h\"\n";
		print {$fhhash->{fh}->{$key}} "\n\n#ifdef mini_INCLUDESRC\n\n";
		foreach my $s ( keys(%{$fhhash->{sources}->{$key}}) ){
				print "source key: $s\n";
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

my $conf = headerfh( "minilib.conf", $mlibdir );

foreach my $header ( keys(%{$headerhash}) ){
		print  $conf "\n\n//     $header    \n";
		foreach my $f ( keys( %{$headerhash->{$header}}) ){ 
				printf $conf "//#define mini_$f\n";
		}
}

print $conf "\n\n#endif\n\n";
close($conf);

