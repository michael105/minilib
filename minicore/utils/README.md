### Static builds for linux amd64

Compiled and linked with the standard toolchain, gcc and ld,  -Os;

Here go tools, not neccessarily present at a standard linux system.

Since I'm aiming at a 64kB (128kB max) base system, I've to separate them.


```
a.out           2021-06-20             3859
ap              2021-06-20             1296
conv            2021-06-20             3104
errno           2021-06-20             7805
fromhex         2021-06-20             816
getresuid       2021-06-20             2400
kgetty          2021-06-20             3859
kgetty-persistent 2021-06-20             4864
ksudo           2021-06-20             904
lockfile        2021-06-20             3928
nbdo            2021-06-20             968
pbutton.d       2021-06-20             3464
rd.pstat        2021-06-20             6456
rinit.daemon    2021-06-20             2040
sed/s           2020-07-07             18656
sed/sed         2020-07-07             16748
sed/sed.bak     2020-06-12             18320
su              2021-06-20             644
tohex           2021-06-20             502
udo             2021-06-20             1204
xorpipe         2021-06-20             4440
===============================================
                         size: 106277 Bytes
```
