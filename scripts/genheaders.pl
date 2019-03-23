#!/bin/perl -w
#
my $fhhash;
# Where to put the generated ansi/posix headers
my $ansidir = shift;
# Header file for storing defines
my $mlh = shift;

my $funchash;
my $depends;


# ansicolors
#define AC_BLACK "\033[0;30m"
#define AC_RED "\033[0;31m"
#define AC_GREEN "\033[32;0m"
#define AC_BROWN "\033[0;33m"
#define AC_BLUE "\033[0;34m"
#define AC_MAGENTA "\033[0;35m"
#define AC_MARINE "\033[0;36m"
#define AC_LGREY "\033[0;37m"
$N= "\033[0;38m";

#define AC_GREY "\033[1;30m" 
$LR = "\033[1;31m"; 
$LG =  "\033[1;32m";
$Y =  "\033[1;33m";
#define AC_LBLUE "\033[1;34m"
#define AC_LMAGENTA "\033[1;35m"
#define AC_LMARINE "\033[1;36m"
#define AC_LWHITE "\033[1;37m"


# gets called for each ansi header referenced
# if the file isn't open yet,
# creates and returns a new filehandle
sub ansifh{
		my $ansi = shift;
		if ( ! exists($fhhash->{fh}->{$ansi}) ){
				open( $fhhash->{fh}->{$ansi}, ">", "$ansidir/$ansi" ) or die;
				my $h = $ansi;
				$h =~ s/\./_/g;
				print {$fhhash->{fh}->{$ansi}} "// Header generated by tools/genheaders.pl\n".
								"// Put changes into $ansi.in\n\n#ifndef ansi_$h\n#define ansi_$h\n\n";

				if ( -e "$ansidir/$ansi.in" ){
						open(FH,"<", "$ansidir/$ansi.in" ) or die;
						while ( <FH> ){
								print {$fhhash->{fh}->{$ansi}} $_;
						}
						print {$fhhash->{fh}->{$ansi}} "\n\n";
						close FH;
				} 

		}
		return( $fhhash->{fh}->{$ansi} );
}

# iterate over commandline args
while ( my $file = shift ){
		open (F, "<", $file) or die;

		my $ansi = 0;

		while ( my $l= <F>){
				my $f;
				my $tag = 0;
				my $func = 0;
				$f->{file} = $file;

				if ($l=~ /^\/\/\+/){
						do {
								$l=~ /^\/\/\+(\S*)\s?(.*)?$/;
								$tag = $1;
								my $c = $2 || 0;
								print "tag: $tag\n";

								if ( $tag eq 'ansi' ){
										print "l: $l";
										#$l =~ /^\/\/\+ansi (\S*)/;
										$f->{ansi} = $c or die;
								} elsif ( $tag eq 'def' ){
										$f->{def} = <F>;
										print "def: $f->{def} l: $l";
										$f->{def} =~ /.* (\S*)\(.+?\)\{.*$/;
										$func = $1;
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
								} elsif( $tag eq 'inc' ){
										print {ansifh($ansi)} "// file: $file\n#include \"$file\"\n";
										$f->{inc} = 1;
								}
								$l = <F>;
								$tag = 0;
						} while (defined($l) && ($l=~ /^\/\/\+(\S*)/) );
						if ( $func ){
								$funchash->{$func} = $f;
								if ( exists($f->{dep} )){
										$depends->{$func} = $f->{dep};
								}
						}
						if ( $ansi && $def ){
								print "ansi: $ansi\n def: $def\n";
								print {ansifh($ansi)} "// file: $file\n$def\n";
								$fhhash->{sources}->{$ansi}->{$file} = 1;
						}
				}
		}

}


# write the #include "source.c" directives
# iterate over each ansi include filehandler
foreach my $key ( keys(%{$fhhash->{fh}}) ){
		print "key: $key\n";
		print {$fhhash->{fh}->{$key}} "\n\n#include \"include/minilib_global.h\"\n";
		print {$fhhash->{fh}->{$key}} "\n\n#ifdef mini_INCLUDESRC\n";
		foreach my $s ( keys(%{$fhhash->{sources}->{$key}}) ){
				print "source key: $s\n";
				print {$fhhash->{fh}->{$key}} "#include \"$s\"\n";
		}
		print {$fhhash->{fh}->{$key}} "// Need global included. Doesn't matter by which file.\n#include \"src/minilib_global.c\"\n";
		print {$fhhash->{fh}->{$key}} "// Need start.c included. Doesn't matter by which file.\n#include \"asm/start.c\"\n";
		print {$fhhash->{fh}->{$key}} "#endif\n\n";

		print {$fhhash->{fh}->{$key}} "#endif\n";
		close( $fhhash->{fh}->{$key} );
}


# write 
use Data::Dumper::Simple;

print Dumper( $funchash );
print Dumper( $depends );

my $includefirst;

# define functions, which are dependencies, when needed
sub printdepend{
		my $d = shift;

		print "\n#ifdef mini_$d\n";
		foreach my $on ( split( " ", $depends->{$d} ) ){
				print "#ifndef mini_$on\n#define mini_$on\n#endif\n";
				$includefirst->{$on} = 1;
		}
		print "#endif\n"
}

# include the header files first, on which we depend,
# or define the needed functions.
sub headerinclude{
		my $i = shift;
		print "\n#ifdef mini_$i\n";
		if ( $funchash->{$i}->{file} =~ /\S\.h$/ ){
				if ( exists($funchash->{$i}->{needs}) ){
						foreach my $c ( split( " ", $funchash->{$i}->{needs} ) ){
								if ( ! exists( $alreadyincluded->{$c} ) ){ # already incuded before. e.g. syscall.h
										print "#include \"$c\"\n";
								}
						}
				}
				print "#include \"$funchash->{$i}->{file}\"\n";
		} else {
				print $funchash->{$i}->{def}."";
		}
		print "#endif\n";
}


foreach my $d ( keys (%{$depends}) ){
		printdepend($d);
}

foreach my $i ( keys(%{$includefirst}) ){
		headerinclude( $i );
}

foreach my $i ( keys(%{$funchash}) ){
		headerinclude( $i );
}
# braucht noch, fuer source: after ( z.B. printf nach uitodec )



