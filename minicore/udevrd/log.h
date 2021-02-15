
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

// todo: put this in mlgl
char _loglevels;
int _logfd[2];
int _kernelfacility;
const char *_kernelprefix;

typedef enum _LOGTARGET { STDOUT=1, STDERR=2, KERNEL=4, LOGFILE=8 } LOGTARGET;

#define _LMASK 03
void setloglevel( LOGTARGET target, int loglevel ){

		if ( target & STDOUT )
				_loglevels = ~(_loglevels ^ ( ~loglevel ));
		if ( target & STDERR )
				_loglevels = ~(_loglevels ^ ( ~(loglevel<<2) ));
		if ( target & KERNEL )
				_loglevels = ~(_loglevels ^ ( ~(loglevel<<4) ));
		if ( target & LOGFILE )
				_loglevels = ~(_loglevels ^ ( ~(loglevel<<6) ));

		printf("set loglevels: %d %d\n", target, _loglevels );
}

void setlog_kernelprefix( const char* prefix ){
		_kernelprefix = prefix;
}
		
//+doc
// kernelprefix: pointer to a string, which is prefixed to every kernel ringbuffer log
// kernelfacility: 
// 0	kern	Kernel messages
// 1	user	User-level messages
// 2	mail	Mail system
// 3	daemon	System Daemons
// 4	auth	Security messages
// 5	syslog	Syslogd messages
// 6	lpr	Line printer subsystem
// 7	news	Network news subsystem
// 8	uucp	UUCP subsystem
// 9	cron	Clock daemon
// 10	authpriv	Security messages
// 11	ftp	FTP daemon
// 12	ntp	NTP subsystem
// 13	security	Security log audit
// 14	console	Console log alerts
// 15	solaris-cron	Scheduling logs
// 16-23	local0 to local7	Locally used facilities
//
// message level:
// 0	Emergency	emerg
// 1	Alert	alert
// 2	Critical	crit
// 3	Error	err
// 4	Warning	warning
// 5	Notice	notice
// 6	Informational	info
// 7	Debug	debug
//
// format: <(kernelfacility*8)+(message level)>prefix: message
//
void initlog( int targets, const char* kernelprefix, int kernelfacility ){
		_loglevels = 0xC; // to stderr, level 3 (all logs)
		_logfd[0]=0;
	 _logfd[1]=0;
	 _kernelprefix = kernelprefix;
	 _kernelfacility = kernelfacility*8;

	 int r;
	if ( targets & KERNEL )
				_logfd[0]=((r = open("/dev/kmsg",O_WRONLY))>0) ? r : 0;

}

#define BL 256

char* _log_kernelprefix(char *p,int level){
		*p++='<';
		int a = _kernelfacility + 5;
		if ( level > 1 )
				a++;
		if ( a>=100 ){
				*p++='1';
				a-=100;
		}
		if ( a>=10 ){
				int t = a/10;
				//int t = a/10;
				*p++=t+'0';
				a-=(t*10);
		}
		*p++=a+'0';
		*p++='>';
		p=stpcpy(p,_kernelprefix);
		*p++=':';
		*p++=' ';
		return(p);
}


void __log(int level, const char* msg, int len){
		char buf[BL];
		char *p = buf;
		//write(STDOUT_FILENO, msg, len);write(STDOUT_FILENO," xxx\n",1);
		if ( level <= ( _loglevels & _LMASK ) ){ //stdout
				if ( level<2 )
						writes(AC_GREEN);
				write(STDOUT_FILENO, msg, len);write(STDOUT_FILENO,"\n",1);
				writes(AC_NORM);
		};

		//printf("loglevels: %d\n", _loglevels );
		if ( level <= ((_loglevels >> 4 ) & _LMASK) ){ // kernel
				p=_log_kernelprefix(buf,level);
				p=stplcpy(p,msg,(buf+BL-p));
				*p++='\n';
				write(_logfd[0],buf,p-buf);
				//writes("to kernel: ");writesl(msg);
		};

}
/*
int sprints(char *buf, const char *msg,...){
		va_list args;
		va_start(args,msg);
		char *p = buf;

		do {
				do{
						*buf= *msg;
						buf++;msg++;
				} while (msg != 0 );
				msg = va_arg(args,char*);
		} while ( msg != 0 );
		va_end(args);
		return(buf-p);
}
*/

void __logs(int level, const char* msg, ...){
		char buf[BL];
		char *p = buf;
		va_list args;
		va_start(args,msg);

		do {
				do{
						*p= *msg;
						p++;msg++;
						if ( p>=(buf+BL-1) ){
							__log( level, buf, BL );
							p = buf;
						}
				} while (*msg != 0 );
				msg = va_arg(args,char*);
		} while ( msg != 0 );
		va_end(args);
		
		__log( level, buf, p-buf );
}



#define  _log( l, msg) __log(l,msg, sizeof(msg))
//#define  _log( msg) {ewritesl(msg);}
#define _logs( l, ... ) __logs(l,__VA_ARGS__,0)
#define _logf( fmt,...) eprintf(fmt,__VA_ARGS__)

#if LOGLEVEL>2
#define  log3( msg) _log(3,msg)
#define logs3( ...) _logs(3,__VA_ARGS__)
#define logf3( fmt,...) _logf(fmt,__VA_ARGS__)
#else
#define  log3( msg) {}
#define logs3( ...) {}
#define logf3( fmt,...) {}
#endif

#if LOGLEVEL>1
#define  log2( msg) _log(2,msg)
#define logs2( ...) _logs(2,__VA_ARGS__)
#define logf2( fmt,...) _logf(fmt,__VA_ARGS__)
#else
#define  log2( msg) {}
#define logs2( ...) {}
#define logf2( fmt,...) {}
#endif



#define  log1( msg) _log(1,msg)
#define logs1( ...) _logs(1,__VA_ARGS__)
#define logf1( fmt,...) _logf(fmt,__VA_ARGS__)


//+doc logging macros
// they take a first parameter, 'loglevel',
// and one or several arguments to log.
// 
// It is possible to enable or disable logging calls at compile time.
// Set LOGLEVEL to 1,2, or 3.
// 1: only log calls with a loglevel of 1 are compiled
// ..
// 3: log calls with loglevels 1,2 and 3 are compiled.
//
// log: write a fixed string. (compute len at compile time with 'sizeof(msg)'
// logs: write one or several strings of variable len.
// logf: write a formatted string. (analog to fprintf)
//+def log
#define log( loglevel, msg) log##loglevel(msg)
#define logs( loglevel, ...) logs##loglevel(__VA_ARGS__)
#define logf( loglevel, fmt,...) logf##loglevel(fmt,__VA_ARGS__)



