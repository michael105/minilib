#!/usr/bin/perl -w
#
# Fast and ugly hack. But works
# combine all sources, which are included by "include" directives.


sub debug{
		print "// ", shift, "\n";
}

#%included;

# Ok. there's the problem, that some includes HAVE to be included several times.
# But, allwing recursive inclusion, might lead to a circle.
# so, next try..
sub slurpfile{
		my $f = shift;
		my $pwd = `pwd`;
		debug( "Current path: $pwd");

		if ( defined( $included{$f} ) ){
				debug ("YYYYYYYYYYYYYY   Already included: $f");
				#return;
		}
		my $fn = $f;
		$f =~/(.*)\/(.*)/;
		my $p = $1; my $fn = $2;
		if ( $fn){
				$p = $1; $fn = $2;
				debug "Path: $p  Name $fn";
				#chdir( $p );
				#debug("chdir( $p )");
				$f = $fn;
		}
		my $mpwd = `pwd`;

		$included{$f} = 1;
		my $F;
		 my @path =("include/", "src/", "asm/", "macros/");
		 my $pa = "";
		 while ( (!open $F, "<", "$pa"."$f" ) ){
			 $pa = shift @path;
			 if ( !$pa ){ die;}
	 		debug("O: $pa"."$f");
		}
		#debug ("XXXXXXXXXXXXXXXXX Couldn't open: $f\n") ;

		while (my $l = <$F>){
				#my $l =$_;
				if ( $l =~ /^#include.*\"(.*)\"/ ){
				my $m = $1;
				if ( $m ){
						debug "XXXXXXXXXXXXXXXXXX*************** file: $m \n";
						slurpfile( $m );
						#chdir ( $mpwd );
						#debug ("chdir ( $mpwd )");
				}; } 
				else {
						print $l;
				}
		}
		close($f);
}


# this also will not resolve every problem.
sub slurpfile_rec{
		my $f = shift;
		my $included = shift;
		my $thislevel;
		if ( defined( $included{$f} ) ){
				debug ("Already include: $f");
				return;
		}
		$included{$f} = 1;
		open my $F, "<", $f or debug ("XXXXXXXXXXXXXXXXX Couldn't open: $f\n") ;

		while (my $l = <$F>){
				#my $l =$_;
				if ( $l =~ /^#include.*\"(.*)\"/ ){
				my $m = $1;
				if ( $m ){
						debug "XXXXXXXXXXXXXXXXXX file: $m \n";
						slurpfile( $m );
				}; } 
				else {
						print $l;
				}
		}
}





my $f = shift;

if ( !$f ){
		print "usage: combinesources sourcefile\n";
		exit;
}

debug "f: $f\n";

slurpfile( $f );
