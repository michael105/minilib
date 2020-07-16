//+doc exit, and execute /bin/errno
// this is intended to give a error message for the 
// given errno num.
// Instead of having the error messages compiled 
// into each binary, they can stay within one executable, "errno"
// This spares about 4kB, but needs errno installed to /bin/errno
// It's the drawback of not having a hared library,
// where all executables would share the same errno messages
// in memory.
// On the other hand, a shared library would need to be installed
// as well.
// The supplied errno can be negative,
// the absolute value is supplied to errno.
//+depends execve errno_str exit ewrites
//+def
void exit_errno( int errnum ){
		errnum &= 0xFF;
		char *args[3]; 
		args[0] = "errno";
		args[1] = (char*)errno_str( errnum );
		args[2] = 0;
		execve("/bin/errno",args,0);
		// /bin/errno couldn't be executed.
		// print the error number,
		// and exit
		ewrites("Error: ");
		write(STDERR_FILENO, args[1], 3 );
		ewrites("\n");
		exit(errnum);
}


