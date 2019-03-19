==============================================
 This is the miniature c systemcalls library.
==============================================


-----------------------------------------------------------
Copyright (c) 2012-2019 Michael (Misc) Myer, 
misc.myer@zoho.com / www.github.com/michael105

Licensed under the terms of 
the Apache License v2.0 (the "License");
you may not use this library except 
in compliance with the License.

Some sourcefiles in the folders headers / contrib
have other licensing terms.
Look at the sources. 

See bottom for the Apache License. 
 Essentially you can do what you want,
 but need to keep the copyright notes as well as the file 
 NOTICE. 
 Static linking is permitted.
-----------------------------------------------------------



====================
 Summary
====================

Minilib isn't complete at all. (2019/03)
..2019/03/19: Ok. about half of ansi c is done.
   some important functions missing (free, e.g)
   but close. Restructuring nearly done.
	 Overall - quite close to a first real release.
	 Yet I could also maintain backward compatibility.
	 (Important to me, since I'm using this lib for 
	 nearly 7 years myself..)

ATM, most possibly meither the OSX nor the linux 32bit port will compile.
I'm just about to finish some things at Linux amd64.
Then I'll be able to check for osx and Linux x32.

Minilib aims to be an incomplete libc replacement,
as simple and small as possible, KISS!!!,
but supplying ANSI-C, the most important tools of libc,
some extras (Which don't add bloat..).
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



====================
 Build dependencies
====================

make
gcc or tcc
ld (or tcc)
perl (when rebuilding minilib)



====================
 Warning
====================

This library is far from beeing complete.
I'm integrating the suckless linux tools now,
sort of a soothing puzzle.

If you have no special interest in using it,
better head for something like musl, dietlibc, klib, ...

I'd especially like to hint you at: 
https://github.com/attractivechaos/klib

It's not very well known, 
but looks good and is active.

Just got minilib running on OSX (10.11, x64),
enabling static linking for small tools.
Ported it from linux 32bit, 
so for the moment it's not sure
it will compile at linux without a little bit of work.

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


🔨 Happy hacking 🔨


====================
 About
====================

Minilib evolved out of some assembler experiments,
where I saw how tiny executables can be if not linked with glibc.
With some more fiddling I got a C "Hello World!" program with 151 bytes,
compiled and linked with the standard gcc makechain.
This is more than 3,000 times less than a hello world program 
linked statically with glibc,
which shows up with 504kB on my system. (5.4kB linked dynamic)

(On OSX there are some limits, 
files with less than 4k aren't executed, 
so that's hello world's size there..)

Just for fun, but this minilib also beats klibc, dietlib and musl 
in the matter of hello world's size..

(Linux 32bit:)
musl: 7.6k
dietlibc: 672
klibc: 367
minilib: 151



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




====================
 Development
====================


At the moment minilib is far of being complete,
but especially adding more syscalls is easy.

Look into include/lseek.h for examples.
As well as include/syscall_stubs.h.

Addendum: ATM, I'm about to restructure this library.

Please, open an issue at github for bugfixes.
(github.com/michael105/minilib)

But please don't do further work,
otherwise we'll get some more chaos.

I should have sorted the basic structure out in a few days. 
(Today is 2019/12/03)
(Today is 2019/18/03)




====================
 Usage
====================


include minilib.h in all sourcefiles, needing definitions from minilib.
define in minilib.h all features needed.

include minilib_implementation.c into a sourcefile or add minilib.c to the sources

copy makefile.template to your sourcedir, rename to makefile.
Edit makefile, set PROG to your prog's name.

done..


====================
 Further Readings
====================

-> https://elinux.org/System_Size  -  Embedded Linux and size

-> http://muppetlabs.com/~breadbox/software/tiny/teensy.html  -  About creating tiny binaries

-> https://olimex.wordpress.com/2012/04/04/unix-on-pic32-meet-retrobsd-for-duinomite/ 
   -  running bsd with 128K RAM (!)

-> https://www.mkompf.com/cplus/cliblist.html  -  Ansi standard c

-> https://www.etalabs.net/compare_libcs.html  -  comparison of c/POSIC standard library implementations


====================
 See Also
====================

(google also..)

----- tiny c lib implementations

klibc
bionic
musl
uLibc
dietlibc


====================
 Notes
====================

letztes makefile: in test-embutils.
(probleme mit den flags...)


include dateien: nach c standard.
(können dann mit gcc -I... überschrieben werden,
ohne Dateien zu verändern.)

"Nutzer" Datei(en) einbinden lassen durch minilib.c (?)



TODO: errno.h : set errno..



============================================================
============================================================
Michael (Misc) Myer, 2012-2019
misc.myer@zoho.com www.github.com/michael105
(my "programming enthusiastic persona"..)
============================================================
============================================================



===================

Copyright (c) 2012-2019 Michael (Misc) Myer, 
misc.myer@zoho.com / www.github.com/michael105

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

====================
