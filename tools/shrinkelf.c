/* sstrip - strip an ELF executable of as much as possible
 *
 * Modified to work with 64bit.
 * Rewrite.
 * (2019) Michael (misc) Myer misc.myer@zoho.com
 *
 * All modifications: MIT X License
 *   The original terms seem to be ok with "relicensing" the whole source 
 *   under the terms of the MIT X License.
 *   So, I do this, and state explicitely, 
 *   this file is based on work by Laurent Bercot and David Madore
 *
 
Copyright (c) 2019 Michael misc Myer, 
	2011 Laurent Bercot
	2002 David Madore
	

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

 */


/* Originally Written by David Madore <david.madore@ens.fr> */
/* Modified by Laurent Bercot <ska-skaware@skarnet.org>
   for use with skalibs */

/* First version: 2002-09-03 */
/* This version:  2011-06-28 */

/* This file is in the Public Domain -- David Madore */

/* However, I kindly request that any copy of this program that is
 * modified by someone other than myself be clearly labeled as such in
 * the comments above, and use a distinguishing tag on the version
 * string above; or else be called by some other name than
 * "superstrip". */

/* This program comes with ABSOLUTELY NO WARRANTY.  Use at your own
 * risk. */

/* This version is still in ALPHA stage of development! */

/* Syntax is: sstrip [file] */

/* [file] must be a seekable ELF file, and this is only useful for an
 * executable, possibly only for a statically linked executable.  It
 * will be copied to a temporary file, but only those parts which are
 * mapped in memory upon loading will be kept: all other data, such as
 * symbol names, section names, section tables, debugging information,
 * etc, are discarded.  Thus, this is like the "strip" operation, but
 * even more radical.  The primary author advises you to use
 * this program only in situations where disk space is extremely
 * scarce (e.g. on a floppy).  Note that this will not gain you any
 * space in memory, by definition. */

/* Some important caveats: */
/* Do not use on object files, nor on dynamic libraries with which you
 * intend to link (I mean ld-link, not run-time link), this would make
 * them useless.  Use on dynamic libraries only intended for run-time
 * link, or on dynamically linked executable, appears to work in some
 * situations, but this is by no means guaranteed (of course, nothing
 * about this program is guaranteed anyway, see above) and strongly
 * discouraged. */
/* Only 32-bit ELF is supported at the moment.  Support for 64-bit ELF
 * is intended in a future version. */
/* Only native endianness is supported.  That is, the program will
 * only treat ELF files made for a machine with the same endianness as
 * that on which it runs. */
/* This has not been extensively tested yet and many bugs are probably
 * still lurking. */


#define mini_INCLUDESRC
#define mini_buf 4096
#define mini_puts
#define mini_malloc
#define mini_start
#define mini_open

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//#include "include/open.h"

//#include "elfconv.h"
#include "elf.h"

#define DBG

#define warn(...) {fprintf(stderr,__VA_ARGS__);fputc('\n',stderr);}
#define err(...) {warn(__VA_ARGS__);exit(1);}

#ifdef DBG
#define dbg(...) warn(__VA_ARGS__)
#else
#define dbg(...) {} 
#endif

//#include "utils.c" // replace skalibs.

int allread(int fd, char *buf, int count){
		return(read(fd, buf, count));
}

int allwrite(int fd, char *buf, int count){
		return(write(fd, buf, count));
}

int fd_move (int to, int from)
{
  int r ;
  if (to == from) return 0 ;
  do
    r = dup2(from, to) ;
  while ((r == -1) && (errno == EINTR)) ;
  if (r < 0) return r ;
  close(from) ;
  return 0 ;
}

#define BUFSIZE 8192

char const *PROG = "sstrip" ;
#define USAGE "sstrip file"

#ifdef HASLITTLE_ENDIAN
#define ENDIAN 0
#else
#ifdef HASBIG_ENDIAN
#define ENDIAN 1
#else
#define ENDIAN (-1)
#endif
#endif

