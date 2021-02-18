//+depends raise signal
//+def
void abort(){
		// TODO: close open streams
		raise(SIGABRT);
		// the abrt handler failed. Restore old disposition
		signal(SIGABRT,SIG_DFL);
		raise(SIGABRT);
		// Shouldn't get here, something went wrong. exit, with error.
		exit(125);
}
