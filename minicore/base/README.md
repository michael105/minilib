### Static builds for linux amd64

Compiled and linked with the standard toolchain, gcc and ld,  -Os;

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
basename        2020-06-21             504
cat             2020-06-21             1171
chmod           2020-06-10             208
chroot          2020-06-21             555
echo            2020-06-21             355
false           2020-06-21             155
getenv          2020-06-21             787
grep            2020-06-21             1067
head            2020-06-21             1389
head-bsd        2020-06-21             1326
kill            2020-06-21             3347
ln              2020-06-21             522
ls              2020-06-21             8792
mkdir           2020-06-21             3864
mkfifo          2020-06-21             525
mount           2020-06-21             1272
mount-sash      2020-06-21             2728
pivot_root      2020-06-21             243
printenv        2020-06-21             386
pwd             2020-06-21             285
rm              2020-06-21             513
rmdir           2020-06-21             517
seq             2020-06-21             420
sleep           2020-06-21             414
sync            2020-06-21             199
tail            2020-06-21             2736
tee             2020-06-21             2580
touch           2020-06-21             427
true            2020-06-21             152
umount          2020-06-21             792
uname           2020-06-21             1423
yes             2020-06-21             315
===============================================
                          size: 39969 Bytes
```
