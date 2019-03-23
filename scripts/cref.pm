$headerdict = {
            'locale.h' => [
                            'setlocale'
                          ],
            'errno.h' => [
                           'errno'
                         ],
            'math.h' => [
                          'acos',
                          'asin',
                          'atan',
                          'atan2',
                          'ceil',
                          'cos',
                          'cosh',
                          'exp',
                          'fabs',
                          'floor',
                          'fmod',
                          'frexp',
                          'ldexp',
                          'log',
                          'log10',
                          'modf',
                          'pow',
                          'sin',
                          'sinh',
                          'sqrt',
                          'tan',
                          'tanh',
                          ''
                        ],
            'stdio.h' => [
                           'clearerr',
                           'fclose',
                           'feof',
                           'fflush',
                           'fgetc',
                           'fgetpos',
                           'fgets',
                           'fopen',
                           'fprintf',
                           'fputc',
                           'fputs',
                           'fread',
                           'freopen',
                           'fscanf',
                           'fseek',
                           'fsetpos',
                           'ftell',
                           'fwrite',
                           'getc',
                           'getchar',
                           'gets',
                           'perror',
                           'printf',
                           'putchar',
                           'puts',
                           'remove',
                           'rewind',
                           'scanf',
                           'setbuf',
                           'setvbuf',
                           'sprintf',
                           'sscanf',
                           'tmpfile',
                           'tmpnam',
                           'ungetc',
                           'vfprintf',
                           'vprintf',
                           'vsprintf'
                         ],
            'string.h' => [
                            'memchr',
                            'memcmp',
                            'memcpy',
                            'memmove',
                            'memset',
                            'strcat',
                            'strchr',
                            'strcmp',
                            'strcoll',
                            'strcpy',
                            'strcspn',
                            'strerror',
                            'strlen',
                            'strncat',
                            'strncmp',
                            'strncpy',
                            'strpbrk',
                            'strrchr',
                            'strspn',
                            'strstr',
                            'strtok',
                            'strxfrm'
                          ],
            'ctype.h' => [
                           'isalnum',
                           'isalpha',
                           'iscntrl',
                           'isdigit',
                           'isgraph',
                           'islower',
                           'isprint',
                           'ispunct',
                           'isspace',
                           'isupper',
                           'isxdigit',
                           'toupper',
                           'tolower'
                         ],
            'conio.h' => [
                           'clrscr',
                           'getch',
                           'getche',
                           'Non'
                         ],
            'setjmp.h' => [
                            'setjmp',
                            'longjmp'
                          ],
            'signal.h' => [
                            'signal',
                            'raise'
                          ],
            'stdarg.h' => [
                            'va_start',
                            'va_arg',
                            'va_end'
                          ],
            'stdlib.h' => [
                            'abort',
                            'abs',
                            'atexit',
                            'atof',
                            'atoi',
                            'atol',
                            'bsearch',
                            'calloc',
                            'div',
                            'exit',
                            'getenv',
                            'free',
                            'labs',
                            'ldiv',
                            'malloc',
                            'mblen',
                            'mbstowcs',
                            'mbtowc',
                            'qsort',
                            'rand',
                            'realloc',
                            'strtod',
                            'strtol',
                            'strtoul',
                            'srand',
                            'system',
                            'wctomb',
                            'wcstombs'
                          ],
            'dirent.h' => [
                            'opendir',
                            'closedir',
                            'readdir',
                            'rewinddir',
                            'scandir',
                            'seekdir',
                            'telldir',
                            'statfs'
                          ],
            'time.h' => [
                          'asctime',
                          'clock',
                          'ctime',
                          'difftime',
                          'gmtime',
                          'localtime',
                          'mktime',
                          'strftime',
                          'time',
                          'Example',
                          'POSIX'
                        ],
            'unistd.h' => [
                            'access',
                            'alarm',
                            'chdir',
                            'chown',
                            'close',
                            'chroot',
                            'ctermid',
                            'cuserid',
                            'dup',
                            'dup2',
                            'execl',
                            'execle',
                            'execlp',
                            'execv',
                            'execve',
                            'execvp',
                            'fchdir',
                            'fork',
                            'fpathconf',
                            'getegid',
                            'geteuid',
                            'gethostname',
                            'getopt,',
                            'getgid',
                            'getgroups',
                            'getlogin',
                            'getpgrp',
                            'getpid',
                            'getppid,',
                            'getuid',
                            'isatty',
                            'link',
                            'lseek',
                            'mkdir',
                            'open',
                            'pathconf',
                            'pause',
                            'pipe',
                            'read',
                            'rename',
                            'rmdir',
                            'setgid',
                            'setpgid',
                            'setsid',
                            'setuid',
                            'sleep',
                            'sysconf',
                            'tcgetpgrp',
                            'tcsetpgrp',
                            'ttyname',
                            'unlink',
                            'write',
                            'Ungrouped'
                          ],
            'assert.h' => [
                            'assert'
                          ]
          };
