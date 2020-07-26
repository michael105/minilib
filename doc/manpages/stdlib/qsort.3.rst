--------------

QSORT(3) BSD Library Functions Manual QSORT(3)

**NAME**

**qsort**, **qsort_b**, **qsort_r**, **heapsort**, **heapsort_b**,
**mergesort**, **mergesort_b** — sort functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void*

**qsort**\ (*void *base*, *size_t nmemb*, *size_t size*,
*int *\ (*\*compar*)(\ *const void *, const void \**));

*void*

**qsort_b**\ (*void *base*, *size_t nmemb*, *size_t size*,
*int *\ (*^compar*)(\ *const void *, const void \**));

*void*

**qsort_r**\ (*void *base*, *size_t nmemb*, *size_t size*,
*void *thunk*,
*int *\ (*\*compar*)(\ *void *, const void *, const void \**));

*int*

**heapsort**\ (*void *base*, *size_t nmemb*, *size_t size*,
*int *\ (*\*compar*)(\ *const void *, const void \**));

*int*

**heapsort_b**\ (*void *base*, *size_t nmemb*, *size_t size*,
*int *\ (*^compar*)(\ *const void *, const void \**));

*int*

**mergesort**\ (*void *base*, *size_t nmemb*, *size_t size*,
*int *\ (*\*compar*)(\ *const void *, const void \**));

*int*

**mergesort_b**\ (*void *base*, *size_t nmemb*, *size_t size*,
*int *\ (*^compar*)(\ *const void *, const void \**));

**DESCRIPTION**

The **qsort**\ () function is a modified partition-exchange sort, or
quicksort. The **heapsort**\ () function is a modified selection sort.
The **mergesort**\ () function is a modified merge sort with exponential
search intended for sorting data with pre-existing order.

The **qsort**\ () and **heapsort**\ () functions sort an array of
*nmemb* objects, the initial member of which is pointed to by *base*.
The size of each object is specified by *size*. The **mergesort**\ ()
function behaves similarly, but *requires* that *size* be greater than
‘‘sizeof(void \*) / 2’’.

The contents of the array *base* are sorted in ascending order according
to a comparison function pointed to by *compar*, which requires two
arguments pointing to the objects being compared.

The comparison function must return an integer less than, equal to, or
greater than zero if the first argument is considered to be respectively
less than, equal to, or greater than the second.

The **qsort_r**\ () function behaves identically to **qsort**\ (),
except that it takes an additional argument, *thunk*, which is passed
unchanged as the first argument to function pointed to *compar*. This
allows the comparison function to access additional data without using
global variables, and thus **qsort_r**\ () is suitable for use in
functions which must be reentrant. The **qsort_b**\ () function behaves
identically to **qsort**\ (), except that it takes a block, rather than
a function pointer.

The algorithms implemented by **qsort**\ (), **qsort_r**\ (), and
**heapsort**\ () are *not* stable, that is, if two members compare as
equal, their order in the sorted array is undefined. The
**heapsort_b**\ () function behaves identically to **heapsort**\ (),
except that it takes a block, rather than a function pointer. The
**mergesort**\ () algorithm is stable. The **mergesort_b**\ () function
behaves identically to **mergesort**\ (), except that it takes a block,
rather than a function pointer.

The **qsort**\ () and **qsort_r**\ () functions are an implementation of
C.A.R. Hoare’s ‘‘quicksort’’ algorithm, a variant of partition-exchange
sorting; in particular, see D.E. Knuth’s *Algorithm Q*. **Quicksort**
takes O N lg N average time. This implementation uses median selection
to avoid its O N**2 worst-case behavior.

The **heapsort**\ () function is an implementation of J.W.J. William’s
‘‘heapsort’’ algorithm, a variant of selection sorting; in particular,
see D.E. Knuth’s *Algorithm H*. **Heapsort** takes O N lg N worst-case
time. Its *only* advantage over **qsort**\ () is that it uses almost no
additional memory; while **qsort**\ () does not allocate memory, it is
implemented using recursion.

The function **mergesort**\ () requires additional memory of size *nmemb
\* size* bytes; it should be used only when space is not at a premium.
The **mergesort**\ () function is optimized for data with pre-existing
order; its worst case time is O N lg N; its best case is O N.

Normally, **qsort**\ () is faster than **mergesort**\ () is faster than
**heapsort**\ (). Memory availability and pre-existing order in the data
can make this untrue.

**RETURN VALUES**

The **qsort**\ () and **qsort_r**\ () functions return no value.

The **heapsort**\ () and **mergesort**\ () functions return the value 0
if successful; otherwise the value −1 is returned and the global
variable *errno* is set to indicate the error.

**EXAMPLES**

A sample program that sorts an array of *int* values in place using
**qsort**\ (), and then prints the sorted array to standard output is:

