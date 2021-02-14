
//#define DEBUG

#ifdef dbg
#undef dbg
#endif

#ifdef dbgs
#undef dbgs
#endif

#ifdef dbgf
#undef dbgf
#endif


#ifdef DEBUG
#define dbg(msg) {ewritesl(msg);}
#define dbgs(...) eprintsl(__VA_ARGS__)
#define dbgf(fmt,...) eprintf(fmt,__VA_ARGS__)
#else
#define dbg(msg) {}
#define dbgs(...) {}
#define dbgf(fmt,...) {}
#endif

#define warning( msg ) {ewritesl(RED msg NORM);}
#define warnings( ...) eprintsl(RED,__VA_ARGS__,NORM)

#define warnif( when, msg ) if(when) warning(msg)


#define errors( ...) eprintsl(RED,__VA_ARGS__,NORM)

// omit logging calls ( LOGLEVEL < loglevel )
#define LOGLEVEL 3

#define  _log( msg) {ewritesl(msg);}
#define _logs( ...) eprintsl(__VA_ARGS__)
#define _logf( fmt,...) eprintf(fmt,__VA_ARGS__)

#if LOGLEVEL>2
#define  log3( msg) _log(msg)
#define logs3( ...) _logs(__VA_ARGS__)
#define logf3( fmt,...) _logf(fmt,__VA_ARGS__)
#else
#define  log3( msg) {}
#define logs3( ...) {}
#define logf3( fmt,...) {}
#endif

#if LOGLEVEL>1
#define  log2( msg) _log(msg)
#define logs2( ...) _logs(__VA_ARGS__)
#define logf2( fmt,...) _logf(fmt,__VA_ARGS__)
#else
#define  log2( msg) {}
#define logs2( ...) {}
#define logf2( fmt,...) {}
#endif



#define  log1( msg) _log(msg)
#define logs1( ...) _logs(__VA_ARGS__)
#define logf1( fmt,...) _logf(fmt,__VA_ARGS__)



#define log( loglevel, msg) log##loglevel(msg)
#define logs( loglevel, ...) logs##loglevel(__VA_ARGS__)
#define logf( loglevel, fmt,...) logf##loglevel(fmt,__VA_ARGS__)



