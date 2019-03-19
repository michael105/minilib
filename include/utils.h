


#define warn(...) {fprintf(stderr,__VA_ARGS__);fputc('\n',stderr);}
#define warnif(a,...) {if ( a ){fprintf(stderr,__VA_ARGS__);fputc('\n',stderr);};}
#define err(...) {warn(__VA_ARGS__);exit(1);}
#define errif(a,...) {if(a){warn(__VA_ARGS__);exit(1);};}

#ifdef DEBUG
#define dbg(...) warn(__VA_ARGS__)
#else
#define dbg(...) {} 
#endif


