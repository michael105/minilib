#!/bin/perl




open F,"<", "functions.txt";
my @f = <F>;
chomp @f;
close F;


#print @f;


my @n = map { if(/(\S*):/){ "$1".`stat --format ":%s" $1`} } @f;


print @n;


