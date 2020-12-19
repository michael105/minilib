//+ansi string.h
//+def
void* memmove(void *dest, const void *src, int n){
		char *d;
		const char *s;

		d = dest;
		s = src;
		while(n-- > 0)
				*d++ = *s++;
		return dest;
}