$functiondict = {
              'setgid' => {
                            'desc' => 'Set the Group ID of the process.  ',
                            'header' => 'unistd.h'
                          },
              'geteuid' => {
                             'header' => 'unistd.h',
                             'desc' => 'Get the User ID of the process.  '
                           },
              'read' => {
                          'header' => 'unistd.h',
                          'desc' => 'Read a file descriptor.  '
                        },
              'printf' => {
                            'desc' => 'O/P data to the screen or a file.  ',
                            'header' => 'stdio.h'
                          },
              'setbuf' => {
                            'header' => 'stdio.h',
                            'desc' => ' '
                          },
              'alarm' => {
                           'desc' => ' ',
                           'header' => 'unistd.h'
                         },
              'ttyname' => {
                             'header' => 'unistd.h',
                             'desc' => ' '
                           },
              'fmod' => {
                          'desc' => 'floating-point remainder function  ',
                          'header' => 'math.h'
                        },
              'strlen' => {
                            'desc' => 'Length of a string.  ',
                            'header' => 'string.h'
                          },
              'fflush' => {
                            'header' => 'stdio.h',
                            'desc' => ' '
                          },
              'free' => {
                          'header' => 'stdlib.h',
                          'desc' => 'memory allocated with malloc.  '
                        },
              'cuserid' => {
                             'desc' => ' ',
                             'header' => 'unistd.h'
                           },
              'strrchr' => {
                             'header' => 'string.h',
                             'desc' => 'Search for a character in a string.  '
                           },
              'isdigit' => {
                             'desc' => 'Checks whether a character is a digit (0-9)  ',
                             'header' => 'ctype.h'
                           },
              'fgetc' => {
                           'header' => 'stdio.h',
                           'desc' => 'Read a character from a file.  '
                         },
              'tmpnam' => {
                            'header' => 'stdio.h',
                            'desc' => ' '
                          },
              'fsetpos' => {
                             'desc' => ' ',
                             'header' => 'stdio.h'
                           },
              'assert' => {
                            'desc' => ' ',
                            'header' => 'assert.h'
                          },
              'tcgetpgrp' => {
                               'desc' => ' ',
                               'header' => 'unistd.h'
                             },
              'wctomb' => {
                            'header' => 'stdlib.h',
                            'desc' => 'convert a wide character to a multibyte character.  '
                          },
              'memchr' => {
                            'desc' => 'Copy a character into memory.  ',
                            'header' => 'string.h'
                          },
              'lseek' => {
                           'header' => 'unistd.h',
                           'desc' => ' '
                         },
              'fputc' => {
                           'desc' => 'Put a charater into a file.  ',
                           'header' => 'stdio.h'
                         },
              'strtol' => {
                            'header' => 'stdlib.h',
                            'desc' => 'String to long integer conversion. Takes data in various number bases.  '
                          },
              'sscanf' => {
                            'desc' => 'Extract fields from a string.  ',
                            'header' => 'stdio.h'
                          },
              'pipe' => {
                          'desc' => ' ',
                          'header' => 'unistd.h'
                        },
              'va_arg' => {
                            'header' => 'stdarg.h',
                            'desc' => ' '
                          },
              'va_start' => {
                              'header' => 'stdarg.h',
                              'desc' => ' '
                            },
              'getch' => {
                           'header' => 'conio.h',
                           'desc' => 'Get a character from the keyboard.  '
                         },
              'ctermid' => {
                             'desc' => ' ',
                             'header' => 'unistd.h'
                           },
              'Non' => {
                         'header' => 'conio.h',
                         'desc' => ''
                       },
              '' => {
                      'header' => 'math.h',
                      'desc' => ''
                    },
              'feof' => {
                          'header' => 'stdio.h',
                          'desc' => 'Check for EOF while reading a file.  '
                        },
              'strtoul' => {
                             'header' => 'stdlib.h',
                             'desc' => 'Convert a string to an unsigned long. This can also perform number base conversion.  '
                           },
              'clock' => {
                           'header' => 'time.h',
                           'desc' => ' '
                         },
              'isgraph' => {
                             'desc' => 'Checks whether a character is a printable character, excluding the space (decimal 32)  ',
                             'header' => 'ctype.h'
                           },
              'execv' => {
                           'header' => 'unistd.h',
                           'desc' => ' '
                         },
              'clrscr' => {
                            'header' => 'conio.h',
                            'desc' => 'Clear screen  '
                          },
              'modf' => {
                          'desc' => ' ',
                          'header' => 'math.h'
                        },
              'bsearch' => {
                             'desc' => 'Binary chop.  ',
                             'header' => 'stdlib.h'
                           },
              'frexp' => {
                           'header' => 'math.h',
                           'desc' => ' '
                         },
              'rewind' => {
                            'header' => 'stdio.h',
                            'desc' => ' '
                          },
              'ispunct' => {
                             'desc' => 'Checks whether a character is punctuation (decimal 32-47, 58-63, 91-96, 123-126)  ',
                             'header' => 'ctype.h'
                           },
              'atof' => {
                          'header' => 'stdlib.h',
                          'desc' => 'convert a string to a double  '
                        },
              'cos' => {
                         'header' => 'math.h',
                         'desc' => 'Cosine. '
                       },
              'tolower' => {
                             'header' => 'ctype.h',
                             'desc' => 'Convert an uppercase character to lowercase.  '
                           },
              'cosh' => {
                          'desc' => ' ',
                          'header' => 'math.h'
                        },
              'strcspn' => {
                             'desc' => ' ',
                             'header' => 'string.h'
                           },
              'atexit' => {
                            'desc' => 'Execute the named function when the program terminates.  ',
                            'header' => 'stdlib.h'
                          },
              'POSIX' => {
                           'desc' => '',
                           'header' => 'time.h'
                         },
              'fscanf' => {
                            'desc' => ' ',
                            'header' => 'stdio.h'
                          },
              'freopen' => {
                             'header' => 'stdio.h',
                             'desc' => ' '
                           },
              'atoi' => {
                          'header' => 'stdlib.h',
                          'desc' => 'Accepts +-0123456789 leading blanks and converts to integer.  '
                        },
              'getgid' => {
                            'header' => 'unistd.h',
                            'desc' => 'Get a group ID.  '
                          },
              'asctime' => {
                             'header' => 'time.h',
                             'desc' => ' '
                           },
              'execl' => {
                           'header' => 'unistd.h',
                           'desc' => ' '
                         },
              'fwrite' => {
                            'header' => 'stdio.h',
                            'desc' => ' '
                          },
              'rename' => {
                            'header' => 'unistd.h',
                            'desc' => 'Rename a file. This function can also be found in the ANSI stdio library. MAN PAGE.  '
                          },
              'longjmp' => {
                             'header' => 'setjmp.h',
                             'desc' => ' '
                           },
              'asin' => {
                          'header' => 'math.h',
                          'desc' => ' '
                        },
              'ftell' => {
                           'header' => 'stdio.h',
                           'desc' => ' '
                         },
              'strtod' => {
                            'header' => 'stdlib.h',
                            'desc' => 'Convert a string to a double.  '
                          },
              'memcpy' => {
                            'header' => 'string.h',
                            'desc' => 'Copy memory.  '
                          },
              'exp' => {
                         'header' => 'math.h',
                         'desc' => ' '
                       },
              'floor' => {
                           'desc' => 'largest integral value not greater than x  ',
                           'header' => 'math.h'
                         },
              'fclose' => {
                            'header' => 'stdio.h',
                            'desc' => 'Close a file.  '
                          },
              'fabs' => {
                          'desc' => 'absolute value of floating-point number  ',
                          'header' => 'math.h'
                        },
              'strstr' => {
                            'header' => 'string.h',
                            'desc' => 'Search a string for a substring.  '
                          },
              'mbstowcs' => {
                              'header' => 'stdlib.h',
                              'desc' => 'convert a multibyte string to a wide character string.  '
                            },
              'dup' => {
                         'desc' => 'duplicate a file descriptor  ',
                         'header' => 'unistd.h'
                       },
              'strncmp' => {
                             'header' => 'string.h',
                             'desc' => 'Compare two strings.  '
                           },
              'strcpy' => {
                            'header' => 'string.h',
                            'desc' => 'Copy strings.  '
                          },
              'sprintf' => {
                             'header' => 'stdio.h',
                             'desc' => 'O/P data in tha same way as \'printf\' but put it into a string.  '
                           },
              'setjmp' => {
                            'desc' => ' ',
                            'header' => 'setjmp.h'
                          },
              'setuid' => {
                            'header' => 'unistd.h',
                            'desc' => 'Set the User ID of the process.  '
                          },
              'execlp' => {
                            'desc' => ' ',
                            'header' => 'unistd.h'
                          },
              'memmove' => {
                             'desc' => 'Move memory.  ',
                             'header' => 'string.h'
                           },
              'atan' => {
                          'header' => 'math.h',
                          'desc' => ' '
                        },
              'tcsetpgrp' => {
                               'desc' => ' ',
                               'header' => 'unistd.h'
                             },
              'vfprintf' => {
                              'desc' => 'O/P a va_list to a file.  ',
                              'header' => 'stdio.h'
                            },
              'strncpy' => {
                             'desc' => 'Copy part of a string.  ',
                             'header' => 'string.h'
                           },
              'execvp' => {
                            'header' => 'unistd.h',
                            'desc' => ' '
                          },
              'strxfrm' => {
                             'header' => 'string.h',
                             'desc' => ' '
                           },
              'log10' => {
                           'header' => 'math.h',
                           'desc' => ' '
                         },
              'strftime' => {
                              'header' => 'time.h',
                              'desc' => ' '
                            },
              'tanh' => {
                          'desc' => 'Hyperbolic tangent. ',
                          'header' => 'math.h'
                        },
              'opendir' => {
                             'header' => 'dirent.h',
                             'desc' => 'Open a directory.  '
                           },
              'tan' => {
                         'desc' => 'Tangent. ',
                         'header' => 'math.h'
                       },
              'fpathconf' => {
                               'header' => 'unistd.h',
                               'desc' => 'Change the current working directory.I am not 100% sure this is supposed to be in unistd.  '
                             },
              'time' => {
                          'header' => 'time.h',
                          'desc' => ' '
                        },
              'strchr' => {
                            'desc' => 'Search for a character in a string.  ',
                            'header' => 'string.h'
                          },
              'iscntrl' => {
                             'header' => 'ctype.h',
                             'desc' => 'Checks whether a character is a control character or delete ( decimal 0-31 and 127)  '
                           },
              'localtime' => {
                               'header' => 'time.h',
                               'desc' => ' '
                             },
              'setpgid' => {
                             'desc' => ' ',
                             'header' => 'unistd.h'
                           },
              'link' => {
                          'desc' => ' ',
                          'header' => 'unistd.h'
                        },
              'fork' => {
                          'header' => 'unistd.h',
                          'desc' => 'Create a child process.  '
                        },
              'islower' => {
                             'header' => 'ctype.h',
                             'desc' => 'Checks whether a character is a lower case letter (a-z).  '
                           },
              'fprintf' => {
                             'desc' => 'O/P a line of data to a file.  ',
                             'header' => 'stdio.h'
                           },
              'sysconf' => {
                             'header' => 'unistd.h',
                             'desc' => ' '
                           },
              'getlogin' => {
                              'header' => 'unistd.h',
                              'desc' => ' '
                            },
              'seekdir' => {
                             'desc' => 'Move to an offset in a directory.  ',
                             'header' => 'dirent.h'
                           },
              'pathconf' => {
                              'desc' => ' ',
                              'header' => 'unistd.h'
                            },
              'getuid' => {
                            'header' => 'unistd.h',
                            'desc' => 'Get the User ID of the process.  '
                          },
              'srand' => {
                           'header' => 'stdlib.h',
                           'desc' => 'Seed a random number.  '
                         },
              'raise' => {
                           'desc' => ' ',
                           'header' => 'signal.h'
                         },
              'getopt,' => {
                             'header' => 'unistd.h',
                             'desc' => 'parse the command line Not 100% sure this is in unistd.  '
                           },
              'gmtime' => {
                            'header' => 'time.h',
                            'desc' => ' '
                          },
              'pow' => {
                         'header' => 'math.h',
                         'desc' => 'Raise a number by a power.  '
                       },
              'closedir' => {
                              'desc' => 'Close a directory.  ',
                              'header' => 'dirent.h'
                            },
              'execve' => {
                            'desc' => ' ',
                            'header' => 'unistd.h'
                          },
              'mktime' => {
                            'desc' => ' ',
                            'header' => 'time.h'
                          },
              'setsid' => {
                            'desc' => ' ',
                            'header' => 'unistd.h'
                          },
              'mbtowc' => {
                            'header' => 'stdlib.h',
                            'desc' => 'convert a multibyte character to a wide character  '
                          },
              'chown' => {
                           'desc' => 'Change the ownership of a file.  ',
                           'header' => 'unistd.h'
                         },
              'pause' => {
                           'header' => 'unistd.h',
                           'desc' => 'Put the program to sleep.  '
                         },
              'putchar' => {
                             'desc' => 'O/P a character to STDOUT.  ',
                             'header' => 'stdio.h'
                           },
              'rewinddir' => {
                               'header' => 'dirent.h',
                               'desc' => 'Return to the beginning of a directory.  '
                             },
              'log' => {
                         'desc' => ' ',
                         'header' => 'math.h'
                       },
              'calloc' => {
                            'header' => 'stdlib.h',
                            'desc' => 'memory for an array.  '
                          },
              'exit' => {
                          'desc' => 'Normally terminate a program.  ',
                          'header' => 'stdlib.h'
                        },
              'errno' => {
                           'desc' => ' ',
                           'header' => 'errno.h'
                         },
              'access' => {
                            'header' => 'unistd.h',
                            'desc' => ' '
                          },
              'gethostname' => {
                                 'header' => 'unistd.h',
                                 'desc' => 'Name of the host (see uname ). Not 100% sure this is in unistd  '
                               },
              'execle' => {
                            'desc' => ' ',
                            'header' => 'unistd.h'
                          },
              'mkdir' => {
                           'header' => 'unistd.h',
                           'desc' => 'Make a directory  '
                         },
              'chroot' => {
                            'header' => 'unistd.h',
                            'desc' => 'Change the root directory I am not 100% sure this is supposed to be in unistd.  '
                          },
              'vsprintf' => {
                              'header' => 'stdio.h',
                              'desc' => 'O/P a va_list to a string.  '
                            },
              'clearerr' => {
                              'desc' => ' ',
                              'header' => 'stdio.h'
                            },
              'getc' => {
                          'header' => 'stdio.h',
                          'desc' => 'Get a character from an input stream.  '
                        },
              'isupper' => {
                             'header' => 'ctype.h',
                             'desc' => 'Checks whether a character is an upper case letter (A-Z).  '
                           },
              'setlocale' => {
                               'header' => 'locale.h',
                               'desc' => ' '
                             },
              'setvbuf' => {
                             'desc' => ' ',
                             'header' => 'stdio.h'
                           },
              'fgets' => {
                           'header' => 'stdio.h',
                           'desc' => 'Read a record from a file (safer than fgetc).  '
                         },
              'atan2' => {
                           'header' => 'math.h',
                           'desc' => ' '
                         },
              'strspn' => {
                            'header' => 'string.h',
                            'desc' => ' '
                          },
              'fgetpos' => {
                             'desc' => ' ',
                             'header' => 'stdio.h'
                           },
              'open' => {
                          'desc' => 'Open a file  ',
                          'header' => 'unistd.h'
                        },
              'getchar' => {
                             'desc' => 'Get a character from the keyboard (STDIN).  ',
                             'header' => 'stdio.h'
                           },
              'telldir' => {
                             'header' => 'dirent.h',
                             'desc' => 'Return the location within a directory.  '
                           },
              'tmpfile' => {
                             'desc' => ' ',
                             'header' => 'stdio.h'
                           },
              'isxdigit' => {
                              'desc' => 'Checks whether a character is hex digit (0-9, A-F, a-f).  ',
                              'header' => 'ctype.h'
                            },
              'ctime' => {
                           'desc' => ' ',
                           'header' => 'time.h'
                         },
              'getenv' => {
                            'desc' => 'Get an environmental variable.  ',
                            'header' => 'stdlib.h'
                          },
              'dup2' => {
                          'desc' => 'duplicate a file descriptor  ',
                          'header' => 'unistd.h'
                        },
              'close' => {
                           'desc' => 'Close a file (see low level functions ',
                           'header' => 'unistd.h'
                         },
              'fseek' => {
                           'desc' => ' ',
                           'header' => 'stdio.h'
                         },
              'ungetc' => {
                            'desc' => ' ',
                            'header' => 'stdio.h'
                          },
              'fputs' => {
                           'desc' => 'Put a string into a file.  ',
                           'header' => 'stdio.h'
                         },
              'isspace' => {
                             'header' => 'ctype.h',
                             'desc' => 'Checks whether a character is white space - space, CR HT VT NL, FF.  '
                           },
              'getgroups' => {
                               'desc' => ' ',
                               'header' => 'unistd.h'
                             },
              'fread' => {
                           'desc' => ' ',
                           'header' => 'stdio.h'
                         },
              'memset' => {
                            'header' => 'string.h',
                            'desc' => 'Set memory.  '
                          },
              'Example' => {
                             'desc' => 'program using some of the time functions.  ',
                             'header' => 'time.h'
                           },
              'strcmp' => {
                            'header' => 'string.h',
                            'desc' => 'Compare strings.  '
                          },
              'rmdir' => {
                           'desc' => 'Remove a directory  ',
                           'header' => 'unistd.h'
                         },
              'remove' => {
                            'desc' => 'Remove a file.  ',
                            'header' => 'stdio.h'
                          },
              'getche' => {
                            'header' => 'conio.h',
                            'desc' => 'Get a character from the keyboard.  '
                          },
              'isalpha' => {
                             'desc' => ' ',
                             'header' => 'ctype.h'
                           },
              'write' => {
                           'header' => 'unistd.h',
                           'desc' => 'Write to a file descriptor.  '
                         },
              'gets' => {
                          'desc' => 'Get string (from keyboard).  ',
                          'header' => 'stdio.h'
                        },
              'memcmp' => {
                            'desc' => 'Compare memory locations.  ',
                            'header' => 'string.h'
                          },
              'rand' => {
                          'header' => 'stdlib.h',
                          'desc' => 'Generate a random number.  '
                        },
              'realloc' => {
                             'desc' => 'Reallocate memory.  ',
                             'header' => 'stdlib.h'
                           },
              'strpbrk' => {
                             'header' => 'string.h',
                             'desc' => ' '
                           },
              'Ungrouped' => {
                               'desc' => '',
                               'header' => 'unistd.h'
                             },
              'perror' => {
                            'desc' => ' ',
                            'header' => 'stdio.h'
                          },
              'malloc' => {
                            'desc' => 'dynamically allocate memory.  ',
                            'header' => 'stdlib.h'
                          },
              'mblen' => {
                           'header' => 'stdlib.h',
                           'desc' => 'determine the number of bytes in a character  '
                         },
              'qsort' => {
                           'desc' => 'Sort an array.  ',
                           'header' => 'stdlib.h'
                         },
              'isprint' => {
                             'header' => 'ctype.h',
                             'desc' => 'Checks whether a character is printable (decimal 32-126).  '
                           },
              'ldiv' => {
                          'header' => 'stdlib.h',
                          'desc' => 'compute the quotient and remainder of long integer division.  '
                        },
              'getpid' => {
                            'header' => 'unistd.h',
                            'desc' => 'get process ID.  '
                          },
              'chdir' => {
                           'header' => 'unistd.h',
                           'desc' => 'Change the current working directory.  '
                         },
              'signal' => {
                            'header' => 'signal.h',
                            'desc' => ' '
                          },
              'wcstombs' => {
                              'header' => 'stdlib.h',
                              'desc' => 'convert a wide character string to a multibyte character string.  '
                            },
              'strcat' => {
                            'desc' => 'Concatinate two strings.  ',
                            'header' => 'string.h'
                          },
              'toupper' => {
                             'header' => 'ctype.h',
                             'desc' => 'Converts a lowercase character to uppercase.  '
                           },
              'fopen' => {
                           'desc' => 'Open a file  ',
                           'header' => 'stdio.h'
                         },
              'scanf' => {
                           'header' => 'stdio.h',
                           'desc' => ' '
                         },
              'unlink' => {
                            'header' => 'unistd.h',
                            'desc' => 'Remove a file  '
                          },
              'system' => {
                            'desc' => 'Issue a command to the operating system  ',
                            'header' => 'stdlib.h'
                          },
              'fchdir' => {
                            'desc' => 'Change the current working directory.I am not 100% sure this is supposed to be in unistd.  ',
                            'header' => 'unistd.h'
                          },
              'sleep' => {
                           'header' => 'unistd.h',
                           'desc' => 'Pause for a required number of seconds.  '
                         },
              'difftime' => {
                              'desc' => ' ',
                              'header' => 'time.h'
                            },
              'ceil' => {
                          'header' => 'math.h',
                          'desc' => 'smallest integral value not less than x  '
                        },
              'scandir' => {
                             'header' => 'dirent.h',
                             'desc' => 'Scan a directory for a matching entry.  '
                           },
              'statfs' => {
                            'header' => 'dirent.h',
                            'desc' => 'Filesystem statistics.  '
                          },
              'labs' => {
                          'desc' => 'compute the absolute value of a long integer  ',
                          'header' => 'stdlib.h'
                        },
              'vprintf' => {
                             'header' => 'stdio.h',
                             'desc' => 'O/P a va_list to stdout.  '
                           },
              'abs' => {
                         'header' => 'stdlib.h',
                         'desc' => 'compute the absolute value of an integer.  '
                       },
              'isatty' => {
                            'desc' => ' ',
                            'header' => 'unistd.h'
                          },
              'getppid,' => {
                              'desc' => 'get parent process ID.  ',
                              'header' => 'unistd.h'
                            },
              'sqrt' => {
                          'desc' => 'Square root of a number.  ',
                          'header' => 'math.h'
                        },
              'getpgrp' => {
                             'header' => 'unistd.h',
                             'desc' => ' '
                           },
              'sin' => {
                         'desc' => 'The sine of an integer.  ',
                         'header' => 'math.h'
                       },
              'isalnum' => {
                             'header' => 'ctype.h',
                             'desc' => 'Checks whether a character is alphanumeric (A-Z, a-z, 0-9)  '
                           },
              'sinh' => {
                          'desc' => ' ',
                          'header' => 'math.h'
                        },
              'va_end' => {
                            'header' => 'stdarg.h',
                            'desc' => ' '
                          },
              'strncat' => {
                             'desc' => 'Concatinate two strings.  ',
                             'header' => 'string.h'
                           },
              'getegid' => {
                             'header' => 'unistd.h',
                             'desc' => 'Get the group ID of the process.  '
                           },
              'strtok' => {
                            'header' => 'string.h',
                            'desc' => 'The books say this function splits a string into tokens. I think its function is best described as parsing a string.  '
                          },
              'readdir' => {
                             'desc' => 'Read a directory entry.  ',
                             'header' => 'dirent.h'
                           },
              'atol' => {
                          'header' => 'stdlib.h',
                          'desc' => 'convert a string to a long integer  '
                        },
              'puts' => {
                          'header' => 'stdio.h',
                          'desc' => 'O/P data to the screen or a file.  '
                        },
              'abort' => {
                           'desc' => 'a program.  ',
                           'header' => 'stdlib.h'
                         },
              'strcoll' => {
                             'desc' => ' ',
                             'header' => 'string.h'
                           },
              'div' => {
                         'desc' => 'compute the quotient and remainder of integer division  ',
                         'header' => 'stdlib.h'
                       },
              'acos' => {
                          'desc' => ' ',
                          'header' => 'math.h'
                        },
              'ldexp' => {
                           'header' => 'math.h',
                           'desc' => ' '
                         },
              'strerror' => {
                              'header' => 'string.h',
                              'desc' => ' '
                            }
            };
