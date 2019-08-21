#ifndef prints_h
#define prints_h
//extern int _mprints(char*msg,...);
extern int dprints(int fd, char *msg,...);
//+header mini_addons.h

//+doc print the string(s) supplied as arg(s) to stdout
//+depends _mprints 
//+macro
#define prints(...) _mprints(__VA_ARGS__,0)

//+doc print the string(s) supplied as arg(s) and newline to stdout
//+depends _mprints 
//+macro
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

//+depends write strlen
//+doc write str to stdout. Needs strlen
//+macro print(str) write(STDOUT_FILENO,str,strlen(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro writes(str) write(STDOUT_FILENO,str,sizeof(str))


//+depends write 
//+doc write the constant str to stdout. Computes length with sizeof(str) at compile time.
//+macro fwrites(fd,str) write(fd,str,sizeof(str))


//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)


//+depends printl print strlen
//+doc write msg to stdout, append a newline. Needs strlen.
//+macro puts(msg) ( print(msg) + printl() )

#endif
