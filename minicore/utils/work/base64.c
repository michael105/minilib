#if 0
mini_start
mini_open
mini_close
mini_write
mini_writes
mini_ewrites
mini_read
#mini_group_printf
#mini_buf 1024
mini_GETOPTS
#LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
OPTFLAG -Os
return
#endif

struct {
	int total;
	int w;
} TT;

// base64
// original work
// Copyright 2014 Rob Landley <rob@landley.net>
// (BSD)
//
// modified 2020/12 by misc

static void wraputchar(int c, int *x)
{
  putchar(c);
  TT.total++;
  if (TT.w && ++*x == TT.w) {
    *x = 0;
    putc('\n');
  };
}


static void do_base64(int fd, char *name)
{
  int out = 0, bits = 0, x = 0, i, len;
  char *buf = toybuf+128;

  TT.total = 0;

  for (;;) {
    // If no more data, flush buffer
    if (!(len = xread(fd, buf, sizeof(toybuf)-128))) {
      if (!(toys.optflags & FLAG_d)) {
        if (bits) wraputchar(toybuf[out<<(6-bits)], &x);
        while (TT.total&3) wraputchar('=', &x);
        if (x) xputc('\n');
      }

      return;
    }

    for (i=0; i<len; i++) {
      if (toys.optflags & FLAG_d) {
        if (buf[i] == '=') return;

        if ((x = stridx(toybuf, buf[i])) != -1) {
          out = (out<<6) + x;
          bits += 6;
          if (bits >= 8) {
            putchar(out >> (bits -= 8));
            out &= (1<<bits)-1;
            if (ferror(stdout)) perror_exit(0);
          }

          continue;
        }
        if (buf[i] == '\n' || (toys.optflags & FLAG_i)) continue;

        break;
      } else {
        out = (out<<8) + buf[i];
        bits += 8;
        while (bits >= 6) {
          wraputchar(toybuf[out >> (bits -= 6)], &x);
          out &= (1<<bits)-1;
        }
      }
    }
  }
}