/* The default page size (4 kilobytes): this is for Intel - double as
 * necessary on other architectures (Sparc...) or if you get a warning
 * about alignment not being multiple of page size. */
#ifndef PAGESIZE
#define PAGESIZE 0x1000
#endif


/* FreeBSD lacks those in <elf.h> */
#ifndef ELFMAG
#define ELFMAG "\177ELF"
#endif
#ifndef SELFMAG
#define SELFMAG 4
#endif

static char const *oldname ;
static char *tmpname ;

static Elf64_Ehdr ehdr ;           /* ELF header */
static Elf64_Phdr *phdr ;          /* Program header (table) */
static Elf64_Off ph_offset ;       /* Offset of the latter in file */
static Elf64_Word ph_filesz ;      /* Size of program header table */

static int cleanup ()
{
  return unlink(tmpname) ;
}

static void read_hdrs ()
     /* Read headers from ELF file. */
{
  if (allread(0, (char *)&ehdr, sizeof(ehdr)) < sizeof(ehdr))
    err( "read ELF header in %s", oldname);

  if (memcmp(ehdr.e_ident, ELFMAG,SELFMAG))
    err("%s is not an ELF file", oldname) ;
  if (ehdr.e_ident[EI_CLASS] != ELFCLASS64){ // misc still need to add elf32 support again.
    err("%s: ELF class %d not supported", oldname, ehdr.e_ident[EI_CLASS]);
  }
  {
    char elfdata2[2] = { ELFDATA2LSB, ELFDATA2MSB } ;
   // if (ENDIAN < 0) strerr_dief1x(100, "machine endianness not supported") ;
	 /*
    if (ehdr.e_ident[EI_DATA] != elfdata2[ENDIAN])
    {
      char *what[2] = { "little", "big" } ;
      char fmt[ULONG_FMT] ;
      fmt[uint_fmt(fmt, ehdr.e_ident[EI_DATA])] = 0 ;
    //  strerr_dief6x(100, oldname, ": data encoding ", fmt, " not supported on this ", what[ENDIAN], "-endian machine") ;
    }*/
  }
  if (ehdr.e_ident[EI_VERSION] != EV_CURRENT){
    err("%s: ELF file version %d %s", oldname, ehdr.e_ident, " not supported");
  }
  if (ehdr.e_type != ET_EXEC)
    	err("not an executable" );
  if (ehdr.e_version != EV_CURRENT)
    	err("ELF version %d %s", ehdr.e_version, " not supported");
  if (ehdr.e_phoff == 0)
    	err("no program header");
  if (ehdr.e_phentsize != sizeof(Elf64_Phdr))
    	err("unexpected program header entries size: %d", ehdr.e_phentsize);
  if (ehdr.e_phnum == 0)
    err("program header has no entries");
  phdr = (Elf64_Phdr *)malloc(ehdr.e_phnum * sizeof(Elf64_Phdr)) ;
  if (!phdr)
    err("Couldn't malloc program header") ;
  if (lseek(0, ehdr.e_phoff, SEEK_SET) == -1)
    err("seek to program header undefined error" );
  if (allread(0, (char *)phdr, ehdr.e_phnum * sizeof(Elf64_Phdr)) < ehdr.e_phnum * sizeof(Elf64_Phdr))
    err("Undefined error reading program header");
  ph_offset = ehdr.e_phoff ;
  ph_filesz = ehdr.e_phentsize * ehdr.e_phnum ;
}
/* The regions in the file which are mapped in memory, _consecutive_
 * and _disjoint_. */

typedef struct region_s region, *region_ref ;
struct region_s
{
  region_ref next ;                      /* (linked list) */
  Elf64_Off offset ;                     /* Offset in input file */
  Elf64_Word filesz ;                    /* Region size (bytes) */
  Elf64_Word disp ;                      /* Input->output file displacement */
  Elf64_Off toffset ;                    /* (Target) offset in output file */
} ;

static region_ref first_region ;

