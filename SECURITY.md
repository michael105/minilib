## Security Policy

Quite obviously, there are (also in the standards)
inherent security problems. 

Minilib is a system library. 
So it cannot be the target to e.g.check 
format strings for printf.
(There are checks done for buffer overflows)

If there should be security flaws within minilib itself,
I'd prefer private mail for noting me.

I'm currently checking with codeQL,
and there has been one (!) flaw in 30.000 loc's.
Which would most probably have resulted in a segfault,
and could have been exploited only when further programming mistakes
would have been done.
(Fixed since v.202106xx)

However, albite I'm working throughly,
I cannot give any guarantees for any functionality
for a open source library.


