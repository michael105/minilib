### Static builds for linux amd64

Compiled abd linked with the standard toolchain, gcc and ld,  -Os;

I'm trying to get a usable basic Unix system (without kernel) built statically within 64kB,
it's going to be interesting.

(Admittedly, possibly it's going to be 128kB. But not more.)

The commands here all shall dump there usage on invocation with -h, showing the implemented arguments.
(Coding this now)

Just now I'm thinking about adding a tool "help" - which could be invoked by the other tools,
also to dump the usage. 

Some sources in this directory are originally written by ammongit (github.com/ammongit/minutils) 
and modified by me.

I also reused some fragments of minix.
I kept all copyright notices within the sources.


```
basename        2019-08-19             493
cat             2019-08-20             1038
echo            2019-08-19             363
false           2019-08-19             153
getenv          2019-08-19             782
head            2019-08-20             1407
pwd             2019-08-19             277
tail            2019-08-20             2576
tee             2019-08-19             2335
true            2019-08-19             150
uname           2019-08-19             1346
yes             2019-08-19             309
===============================================
                          size: 11229 Bytes
```
