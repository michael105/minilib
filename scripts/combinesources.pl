#!/usr/bin/perl -w
#
# Fast and ugly hack. But works
# combine all sources, which are included by "include" directives.


sub debug{
		print STDERR "// ", shift, "\n";
}

$included;

my $recursion = 0;
	
#my $includeonce = { syscall_stubs.h=>1 }



# Ok. there's the problem, that some includes HAVE to be included several times.
# But, allwing recursive inclusion, might lead to a circle.
# so, next try..
sub slurpfile{
		my $f = shift;
		$recursion++;
		my $orif = $f;
		my $pwd = `pwd`;
		debug( "Current path: $pwd,  recursion: $recursion");

		if ( defined( $included{$f} ) ){
				debug ("YYYYYYYYYYYYYY   Already included: $f");
				return;
		}
		my $fn = $f;
		$f =~/(.*)\/(.*)/;
		my $p = $1; $fn = $2;
		if ( $fn){
				$p = $1; $fn = $2;
				debug "Path: $p  Name $fn";
				#chdir( $p );
				#debug("chdir( $p )");
				$f = $fn;
		}
		my $mpwd = `pwd`;

		$f = $orif;

		if ( $recursion > 2 ){
				if ( grep { /$f/ } qw /minilib.h syscall_stubs.h syscall.h timeval.h msprintf.c mfprintf.c exit.h/ ){
						debug "Recurse: $recursion, file: $f, Returning.";
						return;
				}
		}



		$included{$f} = 1;
		my $F;
		 my @path =("include/", "src/", "asm/", "macros/", "headers/common/", "headers/linux_x64/");
		 my $pa = "";
		 debug("f: $f");
		 while ( (!open $F, "<", "$pa"."$f" ) ){
			 $pa = shift @path;
			 if ( !$pa ){ print STDERR "Couldn't find $f\n"; return }
	 		debug("O: $pa"."$f");
		}
		#debug ("XXXXXXXXXXXXXXXXX Couldn't open: $f\n") ;

		while (my $l = <$F>){
				#my $l =$_;
				if ( ( $l =~ /^#include.*\"(.*)\"/ ) || ($l =~ /^#include.*\<(.*)>/ )){
				my $m = $1;
				if ( $m ){
						debug "YYYYYXXXXXXXXXXXX*************** file: $m \n";
						slurpfile( $m );
						#chdir ( $mpwd );
						#debug ("chdir ( $mpwd )");
				}; } 
				else {
						print $l;
				}
		}
		close($f);
		$recursion --;
}

#
## this also will not resolve every problem. 
#    note.. (2020)..rotfl sometimes I have to
#    laugh really hard about myself. grin. 
#    "this also will not resolve every problem"...
#    so my whatever recursive inclusion recursion
#    solver did not solve every problem. :)) very well. slurpfile_rec grin
#    dbg('XXXXXXXXXXXX') might mean .. fxx. :)
#sub slurpfile_rec{
#		my $f = shift;
#		my $included = shift;
#		if ( $f =~ /minilib.h/ ){
#				return;
#		}
#		my $thislevel;
#		if ( defined( $included{$f} ) ){
#				debug ("Already include: $f");
#				return;
#		}
#		$included{$f} = 1;
#		open my $F, "<", $f or debug ("XXXXXXXXXXXXXXXXX Couldn't open: $f\n") ;
#
#		while (my $l = <$F>){
#				#my $l =$_;
#				if ( $l =~ /^#include.*\"(.*)\"/ ){
#				my $m = $1;
#				if ( $m ){
#						debug "XXXXXXXXXXXXXXXXXX file: $m \n";
#						slurpfile( $m );
#				}; } 
#				else {
#						print $l;
#				}
#		}
#}
#




my $f = shift;

if ( !$f ){
		print "usage: combinesources sourcefile\n";
		exit;
}

debug "f: $f\n";

slurpfile( $f );
