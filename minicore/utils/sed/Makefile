


sed: sed.h sedcomp.c sedexec.o
	../../../mini-cc --config minilib.conf -o sed sedexec.o sedcomp.c -Os -DINCLUDESRC -s  

sedexec.o: sedexec.c sed.h
	../../../mini-cc --config minilib.conf -c -o sedexec.o sedexec.c -Os -s
