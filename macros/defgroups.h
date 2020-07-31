// define grouping switches.
//





//+doc enable print and related functions
// This switch enables strlen;
// but neither globals nor the mini_buf are used.
//+depends print prints printsl printl eprint eprintl eprintsl eprints printfs eprintfs puts eputs strlen
//+def group_print





//+doc write, and related functions
// these functions do not depend on strlen, 
// or any globals.
//+depends write ewrite writes ewrites fwrites 
//+def group_write



//+doc printf, eprintf, fprintf, itodec and ltodec (conversions %d %l), 
//+depends printf eprintf fprintf itodec ltodec uitodec snprintf
//+def group_printf
//


