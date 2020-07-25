#if 0
mini_start
mini_writes
mini_printf
mini_printfs
mini_buf 1024
mini_itodec
globals_on_stack


mini_scandir
mini_perror
mini_errno
mini_strcmp
mini_qsort
mini_getchar

#OPTFLAG -O0
#STRIPFLAG -g
INCLUDESRC

return
#endif

#if 0
void ssort(void  *base,
				size_t nel,
				size_t width,
				int (*comp)(const void *, const void *))
{
		size_t wnel, gap, wgap, i, j, k;
		char *a, *b, tmp;

		wnel = width * nel;
		for (gap = 0; ++gap < nel;)
				gap *= 3;
		while ((gap /= 3) != 0) {
				wgap = width * gap;
				for (i = wgap; i < wnel; i += width) {
						for (j = i - wgap; ;j -= wgap) {
								a = j + (char *)base;
								b = a + wgap;
								if ((*comp)(a, b) <= 0)
										break;
								k = width;
								do {
										tmp = *a;
										*a++ = *b;
										*b++ = tmp;
								} while (--k);
								if (j < wgap)
										break;
						}
				}
		}
}
#endif


int compare(const struct dirent** a, const struct dirent** b){
		//printf("name: %s %s\n",(*a)->d_name,(*b)->d_name);
		int ret;
		//ret=-strcmp((*a)->d_name,(*b)->d_name);
		//printf("ret: %d\n",ret);
		//return(ret);
		int n = 0;
		ret = 0;
		while ( (*a)->d_name[n]!=0 && ((*a)->d_name[n]==(*b)->d_name[n]) )
				n++;
		if ((*a)->d_name[n]>(*b)->d_name[n])
				ret=-1;
		if ((*a)->d_name[n]<(*b)->d_name[n])
				ret=1;

		//printf("ret: %d\n",ret);
		return(ret);
}



int main(int argc, char **argv){
		struct dirent **namelist;
		int n;
		if ( argc > 1 ){
				for ( *argv++; *argv; *argv++ ){
						n = scandir(argv[0], &namelist, NULL, &compare );
						printfs("\nPath: %s\n",argv[0]);
						while(n-->0){
								//printf("n: %d\n",n);
								printf("%s\n", namelist[n]->d_name);
						}
						//getchar();
						free_brk();
				}
		
		} else {
		n = scandir(".", &namelist, NULL, &compare );
		if (n == -1) {
				perror("scandir");
				exit(EXIT_FAILURE);
		}

		while (n--) {
				printf("%s\n", namelist[n]->d_name);
				//free(namelist[n]);
		}
		//free(namelist);

		}

		exit(EXIT_SUCCESS);
}

