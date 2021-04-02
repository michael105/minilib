//+def
int inet_aton(const char* s, struct in_addr *addr){

		union { uint32_t i; char c[4]; } u = { .i=0 };
		int p = 0;
		char *pc = (char*)s;

		do {
			while ( ( '0' <= *pc ) && ( *pc <= '9' ) ){
					u.c[p] = u.c[p]*10 + ( *pc-'0' );
					pc++;
			}
			printf("u.c: %d\n",u.c[p]);
			if ( !*pc )
					break;
			p++;
			pc++;
		}	while (p<4);
			printf("p: %d  u.c: %d\n",p,u.c[p]);
		if ( p<4 ){
				u.c[3] = u.c[p];
				u.c[p] = 0;
		}
		addr->s_addr = u.i;
	return(1);
}
