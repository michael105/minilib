#ifndef prints_h
#define prints_h
extern int _mprints(char*msg,...);
//+header mini_addons.h

//+doc print the string(s) supplied as arg(s) to stdout
#define prints(...) _mprints(__VA_ARGS__,0)
//#define printl(...) _mprints(__VA_ARGS__,"\n",0)

//+doc print the string(s) supplied as arg(s) and newline to stdout
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

//+depends write
//+doc write str to stdout
//+macro print(str) write(STDOUT_FILENO,str,sizeof(str)-1)

//+depends write
//+doc write a newline to stdout
//+macro printl() write(STDOUT_FILENO,"\n",1)

//+depends printl print
//+doc write msg to stdout, append a newline
//+macro puts(msg) ( print(msg) + printl() )

#endif
