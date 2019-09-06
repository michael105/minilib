#ifndef closedir_c
#define closedir_c

//+depends free
//+def
int closedir(DIR *dir){
	int ret = close(dir->fd);
	free(dir);
	return ret;
}



#endif
