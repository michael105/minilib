#!/bin/perl -w

my @files = `	find . -executable -type f`; #-exec ls -lo --time-style=long-iso {} \; `;
chomp @files;

my $bytes = 0;

foreach my $k ( sort( @files)){ 
		$k=~s/^\.\///;

		my $date = `stat --printf=%y $k.c`;
		$date=~s/(\S*) *.*/$1/;

		my $size = `stat --printf=%s $k`;
		$bytes+=$size;

		printf("%-15s %s             %s\n", $k, $date, $size) ; 
}

print("===============================================\n");
printf("%+44s", "size: $bytes Bytes\n");

