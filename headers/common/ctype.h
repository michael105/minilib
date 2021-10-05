//#ifndef	_CTYPE_H
//#define	_CTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

//#include <features.h>


#include "bits/alltypes.h"

int   isalnum_l(int, locale_t);
int   isalpha_l(int, locale_t);
int   isblank_l(int, locale_t);
int   iscntrl_l(int, locale_t);
int   isdigit_l(int, locale_t);
int   isgraph_l(int, locale_t);
int   islower_l(int, locale_t);
int   isprint_l(int, locale_t);
int   ispunct_l(int, locale_t);
int   isspace_l(int, locale_t);
int   isupper_l(int, locale_t);
int   isxdigit_l(int, locale_t);
int   tolower_l(int, locale_t);
int   toupper_l(int, locale_t);

#ifdef __cplusplus
}
#endif

//#endif
