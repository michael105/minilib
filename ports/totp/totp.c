/*
 *  TOTP: Time-Based One-Time Password Algorithm
 *  Copyright (c) 2019, Michael Santos <michael.santos@gmail.com>
 *  Copyright (c) 2015, David M. Syzdek <david@syzdek.net>
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *     1. Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *
 *     2. Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *
 *     3. Neither the name of the copyright holder nor the names of its
 *        contributors may be used to endorse or promote products derived from
 *        this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 *  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  Keys are entered in base32 encodings
 *
 *  Compile with:  gcc -Wall -o totp totp.c -lcrypto
 */

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <hmac/hmac.h>

#if defined(RESTRICT_PROCESS_rlimit)
#include <sys/resource.h>
#include <sys/time.h>
#define RESTRICT_PROCESS "rlimit"
#define SYS_EXIT(_status) return (_status)
#elif defined(RESTRICT_PROCESS_seccomp)
#include <linux/seccomp.h>
#include <stdnoreturn.h>
#include <sys/prctl.h>
#include <syscall.h>
#define RESTRICT_PROCESS "seccomp"
static noreturn void sys_exit(int status);
#define SYS_EXIT(_status) sys_exit(_status)
#elif defined(RESTRICT_PROCESS_capsicum)
#include <sys/capsicum.h>
#include <sys/param.h>
#include <sys/resource.h>
#include <sys/types.h>
#define RESTRICT_PROCESS "capsicum"
#define SYS_EXIT(_status) return (_status)
#elif defined(RESTRICT_PROCESS_pledge)
#define RESTRICT_PROCESS "pledge"
#define SYS_EXIT(_status) return (_status)
#elif defined(RESTRICT_PROCESS_null)
#define RESTRICT_PROCESS "null"
#define SYS_EXIT(_status) return (_status)
#endif

#include "sha/sha.h"
#include "sha/sha1.c"
#include "hmac/hmac.h"
#include "hmac/hmac_sha1.c"

static const int8_t base32_vals[256] = {
    /*
         This map cheats and interprets:
            - the numeral zero as the letter "O" as in oscar
            - the numeral one as the letter "L" as in lima
            - the numeral eight as the letter "B" as in bravo

    00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F

    */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0x00 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0x10 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0x20 */
    14, 11, 26, 27, 28, 29, 30, 31, 1,  -1, -1, -1, -1, 0,  -1, -1, /* 0x30 */
    -1, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, /* 0x40 */
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, /* 0x50 */
    -1, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, /* 0x60 */
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, -1, -1, -1, -1, /* 0x70 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0x80 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0x90 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0xA0 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0xB0 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0xC0 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0xD0 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0xE0 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0xF0 */
};
/* static const char * base32_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567="; */

static int restrict_process(void);

