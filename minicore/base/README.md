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
basename        2019-08-19             560
cat             2020-07-14             1364
cat2            2020-07-09             1272
chroot          2020-06-16             667
dd              2020-07-07             4920
echo            2020-06-13             355
false           2019-08-19             211
getenv          2019-08-19             1075
grep            2020-06-18             1123
head            2020-07-14             5584
kill            2020-07-05             1946
ln              2020-06-13             830
ls              2019-09-02             8624
mkdir           2020-06-07             4016
mkfifo          2020-06-10             886
mount           2020-06-21             1612
pivot_root      2020-06-02             355
printenv        2020-06-18             674
pwd             2019-08-19             341
rm              2020-06-07             850
rmdir           2020-06-07             886
seq             2020-07-11             549
sleep           2020-06-10             526
sync            2020-07-14             255
tail            2020-06-09             4528
tee             2019-08-19             2789
touch           2020-05-20             539
true            2020-07-14             208
umask           2020-07-08             492
umount          2020-06-21             1112
uname           2020-06-21             1764
usleep          2020-07-06             486
waitfor         2020-07-20             1289
yes             2019-08-19             371
===============================================
                          size: 53059 Bytes
```
