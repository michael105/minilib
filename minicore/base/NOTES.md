notes.



mkdir - bloating. nearly 4kb.
 to strip - printf.

 possibly remove option -p ? 



rm : mini_errno is 50 Bytes (!)



kill: quite bloated. 3kB.
better strip the signal names.
rewrite.?
Could also save some bytes, 
converting the signal struct array to a array.
3k for a syscall wrapper is . much.


error.c -> just translate error codes.
 (return errno on error from tools?




in general: printf bloats. itodec even more.

either use writes or fputs/fprintfs, when possible

comparing, what I've written from scratch to the other tools,
or to other collections, wouldn't be fair.
I wrote the tools with size in mind, before I started.

Under normal circumstances, I wouldn't mind to use, e.g., fprintf.

with option parsing, and so on, the same.

I have fun, anyways.. <)



memo: seems to me, most bloat is given by the fprint family.
      some tools I put in here, just to test the compilation.
			Should change them to avoid the unnecessary bloat.
			in most cases, only the printf calls have to be changed to
			writes / prints.
			Just now I realize, cpp has it's advantages. If used right,
			even at system level programming.
			The problem comes with "if used right".
