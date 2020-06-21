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
basename        2020-06-18             493
cat             2020-06-20             1126
chmod           2020-06-10             208
chroot          2020-06-18             538
echo            2020-06-18             350
false           2020-06-18             155
getenv          2020-06-18             782
grep            2020-06-18             1067
head            2020-06-18             1379
head-bsd        2020-06-18             1319
kill            2020-06-18             3303
ln              2020-06-18             510
ls              2020-06-18             8432
mkdir           2020-06-18             3816
mkfifo          2020-06-18             520
mount           2020-06-21             1260
mount-sash      2020-06-21             2482
printenv        2020-06-18             386
pwd             2020-06-18             283
rm              2020-06-18             508
rmdir           2020-06-18             512
seq             2020-06-18             418
sleep           2020-06-18             407
sync            2020-06-18             199
tail            2020-06-18             2688
tee             2020-06-18             2547
touch           2020-06-18             424
true            2020-06-18             152
uname           2020-06-18             1378
yes             2020-06-18             315
===============================================
                          size: 37957 Bytes
```
