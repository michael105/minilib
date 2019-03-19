
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
