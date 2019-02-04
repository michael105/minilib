
int itohex(int i,char* buf,int padding){

		padding = padding - 8;
		if ( padding < -7 )
				padding = -7;

		union { int n; char c[4]; } conv[2];
		conv[0].n = (( i & 0xf0f0f0f0 ) >> 4);
		conv[1].n = ( i & 0x0f0f0f0f );
		int p = 0;
		int a,b;

		for ( a=3; a>=0; a-- ){
				for ( b=0; b <=1; b++ ){
						if ( padding != 0 ){
								if ( conv[b].c[a] != 0 ){
										padding = 0;
								}
						}
						if ( padding == 0 ){
								char c = conv[b].c[a];
								if ( c < 0xa )
										c = c + 48;
								else
										c = c + 87; // 55 for big abc ..
								buf[p] = c;
								p++;
						} else
								padding++;
				}
		}
		buf[p] = 0 ;
		return(p);
}



