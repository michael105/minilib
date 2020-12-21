#if 0
mini_start
mini_write 
mini_read

INCLUDESRC

return
#endif

#define BUF 4096


int main(){
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
