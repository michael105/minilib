#if 0
mini_buf 256
mini_start
mini_printf
mini_nanosleep
mini_sleep
mini_itodec
mini_atoi
mini_fork
mini_sigaction
mini_sigemptyset
mini_writes
mini_errno
mini_INCLUDESRC
return
#endif

#include "minilib/minilib.h"

void handler(int signal){
		writes("Within handler\n");
		printf("signal %d\n",signal);
}

int main( int argc, char *argv[] ){
		printf("Fork.\n");

   struct sigaction action;

   sigemptyset(&action.sa_mask);
   //sigaddset(&action.sa_mask, signo);
   action.sa_flags = 0;
   action.sa_handler = handler;

		errno=0;
   int r;
	 int e;

	 r = sigaction (SIGTERM, &action,0);
	 e = errno;
	 printf("errno: %d\n",e);
	 printf("r: %d\n",r);

 r = sigaction (SIGUSR1, &action,0);
	 e = errno;
	 printf("errno: %d\n",e);
	 printf("r: %d\n",r);

	 int pid = fork();
	 //		int pid = 0;
	 printf("Forked.\n");
	 usleep(1000);
	 if ( pid ){
			 int r=0;
			 usleep(10000);
			 kill(pid,SIGUSR1);
			 kill(pid,SIGTERM);
			 do{
					 printf("errno: %d, r: %d\n",errno,r);
					 errno=0;
					 r = usleep(500000);
			 }while ( errno );


			 writes("kill child\n");
			 kill(pid,SIGKILL);
			 usleep(1000);

			 writes("Exit parent\n");
			 exit(0);
	 }

		writes("Child\n");
		do{
				printf("errno: %d, r: %d\n",errno,r);
				errno=0;
				r = sleep(30);
		}while ( errno );




		writes("Exit child\n");

		return(0);
}
