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
basename        2021-06-20             568
chroot          2021-06-20             619
echo            2021-06-20             464
false           2021-06-20             213
getenv          2021-06-20             1142
head            2021-06-20             1464
kill            2021-06-20             1882
ls2             2021-06-20             4648
mkdir           2021-06-20             4064
pivot_root      2021-06-20             345
printenv        2021-06-20             682
pwd             2021-06-20             337
rgrep           2021-06-20             6416
rgrep.dbg       2021-06-20             67168
seq             2021-06-20             527
sleep           2021-06-20             498
stat            2021-06-20             2152
sync            2021-06-20             367
tail            2021-06-20             2976
tee             2021-06-20             2919
touch           2021-06-20             536
true            2021-06-20             210
umount          2021-06-20             1120
usleep          2021-06-20             456
waitfor         2021-06-20             3080
yes             2021-06-20             367
===============================================
                         size: 105220 Bytes
```
