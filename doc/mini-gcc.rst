**mini-gcc** v.GIT 2020-06-08 11:51:39

::


Usage: `mini-gcc [options] [gcc-options] -o outputfile inputfile(s).c`

mini-gcc compiles binaries and links them statically with minilib.
It's a wrapper to call gcc with the right compile options,
generate the config of minilib and include minilib.h. 

mini-gcc passes all options it's invoked with on to gcc,
besides the options described below, which must be passed 
before options and parameters for gcc.

-h, --help:
        shows this help

--version:
        version info

--license:
        shows the license (BSD 3-clause)

-v,--verbose:
        work verbosely

--config 'file':
        when the --config 'file' option is given
        mini-gcc also parses the config in 'file',
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
        within 'infiles'
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


\(c) 2019-2020 Michael misc Myer - BSD 3-clause
 ('mini-gcc --license' shows the terms)


