//+include


//+doc defines for ansicolors at the console, 16 color mode
//the names are:
// AC_NORM ( white text on black background)
// AC_BLACK 
// AC_RED 
// AC_GREEN 
// AC_BROWN 
// AC_BLUE 
// AC_MAGENTA 
// AC_MARINE (= AC_CYAN)
// AC_LGREY 
// AC_WHITE 
// AC_GREY 
// AC_LRED 
// AC_LGREEN 
// AC_YELLOW 
// AC_LBLUE 
// AC_LMAGENTA 
// AC_LMARINE (= AC_LCYAN)
// AC_LWHITE 
// AC_BGBLACK 
// AC_BGRED 
// AC_BGGREEN 
// AC_BGBROWN 
// AC_BGBLUE 
// AC_BGMAGENTA 
// AC_BGMARINE 
// AC_BGLGREY 
// AC_BGWHITE 
//
// AC_BOLD
// AC_FAINT
// AC_CURSIVE
// AC_UNDERLINE
// AC_LIGHTBG
// AC_BLINK
// AC_INVERTED
// AC_INVERSE
//
// ( Faint to inverse are not available at every terminal )
//+def ansicolors


#ifdef mini_shortcolornames
#ifndef mini_ansicolors
#define mini_ansicolors
#endif
#endif


#ifdef mini_ansicolors
#define AC_NORM "\033[0;38;40m"
#define AC_BLACK "\033[0;30m"
#define AC_RED "\033[0;31m"
#define AC_GREEN "\033[32;0m"
#define AC_BROWN "\033[0;33m"
#define AC_BLUE "\033[0;34m"
#define AC_MAGENTA "\033[0;35m"
#define AC_MARINE "\033[0;36m"
#define AC_CYAN "\033[0;36m"
#define AC_LGREY "\033[0;37m"
#define AC_WHITE "\033[0;38m"

#define AC_GREY "\033[1;30m" 
#define AC_LRED "\033[1;31m" 
#define AC_LGREEN "\033[1;32m" 
#define AC_YELLOW "\033[1;33m"
#define AC_LBLUE "\033[1;34m"
#define AC_LMAGENTA "\033[1;35m"
#define AC_LMARINE "\033[1;36m"
#define AC_LCYAN "\033[1;36m"
#define AC_LWHITE "\033[1;37m"

#define AC_BGBLACK "\033[40m"
#define AC_BGRED "\033[41m"
#define AC_BGGREEN "\033[32;0m"
#define AC_BGBROWN "\033[43m"
#define AC_BGBLUE "\033[44m"
#define AC_BGMAGENTA "\033[45m"
#define AC_BGMARINE "\033[46m"
#define AC_BGLGREY "\033[47m"
#define AC_BGWHITE "\033[48m"


#define AC_BOLD "\033[1m"
#define AC_FAINT "\033[2m"
#define AC_CURSIVE "\033[3m"
#define AC_UNDERLINE "\033[4m"
#define AC_LIGHTBG "\033[5m"
#define AC_BLINK "\033[6m"
#define AC_INVERTED "\033[7m"
#define AC_INVERSE "\033[8m"




//+doc short ansi color names
// all colornames, without the praefix "AC_"
//+def shortcolornames

#ifdef mini_shortcolornames

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
#define CYAN     AC_MARINE
#define LGREY    AC_LGREY
#define WHITE    AC_WHITE
#define GREY     AC_GREY
#define LRED     AC_LRED
#define LGREEN   AC_LGREEN
#define YELLOW   AC_YELLOW
#define LBLUE    AC_LBLUE
#define LMAGENTA AC_LMAGENTA
#define LMARINE  AC_LMARINE
#define LCYAN    AC_LMARINE
#define LWHITE   AC_LWHITE

#define BGBLACK    AC_BGBLACK
#define BGRED      AC_BGRED
#define BGGREEN    AC_BGGREEN
#define BGBROWN    AC_BGBROWN
#define BGBLUE     AC_BGBLUE
#define BGMAGENTA  AC_BGMAGENTA
#define BGMARINE   AC_BGMARINE
#define BGLGREY    AC_BGLGREY
#define BGWHITE    AC_BGWHITE


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

#endif
