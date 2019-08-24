
 minilib
==============================================

    A tiny c system library,
    headeronly, intended for static linking


```
>    Copyright (c) 2012-2019 Michael (Misc) Myer, 
>    misc.myer@zoho.com / www.github.com/michael105
>
>    BSD License
>    Static linking is permitted.
>    See bottom for the BSD License. 
>    Some sourcefiles in the folders headers and contrib
>    have other licensing terms, 
>    which are in my opinion compatible to the BSD-Licenses.
>    Please look at the sources. 
```


 Summary
--------------------


Minilib aims to be an incomplete libc replacement,
single header only, as simple and small as possible, KISS,
but supplying ANSI-C, the most important tools of libc,
and some addons (Which don't add bloat and are optional).

"It's sometimes smarter to stay special,
 albeit in this case this means the opposite"


Although the header file is parsed and compiled for every
source file, this takes only fractions of a second
at my development system. (amd Turion 2Ghz)

```
>  ~/prog/minilib $  time ./mini-gcc --ldscript onlytext -o hello hello.c
 ./mini-gcc -o hello hello.c  0.06s user 0.05s system 92% cpu 0.116 total
>  ~/prog/minilib $  ./tools/shrinkelf hello
 stripping: hello
>  ~/prog/minilib $  ls -l hello
 -rwxr-xr-x 1 micha micha 185 Aug 15 16:16 hello
```

 About
--------------------

Minilib evolved out of some assembler experiments,
where I saw how tiny executables can be, if not linked with glibc.
With some more fiddling I got a C "Hello World!" program with 151 bytes,
compiled and linked with the standard gcc makechain.
This is more than 3,000 times less than a hello world program 
linked statically with glibc,
which shows up with 504kB on my system. (5.4kB linked dynamic)

(On OSX there are some limits, 
files with less than 4k aren't executed, 
so that's hello world's size there..)

minilib also saves a lot of startup overhead,
giving a more responsive system.

Just for fun, but this minilib also beats klibc, dietlib and musl 
in the matter of hello world's size..

```
(Linux 32bit:)
musl: 7.6k
dietlibc: 672
klibc: 367
minilib: 151
```

(On Linux 64bit I didn't check the other libraries,
 but the bigger registers cost a few bytes:
 hello world counts here 185 Bytes.)
..


Being in syscalls, linker scripts and gcc optimization hell,
I realized, that after I got over the fundamental problems adding 
more standard c routines would be cheap.
So I started to port some more little c tools to minilib,
adding more functionality to minilib as well.

Since I hate todays usual overhead in modern libraries,
resulting in the unbelievable size of hundreds of Megabytes 
for simple applications as well as minutes for just starting them up,
I also tried to optimize functions like printf where sensible.

You are able to customize the compilation of the library
and define just only the functions you need.


This whole project exaggerated out of fun.

I decided to publish this anyway,
since I hope this could be of some use and there's too much on 
my harddisk lying and dying.



 Build dependencies
--------------------

* Needs:
gcc or tcc, bash, sed

* Optionally:
gzip, sort (might be already on every unix related system)

make, perl (when rebuilding minilib)



 Usage
----------


Include minilib.h in all sourcefiles, needing definitions from minilib.

Either define functions you need yourself, before you include minilib.h.
Example: #define mini_write
(Or) use the config framework, implemented within the script mini-gcc.
(Also documented there for now)
The config framework has the big advantage of raising syntax errors for e.g. mistypes,
so instead of having to look for the mistype, it's shown up even before the compile.

In one of your sourcefiles you also have to define "#define mini_INCLUDESRC",
before the "include "minilib.h" directive.

Either use the supplied makefile.template by copying it;
or export CC via 'export "CC=[path to minilib]/mini-gcc [--config configfile.conf]"'
(There are a lot of compile options needed in order to prevent gcc from including 
the standard libraries, but you can also read the options out of mini-gcc,
if you'd like to. I just guess, having the config options all in a central place
is better, e.g. in the matters of platform portability.)

done..
..
Cross your fingers .. Get some strange errors .. shout out, loudly .. 
.. and open an issue here at github, please




 State
----------

ATM, most possibly neither the OSX nor the linux 32bit port will compile.
I'm just about to finish some things at Linux amd64.
Then I'll be able to check for osx and Linux x32.


* 2019/08
	restructured the build system.
	wrote mini-gcc, a wrapper around gcc.
	Close to be a dropin replacement for glibc,
	without the need of changing any sources when
	compiling with mini-gcc and minilib 
	instead of glibc.


* 2019/04/02
	Overall, minilib gets into a more stable state.
	The build framework as well as the config framework
	look good to me. And it's generic enough to don't get into trouble,
	when there something has to be changed.

	Ansi C (C89) / is about 75% done. Some functions (fopen/fclose) 
	 only trivially tested.
	
	Atm, I'm working on getting more tools of the 'suckless linux base' 
	and the 'minutils' compiled with minilib.
	Besides, I'm fiddling around with some security and performance related 
	fundamental matters. Stack and elf section related; 
	but these questions are optimizations and no fixes.
	(Or, to be more exact, these questions are about 
	 fixes of existing security holes.)
	


* 2019/03/28
	Restructuring done,
	config system written.

	The documentation about the build process isn't on state.
	The examples might be self explaining,
	but I have to rewrite the docs.



* 2019/03/19: 
	Ok. about half of ansi c is done.
	some important functions missing (free, e.g)
	but close. Restructuring nearly done.
	Overall - quite close to a first real release.
	Yet I could also maintain backward compatibility.
	(Important to me, since I'm using this lib for 
	nearly 7 years myself..)


* 01/2019  Got minilib running on OSX (10.11, x64),
	enabling static linking for small tools.

	Anyways, being able to link small tools statically 
	on osx is a great thing. 
	This doesn't work with the native libs,
	and there are reasons, you might want to link statically.
	
	Hacking the OS, or executing security critical code,
	for example. If the kernel has been hacked, well...
	But statically linking prevents from lib injection.
	BUT PLEASE BE AWARE, minilib itself is neither checked nor written
	for security. Although there are some tests, e.g. for buffer overflows,
	I cannot guarantee any defined functionality.
	But I worked thoroughly, and I'm using this lib myself for several years.



Minilib aims to be an incomplete libc replacement,
as simple and small as possible, KISS!!!,
but supplying ANSI-C, the most important tools of libc,
some addons (Which don't add bloat..).
Some syscall wrappers.

One reason to use syscall wrappers is type safety.
(The kernel doesn't know about type safety,
 he simply grabs the arguments he's fed, so, ..) 

Minilib shall be portable. 
For now there is Linux x86_64, x86_32,
and OSX Darwin.

Android is targeted. 
BSD is targeted. 

Minilib should stay tiny.
Ideally minilib is going to supply glibc compatible
headers. (sort of)


 Warning
====================

This library is not complete.
I'm integrating the suckless linux tools now,
sort of a soothing puzzle.

If you have no special interest in using minilib,
better head for something like musl, dietlibc, klib, ...

🔨 Happy hacking 🔨



 Development
--------------

Especially adding more syscalls is easy.

Look into include/lseek.h for examples.
As well as include/syscall_stubs.h.
(That's the file, where all wrappers are defined)

Addendum: Having written a build framework, 
 	which already rewrites the system call defines;
	I still have to document this.

Please, open an issue at github for bugs or bugfixes.
(github.com/michael105/minilib)

Also, the standards are quite a mess.
I'm trying to figure out something sensible,
to work with Ansi-C / Posix-C in a compatible way.


 Further Readings
------------------ 

-> https://elinux.org/System_Size  -  Embedded Linux and size

-> http://muppetlabs.com/~breadbox/software/tiny/teensy.html  -  About creating tiny binaries

-> https://olimex.wordpress.com/2012/04/04/unix-on-pic32-meet-retrobsd-for-duinomite/ 
   -  running bsd with 128K RAM (!)

-> https://www.mkompf.com/cplus/cliblist.html  -  Ansi standard c

-> https://www.etalabs.net/compare_libcs.html  -  comparison of c/POSIC standard library implementations


 See Also
-----------

(google also..)

----- tiny c lib implementations

~~~
klibc
bionic
musl
uLibc
dietlibc
minibase
~~~


 Notes
-------


"It's sometimes smarter to stay special,
 although in this case this means the opposite"

 Stumbled upon this comment of myself today,
 regarding my (strangely simplicistic) malloc implementation.
 Which fit's quite well to the minilib in whole.
 Being smart with utf-anything, don't know which 
 bordercase and so on - 
 is sometimes overall not smart.

 So, having a 500kB "hello world" like with glibc, 
 is not soo smart. Especially when it needs to be 
 compiled again at the target, so most bordercases
 aren't of any interest.

 151 Bytes, as accomplished with minilib - 
 There's still some overhead. 
 But it's another dimension. 




----------------------------------------------------
    Michael (Misc) Myer, 2012-2019
    misc.myer@zoho.com www.github.com/michael105
    (my "programming enthusiastic persona"..)
----------------------------------------------------


------------------------------------------------------------


```
Copyright (c) 2012-2019, Michael (Misc) Myer 
(misc.myer@zoho.com, www.github.com/michael105)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
   the file NOTICE, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
   the file NOTICE, this list of conditions and the following disclaimer in 
   the documentation and/or other materials provided with the distribution.
 * Neither the name of the minilib nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL Michael Myer BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```