int main(int argc, char *argv[]) {
  size_t pos;
  size_t len;
  size_t keylen;
  uint32_t endianness;
  time_t t0; /* Unix time offset to start counting time step */
  char *env_now;
  time_t now; /* Unix time */
  uint64_t x; /* step in seconds */
  uint64_t t; /* number of steps */
  uint64_t offset;
  uint8_t hmac_result[20] = {0};
  size_t hmac_result_len;
  uint32_t bin_code;
  uint32_t totp;
  uint8_t *k; /* user's secret key */
  char buf[8] = {0};
  uint8_t keybuf[32] = {0};
  char *p;

  x = 30;
  t0 = 0;

  env_now = getenv("TOTP_SECONDS");
  now = env_now == NULL ? time(NULL) : strtoll(env_now, NULL, 0);

  if (restrict_process() < 0) {
    fprintf(stderr, "error: restrict_process: %s\n", strerror(errno));
    SYS_EXIT(111);
  }

  switch (argc) {
  case 4:
    t0 = strtoll(argv[3], NULL, 0);
    /* fallthrough */
  case 3:
    x = strtoll(argv[2], NULL, 0);
    /* fallthrough */
  case 2:
    k = (uint8_t *)argv[1];
    if (k == NULL)
      SYS_EXIT(111);
    if (k[0] == '-') {
      if (read(STDIN_FILENO, keybuf, sizeof(keybuf) - 1) <= 0) {
        SYS_EXIT(128 + errno);
      }
      p = strchr((char *)keybuf, '\n');
      if (p != NULL)
        *p = '\0';
      k = keybuf;
    }
    break;

  default:
    fprintf(stderr,
            "Usage: %s <b32_key> [ <interval> [ <start> ] ]\n(using %s "
            "process restriction)\n",
            argv[0], RESTRICT_PROCESS);
    SYS_EXIT(1);
    break;
  };

  len = strlen((char *)k);

  /* validates base32 key */
  if (((len & 0xF) != 0) && ((len & 0xF) != 8)) {
    fprintf(stderr, "%s: invalid base32 secret\n", argv[0]);
    SYS_EXIT(1);
  };
  for (pos = 0; (pos < len); pos++) {
    if (base32_vals[k[pos]] == -1) {
      fprintf(stderr, "%s: invalid base32 secret\n", argv[0]);
      SYS_EXIT(1);
    };
    if (k[pos] == '=') {
      if (((pos & 0xF) == 0) || ((pos & 0xF) == 8)) {
        fprintf(stderr, "%s: invalid base32 secret\n", argv[0]);
        SYS_EXIT(1);
      }
      if ((len - pos) > 6) {
        fprintf(stderr, "%s: invalid base32 secret\n", argv[0]);
        SYS_EXIT(1);
      };
      switch (pos % 8) {
      case 2:
      case 4:
      case 5:
      case 7:
        break;

      default:
        fprintf(stderr, "%s: invalid base32 secret\n", argv[0]);
        SYS_EXIT(1);
      };
      for (; (pos < len); pos++) {
        if (k[pos] != '=') {
          fprintf(stderr, "%s: invalid base32 secret\n", argv[0]);
          SYS_EXIT(1);
        };
      };
    };
  };

  /* decodes base32 secret key */
  keylen = 0;
  for (pos = 0; pos <= (len - 8); pos += 8) {
    /* MSB is Most Significant Bits  (0x80 == 10000000 ~= MSB)
     * MB is middle bits             (0x7E == 01111110 ~= MB)
     * LSB is Least Significant Bits (0x01 == 00000001 ~= LSB)
     */

    /* byte 0 */
    k[keylen + 0] = (base32_vals[k[pos + 0]] << 3) & 0xF8;  /* 5 MSB */
    k[keylen + 0] |= (base32_vals[k[pos + 1]] >> 2) & 0x07; /* 3 LSB */
    if (k[pos + 2] == '=') {
      keylen += 1;
      break;
    };

    /* byte 1 */
    k[keylen + 1] = (base32_vals[k[pos + 1]] << 6) & 0xC0;  /* 2 MSB */
    k[keylen + 1] |= (base32_vals[k[pos + 2]] << 1) & 0x3E; /* 5  MB */
    k[keylen + 1] |= (base32_vals[k[pos + 3]] >> 4) & 0x01; /* 1 LSB */
    if (k[pos + 4] == '=') {
      keylen += 2;
      break;
    };

    /* byte 2 */
    k[keylen + 2] = (base32_vals[k[pos + 3]] << 4) & 0xF0;  /* 4 MSB */
    k[keylen + 2] |= (base32_vals[k[pos + 4]] >> 1) & 0x0F; /* 4 LSB */
    if (k[pos + 5] == '=') {
      keylen += 3;
      break;
    };

    /* byte 3 */
    k[keylen + 3] = (base32_vals[k[pos + 4]] << 7) & 0x80;  /* 1 MSB */
    k[keylen + 3] |= (base32_vals[k[pos + 5]] << 2) & 0x7C; /* 5  MB */
    k[keylen + 3] |= (base32_vals[k[pos + 6]] >> 3) & 0x03; /* 2 LSB */
    if (k[pos + 7] == '=') {
      keylen += 4;
      break;
    };

    /* byte 4 */
    k[keylen + 4] = (base32_vals[k[pos + 6]] << 5) & 0xE0;  /* 3 MSB */
    k[keylen + 4] |= (base32_vals[k[pos + 7]] >> 0) & 0x1F; /* 5 LSB */
    keylen += 5;
  };
  k[keylen] = 0;

  t = (now + t0) / x;

  /* converts T to big endian if system is little endian */
  endianness = 0xdeadbeef;
  if ((*(const uint8_t *)&endianness) == 0xef) {
    t = ((t & 0x00000000ffffffff) << 32) | ((t & 0xffffffff00000000) >> 32);
    t = ((t & 0x0000ffff0000ffff) << 16) | ((t & 0xffff0000ffff0000) >> 16);
    t = ((t & 0x00ff00ff00ff00ff) << 8) | ((t & 0xff00ff00ff00ff00) >> 8);
  };

  /* determines hash */
  hmac_result_len = sizeof(hmac_result);
  hmac_sha1(k, keylen, (const unsigned char *)&t, sizeof(t), hmac_result,
            &hmac_result_len);

  /* dynamically truncates hash */
  offset = hmac_result[19] & 0x0f;
  bin_code = (hmac_result[offset] & 0x7f) << 24 |
             (hmac_result[offset + 1] & 0xff) << 16 |
             (hmac_result[offset + 2] & 0xff) << 8 |
             (hmac_result[offset + 3] & 0xff);

  /* truncates code to 6 digits */
  totp = bin_code % 1000000;

  //snprintf(buf, sizeof(buf), "%06u\n", totp);
  //if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) < 0)
   // SYS_EXIT(128 + errno);
	 printf("%06u\n",totp);

  SYS_EXIT(0);
}

#if defined(RESTRICT_PROCESS_rlimit)
static int restrict_process() {
  struct rlimit rl_zero = {0};

  if (setrlimit(RLIMIT_NPROC, &rl_zero) < 0)
    return -1;

  if (setrlimit(RLIMIT_NOFILE, &rl_zero) < 0)
    return -1;

  return setrlimit(RLIMIT_FSIZE, &rl_zero);
}
#elif defined(RESTRICT_PROCESS_seccomp)
static int restrict_process() {
  return prctl(PR_SET_SECCOMP, SECCOMP_MODE_STRICT,0,0,0);
}

static noreturn void sys_exit(int status) {
  for (;;)
    //syscall(__NR_exit, status);
		exit(status);
}
#elif defined(RESTRICT_PROCESS_capsicum)
static int restrict_process() {
  struct rlimit rl = {0};
  cap_rights_t policy_read;
  cap_rights_t policy_write;

  if (setrlimit(RLIMIT_NPROC, &rl) < 0)
    return -1;

  (void)cap_rights_init(&policy_read, CAP_READ, CAP_EVENT, CAP_FCNTL);
  (void)cap_rights_init(&policy_write, CAP_WRITE, CAP_READ);

  if (cap_rights_limit(STDIN_FILENO, &policy_read) < 0)
    return -1;

  if (cap_rights_limit(STDOUT_FILENO, &policy_write) < 0)
    return -1;

  if (cap_rights_limit(STDERR_FILENO, &policy_write) < 0)
    return -1;

  return cap_enter();
}
#elif defined(RESTRICT_PROCESS_pledge)
static int restrict_process() { return pledge("stdio", NULL); }
#elif defined(RESTRICT_PROCESS_null)
static int restrict_process() { return 0; }
#endif
