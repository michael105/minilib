### Static builds for linux amd64

Compiled and linked with the standard toolchain, gcc and ld,  -Os;

Here go tools, not neccessarily present at a standard linux system.

Since I'm aiming at a 64kB (128kB max) base system, I've to separate them.


```
                             
error           2020-06-19             10256
kgetty          2020-06-02             2584
minilib         2020-06-01             6
pivot_root      2020-06-02             271
sed/sed         2020-06-12             18744
sed/sed.bak     2020-06-12             18320
===============================================
                          size: 50181 Bytes
```
