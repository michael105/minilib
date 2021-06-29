//+cat userdb
//+depends munmap pwent
//+def
void endpwent(){
	munmap( (void*)mlgl->passwdfile.file, mlgl->passwdfile.size );
	mlgl->passwdfile.file = 0;
}
