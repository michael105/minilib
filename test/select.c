#define mini_start
#define mini_write
#define mini_select
#define mini_strlen
#define mini_printf
#define mini_itodec
#define mini_errno
#define mini_buf 1024
#define INCLUDESRC

#include "minilib.h"

int main(){
		printf("Ok\n\n");
		printf("EBADF: %d\n",EBADF);
		printf("EINTR: %d\n",EINTR);
		printf("EINVAL: %d\n",EINVAL);
		printf("ENOMEM: %d\n",ENOMEM);


		return(0);
}

