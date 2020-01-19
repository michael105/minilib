#ifndef mini_getoptm_h
#define mini_getoptm_h

//+include


#define DEF_OPTIONS_ENUM_short enum MINI_OPTIONS_short { a=0x1,b=0x2,c=0x4,d=0x8,e=0x10,f=0x20,g=0x40,h=0x80,i=0x100,j=0x200,\
						k=0x400,l=0x800,m=0x1000,n=0x2000,o=0x4000,p=0x8000,q=0x10000,r=0x20000,s=0x40000,\
						t=0x80000,u=0x100000,v=0x200000,w=0x400000,x=0x800000,y=0x1000000,z=0x2000000 };

//+doc Parse "argv" for short options "options", small capitals.
//	Save them in the bitfield (int32) "opts".
//	If there is an unrecognized option, do "unrecognized". char "option" keeps the unrecognized option.
//	Possible options have to be supplied in this form: ( a+l+h+... )
//	e.g.: 
//		PARSEOPTS_short( opts, argv, (a+h+l),{ fprintf(stderr, "Unrecognized option: -%c\n", option); exit(1); });
//
//	Returns a number, pointing to the first regular argument. 
//		(Doesn't check for it's existence, so you can proceed with 
//		e.g.:) for ( int a= ret; argv[a] !=0; a++ ){ ... }
//
//+def
#define PARSEOPTS_short( opts, argv, options, unrecognized ) ({\
		DEF_OPTIONS_ENUM_short;\
		int argp=1;\
		for ( int ap=1; argv[ap]; ap++ ){\
				if ( argv[ap][0] == '-' ){\
						argp = ap+1;\
						for ( int b=1; argv[ap][b]; b++ ){\
								int ti; char option;\
								opts |= (ti=1<< ((option=argv[ap][b])-97) );\
								if ( ! ( (options) & ti ) ){\
									unrecognized;\
									}\
						}\
				}\
		}\
		argp;\
		} )


//+doc Tests, whether a bit (option flag) is set
//+def
#define GETOPT_short( opts, option ) ({\
				DEF_OPTIONS_ENUM_short;\
				opts & option;\
				} )

//+doc Set a option flag(s) (bit(s))  manually.
//		param options: e.g. just a, or ( a+h+l) to check for several flags at once
//+def
#define SETOPT_short( opts, option ) ({\
				DEF_OPTIONS_ENUM_short;\
				opts = (opts | option);\
				} )



#endif
