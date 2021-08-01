bin
===

Static compiled binaries,
needed for boot/shutdown,
go here.




contents
--------

- sh: stripped down sh interpreter of busybox

- ash: stripped down ash shell of busybox
       Intended for bigger scripts, most commands are compiled into the interpreter

       Currently defined functions:
        	[, [[, ash, base64, basename, busybox, cat, chmod, chown, cksum, 
          cp, cut, date, echo, false, fsync, head, hello, id, ls, md5sum, 
          mkdir, mv, nologin, printf, pwd, rm, sed, sh, sha1sum, sha256sum, 
          sha3sum, sha512sum, shred, sleep, stat, sum, sync, tac, tail, 
          test, touch, true, uname, uniq, uuencode, wc, whoami


- bb: directory, containing busybox and symbolic links
