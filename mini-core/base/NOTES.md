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





