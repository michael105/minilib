//+doc Sort dirents by name.
// Deviating of the standard, 
// the asciitables is used for the comparison
// (using strcmp)
//+depends strcmp
//+def
int alphasort( const struct dirent** de1, const struct dirent** de2 ){
		return(strcmp((*de1)->d_name,(*de2)->d_name) );
}

