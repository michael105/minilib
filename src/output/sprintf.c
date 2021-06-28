
//+include

//+doc I'm really uncertain about the size arg here, amongst others
// these are just misdefined functions, inhaerent insecure. :/
// If possible, do not use sprintf. Use snprintf instead. 
//+depends snprintf vsnprintf strlen
//+macro
#define sprintf(str,...) snprintf( str, mini_buf,  __VA_ARGS__)

//
// todo: add attribute printf (gcc format checking)


