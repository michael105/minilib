LICENSE 
=======



___________________________________________________

::

		    Copyright (c) 2012-2021, Michael (misc) Myer 
		    (misc.myer@zoho.com, www.github.com/michael105)
		    Donations welcome: Please contact me.
		    All rights reserved.
___________________________________________________


I did this minilib out of enthuiasm.
One side, I`d like to have this project being opensource.
On the other hand, I spent really much time with the development.
In an ideal world, someone would sponsor me for this time.
It is, however, not an ideal world we are living in.
Therefore I do have to insist on attributions and what
I`d like to call `fair use`.

In short, you are allowed to do with this project what you wish,
as long you show the copyright notice at a prominent place, 
and include the file NOTICE in distributions.

That`s the intention of this license,
which I`d like to name "Fair use with attribution".



License
=======

   The terms `minilib`, `source code`, `redistribution` or `linked with`
   apply to the minilib in full as well as to parts of minilib.
  
   All files belonging to this project are subject to this license, besides 
	 files, where within the header explicitely other licensing terms are noted.
    
   Michael (misc) Myer is a Pseudonym. 
	 When your local laws don`t permit usage of pseudonyms, this license 
	 or one of its sentences would be not legal, or you do not comply
	 to this license, you may neither use minilib nor parts of this project.
   The author is under this condition still the owner and copyright holder 
	 of this software. Please contact me for different licensing terms 
	 in this case, and explain your situation.
  

Redistribution, use and derived works in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above full notice,
   the file NOTICE, this list of conditions and the following disclaimer in 
   the documentation and other materials provided with the distribution

 * Redistributions in binary form must reproduce the above copyright notice,
   the file NOTICE, this list of conditions and the following disclaimer in 
   the documentation and other materials provided with the distribution

 * Software linked with, or derived from minilib must reproduce 
   the file NOTICE, this list of conditions and the following disclaimer
   in the documentation, and other materials

 * Applications and software linked with, or derived from minilib must 
   in addition reproduce one of the according full notices below for derived or 
	 linked works within a documentation accessible at runtime:
   - `--help` documentation
   - online manual for web applications
   - Alternatively within a for every user clearly visible and
	   readable message at the application startup
 
 * Software and applications without a textual or graphical user interface
   linked with, or derived from minilib must 
   reproduce the above copyright notice,
   the file NOTICE, this list of conditions and the following disclaimer in 
   the documentation and all other materials like advertisements, 
   manuals, datasheets, etc.
	 
 * Neither the name of the minilib nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission
  
 * You inform me with an email with the subject `minilib usage` 
   about your usage of minilib and agree to a possible announcement 
	 with your and/or your companie`s name at the homepage of minilib


Disclaimer:

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

End of the license.


Please contact me, if you are in need of differing licensing terms.


Notices:

::

  (Notice for linked works)
................................................

::

    Linked with minilib,
    Copyright (c) 2012-2021, Michael (misc) Myer 
    (misc.myer@zoho.com, www.github.com/michael105)
    Donations welcome: Please contact me.
    All rights reserved.
................................................

::

(Notice for derived works)
................................................

::  

    Based on minilib,
    Copyright (c) 2012-2021, Michael (misc) Myer 
    (misc.myer@zoho.com, www.github.com/michael105)
    Donations welcome: Please contact me.
    All rights reserved.
................................................






-----

Some files in the folder contrib have other licensing terms.
Please look at the sources.

-----


The files in the folder header have different licensing terms,
they define the kernel interface(s) and are either from linux itself (SPDX licensed),
or from musl.

The following section of the musl-License applies:

In addition, permission is hereby granted for all public header files
(include/* and arch/*/bits/*) and crt files intended to be linked into
applications (crt/*, ldso/dlstart.c, and arch/*/crt_arch.h) to omit
the copyright notice and permission notice otherwise required by the
license, and to use these files without any requirement of
attribution. These files include substantial contributions from:

Bobby Bingham
John Spencer
Nicholas J. Kain
Rich Felker
Richard Pennington
Stefan Kristiansson
Szabolcs Nagy

all of whom have explicitly granted such permission.

This file previously contained text expressing a belief that most of
the files covered by the above exception were sufficiently trivial not
to be subject to copyright, resulting in confusion over whether it
negated the permissions granted in the license. In the spirit of
permissive licensing, and of not having licensing issues being an
obstacle to adoption, that text has been removed.

------

The kernel syscall definitions fall under the syscall exception clause.


SPDX-Exception-Identifier: Linux-syscall-note
SPDX-URL: https://spdx.org/licenses/Linux-syscall-note.html
SPDX-Licenses: GPL-2.0, GPL-2.0+, GPL-1.0+, LGPL-2.0, LGPL-2.0+, LGPL-2.1, LGPL-2.1+, GPL-2.0-only, GPL-2.0-or-later
Usage-Guide:
This exception is used together with one of the above SPDX-Licenses
to mark user space API (uapi) header files so they can be included
into non GPL compliant user space application code.
To use this exception add it with the keyword WITH to one of the
identifiers in the SPDX-Licenses tag:
SPDX-License-Identifier: <SPDX-License> WITH Linux-syscall-note
License-Text:

NOTE! This copyright does *not* cover user programs that use kernel
services by normal system calls - this is merely considered normal use
of the kernel, and does *not* fall under the heading of "derived work".
Also note that the GPL below is copyrighted by the Free Software
Foundation, but the instance of code that it refers to (the Linux
kernel) is copyrighted by me and others who actually wrote it.

Also note that the only valid version of the GPL as far as the kernel
is concerned is _this_ particular version of the license (ie v2, not
v2.2 or v3.x or whatever), unless explicitly otherwise stated.

Linus Torvalds


-----

To sum it up, some files (which are only accompanying to the minilib itself),
do have other licensing terms, in question please look into the sources.

Minilib itself is free to use, as long as you keep the copyright notices
and the file NOTICE with your distributions.

There is no warranty, under all circumstances.

I worked thoroughly and with my best knowledge, 
but I cannot give any guarantees as a private person.

If you are in the need of another license, or individual changes,
please contact me.

misc.





