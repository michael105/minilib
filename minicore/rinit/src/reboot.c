#define mini_start
#define mini_kill
#define mini_errno
#define INCLUDESRC
#include "minilib.h"

int main(){
	kill(1,SIGINT);
	return(errno);
}
