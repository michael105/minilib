### Static builds for linux amd64

Compiled and linked with the standard toolchain, gcc and ld,  -Os;

I'm trying to get a usable basic Unix system (without kernel) built statically within 64kB,
it's going to be interesting.

(Admittedly, possibly it's going to be 128kB. But not more.)

The commands here all shall dump there usage on invocation with -h, showing the implemented arguments.
(Coding this now)

Just now I'm thinking about adding a tool "help" - which could be invoked by the other tools,
also to dump the usage. 



These tools are from other authors and modified by me:

David Bell: dd 

grep,mkdir (xv6)

ammongit: uname,cat,basename

minutils: tee,tail

Andy Tannenbaum (minix): head



All other tools are written by me and BSD Licensed.
 



```
basename        2019-08-19             504
cat             2020-06-20             1188
chroot          2020-06-16             555
dd              2020-07-07             4600
echo            2020-06-13             355
false           2019-08-19             155
getenv          2019-08-19             787
grep            2020-06-18             1067
head            2020-06-18             1389
kill            2020-07-05             1634
ln              2020-06-13             522
ls              2019-09-02             8816
mkdir           2020-06-07             3864
mkfifo          2020-06-10             542
mount           2020-06-21             1272
pivot_root      2020-06-02             243
printenv        2020-06-18             386
pwd             2019-08-19             285
rm              2020-06-07             530
rmdir           2020-06-07             534
seq             2020-07-06             440
sleep           2020-06-10             414
sync            2020-06-10             199
tail            2020-06-09             2736
tee             2019-08-19             2581
touch           2020-05-20             427
true            2019-08-19             152
umount          2020-06-21             792
uname           2020-06-21             1440
usleep          2020-07-06             374
yes             2019-08-19             315
===============================================
                          size: 39098 Bytes
```
