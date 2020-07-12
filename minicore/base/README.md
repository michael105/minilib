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
basename        2019-08-19             584
cat             2020-06-20             1412
cat2            2020-07-09             1216
chroot          2020-06-16             623
dd              2020-07-07             4848
echo            2020-06-13             367
false           2019-08-19             223
getenv          2019-08-19             995
grep            2020-06-18             1135
head            2020-07-12             1500
kill            2020-07-05             1890
ln              2020-06-13             782
ls              2019-09-02             8632
mkdir           2020-06-07             4104
mkfifo          2020-06-10             830
mount           2020-06-21             1532
pivot_root      2020-06-02             311
printenv        2020-06-18             626
pwd             2019-08-19             353
rm              2020-06-07             794
rmdir           2020-06-07             798
seq             2020-07-11             1720
sleep           2020-06-10             482
sync            2020-06-10             297
tail            2020-06-09             4528
tee             2019-08-19             2733
touch           2020-05-20             495
true            2019-08-19             220
umask           2020-07-08             448
umount          2020-06-21             1032
uname           2020-06-21             1708
usleep          2020-07-06             442
yes             2019-08-19             384
===============================================
                          size: 48044 Bytes
```
