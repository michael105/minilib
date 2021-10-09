//+include
//+depends abort ewrites
//+def assert

#define __QUOTE(s) #s
#define _QUOTE(s) __QUOTE(s)
#define assert(exp) {if ( !(exp) ){ \
	ewrites( __FILE__ ": " _QUOTE(__LINE__) " " _QUOTE(__func__) "\n" );\
	abort(); };}


