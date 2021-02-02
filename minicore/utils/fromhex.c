#if 0
mini_start
mini_write 
mini_writes
mini_read

INCLUDESRC

return
#endif

// misc 2020

#define BUF 4096


void usage(){
	writes("fromhex. convert hexadecimal input to ascii.\n\
Doesn't check for errors.(0x, linebreaks,..)\n");
	exit(0);
}


int main(int argc, char **argv){

		if ( argc>1 )
				usage();

		char c[BUF];
		char o[BUF/2];
		int r = 0;
		while ( (r=read(0,&c,BUF) ) > 0 ){
				for (int a=0; a<r; a+=2 ){
						char t=c[a];
						char t2=c[a+1];
						o[a>>1]= ((47 < t && t < 58 ?(t-48) : (t-87) )<<4) | 
						(47<t2 && t2<58 ? (t2-48) : (t2-87));
				}
				write(1,o,r>>1);
		}

		return(0);
}
