
//+def
unsigned long sdbm_hash(const unsigned char *str){
		unsigned long hash = 0;
		int c;

		while ((c = *str++))
				hash = c + (hash << 6) + (hash << 16) - hash;

		return hash;
}

