**mini-gcc** v.20210804

::


Usage: `mini-gcc [options] [gcc-options] [-o outputfile] inputfile(s).c|inputfile.conf`

mini-gcc compiles binaries and links them statically with minilib.
It's a wrapper to call gcc or clang with the right compile options,
generate the config of minilib and include minilib.h. 

In the most shorthand form, the only argument is the file,
containing the configuration directives. (And possibly the c source)

mini-gcc passes all options it's invoked with on to gcc,
besides the options described below, which must be passed 
before options and parameters for gcc.

-h, --help:
        shows this help

--version:
        version info

--license:
        shows the license (Opensource, fair use by attribution)

-v,--verbose:
        work verbosely

--config 'file':
        when the --config 'file' option is given
        mini-gcc parses the config in 'file',
        and includes the generated define switches
        into every compiled file via the gcc option -include and pipes. 
        The configfile syntax is described within the file
        'minilib.mconf', which is also a minimal configuration file
        for the hello world examples.
        When the file 'minilib.h' is not found, 
        minilib.h will be piped to gcc on the fly.

--dump-config 'file':
        Parses 'file' as configuration file, and dumps the generated
        define switches to stdout.
        Used internally, to pass the generated header via pipe to gcc

--showsources:
        Dump all used sources to the terminal 
        (gcc options -E -P)

--no-mbuf:
        When generating a config, don't write switches for the global mini_buf, 
        also don't generate the global structures for the fstream streams. 
        (Handle them as simple numeric file descriptors within the according
        minilib fstream functions)
        Without global data some initialization code can be saved,
        as well as all elf segments besides 'text'.
        Eitheradd  the line into your configfile: 'LDSCRIPT onlytext'
        Or use the switch '--ldscript onlytext'

--ldscript-file 'file':
        Uses the supplied 'file' as linker script for ld.

--dump 'var':
        Dumps the content of 'var' to stdout

--ldscript 'name':
        Either includes the according ld.script.'name' file 
        from the directory ldscripts, if existent, or extracts the according
        script and writes it into minilib.ldscript.
        This script is passed to ld with the option -T
        name can be one of:
          - onlytext     ( drop all sections beside the text segment )
          - text_and_bss ( keep also the bss segment )

--autoconf / -ac:
        This is going to generate the configuration file 'minilib.mconf'
        and compile the supplied sources with this configuration
        It is essentially the same, as calling 'mini-gcc --genconf minilib.mconf',
        and 'mini-gcc --config minilib.mconf [args]

[--force] --genconf 'outfile' 'infile1' 'infile2' ...:
        parses the sourcefiles 'infile1',.. and writes a config into
        outfile, which enables compiling of all used minilib functions
        within 'infiles'. 
        Most possibly you'll still have to edit the config manually,
        e.g. printf conversions aren't correctly recognized.
        After the config is written to outfile, 
        use the config file with --config 'outfile' 
          --force
            Overwrite existing files without warning

--shrinkelf:
        Shrink the resulting elf binary via tools/shrinkelf.
        TODO: implement proper search algorithm. 
        Prob. keep shrinkelf's sourcecode within mini-gcc (?)

--dump var:
        dump the content of 'var', if defined.

--dump-minilib:
        dump the contained headerfile minilib.h to stdout
        (if bundled within mini-gcc)

--gcc:
        The following arguments are passed unchanged to gcc.
        It's not strictly necessary, to pass this parameter;
        the first argument not recognized will do the same
        and be passed on to gcc

--exec 'sourcefile':
        Compile sourcefile to 'basename sourcefile .c';
        and execute the binary 
        (works only with embedded 'define' configuration yet) (TODO)

-mlc, --compile 'sourcefile':
        compile sourcefile, use embedded scripting config
        (same as: --config 'sourcefile' -o `basename sourcefile` 'sourcefile')

--dlog  debug log, write debug info to 'debuglog.n' (n counting up):

--compat:
        Include the provided compat headers (stdio.h,stdlib.h,...) directory 
        into the include search path.
        Using them is not recommended, they are not stable.

--fulldebug generate an outputfile (sourcefile.dbg.c) including the used parts:
        of minilib, and compile this file to sourcefile.dbg with the options
        -g2 -Og set.


---------:


The following (optional) environmental variables are used:

CC          The name and path of the compiler
CFLAGS      optional flags for the compiler
CLANG       Set this to 1 to use clang as compiler.
            (Or set CC to clang)
OPTFLAG     optimization flag (default -Os)
STRIPFLAG   stripflag (default -s)
PICFLAG     parameter -fpic/-fno-pic .. (default -fno-pic)
LDFLAG      Name of the ldscript
VERBOSE     Set this to 1 to enable verbose messages
NOCOLOR     Set this to 1 to disable colors
SHOWSOURCES Set to 1 to save all combined sources into the outputfile


\(c) 2019-2021 Michael misc Myer. All rights reserved.
 ('mini-gcc --license' shows the license)


