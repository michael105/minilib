// different checksums
//+cat hashes
//+doc checksum algorithm by d.j.bernstein.
// Didn't do any benchmarks, but the computation 
// might be quite performant. 
// It is a bitshift and two additions per byte.
//+def
unsigned int djb_cksum( const char* p, unsigned int len ){
	unsigned int hash = 5381;
	while ( len-->0 ){
		hash = ((hash<<5)+hash) + *p;
		p++;
	}
	return( hash );
}

//+doc bsd checksum, called by bsd_cksum,
// with initial hash value
//+def
unsigned int bsd_cksumblock( unsigned int hash, const char* p, unsigned int len ){
	while (len-->0 ){
		hash = (hash>>1) + ((hash & 1)<<15);
		hash+= *p;
		hash &= 0xffff;
		p++;
	}
	return( hash );
}
//+doc bsd checksum
//+def
unsigned int bsd_cksum( const char* p, unsigned int len ){
	return( bsd_cksumblock(0,p,len) );
}
