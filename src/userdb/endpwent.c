//+cat userdb
//+def
void endpwent(){
	munmap( (void*)mlgl->passwdfile, mlgl->passwdfilesize );
	mlgl->passwdfile = 0;
}
