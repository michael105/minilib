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
gid             2021-05-21             2920
grep            2021-02-11             1104
head            2020-07-14             1520
id              2021-05-21             2912
kill            2020-07-05             1946
ln              2020-06-13             838
ls              2021-02-11             5448
ls2             2020-07-22             4648
mkdir           2020-06-07             4032
mkfifo          2020-06-10             888
mount           2020-06-21             1592
pivot_root      2020-06-02             343
printenv        2020-06-18             682
pwd             2019-08-19             335
rgrep           2021-02-11             6416
rgrep.dbg       2021-02-10             67168
rm              2020-06-07             884
rmdir           2020-06-07             888
seq             2020-07-11             526
sleep           2020-06-10             517
stat            2021-02-13             2192
sum             2021-02-11             3746
sync            2020-07-14             365
tail            2020-06-09             2944
tee             2019-08-19             2951
touch           2020-05-20             534
true            2020-07-14             208
umask           2021-02-11             487
umount          2020-06-21             1184
uname           2021-04-07             1862
usleep          2020-07-06             469
waitfor         2020-07-28             3160
where           2021-02-11             1024
yes             2019-08-19             365
===============================================
                         size: 137710 Bytes
```
