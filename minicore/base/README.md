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
basename        2020-07-06             504
cat             2020-07-06             1188
chmod           2020-06-10             208
chroot          2020-07-06             555
echo            2020-07-06             355
false           2020-07-06             155
getenv          2020-07-06             787
grep            2020-07-06             1067
head            2020-07-06             1403
kill            2020-07-06             1634
ln              2020-07-06             522
ls              2020-07-06             8800
mkdir           2020-07-06             3896
mkfifo          2020-07-06             542
mount           2020-07-06             1272
pivot_root      2020-07-06             243
printenv        2020-07-06             386
pwd             2020-07-06             285
rm              2020-07-06             530
rmdir           2020-07-06             534
seq             2020-07-06             440
sleep           2020-07-06             414
sync            2020-07-06             199
tail            2020-07-06             2744
tee             2020-07-06             2581
touch           2020-07-06             427
true            2020-07-06             152
umount          2020-07-06             792
uname           2020-07-06             1440
usleep          2020-07-06             374
yes             2020-07-06             315
===============================================
                          size: 34744 Bytes
```
