#!/bin/perl
#
#use Misc::Template;



open F, "<", shift or die ("No such file");


my @calls = grep { /^\|\d/ } <F>;

#print @calls;

open DOC, "<", "syscalls_doc.asc";
my @doc = <DOC>;
close DOC;
open DOC, ">", "syscalls_docout.asc";

print @doc;

open H, ">", "syscalls_x64.h";
print H "#ifndef syscalls_x64_h\n
#define syscalls_x64_h\n
";



while ( my $l = shift(@doc) ) {  
		last if ( $l =~ /^\/\/ TMPL_START/ );
		print DOC $l;
}
my $a=0;

foreach my $c ( @calls ){
		#last if ( ($a++)==11 );
		my $def = $c;
		if ( $c =~ s/^\|\d*\| sys_(.*?)\|// ){
				print "call: $1\n";
				my $d = $1;
				while(	$c=~ s/^(...*?)\|(.*?\S\S+\s+.*?)(\||\s+$)/$1, $2\|/ ){
						print "c: $c\n";
				}
				$c =~ s/(\s*\|\s*)*//g;
				print "ccc: $c\ndef: $def d: $d\n";
				syscalldef( $d, $c, $def );

		} else {
				#print "XXX: $c\n";
		}

}

my $l;
while ( $l=shift(@doc) ){
		last if ( $l=~ /\/\/ TMPL_END/ );
}

do {
		print DOC $l;
}		while( $l=shift(@doc) );

print H "\n\n#endif\n\n";

close DOC;
close H;


sub syscalldef{
		my $call = shift;
		my $args = shift;
		my $def = shift;
		print "\033[34m call: $call \033[30m\n";
		print "\033[33m int sys_$call( $args );\033[37m \n";
		my $argcount = 0;
		my $a = $args;
		my @p;
		if ( $args =~ /\S/ ){
				$argcount = 1;
				$a=~s/(.*?)\s*\S*,/push @p,$1;$argcount++/eg;
		}

		my @m = `man 2 $call`;
		my $n = "";
		if ( @m > 5 ){
				while ( $n = shift @m ){
						if ( $n =~ /NAME/ ){
								 $n = shift @m;
								last;
						}
				}
				#print @m;
		}
		print DOC $def;
		print DOC "|\n7+| $n\n";
		if ( $argcount ){
				print H "\nDEF_syscall($call,$argcount,";
				print H $args,")\n";
		} else {
				print H "\nDEF_syscall($call,0)\n";
		}

		#print H join(",",@p);
}


