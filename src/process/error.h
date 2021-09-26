#ifndef mini_error_c
#define mini_error_c

//+doc print an error message to stderr
// when errnum is not 0, print either the number,
//  or a verbose error message (with strerror), 
//  when mini_verbose_errstr is defined.
//  (verbose error messages add aboyut 4kB)
//
// when status is non null, terminate with status
//+depends strerror exit fprintf fprints
//+macro
#define error( status, errnum, fmt ... ) { fprintf(stderr,fmt ); if (errnum) fprints(stderr,":",strerror(errnum)); if ( status ) exit(status); }

//+doc print an error message to stderr,
// print an error message dependend on errno ( strerror(errno) ),
// exit with status
//+depends strerror exit fprintf errno fprints
//+macro
#define err( status, fmt ... ) { fprintf(stderr,fmt ); fprints(stderr,":",strerror(errno)); exit(status); }


//+doc print an error message to stderr,
// exit with status
//+depends exit fprintf
//+macro
#define errx( status, fmt ... ) { fprintf(stderr,fmt); exit(status); }


//+doc print an error message to stderr
//+depends fprintf 
//+macro
#define warn( fmt ... ) { fprintf(stderr,fmt ); }





#endif

