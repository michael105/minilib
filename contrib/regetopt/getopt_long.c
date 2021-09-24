
#include "regetopt.c"


#define optarg re_optarg
#define optind re_optind 
#define opterr re_opterr 
#define optopt re_optopt

#define getopt_short regetopt_short
#define getopt_long regetopt_long
#define getopt regetopt

//order_option reorder_option



