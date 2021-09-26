//+doc gethostname
//+depends network uname
//+def 
static int gethostname(char *name,int len){
	struct new_utsname u;
	int ret=uname(&u);
	if (ret==0) {
		if (len > sizeof(u.nodename)) len = sizeof(u.nodename);
		int i;
		for (i=0; i<len && (name[i] = u.nodename[i]); i++);
		if (i && i==len) name[i-1] = 0;
	}
	return(ret);
}

