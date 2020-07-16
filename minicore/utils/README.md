### Static builds for linux amd64

Compiled and linked with the standard toolchain, gcc and ld,  -Os;

Here go tools, not neccessarily present at a standard linux system.

Since I'm aiming at a 64kB (128kB max) base system, I've to separate them.


```
conv            2020-07-16             2804
errno           2020-07-16             6352
kgetty          2020-07-16             4409
sed/s           2020-07-07             18656
sed/sed         2020-07-07             16748
sed/sed.bak     2020-06-12             18320
udo             2020-07-16             1056
===============================================
                          size: 68345 Bytes
```
