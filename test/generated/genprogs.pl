#!/bin/perl

open F, "<", "functions.txt";


foreach my $l ( <F> ){
		next if ( length($l) < 3 );
		$l=~/^(\S*):\s*(.*)/;
		my $f = $1; my $def= $2;
		print "f: $f, def: $def\n";
		next if ( $def=~/DEF/ );
		if ( -e "edited/$f.c" ){
				print "Edited: $f\n";
				system("cp edited/$f.c ./");
				next;
		}

		open C, ">", "$f.c";
		print C 
"#if 0
mini_$f
mini_buf 0
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT text_and_bss
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
";

	$def =~ /\((.*)\)/;
	my $args = $1;
	print "args: $args\n";
	my @para;
	my $b = 1;
	foreach my $a ( split( ',', $args ) ){
			print "a:$a\n";
			my $t;
			my $var="a$b=0";
			if ( $a=~/^(.*\*)/ ){
					$t = $1;
					if ( $t=~ /char\s*\*/ ){
							$var="a$b=".'""';
					}
			} else {
					$a=~s/\S+\s*\s*$//;
					$t=$a;
			}
			print "t: $t\n";
			if ( $t =~ /va_list/ ){
					print C "  volatile $t a$b;\n";
			} else { 
					print C "  volatile $t $var;\n";
			}
			push @para,"a$b";
			$b++;
	}

	print C "  $f(".join(",", @para ).");\n";

	print C "  return(ret);\n}\n";
}


