


#define re_option option
#define re_optarg optarg
#define re_optind optind 
#define re_opterr opterr 
#define re_optopt optopt
#define regetopt_short getopt_short
#define regetopt_long getopt_long
#define regetopt getopt

//order_option reorder_option

#define no_argument 0
#define required_argument 1
#define optional_argument 2



#define REGETOPT_INTERNAL 1
#include "contrib/regetopt/include/regetopt.h"
#include "contrib/regetopt/regetopt.c"

