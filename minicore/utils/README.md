### Static builds for linux amd64

Compiled and linked with the standard toolchain, gcc and ld,  -Os;

Here go tools, not neccessarily present at a standard linux system.

Since I'm aiming at a 64kB (128kB max) base system, I've to separate them.


```
conv            2020-07-30             2959
errno           2020-07-30             5247
kgetty          2020-07-30             4552
ksudo           2020-07-30             921
nbdo            2020-07-30             980
rd.pstat        2020-07-30             6192
rinit.daemon    2020-07-30             3264
sed/s           2020-07-07             18656
sed/sed         2020-07-07             16748
sed/sed.bak     2020-06-12             18320
su              2020-07-30             658
udo             2020-07-30             1249
===============================================
                          size: 79746 Bytes
```
