#ifndef ctype_h
#define ctype_h

//+header ctype.h
//+inc


//+nop 
#define isalpha(a) (0 ? 1 : (((unsigned)(a)|32)-'a') < 26)
//+nop 
#define isdigit(a) (0 ? 1 : ((unsigned)(a)-'0') < 10)
//+nop 
#define islower(a) (0 ? 1 : ((unsigned)(a)-'a') < 26)
//+nop 
#define isupper(a) (0 ? 1 : ((unsigned)(a)-'A') < 26)
//+nop 
#define isprint(a) (0 ? 1 : ((unsigned)(a)-(0x20)) < 0x5f)
//+nop 
#define isgraph(a) (0 ? 1 : ((unsigned)(a)-0x21) < 0x5e)
//+nop 
#define isspace(a) ((a==' ')||(a=='\t')||(a=='\n')||(a=='\f')||(a=='\r')||(a=='\v'))
//+nop
#define isalnum(a) (isalpha(a) || isdigit(a))


//+nop 
#define _tolower(a) ((a)|0x20)
//+nop 
#define tolower(a) ((a)|0x20)
//+nop 
#define _toupper(a) ((a)&0x5f)
//+nop 
#define toupper(a) ((a)&0x5f)
//+nop 
#define isascii(a) (0 ? isascii(a) : (unsigned)(a) < 128)




#endif
