//+cat userdb
//+depends munmap pwent
//+def
void endgrent(){
	munmap( (void*)mlgl->groupfile.file, mlgl->groupfile.size*2 );
	mlgl->groupfile.file = 0;
}
