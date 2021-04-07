#ifndef mini_byteorder_h
#define mini_byteorder_h


//+def 
static uint16_t htons(uint16_t i){
		union { uint16_t i; char c[2]; } u = { .i=i };
		u.c[0] ^= u.c[1];
		u.c[1] ^= u.c[0];
		u.c[0] ^= u.c[1];
		return( u.i );
}

//+macro ntohs(i) htons(i)

//+def 
static uint32_t htonl(uint32_t i){
		union { uint32_t i; char c[4]; } u = { .i=i };
		u.c[0] ^= u.c[3];
		u.c[1] ^= u.c[2];
		u.c[3] ^= u.c[0];
		u.c[2] ^= u.c[1];
		u.c[0] ^= u.c[3];
		u.c[1] ^= u.c[2];
		return( u.i );
}


//+macro ntohl(i) htonl(i)


#endif
