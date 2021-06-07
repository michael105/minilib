#if 0
compile start fopen fprintf printf 
#mini_start
#mini_fopen
#mini_fclose
#mini_fprintf
#mini_printf
mini_print
mini_itodec
mini_itohex
mini_fileno
mini_puts
mini_read
mini_strlen
mini_strtol
mini_inet_aton
mini_inet_ntoa
mini_buf 1024
mini_gethostname

OPTFLAG -O0
INCLUDESRC

return
#endif


#include "minilib/minilib.h"


uint32_t htonl(uint32_t hostlong) {
#if 1
//#if __BYTE_ORDER==__LITTLE_ENDIAN
		  return (hostlong>>24) | ((hostlong&0xff0000)>>8) |
					    ((hostlong&0xff00)<<8) | (hostlong<<24);
#else
			  return hostlong;
#endif
}



// (from dietlibc)
/* inet_aton() converts the Internet host address cp from the standard
 *  * numbers-and-dots  notation  into  binary data  and  stores it in the
 *   * structure that inp points to. inet_aton returns nonzero if the
 *    * address is valid, zero if not. */

/* problem is, inet_aton is historically quite, uh, lenient.
 *  * the following are all acceptable:
 *   *   0x7f000001 == 127.1 == 127.0.0.1.0 == 127.0.0.1
 *    * btw: 127.0.0.x.y == 127.0.0.(x|y)
 *     * and: 10.1.1 == 10.1.0.1 (huh?!)
 *      * and: 10 == 0.0.0.10 (?!?!?)
 *       * The Berkeley people must have been so stoned that they are still high.
 *        */

/* I hereby disclaim that I wrote this code. */
int d_inet_aton(const char *cp, struct in_addr *inp) {
		int i;
		unsigned int ip=0;
		char *tmp=(char*)cp;
		for (i=24; ;) {
				long j;
				j=strtol(tmp,(const char**)&tmp,0);
				if (*tmp==0) {
						ip|=j;
						break;
				}
				if (*tmp=='.') {
						if (j>255) return 0;
						ip|=(j<<i);
						if (i>0) i-=8;
						++tmp;
						continue;
				}
				return 0;
		}
		inp->s_addr=htonl(ip);
		return 1;
}


static unsigned int i2a(char* dest,unsigned int x) {
	register unsigned int tmp=x;
	register unsigned int len=0;
	if (x>=100) { *dest++=tmp/100+'0'; tmp=tmp%100; ++len; }
	if (x>=10) { *dest++=tmp/10+'0'; tmp=tmp%10; ++len; }
	*dest++=tmp+'0';
	return len+1;
}

char *dinet_ntoa_r(struct in_addr in,char* buf) {
	unsigned int len;
	unsigned char *ip=(unsigned char*)&in;
	len=i2a(buf,ip[0]); buf[len]='.'; ++len;
	len+=i2a(buf+ len,ip[1]); buf[len]='.'; ++len;
	len+=i2a(buf+ len,ip[2]); buf[len]='.'; ++len;
	len+=i2a(buf+ len,ip[3]); buf[len]=0;
	return buf;
}



void conv(char *s){
		struct in_addr ad;
		inet_aton(s,&ad);
		int i = ad.s_addr;
		char buf[32];
		printf("Ok\n");
		printf( "conv: %s   %x - %d - %s\n",s,i,i,inet_ntoa(ad));
		d_inet_aton(s,&ad);
		i = ad.s_addr;
		printf("Ok - diet\n");
		dinet_ntoa_r(ad,buf);
		printf( "conv: %s   %x - %d - %s\n\n\n",s,i,i,buf);

}

int main( int argc, char *argv[] ){

	fprintf( stdout, "stdio.\n" );
	char buf[32];
	gethostname(buf,32);
	fprintf( stdout, "hostname: %s\n",buf );

	conv("127.0.0.1");
	conv("127.0.0.2");
	conv("127.0.1");
	conv("127.2");
	conv("127");
	

	return(0);
}