static void compute_regions ()
     /* Determine which file regions are "important" (that is, contain
      * a segment or the ELF header or the program header). */
{
  long i ;

  /* i==-2 => ELF header */
  /* i==-1 => program header */
  /* i>=0 => section i */

  for (i = -2 ; i < (long)ehdr.e_phnum ; i++)
  {
    region_ref p = 0, q = first_region ;
    Elf64_Off s_offset ;
    Elf64_Word s_filesz ;

    if (i == -2)
    {
      s_offset = 0 ;
      s_filesz = sizeof(ehdr) ;
    }
    else if (i == -1)
    {
      s_offset = ph_offset ;
      s_filesz = ph_filesz ;
    }
    else
    {
      if (phdr[i].p_type == PT_NULL) continue ;
      if (phdr[i].p_align != 0 && PAGESIZE % phdr[i].p_align != 0)
        warn("%s: alignment not multiple of page size", oldname);
      s_offset = phdr[i].p_offset ;
      s_filesz = phdr[i].p_filesz ;
    }
    if (s_filesz == 0) continue ;

    /* s_offset and s_filesz contain the offset and size of a part
     * of the file that is important and should be added (if needed)
     * to the regions list. */

    while (q && (q->offset < s_offset))
    {
      p = q ;
      q = p->next ;
    }
    if (p && ((p->offset + p->filesz) >= s_offset))
    {
      /* Merge with previous region. */
      if ((s_offset + s_filesz) > (p->offset + p->filesz))
        p->filesz = s_offset - p->offset + s_filesz ;
    }
    else
    {
      region_ref t = (region_ref)malloc(sizeof(region));
      if (!t) err("Couldn't allocate region for %s", oldname);
      if (p) p->next = t ;
      else first_region = t ;
      p = t ;
      p->next = q ;
      p->offset = s_offset ;
      p->filesz = s_filesz ;
    }
    while (q && (q->offset <= (p->offset + p->filesz)))
    {
      /* Merge with next region. */
      p->next = q->next ;
      if ((q->offset + q->filesz) > (p->offset + p->filesz))
        p->filesz = q->offset - p->offset + q->filesz ;
      free(q) ;
      q = p->next ;
    }
  }
}

static void compute_disps ()
     /* Now compute displacements from input file to output file: we
      * impose them to be multiple of PAGESIZE. */
     /* (Note: this whole displacement bit seems pretty much unused,
      * complicating the program immensely; but, who knows, we may
      * find an ELF with huge unmapped sections in the middle.) */
{
  region_ref p ;
  Elf64_Word curdisp ;
  Elf64_Off curoff = 0 ;

  for (p = first_region ; p ; p = p->next)
  {
    curdisp = ((p->offset - curoff)/PAGESIZE) * PAGESIZE ;
    p->disp = curdisp ;
    p->toffset = p->offset - curdisp ;
    curoff = p->toffset + p->filesz ;
  }
}
static void modify_hdrs ()
     /* Modify ELF headers to take account of the displacement of
      * segments (and possibly the program header) and the removal of
      * section header table. */
{
  long i ;

  ehdr.e_shoff = 0 ;
  ehdr.e_shentsize = 0 ;
  ehdr.e_shnum = 0 ;
  ehdr.e_shstrndx = 0 ;
  for (i = -1 ; i < (long)ehdr.e_phnum ; i++)
  {
    region_ref p ;

    if ((i >= 0) && ((phdr[i].p_type == PT_NULL) || (phdr[i].p_filesz == 0))) continue ;
    for (p = first_region ; p ; p = p->next)
      if ((i == -1) ? ((ph_offset >= p->offset) && ((ph_offset + ph_filesz) <= (p->offset + p->filesz))) : ((phdr[i].p_offset >= p->offset) && (((phdr[i].p_offset + phdr[i].p_filesz) <= (p->offset + p->filesz)))))
        break ;
    if (!p)
      err("internal error: unable to find region for segment %d %s %s", i, " in ", oldname) ;

    if (i == -1) ehdr.e_phoff -= p->disp ;
    else phdr[i].p_offset -= p->disp ;
  }
}

