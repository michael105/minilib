//+depends network
//+def 
static uint16_t htons(uint16_t i){
		union { uint16_t i; char c[2]; } u = { .i=i };
		u.c[0] ^= u.c[1];
		u.c[1] ^= u.c[0];
		u.c[0] ^= u.c[1];
		return( u.i );
}


//+macro ntohs(i) htons(i)