| #include <stdio.h>
| #include <stdlib.h>

| /\*
| \* Custom comparison function that compares ’int’ values through
  pointers
| \* passed by qsort(3).
| \*/
| static int
| int_compare(const void \*p1, const void \*p2)
| {

+-----------------------+-----------------------+-----------------------+
|                       | int left = \*(const   |                       |
|                       | int \*)p1;            |                       |
+-----------------------+-----------------------+-----------------------+
|                       | int right = \*(const  |                       |
|                       | int \*)p2;            |                       |
+-----------------------+-----------------------+-----------------------+
|                       | return ((left >       |                       |
|                       | right) - (left <      |                       |
|                       | right));              |                       |
+-----------------------+-----------------------+-----------------------+

}

| /\*
| \* Sort an array of ’int’ values and print it to standard output.
| \*/
| int
| main(void)
| {

+-----------------+-----------------+-----------------+-----------------+
|                 | int int_array[] |                 |                 |
|                 | = { 4, 5, 9, 3, |                 |                 |
|                 | 0, 1, 7, 2, 8,  |                 |                 |
|                 | 6 };            |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | size_t          |                 |                 |
|                 | array_size =    |                 |                 |
|                 | sizeof(int_arra |                 |                 |
|                 | y)              |                 |                 |
|                 | /               |                 |                 |
|                 | sizeof(int_arra |                 |                 |
|                 | y[0]);          |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | size_t k;       |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | qsort(&int_arra |                 |                 |
|                 | y,              |                 |                 |
|                 | array_size,     |                 |                 |
|                 | sizeof(int_arra |                 |                 |
|                 | y[0]),          |                 |                 |
|                 | int_compare);   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | for (k = 0; k < |                 |                 |
|                 | array_size;     |                 |                 |
|                 | k++)            |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | printf(" %d",   |                 |
|                 |                 | int_array[k]);  |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | puts("");       |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | return          |                 |                 |
|                 | (EXIT_SUCCESS); |                 |                 |
+-----------------+-----------------+-----------------+-----------------+

}

**COMPATIBILITY**

Previous versions of **qsort**\ () did not permit the comparison routine
itself to call **qsort**\ (*3*). This is no longer true.

**ERRORS**

The **heapsort**\ () and **mergesort**\ () functions succeed unless:

[EINVAL]

The *size* argument is zero, or, the *size* argument to
**mergesort**\ () is less than ‘‘sizeof(void \*) / 2’’.

[ENOMEM]

The **heapsort**\ () or **mergesort**\ () functions were unable to
allocate memory.

**SEE ALSO**

sort(1), radixsort(3)

Hoare, C.A.R.

, "

| Quicksort ", *
  The Computer Journal* ,
| 5:1 ,
| pp. 10-15 ,
| 1962 .

Williams, J.W.J

, "

| Heapsort ", *
  Communications of the ACM* ,
| 7:1 ,
| pp. 347-348 ,
| 1964 .

Knuth, D.E.

, "

| Sorting and Searching ", *
  The Art of Computer Programming* ,
| Vol. 3 ,
| pp. 114-123, 145-149 ,
| 1968 .

McIlroy, P.M.

, "

| Optimistic Sorting and Information Theoretic Complexity ", *
  Fourth Annual ACM-SIAM Symposium on Discrete Algorithms* ,
| January 1992 .

Bentley, J.L.

and

| McIlroy, M.D. , "
| Engineering a Sort Function ", *
  Software--Practice and Experience* ,
| Vol. 23(11) ,
| pp. 1249-1265 ,
| November 1993 .

**STANDARDS**

The **qsort**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

**HISTORY**

The variants of these functions that take blocks as arguments first
appeared in Mac OS X. This implementation was created by David Chisnall.

BSD February 20, 2013 BSD

--------------

.. Copyright (c) 1990, 1991, 1993
..	The Regents of the University of California.  All rights reserved.
..
.. This code is derived from software contributed to Berkeley by
.. Chris Torek and the American National Standards Committee X3,
.. on Information Processing Systems.
..
.. Redistribution and use in source and binary forms, with or without
.. modification, are permitted provided that the following conditions
.. are met:
.. 1. Redistributions of source code must retain the above copyright
..    notice, this list of conditions and the following disclaimer.
.. 2. Redistributions in binary form must reproduce the above copyright
..    notice, this list of conditions and the following disclaimer in the
..    documentation and/or other materials provided with the distribution.
.. 3. Neither the name of the University nor the names of its contributors
..    may be used to endorse or promote products derived from this software
..    without specific prior written permission.
..
.. THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
.. ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
.. IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
.. ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
.. FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
.. DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
.. OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
.. HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
.. LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
.. OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
.. SUCH DAMAGE.

