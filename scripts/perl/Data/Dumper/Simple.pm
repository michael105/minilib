package Data::Dumper::Simple;

$REVISION = '$Id: Simple.pm,v 1.10 2005/05/20 01:37:08 ovid Exp $';
$VERSION  = '0.11';
use Filter::Simple;
use Data::Dumper ();
use strict;

my $DUMPER_FUNCTION = 'Dumper';
my $AUTOWARN;

my $COMMA      = qr/(?:,|=>)/;
my $ATOM       = qr/(?!\d)[[:word:]]+/;
my $SEP        = qr/::/;
my $NAME       = qr/$SEP?$ATOM(?:$SEP$ATOM)*/;

my $SCALAR     = qr/\$$NAME/;
my $ARRAY_ELEM = qr/\$$NAME\[[^]]+\]/;
my $ARRAY      = qr/\@$NAME/;
my $HASH_ELEM  = qr/\$$NAME\{[^}]+\}/;
my $HASH       = qr/\%$NAME/;

my $VAR        = qr/(?:$ARRAY|$HASH|$ARRAY_ELEM|$HASH_ELEM|$SCALAR)/;
my $END_STMT   = qr/(?=\s*[;}])/;

my $ARG_LIST   = qr/$VAR(?:\s*$COMMA\s*$VAR)*$END_STMT/;
my $PAREN_LIST = qr/\([^)]+\)/;

sub import {
    my ( $class, @args ) = @_;
    @args = $class->_validate_args(@args);
    my %args = @args;
    $DUMPER_FUNCTION = $args{as}       if $args{as};
    $AUTOWARN        = $args{autowarn} if $args{autowarn};
}

FILTER_ONLY executable =>
  sub {    # not using code due to a possible bug in Filter::Simple
    s{
            $DUMPER_FUNCTION\s*($PAREN_LIST|$ARG_LIST)
        }{
            my $args = $1;
            $args =~ s/^\((.*)\)$/$1/s;        # strip parens, if any
            my ($references, $names) = _munge_argument_list($args);
            # keep it on a single line so users can comment it out
            my $output = "Data::Dumper->Dump( [$references], [qw/$names/] )";
            if ($AUTOWARN) {
                $output = "$AUTOWARN($output)";
            }
            "($output)"; # parens prevent accidental indirect method syntax
        }gex
  };

sub _validate_args {
    my ( $class, @args ) = @_;
    if ( @args % 2 ) {
        _croak("$class->import requires an even sized list");
    }
    my %args = @args;
    if ( $args{as} && !_valid_sub_name( $args{as} ) ) {
        _croak("$args{as} is not a valid name for a subroutine");
    }
    if ( $args{autowarn} ) {
        $args{autowarn} = 'warn' unless _valid_sub_name( $args{autowarn} );
    }
    return %args;
}

sub _valid_sub_name { shift =~ /^[[:alpha:]][[:word:]]*$/ }

sub _croak {
    require Carp;
    Carp::croak(shift);
}

sub _munge_argument_list {
    my $arguments     = shift;
    my $sigils        = '@%&';
    my @raw_var_names =
      map { _strip_whitespace($_) }
      split /(?:,|=>)/ => $arguments;
    my @raw_escaped = @raw_var_names;
    my $varnames = join ' ' => map {
        s/(\\)?[$sigils]/$1 ? '$' : '*'/ge;
        s/\\//g;
        $_
      }    # turn @array into => [$*]array
      @raw_var_names;

    my $escaped_vars =
      join ', ' => map { s/\\\$/\$/g; $_ } # do not take a reference to a scalar
      map { s/(?<!\\)(?=[$sigils])/\\/g; $_ }    # take references to all else
      @raw_escaped;
    return ( $escaped_vars, $varnames );
}

sub _strip_whitespace {
    $_[0] =~ s/\s//g;
    return $_[0];
}

1;

__END__

=head1 NAME

Data::Dumper::Simple - Easily dump variables with names

=head1 SYNOPSIS

  use Data::Dumper::Simple;
  warn Dumper($scalar,  @array,  %hash);
  warn Dumper($scalar, \@array, \%hash);
  warn Dumper $scalar, @array, %hash;

=head1 ABSTRACT

  This module allow the user to dump variables in a Data::Dumper format.
  Unlike the default behavior of Data::Dumper, the variables are named
  (instead of $VAR1, $VAR2, etc.)  Data::Dumper provides an extended 
  interface that allows the programmer to name the variables, but this
  interface requires a lot of typing and is prone to tyops (sic).  This 
  module fixes that.

=head1 DESCRIPTION

C<Data::Dumper::Simple> is actually a source filter that replaces all instances
of C<Dumper($some, @args)> in your code with a call to
C<Data::Dumper-E<gt>Dump()>.  You can use the one function provided to make
dumping variables for debugging a trivial task.

Note that this is primarily a debugging tool.  C<Data::Dumper> offers a bit
more than that, so don't expect this module to be more than it is.

Note that if you strongly object to source filters, I've also released
L<Data::Dumper::Names>.  It does what this module does by it uses L<PadWalker>
instead of a source filter.  Unfortunately, it has a few limitations and is not
as powerful as this module.  Think of L<Data::Dumper::Names> as a "proof of
concept".

=head2 The Problem