static void process_file ()
     /* Now that all preliminary information has been gathered, do the
      * actual processing, copying input file to output file,
      * performing necessary skips and replacements along the way. */
{
  region_ref p ;

  /* Copy region by region... */
  for (p = first_region ; p ; p = p->next)
  {
    size_t thisoff, thisendoff ;
    size_t toread, thisread ;
    char buf[BUFSIZE] ;

    if (lseek(0, p->offset, SEEK_SET) == -1)
    {
      cleanup() ;
      err("Undefined error seeking %s", oldname) ;
    }
    if (lseek(1, p->toffset, SEEK_SET) == -1)
    {
      cleanup() ;
      err("Undefined error seeking output %s", oldname) ;
    }

    thisoff = p->offset ;
    toread = p->filesz ;
      /* ...and block by block in each region. */
    while (toread > 0)
    {
      if (toread > BUFSIZE) thisread = BUFSIZE ;
      else thisread = toread ;
      if (allread(0, buf, thisread) < thisread)
      {
        cleanup() ;
        err("Unkown error while reading") ;
      }
      thisendoff = thisoff + thisread ;
      /* Adjust for modified ELF header if necessary. */
      if (thisoff < sizeof(ehdr))
      {
        size_t posa, posb ;
        size_t len ;

        posa = thisoff ;
        posb = 0 ;
        len = sizeof(ehdr) - posa ;
        if (len > (thisread - posb)) len = thisread - posb ;
        memcpy(buf + posb, ((char *)&ehdr) + posa, len) ;
      }
      /* Adjust for modified program header if necessary. */
      if ((thisoff < (ph_offset + ph_filesz)) && (ph_offset < thisendoff))
      {
        size_t posa, posb ;
        size_t len ;

        if (thisoff < ph_offset)
        {
          posa = 0 ;
          posb = ph_offset - thisoff ;
        }
        else
        {
          posa = thisoff - ph_offset ;
          posb = 0 ;
        }
        len = ph_filesz - posa ;
        if (len > thisread - posb) len = thisread - posb ;
        memcpy(buf + posb, ((char *)phdr) + posa, len) ;
      }
      if (allwrite(1, buf, thisread) < thisread)
      {
        cleanup() ;
        err("Unkown error writing to temp file");
      }
      toread -= thisread ;
      thisoff += thisread ;
    }
  }
}

int main (int argc, char const *const *argv)
{
  if (argc < 2) err("usage: %s\n",USAGE);
  oldname = argv[1] ;

  {
    register int fdr = open(argv[1],O_CLOEXEC) ;
    if (fdr == -1)
      err( "Couldn't open ", oldname ) ;
    if (fd_move(0, fdr) == -1)
      err("move fd for ", oldname) ;
  }

  read_hdrs() ;


  compute_regions() ;

  compute_disps() ;

  modify_hdrs() ;

  {
    tmpname = malloc(strlen(oldname)+8);
    strcpy( tmpname, oldname );
		strcpy(	&tmpname[strlen(oldname)],".sstrip");
		fprintf(stdout, "stripping: %s\n",oldname);

    {
      struct stat st ;
      register int fdw ;
      if (fstat(0, &st) == -1)
        err("Unkown error stat %s", oldname) ;
      fdw = open(tmpname, O_WRONLY|O_CREAT|O_TRUNC|O_EXCL, st.st_mode & 0777) ;
      if (fdw == -1)
        err("Unkown error opening temp file %s", tmpname, " for writing") ;
     if (fd_move(1, fdw) == -1)
        err("Unkown error moving fd for %s", tmpname) ;
    }

    process_file() ;
    close(0); close(1);

    if (rename(tmpname, oldname) == -1)
    {
      cleanup() ;
      err("Unkown error renaming %s %s %s", tmpname, " into ", oldname) ;
    }
   /* stralloc_free(&sa) ; */
  }
  return 0 ;
}
