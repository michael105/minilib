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
basename        2019-08-19             523
cat             2020-06-20             1372
cat2            2020-07-09             1144
chroot          2020-06-16             562
dd              2020-07-07             4808
echo            2020-06-13             362
false           2019-08-19             162
getenv          2019-08-19             947
grep            2020-06-18             1074
head            2020-07-11             1388
kill            2020-07-05             1818
ln              2020-06-13             710
ls              2019-09-02             8648
mkdir           2020-06-07             4064
mkfifo          2020-06-10             758
mount           2020-06-21             1460
pivot_root      2020-06-02             250
printenv        2020-06-18             546
pwd             2019-08-19             292
rm              2020-06-07             754
rmdir           2020-06-07             758
seq             2020-07-06             448
sleep           2020-06-10             421
sync            2020-06-10             199
tail            2020-06-09             4528
tee             2019-08-19             2693
touch           2020-05-20             434
true            2019-08-19             159
umask           2020-07-08             387
umount          2020-06-21             992
uname           2020-06-21             1668
usleep          2020-07-06             381
yes             2019-08-19             323
===============================================
                          size: 45033 Bytes
```
