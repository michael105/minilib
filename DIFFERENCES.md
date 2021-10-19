### Differences and addons to other libc's



- errno is optional (Switch mini_errno)
  When errno isn't compiled (faster syscalls, branching is not neccesary
  for setting errno, one global less), 
  all syscalls do return on error the negative errno code;
  on success 0 or a positive value.
```
 if ( (ret = read(0,buf,64)) < 0 )
 	die( ret, "Couldn't read from stdin" );
```

- streams
  there is no buffering yet, besides the global buffer used for printf, et al.
  (Not threadsafe)

- argument parsing
  There is the posix getopt function available (mini_getopt), written by skeeto.
  Besides, there is the macro PARSEOPTS_short (mini_PARSEOPTS_short),
  which aims for size optimization.

- die(errno,msg)
  exit with errno. Write msg to stderr. When /bin/errno is present,
  write a verbose error message to stderr. Else the error code is written.

- dies(errno, ... ) / dief(errno,fmt,...)
  alanog to die, but also call eprints / eprintf with the parameters.

- die_if( when, errno, msg ) / dief_if( when, errnum, fmt, ... ) / dies_if( when, errnum, ... )
  if "when" is true, die with errno / call dies or dief.

- writes family
  writes(s), writesl(s),erites(s) and ewritesl(s) all write to stdout/stderr(ewrite).
  The string s has to be fixed, the len of s is determined at compile time via the macro
  sizeof(s). writesl/ewritesl append a linebreak to the output.

- prints(s1,s2,..) /printsl, eprint/eprintsl
  write to stdout/stderr, variable size of the strings, 
  and variable count of arguments. the ..l versions also append a linebreak.

- printfs(fmt,...), eprintfs(fmt,...), fprintfs(stream,fmt,...)
  write fmt and formatted arguments to stdout/stderr/stream.
  only %s and %c are recognized. 
  (Saves a few bytes, the global output buffer isn't needed, 
  and the output can be optimized)



