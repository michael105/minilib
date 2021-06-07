#ifndef prints_h
#define prints_h
//extern int _mprints(char*msg,...); // strange errors caused by that
extern int dprints(int fd, const char *msg,...);
//+header mini_addons.h

//+needs prints.h stdarg.h
//+depends dprints write
//+macro
#define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)



//+doc print the string(s) supplied as arg(s) to stdout,
// this macro has an variable argument count.
//+depends _mprints dprints
//+macro
#define prints(...) _mprints(__VA_ARGS__,0)



//+doc print the string(s) supplied as arg(s) to stdout
// this macro has an variable argument count.
//+depends dprints 
//+macro
#define eprints(...) dprints(STDERR_FILENO,__VA_ARGS__,0)



//+doc print the string(s) supplied as arg(s) to stream
// this macro has an variable argument count.
//+depends fileno write strlen
//+macro
#define fprints(F,...) dprints(fileno(F),__VA_ARGS__,0)




//+doc print the string(s) supplied as arg(s) and newline to stdout
//+depends _mprints dprints
//+macro
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)


//+doc print the string(s) supplied as arg(s) and newline to stderr
//+depends dprints
//+macro
#define eprintsl(...) dprints(STDERR_FILENO,__VA_ARGS__,"\n",0)




//+depends write strlen
//+doc write str to stdout. Needs strlen
//+macro print(str) write(STDOUT_FILENO,str,strlen(str))

//+depends write strlen
//+doc write str to stderr. Needs strlen
//+macro eprint(str) write(STDERR_FILENO,str,strlen(str))


//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)

//+depends write
//+doc write a newline to stderr
//+macro eprintl() write(STDERR_FILENO,"\n",1)



//+depends printl print strlen write printf
//+doc write msg to stdout, append a newline. Needs strlen.
//+macro puts(msg) ( print(msg) + printl() )

//+depends eprintl eprint strlen write
//+doc write msg to stderr, append a newline. Needs strlen.
//+macro eputs(msg) ( eprint(msg) + eprintl() )




//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro writes(str) write(STDOUT_FILENO,str,sizeof(str))

//+depends write 
//+doc write the constant str to stderr. Computes length with sizeof(str) at compile time.
//+macro ewrites(str) write(STDERR_FILENO,str,sizeof(str))


//+depends write 
//+doc write the constant str to stdout, followed by a newline. 
// Computes length with sizeof(str) at compile time.
//+macro writesl(str) {write(STDOUT_FILENO,str,sizeof(str));write(STDOUT_FILENO,"\n",1);}


//+depends write 
//+doc write the constant str to stderr, followed by a newline. 
// Computes length with sizeof(str) at compile time.
//+macro ewritesl(str) write(STDERR_FILENO,str,sizeof(str));write(STDERR_FILENO,"\n",1)



//+depends write 
//+doc write the constant str to fd. Computes length with sizeof(str) at compile time.
//+macro fwrites(fd,str) write(fd,str,sizeof(str))



//+depends write 
//+doc write the constant str to fd,followed by a newline. 
// Computes length with sizeof(str) at compile time.
//+macro fwritesl(fd,str) write(fd,str,sizeof(str));write(fd,"\n",1)



//+depends fprintfs fputs strlen
//+doc write fmt and arguments to stdout. 
// only format %s and %c are recognized
//+macro printfs(fmt,...) fprintfs(stdout, fmt, __VA_ARGS__)


//+depends fprintfs fputs strlen
//+doc write fmt and arguments to stderr. 
// only format %s and %c are recognized
//+macro eprintfs(fmt,...) fprintfs(stderr, fmt, __VA_ARGS__)


//+depends fprintfs fputs strlen
//+doc write fmt and arguments to stderr. 
//+macro eprintf(fmt,...) fprintf(stderr, fmt, __VA_ARGS__)






#endif
