

//+doc fprintf, formatted output
// conversions implemented:
// %d: signed int (mini_itodec)
// %u: unsigned int (mini_uitodec)
// %f: double (max precision 8 digits, highest possible number: 2^31 (mini_dtodec)
// %l (modify a following d,u to long) (mini_ltodec,mini_ultodec)
// %s: string
// %c: char
// binary and hex output print the numbers, 
// as they are internally stored(!).
// Negative numbers are represented with the first sign bit set.
// (e.g. -1 = 0xFFFFFFFF at x64)
// %b : binary output  (mini_itobin)
// %o : octal output (mini_itooct)
// %x/X : hex output (small/big capitals) (mini_itohex,mini_itoHEX
// %(: grouping (mini_atoi)
//
// warning - most possibly you'd like to define besides fprintf, or family,
// mini_itodec (%d conversion) 
// 
// For squeezing a few more bytes, and saving some checking;
// writes(constant string) and print (variable string), 
// prints (formatted output of one or several strings) are provided.
//
// 
//+header stdio.h
//+depends write snprintf fileno globals getpid kill
//+needs mini_fstream.h 
//+after itobin atoi itodec dtodec ltodec itohex
//+macro fprintf(stream,...)	write(fileno(stream),mlgl->mbuf,snprintf(mlgl->mbuf,mlgl->mbufsize,__VA_ARGS__))


