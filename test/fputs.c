#define mini_start
#define mini_fileno
#define mini_fputs
#define INCLUDESRC
#include "minilib/minilib.h"



int main(){
		fputs( "Hello!\n", stdout );
		fputs( "Hello stderr!\n", stderr );

		return(0);
}
