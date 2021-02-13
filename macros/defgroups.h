// define grouping switches.
//





//+doc enable print and related functions
// This switch enables strlen;
// but neither globals nor the mini_buf are used.
//+depends print prints printsl printl eprint eprintl eprintsl eprints printfs eprintfs puts eputs strlen _mprints dprints
//+def group_print





//+doc write, and related functions
// these functions do not depend on strlen, 
// or any globals.
//+depends write ewrite writes ewrites fwrites ewritesl writesl
//+def group_write



//+doc printf, eprintf, fprintf, itodec, ltodec, itohex, anprintf, sprintf (conversions %d %l %x %ud %ul %ux ), 
//+depends printf eprintf fprintf itodec ltodec uitodec snprintf atoi itohex uitohex itoHEX uitoHEX strlen globals fileno vsnprintf sprintf dprints itooct
//+def group_printf
//



