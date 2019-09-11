#if 0
mini_read
mini_write
mini_start
INCLUDESRC
OPTFLAG -Os
shrinkelf
LDSCRIPT text_and_bss

return
#endif

// This is a showcase of minilib / the z2 compression algorithm.
// compile with "mini-gcc --config z2cat.c -o z2cat z2cat.c"
//
//   (I'm pretty sure, I didn't "invent" this compression algorithm)
//		So possibly better call it the "z2 implementation".
//		I just don't know the algorithm,
//		and did experience some interesting outcomes while implementing.
//		e.g., changing the length of the dictionary table to more than 2 didn't have
//		the expected effect of a better compression, 
//		only higher complexity of the implementation.
//
//
//
// z2cat decompresses from stdin to stdout
// unbuffered, which is not very effective.
// The decompression speed is limited by the overhead of the syscalls
// for reading/writing stdout.
//
// It's the tradein for having a tiny executable
// ( 289 Bytes, compiled and statically "linked" with gcc )
//
// The compression rate is quite stable around 50% for most text files.
// Memory used when decompressing is 256 Bytes + 
// the stack needed for the recursive function call to decomp(),
// which rarely exceeds 6 recursive calls.
// 
// (The highly theoretical limit is 128 recursions. Which could only happen, 
// when feeding a text file to the compressor, consisting of only blank spaces and 
// a length of 2^128. Which is not possible at todays architectures,
// since this would be 3.4 * 10^38 Bytes.
// 
// So, if given a blocksize of 1MB, the max. recursion would be 20, (2^20 = 1MB)
// when the block consists of nothing than blank spaces. (or nulls,..)
// which would get compressed to 1Byte + the table ( 40 Bytes )
//
// At the moment, the implementation has a max recursion of 16.
//
// Compressed file format:
// *1 1 Byte "check number" : 0xC2  
// *2 1[+1] Byte: skip x Bytes. (can be 0: ->goto *3)
//   	if the first (msb) bit is set, clear it, shift 8 bits left,
//   	and use the next byte for the lower 8 Bits of the resulting 
//   	16(15) bit value. This coding is named 1[+1] below
//   	skip the value. repeat, until 0 is read.
//
//	       [skipped bytes] 
//
//	 goto *2* 
//	   - again either 1 Byte 0x0 (goto *3). Or again 1[+1] Byte(s) skip x Bytes.
//	 		0x0 serves also as file check. 
//			(It's unlikely to hit a 0 by accident, with a max recursion of 8. 
//			So if there's no 0 read before eof/the 9th recursion,
//	 		something might be wrong)
//
// *3 1 Byte (table length)/2 : 0x80 ( or less. )
// *4 table 
//
// *5 1 Byte (char replacement table length). (coould be 0)
// *6 char replacement table
//
// *7 1[+1] Byte offset of compressed data start. (->*10)
//	 		(possibility to ignore/omit len and crc block)
//
// *8 2 Bytes (compressed block length in Bytes)
//    if the first (most significant) byte is set, clear it,
//    treat the first two bytes of the compressed data block as bsd-checksum
//    if the second bit is set, clear it,
//    shift left 16 bits, add the next 2 Bytes to the block len.
// *9 2 Bytes uncompressed data block len
// 		1 Bit (msb) set: clear 1 Bit, shift left 16 Bits, 
// 		add next two bytes to the uncompressed data block len.
//
// *10 2 Bytes: BSD-checksum (or 0's )
//
// *11 Byte 0 (or 1[+1] skip again)
//
// *12 compressed data.
//
// *13 1 Byte (selection byte): 
//   				0x0 = EOF
//   				0x1 = start again with table length (->*3)
//   				0x2 = -> start again at 1 Byte skip x^2 Bytes (*2)
//   				0x3 = start again at "next data block" length (*7)
//    
// BSD 3clause, Michael (misc) Myer, (c) 2019

unsigned char ct[256];

void decomp( const unsigned char data){
				if ( data & 0x80 ){
						decomp( ct[(unsigned char)(data<<1)] );
						decomp( ct[((unsigned char)(data<<1)+1)]  );
				} else {
						write( STDOUT_FILENO, &data, 1 );
				}
}


int main(){
	 	unsigned char data,c;
		int i = 0;

		read( STDIN_FILENO, (POINTER*)&data, 1 ); // "magic" byte
		if ( data != 0xc2 )
				return(-1);

		data = 0;

		do{
				i = data;
				if ( data & 0x80 ){ // first bit set
						i = ((data & 0x7F) << 8 );
						read( STDIN_FILENO, (POINTER*)&data, 1);
						i = i | data;
				}
				while ( i > 0 ){
						read( STDIN_FILENO, (POINTER*)&data,1 );
						i--;
				}
				read( STDIN_FILENO, (POINTER*)&data, 1);
		} while ( data != 0 ); // skip leading data, reserved for later implementations.

		

		// read the decompression table.
		// no error handling.
		read( STDIN_FILENO, (POINTER*)&data, 1 ); // len of table / 2
		read( STDIN_FILENO, (POINTER*)ct, data*2 );
		
		// decompress, byte by byte. 
		// It's not very effective.
		// Especially cause every decompressed byte is written byte by byte to stdout, unbuffered.
		// On the other hand, this rectifies the claim of being the smallest decompressor executable
		// available. ( 289 Bytes, regular elf, amd64, compiled and statically "linked" with gcc )
		while ( read( STDIN_FILENO, (POINTER*)&data, 1 ))
						decomp( data );

		return(0);
}
