


sed: sed.h sedcomp.c sedexec.o
	../../../minimake --config minilib.conf -o sed sedexec.o sedcomp.c -Os -DINCLUDESRC -s  

sedexec.o: sedexec.c sed.h
	../../../minimake --config minilib.conf -c -o sedexec.o sedexec.c -Os -s
