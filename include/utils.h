
/// Debugging macros
#ifdef DEBUG
#define mini_fputc
#define mini_fprintf
static inline int fputc(int c, int fd);


#define dbgwarnf(...) {fprintf(stderr,__VA_ARGS__);fputc('\n',stderr);}
#define dbgwarn(s) {write(stderr,s,sizeof(s));fputc('\n',stderr);}
#define dbgwarnfif(a,...) {if ( a ){dbgwarnf(__VA_ARGS__)};}
#define dbgwarnif(a,s) {if ( a ){dbgwarn(s)};}
#define dbgerr(s) {dbgwarn(s);exit(1);}
#define dbgerrf(...) {dbgwarnf(__VA_ARGS__);exit(1);}
#define dbgerrif(a,s) {if(a){dbgwarn(s);exit(1);};}
#define dbgerrfif(a,...) {if(a){dbgwarnf(__VA_ARGS__);exit(1);};}

#define dbg(s) dbgwarn(s)
#define dbgf(...) dbgwarnf(__VA_ARGS__)

#else

#define dbg(s) {}
#define dbgf(...) {}


#define dbgwarnf(...) {}
#define dbgwarn(s) {} 
#define dbgwarnfif(a,...) {} 
#define dbgwarnif(a,s) {} 
#define dbgerr(s) {}
#define dbgerrf(...) {}
#define dbgerrif(a,s) {}
#define dbgerrfif(a,...) {}

#endif


// ansicolors
#define AC_BLACK "\033[0;30m"
#define AC_RED "\033[0;31m"
#define AC_GREEN "\033[32;0m"
#define AC_BROWN "\033[0;33m"
#define AC_BLUE "\033[0;34m"
#define AC_MAGENTA "\033[0;35m"
#define AC_MARINE "\033[0;36m"
#define AC_LGREY "\033[0;37m"
#define AC_WHITE "\033[0;38m"

#define AC_GREY "\033[1;30m" 
#define AC_LRED "\033[1;31m" 
#define AC_LGREEN "\033[1;32m" 
#define AC_YELLOW "\033[1;33m"
#define AC_LBLUE "\033[1;34m"
#define AC_LMAGENTA "\033[1;35m"
#define AC_LMARINE "\033[1;36m"
#define AC_LWHITE "\033[1;37m"



#ifdef SHORTCOLORNAMES

#define NORM     AC_NORM
#define INVERSE  AC_INVERSE
#define BLINK    AC_BLINK
#define BLACK    AC_BLACK
#define RED      AC_RED
#define GREEN    AC_GREEN
#define BROWN    AC_BROWN
#define BLUE     AC_BLUE
#define MAGENTA  AC_MAGENTA
#define MARINE   AC_MARINE
#define LGREY    AC_LGREY
#define WHITE    AC_WHITE
#define GREY     AC_GREY
#define LRED     AC_LRED
#define LGREEN   AC_LGREEN
#define YELLOW   AC_YELLOW
#define LBLUE    AC_LBLUE
#define LMAGENTA AC_LMAGENTA
#define LMARINE  AC_LMARINE
#define LWHITE   AC_LWHITE

#endif

#ifdef SHRTSHORTCOLORNAMES

#define cN   AC_NORM
#define cBL  AC_BLACK
#define cR   AC_RED
#define cG   AC_GREEN
#define cBR  AC_BROWN
#define cB   AC_BLUE
#define cMG  AC_MAGENTA
#define cM   AC_MARINE
#define cLG  AC_LGREY
#define cW   AC_WHITE
#define cG   AC_GREY
#define cLR  AC_LRED
#define cLGN AC_LGREEN
#define cY   AC_YELLOW
#define cLB  AC_LBLUE
#define cLMG AC_LMAGENTA
#define cLM  AC_LMARINE
#define cLW  AC_LWHITE

#endif





