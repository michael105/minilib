//+doc hashes, from d.j.Bernstein
// (http://www.cse.yorku.ca/~oz/hash.html)
// I've tested djb2_hash, and it gives quite good results.
// But I'm sure, Bernstein did think and test his algorithm sincerely.
// When combining djb2_hash and sdbm_hash, the probability of collisions
// might tend to zero.
// Me I'm going this way. I guess. I might check djb2_hash for collisions within a space of around 8 digits.
//
//+def
unsigned long djb2_hash(const unsigned char *str){
		unsigned long hash = 5381;
		int c;

		while ((c = *str++))
				hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

		return hash;
}

//+def
unsigned long sdbm_hash(const unsigned char *str){
		unsigned long hash = 0;
		int c;

		while ((c = *str++))
				hash = c + (hash << 6) + (hash << 16) - hash;

		return hash;
}

