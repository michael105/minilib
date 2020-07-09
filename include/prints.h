#ifndef prints_h
#define prints_h
//extern int _mprints(char*msg,...); // strange errors caused by that
extern int dprints(int fd, const char *msg,...);
//+header mini_addons.h


//+doc print the string(s) supplied as arg(s) to stdout
//+depends _mprints 
//+macro
#define prints(...) _mprints(__VA_ARGS__,0)


//+doc print the string(s) supplied as arg(s) to stream
//+depends fileno write strlen
//+macro
#define fprints(F,str) write(fileno(F),str,strlen(str))




//+doc print the string(s) supplied as arg(s) and newline to stdout
//+depends _mprints 
//+macro
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

//+depends write strlen
//+doc write str to stdout. Needs strlen
//+macro print(str) write(STDOUT_FILENO,str,strlen(str))

//+depends write strlen
//+doc write str to stderr. Needs strlen
//+macro eprint(str) write(STDERR_FILENO,str,strlen(str))



//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro writes(str) write(STDOUT_FILENO,str,sizeof(str))

//+depends write 
//+doc write the constant str to stderr. Computes length with sizeof(str) at compile time.
//+macro ewrites(str) write(STDERR_FILENO,str,sizeof(str))



//+depends write 
//+doc write the constant str to fd. Computes length with sizeof(str) at compile time.
//+macro fwrites(fd,str) write(fd,str,sizeof(str))


//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)

//+depends write
//+doc write a newline to stderr
//+macro eprintl() write(STDERR_FILENO,"\n",1)



//+depends printl print strlen
//+doc write msg to stdout, append a newline. Needs strlen.
//+macro puts(msg) ( print(msg) + printl() )

//+depends eprintl eprint strlen
//+doc write msg to stderr, append a newline. Needs strlen.
//+macro eputs(msg) ( eprint(msg) + eprintl() )



//+depends fprintfs fputs
//+doc write str to stdout. 
// only format %s is recognized
//+macro printfs(fmt,...) fprintfs(stdout, fmt, __VA_ARGS__)


//+depends fprintfs fputs
//+doc write str to stderr. 
// only format %s is recognized
//+macro eprintfs(fmt,...) fprintfs(stderr, fmt, __VA_ARGS__)





#endif
