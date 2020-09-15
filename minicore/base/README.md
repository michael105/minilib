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
basename        2020-08-01             566
cat             2020-07-14             1430
cat2            2020-07-09             1304
chroot          2020-06-16             617
dd              2020-07-07             4880
echo            2020-06-13             462
false           2019-08-19             211
getenv          2019-08-19             1142
grep            2020-06-18             1101
head            2020-07-14             1520
kill            2020-07-05             1946
ln              2020-06-13             838
ls              2020-09-15             5496
ls2             2020-07-22             4648
mkdir           2020-06-07             4032
mkfifo          2020-06-10             888
mount           2020-06-21             1592
pivot_root      2020-06-02             343
printenv        2020-06-18             682
pwd             2019-08-19             335
rm              2020-06-07             884
rmdir           2020-06-07             888
seq             2020-07-11             526
sleep           2020-06-10             517
sync            2020-07-14             365
tail            2020-06-09             2944
tee             2019-08-19             2951
touch           2020-05-20             534
true            2020-07-14             208
umask           2020-07-08             484
umount          2020-06-21             1184
uname           2020-06-21             1862
usleep          2020-07-06             469
waitfor         2020-07-28             3160
yes             2019-08-19             365
===============================================
                          size: 51374 Bytes
```
