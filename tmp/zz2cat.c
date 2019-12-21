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

// This is a showcase of minilib / "z2" compression algorithm.
// zz2cat decompresses from stdin to stdout.
//  It's not meant to be used in production environment,
//  it's just my first implementation of the compression algorithm
//  and missing all error checks. 
//  But giving a tiny executable of 309 Bytes, stacically linked with 
//  minilib ( another project of mine ).
//  The code might even work at a 8bit architecture,
//  and it's blazingly fast, even in this unoptimized form.
//  
// compile with "mini-gcc --config zz2cat.c -o zz2cat zz2cat.c"
//
//   (I'm pretty sure, I didn't "invent" this compression algorithm)
//		So possibly better call it the "z2 implementation".
//		I just don't know the algorithm,
//		and did experience some interesting outcomes while implementing.
//		e.g., changing the length of the dictionary table to more than 2 
//		or dynamic values didn't have
//		the expected effect of a significant better compression, 
//		but higher complexity of the implementation.
//
//
//
// zz2cat decompresses from stdin to stdout
// unbuffered, which is not very effective.
// The decompression speed is limited by the overhead of the syscalls
// for reading and writing stdin/out.
//
// It's the tradein for having a tiny executable
// ( 309 Bytes, compiled and statically "linked" with gcc )
//
// The compression rate is quite stable around 50% for most text files.
// Memory used when decompressing is dictionary size (max.256 Bytes) + 
// the stack needed for the recursive function calls to decomp(),
// which rarely exceeds 6 recursions.
// 
// (The highly theoretical limit is 128 recursions. Which could only happen, 
// when feeding a text file to the compressor, consisting of only blank spaces and 
// a length of 2^128. Which is not possible at nowadays architectures,
// since this would be 3.4 * 10^38 Bytes. 
// 
// So, if given a blocksize of 1GB, the max. recursion would be 20, (2^20 = 1MB)
// when the block consists of nothing than blank spaces. (or nulls,..)
// which would get compressed to 2Byte + the table ( 40 Bytes )), 
// getting 42 Bytes.
//
// Experiments show, however, the best ratio between compression speed
// and compression rate is around 64 kB, although this might vary,
// depending on the input, architecture, and compiler optimizations.
//
// This whole thing resulted out of my experiments of trying to compress
// a list of error messages (errno), since I'd like to have some more verbose
// "perror" error messages with minilib - but the list for 133 different
// error codes is at around 3.1kB. 
// Given the fact, "hello world" comes statically linked with 185 Bytes -
// This would mean huge "bloat". 
// I've been able to break the error messages down to 1.4kB; only marginally
// more than with the lzma algorithm. 
// However, adding this overhead to every executable still means "bloating".
// So, atm, I lean towards a separated executable, "perror", 
// printing the given argument error code to stderr.
// The other posibility would be a sort of lazy plugin loading mechanism.
// Which remembers me of another idea, having plugins as separated processes,
// communicating via shared memory, but with a function and object based interface.
// There would be the advantage of separating security and stability related matters.
// 
//
//
// Compressed file format:
// 	numbers in round brackets () are optional
//	numbers in {} mean, there's a (optional) loop,
//	in order to be able to put more data into the header later
//	without breaking backwards compatibility
//
//
// *1 1 Byte "check number" : 0xC2  
// {*2} 1[+1] Byte: skip x Bytes. (can be 0: ->goto *3)
//   	if the first (msb) bit is set, clear it, shift 8 bits left,
//   	and use the next byte for the lower 8 Bits of the resulting 
//   	16(15) bit value. This coding is named 1[+1] below.
//
//   	skip the value. repeat, until 0 is read.
//
//	       (skipped bytes, optionally)
//
//	 (goto *2*)
//	   - again either 1 Byte 0x0 (goto *3). Or again 1[+1] Byte(s) skip x Bytes.
//	 		0x0 serves also as file check. 
//			(It's unlikely to hit a 0 by accident, with a max recursion of 8. 
//			So if there's no 0 read before eof/the 9th recursion,
//	 		something might be wrong)
//
// *3 1 Byte (table length)/2 : 0x80 ( or less. )
// (*4) table 
//
// *5 1 Byte (char replacement table length). (could be 0)
// (*6) char replacement table
//
// *7 1[+1] Byte offset of compressed data start. (->*12)
//	 		(possibility to ignore/omit len and crc block by passing 0)
//
// (*8) 2 Bytes (compressed block length in Bytes)
//      if the first (most significant) byte is set, clear it,
//      read the following two Bytes (*9) as bsd checksum
//      if the second bit is set, clear it,
//      shift left 16 bits, add the next 2 Bytes to the block len.
// ((*9)) 2 Bytes: BSD-checksum of the compressed block
// (*10) 2 Bytes uncompressed data block len
// 			1st Bit (msb) set: BSD-checksum of uncompressed data present in *11
//   	  2nd Bit (msb) set: clear it, shift left 16 Bits, 
// 	    add next two bytes to the uncompressed data block len.
// ((*11)) 2 Bytes: BSD-checksum of the uncompressed block
//
// (*12) Byte 0 (or 1[+1] skip again, until 0. same as *2)
// 
// *13 compressed data.
//
// *14 1 Byte (selection byte): 
//   				0x0 = EOF
//   				0x2 = -> start again at (*2) 
//   				0x3 = start again with table length (->*3)
//   				0x7 = start again at "next data block" length (*7)
//    
// BSD 3clause, Michael (misc) Myer, (c) 2019

// Ideas: Encryption. 
// 	( Mix several encodings. Noone nows exactly, 
// 	how long it takes to break a chiffre. 
//  Password input. mixture of 2factor, colors, pictures, 
//    scriptable dependence on hour,date, moon, whatever,
//    selecting columns with given chars.
//    randomizing (adding some randomness to the current password,
//    needing a "tiny" bruteforce everytime.
//
// ->password feeder. (encrypted memory for comm.?)
// 


// the dictionary table.
unsigned char ct[256];

void decomp( const unsigned char data){
				if ( data & 0x80 ){
						decomp( ct[(unsigned char)(data<<1)] );
						decomp( ct[((unsigned char)(data<<1)+1)]  ); // this could be replaced by a loop. 
				} else {
						write( STDOUT_FILENO, &data, 1 );
				}
}


int main(){
		// "buffer"
	 	unsigned char data;

		// read the decompression table.
		// no error handling.
		read( STDIN_FILENO, (POINTER*)&data, 1 ); // len of dictionary / 2
		read( STDIN_FILENO, (POINTER*)ct, data*2 ); // read dict
		
		// decompress, byte by byte. 
		// It's not very effective.
		// Especially cause every decompressed byte is written byte by byte to stdout, unbuffered.
		// On the other hand, this rectifies the claim of being the smallest decompressor executable
		// available. ( 309 Bytes, regular elf, amd64, compiled and statically linked to minilib
		// with the standard gcc toolchain )
		while ( read( STDIN_FILENO, (POINTER*)&data, 1 ))
						decomp( data );

		return(0);
}
