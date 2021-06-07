//+cat userdb
//+def
void setgrent(){
	mlgl->groupfile.p = mlgl->groupfile.file;
	mlgl->groupfile.p2 = (char**)(mlgl->groupfile.file+mlgl->groupfile.size);
}


