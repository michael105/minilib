#if 0

. basicconf.conf

mini_strcpy
mini_gets

return
#endif


int main(){
	int a;
	for ( a=0; a<3; a++ )
		printf("a: %d\n",a);

	while (a-->0){
		printf("a: %d\n",a);
	}

	char c[64];
	strcpy(c,"12345 Hallo\n");
	prints(c);

	return(0);
}
