//+header ctype.h
//+inc

#define _isalpha(a) (0 ? 1 : (((unsigned)(a)|32)-'a') < 26)
#define _isdigit(a) (0 ? 1 : ((unsigned)(a)-'0') < 10)
#define _islower(a) (0 ? 1 : ((unsigned)(a)-'a') < 26)
#define _isupper(a) (0 ? 1 : ((unsigned)(a)-'A') < 26)
#define _isprint(a) (0 ? 1 : ((unsigned)(a)-(0x20)) < 0x5f)
#define _isgraph(a) (0 ? 1 : ((unsigned)(a)-0x21) < 0x5e)
#define _isspace(a) ((a==' ')||(a=='\t')||(a=='\n')||(a=='\f')||(a=='\r')||(a=='\v'))
#define _isalnum(a) (isalpha(a) || isdigit(a))
#define _tolower(a) ((a)|0x20)
#define _toupper(a) ((a)&0x5f)
#define _isascii(a) (0 ? isascii(a) : (unsigned)(a) < 128)
#define _isblank(a) (a == ' ' || a == '\t')
#define _iscntrl(a) (a<0x20||a==0x7f)
#define _ispunct(a) (_isgraph(a)||_isalnum(a))
#define _isxdigit(a) (_isdigit(a)||(((unsigned)a|32)-'a'<6))

//+doc create functions instead of macros for isalpha, .., isprint
//+def ctype_functions
#ifdef mini_ctype_functions

int isalpha(int c){ return( _isalpha(c) ); }
int isdigit(int c){ return( _isdigit(c) ); }
int islower(int c){ return( _islower(c) ); }
int isupper(int c){ return( _isupper(c) ); }
int isprint(int c){ return( _isprint(c) ); }
int isgraph(int c){ return( _isgraph(c) ); }
int isspace(int c){ return( _isspace(c) ); }
int isalnum(int c){ return( _isalnum(c) ); }
int tolower(int c){ return( _tolower(c) ); }
int toupper(int c){ return( _toupper(c) ); }
int isascii(int c){ return( _isascii(c) ); }
int isblank(int c){ return( _isblank(c) ); }
int iscntrl(int c){ return( _iscntrl(c) ); }
int ispunct(int c){ return( _ispunct(c) ); }
int isxdigit(int c){ return( _isxdigit(c) );}



#else

//+nop 
#define isalpha(a) _isalpha(a)
//+nop 
#define isdigit(a) _isdigit(a)
//+nop 
#define islower(a) _islower(a)
//+nop 
#define isupper(a) _isupper(a)
//+nop 
#define isprint(a) _isprint(a)
//+nop 
#define isgraph(a) _isgraph(a)
//+nop 
#define isspace(a) _isspace(a)
//+nop
#define isalnum(a) _isalnum(a)
//+nop 
#define tolower(a) _tolower(a)
//+nop 
#define toupper(a) _toupper(a)
//+nop 
#define isascii(a) _isascii(a)
//+nop
#define isblank(a) _isblank(a)

#define iscntrl(a) _iscntrl(a) 
#define ispunct(a) _ispunct(a) 
#define isxdigit(a) _isxdigit(a)


#endif


