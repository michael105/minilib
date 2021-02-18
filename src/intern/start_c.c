#ifndef startc_c
#define startc_c


// this gets included only when
// mini_vsyscalls is defined

typedef struct _elf_aux_v {
		unsigned int type;
		unsigned int value;
} elf_aux_v;



void __start_c(char **envp){

		//for ( ; *envp == 0; envp++  );
		while ( *envp++ != 0 );
		elf_aux_v *p = (elf_aux_v*)envp;

		while ( p ){
				if ( p->type == 32 ){
						__mini_vsys = p->value;
						return;
				}
				p++;
		}
}


#endif

