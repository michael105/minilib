//+cat userdb
//+def
void setgrent(){
	mlgl->groupfile.p = mlgl->groupfile.file;
	mlgl->groupfile.p2 = mlgl->groupfile.file+mlgl->groupfile.size;
}


