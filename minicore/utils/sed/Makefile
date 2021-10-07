


sed: sed.h sedcomp.c sedexec.o
	../../../minicc --config minilib.conf -o sed sedexec.o sedcomp.c -Os -DINCLUDESRC -s  

sedexec.o: sedexec.c sed.h
	../../../minicc --config minilib.conf -c -o sedexec.o sedexec.c -Os -s
