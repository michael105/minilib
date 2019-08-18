#ifndef print_c
#define print_c
//#include "../include/write.h"
//
////+depends write
////+def
//int print(const char *msg){
//		int a=0;
//		while (msg[a] != 0 ){
//				a++;
//		}
//		return( write(1,msg,a) );
//}
//
////+header stdio.h
////+depends write
////+def
//int printl(const char *msg){
//		int ret = print(msg);
//		ret += write(1,"\n",1);
//		return(ret);
//}
//
////+header stdio.h
////+depends printl
////+def 
//int puts(const char *c){ 
//		return( printl(c) ); 
//}
//
//
//#ifdef mini_puts
////int puts( const char *c ){
////		return(printl(c));
////}
//#endif
//
#endif
