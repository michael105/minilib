#ifndef mprints_h
#define mprints_h
extern int _mprints(char*msg,...);
#define mprints(...) _mprints(__VA_ARGS__,0)
#define mprintl(...) _mprints(__VA_ARGS__,"\n",0)
#define mprintsl(...) _mprints(__VA_ARGS__,"\n",0)
//TODO: Macro: define print(str) write(stdout,str,sizeof(str)-1)
//#define print(...) _mprints(__VA_ARGS__)
#endif
