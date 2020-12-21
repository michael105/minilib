#if 0
mini_start
mini_write 
mini_read

INCLUDESRC

return
#endif

#define BUF 4096



char *table = "0123456789abcdef";
int main(){
		char c[BUF/2];
		char o[BUF];
		int r = 0;
		while ( (r=read(0,&c,BUF/2) ) > 0 ){
				for (int a=0; a<r; a++ ){
						o[a<<1]= table[ c[a]>>4 ];
						o[(a<<1)+1]= table[ c[a] & 0xf ];
				}
				write(1, o, r<<1 );
		}

		return(0);
}
