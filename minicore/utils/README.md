### Static builds for linux amd64

Compiled and linked with the standard toolchain, gcc and ld,  -Os;

Here go tools, not neccessarily present at a standard linux system.

Since I'm aiming at a 64kB (128kB max) base system, I've to separate them.


```
errno           2020-06-21             6608
kgetty          2020-06-21             3266
sed/sed         2020-06-12             18744
sed/sed.bak     2020-06-12             18320
===============================================
                          size: 46938 Bytes
```
