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
//+macro print(str) write(stdout,str,sizeof(str)-1)

//+depends write
//+doc write a newline to stdout
//+macro printl() write(stdout,"\n",1)



#endif
