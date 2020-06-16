### Static builds for linux amd64

Compiled abd linked with the standard toolchain, gcc and ld,  -Os;

I'm trying to get a usable basic Unix system (without kernel) built statically within 64kB,
it's going to be interesting.

(Admittedly, possibly it's going to be 128kB. But not more.)

The commands here all shall dump there usage on invocation with -h, showing the implemented arguments.
(Coding this now)

Just now I'm thinking about adding a tool "help" - which could be invoked by the other tools,
also to dump the usage. 

Some sources in this directory are originally written by ammongit (github.com/ammongit/minutils) 
and modified by me.

I also reused some fragments of minix.
I kept all copyright notices within the sources.


```
basename        2019-08-19             493
cat             2019-08-20             1038
chmod           2020-06-10             208
chroot          2020-06-07             567
echo            2020-06-13             368
false           2019-08-19             153
getenv          2019-08-19             782
head            2019-08-20             1407
kill            2020-06-08             3331
ln              2020-06-13             510
ls              2020-01-15             13344
mkdir           2020-06-07             3712
mkfifo          2020-06-10             512
pwd             2019-08-19             277
rm              2020-06-07             500
rmdir           2020-06-07             512
seq             2020-06-10             445
sleep           2020-06-10             435
sync            2020-06-10             225
tail            2020-06-09             2712
tee             2019-08-19             2335
touch           2020-06-01             464
true            2019-08-19             150
uname           2019-08-19             1346
yes             2020-01-15             309
===============================================
                          size: 36135 Bytes
```