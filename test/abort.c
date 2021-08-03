#if 0
mini_start
mini_prints
mini_signal
mini_abort


INCLUDESRC


if [ -n "$CLANG" ]; then
	OPTFLAG -O2
	mini_memset
fi

return
#endif

void sigabrt(int num){
		prints("Handler Sigabrt\n");
}

int main(int argc, char **argv){

		prints("abort. Install handler\n");
		signal(SIGABRT, &sigabrt );

		prints("abort.\n");


		abort();
		prints("abort failed\n");
		return(1);
}