Frequently, we use C<Data::Dumper> to dump out some variables while debugging.
When this happens, we often do this:

 use Data::Dumper;
 warn Dumper($foo, $bar, $baz);

And we get simple output like:

 $VAR1 = 3;
 $VAR2 = 2;
 $VAR3 = 1;

While this is usually what we want, this can be confusing if we forget which
variable corresponds to which variable printed.  To get around this, there is
an extended interface to C<Data::Dumper>:

  warn Data::Dumper->Dump(
    [$foo, $bar, $baz],
    [qw/*foo *bar *baz/]
  );

This provides much more useful output.

  $foo = 3;
  $bar = 2;
  $baz = 1;

(There's more control over the output than what I've shown.)

You can even use this to output more complex data structures:

  warn Data::Dumper->Dump(
    [$foo, \@array],
    [qw/*foo *array/]
  );

And get something like this:

  $foo = 3;
  @array = (
             8,
             'Ovid'
           );

Unfortunately, this can involve a lot of annoying typing.

  warn Data::Dumper->Dump(
    [$foo, \%this, \@array, \%that],
    [qw/*foo *that *array *this/]
  );

You'll also notice a typo in the second array ref which can cause great
confusion while debugging.

=head2 The Solution

With C<Data::Dumper::Simple> you can do this instead:

  use Data::Dumper::Simple.
  warn Dumper($scalar, @array, %hash);

Note that there's no need to even take a reference to the variables.  The 
output of the above resembles this (sample data, of course):

  $scalar = 'Ovid';
  @array = (
             'Data',
             'Dumper',
             'Simple',
             'Rocks!'
           );
  %hash = (
            'it' => 'does',
            'I' => 'hope',
            'at' => 'least'
          );

Taking a reference to an array or hash works as expected, but taking a
reference to a scalar is effectively a no-op (because it can turn into a
confusing reference to a reference);

 my $foo   = { hash => 'ref' };
 my @foo   = qw/foo bar baz/;
 warn Dumper ($foo, \@foo);

Produces:

 $foo = {
   'hash' => 'ref'
 };
 $foo = [
   'foo',
   'bar',
   'baz'
 ];

Note that this means similarly named variables can get quite confusing, as in
the example above.

If you already have a C<&Dumper> function, you can specify a different
function name with the C<as> key in the import list:

  use Data::Dumper::Simple as => 'display';
  warn display( $scalar, @array, %hash );

Also, if you really, really can't stand typing C<warn> or C<print>, you can
turn on C<autowarn>:

  use Data::Dumper::Simple as => 'display', autowarn => 1;
  display($scalar, @array, $some->{ data });

Or you can send the output (as a list) to a different function:

  use Data::Dumper::Simple as => 'debug', autowarn => 'to_log';

  sub to_log {
      my @data = @_;
      # some logging function
  }

  debug(
    $customer => @order_nums
  ); # yeah, we support the fat comma "=>" and newlines

=head1 EXPORT

The only thing exported is the Dumper() function.

Well, actually that's not really true.  Nothing is exported.  However, a source
filter is used to automatically rewrite any apparent calls to C<Dumper()> so
that it just Does The Right Thing.

=head1 SEE ALSO

=over 4

=item * 
Data::Dumper - Stringified perl data structures

=item *
Filter::Simple - Simplified source filtering

=back

=head1 BUGS

This module uses a source filter.  If you don't like that, don't use this.
There are no known bugs but there probably are some as this is B<Alpha Code>.

=head1 LIMITATIONS

=over 4

=item * Calling with a sub

Do not try to call C<Dumper()> with a subroutine in the argument list:

  Dumper($foo, some_sub()); # Bad!

The filter gets confused by the parentheses.  Your author was going to fix this
but it became apparent that there was no way that C<Dumper()> could figure out
how to name the return values from the subroutines, thus ensuring further
breakage.  So don't do that.

=item * Multiple enreferencing

Getting really crazy by using multiple enreferencing will confuse things (e.g.,
C<\\\\\\$foo>), don't do that, either.  I might use C<Text::Balanced> at some
point to fix this if it's an issue.

=item * Slices

List and hash slices are not supported at this time.

=item * String interpolation

C<Dumper($foo)> can potentially interpolate if it's in a string.  This is
because of a weird edge case with "FILTER_ONLY code" which caused a failure on
some items being dumped.  I've fixed that, but made the module a wee bit less
robust.  This will hopefully be fixed in the next release of Text::Balanced.

=item * Line numbers may be wrong

Because this module uses a source filter, line numbers reported from
syntax or other errors may be thrown off a little. 

This is probably a bug in the source filter implementation, which should
use C<#line> directives. As a workaround until this is fixed, put a
directive (such as C<#line 10000>) a few lines ahead of the suspected
bug. If the error is reported as happening in line 10007, you know to
look about eight lines below your directive for the bug. Be sure to
remove the bogus directive once you find the bug!

=item * The parentheses are optional, but the syntax isn't bulletproof

If you try, it's not hard to confuse the parser. Patches welcome.

=back

Note that this is not a drop-in replacement for C<Data::Dumper>.  If you
need the power of that module, use it.

=head1 AUTHOR

Curtis "Ovid" Poe, E<lt>eop_divo_sitruc@yahoo.comE<gt>

Reverse the name to email me.

=head1 COPYRIGHT AND LICENSE

Copyright 2004 by Curtis "Ovid" Poe

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself. 

=cut
