// warnings 

#ifndef no_warnings

#ifdef mini_gets
#warn gets is inherent insecure. Use fgets when possible.
#endif
#ifdef mini_getenv 
#warn You should read the environment before processing any user input, or be sure, the stack cannot overflow.
#endif
#ifdef mini_sprintf
#warn sprintf is not safe. Please use snprintf instead
#endif


#endif
