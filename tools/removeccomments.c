#if 0
# config generated by mini-gcc.
# Save default. The minibuf is needed for malloc, printf, and file streams.
mini_buf 1024

# define headerguards, to prevent parsing the standard header
HEADERGUARDS

# Startup function
mini_start

# optimization Flag. Os,O1,O2 might be save. O3 is known to cause sometimes trouble
OPTFLAG -Os

# (with debug info)
#OPTFLAG -g -O0

# stripflag ( defaults to -s)
#STRIPFLAG

# Build minilib source
INCLUDESRC

# the ldscript to use
# Can be one of: default, onlytext, textandbss
LDSCRIPT default

# Shrink the compiled binary with shrinkelf
SHRINKELF

# generate debug info (-O0 -g). Overwrites OPTFLAG, STRIPFLAG and SHRINKELF
#DEBUG


# function switches. Only functions named below will be compiled

mini_fprintf
mini_putchar
mini_puts
mini_read
mini_sprintf

return
#endif

/* Author:  qeatzy
 * Create:  2018-11-29
 * Revision:2018-11-30
 * state:   final. tested with cpython code, work correctly and fast.
 */ 
#include <stdio.h>
#include <unistd.h> // read

#define SEGSIZE 4096
#define BUFSIZE ((int)1e6)
char filebuf[BUFSIZE];
#define MAXLINECOUNT ((int)5e5)
struct {
    char /*atest*/ *p;
    int n;
} lines[MAXLINECOUNT];

#ifndef DEBUG
#define pf(...) ;
#define pline(xxx,yyy) ;
#else
#define pf printf
void pline(const char *ptr, int len) {
    if (ptr == NULL) { puts("empty line"); return; }
    for (int i = 0; i < len; i++) putchar(ptr[i]);
    putchar('\n');
}
#endif

int readfile(int fd, char **filebuf) {
    if (filebuf == NULL || *filebuf == NULL) return 0;
    int total = 0, n;
    char *buf = *filebuf;
    /* while ((n = fread(buf,1,SEGSIZE,stream)) > 0) { */
    while ((n = read(fd,buf,SEGSIZE)) > 0) {
        total += n, buf += n;
        if (total > BUFSIZE) {
            fprintf(stderr, "error: file larger %d\n", BUFSIZE);
            return -1;
        }
    }
    return total;
}

int match_quote(const char *ptr, int *pos, int len) {
    /* pf("match_quote: pos,len = %d %d\n", *pos, len); */
    int ret = 0, j = *pos;
    while (j < len) {
        while (ptr[j] != '"' && j < len) j++;
        if (j < len) {
            j++;
            if (ptr[j-2] == '\\') continue;
            else { ret = 1; break; }
        }
    }
    *pos = j;
    /* if (ret) pf("match_quote succeeded\n"); */
    return ret;
}

int match_cms(const char *ptr, int *pos, int len) {
    /* pf("match_cms: pos,len = %d %d\n", *pos, len); */
    int ret = 0, j = (*pos < len ? *pos + 1 : *pos);    // "/*/" not, "/**/" valid
    while (j < len) {
        while (ptr[j] != '/' && j < len) j++;
        if (j < len) {
            j++;
            if (ptr[j-2] == '*') { ret = 1; break; }
            else continue;
        }
    }
    *pos = j;
    /* if (ret) pf("match_cms succeeded\n"); */
    return ret;
}

int splittolines(char *buf, int total) {
    pf("splittolines: total = %d\n", total);
    if (buf == NULL || total <= 0) { return 0; }
    int n = 0, i, prev = -1;
    int flag_quote = 0, flag_cms = 0, flag_ccms = 0;
    buf[total] = '\n';
    for (i = 0; i < total; i++, n++) {
        char *ptr = buf + i;
        /* if (i != 0 && ptr[-1] != '\n') pf("ptr error\n"); */
        int j = 0, start, len, cms = -1;
        while (ptr[j] <= ' ' && ptr[j] != '\n' && ptr[j] != '\r') j++;  // remove leading space
        len = start = j;
        while (ptr[len] != '\n' && ptr[len] != '\r') len++;
        lines[n].p = ptr;
        lines[n].n = len;
        char sout[16]; sprintf(sout,"%2d %2d %2d", n+1, start, len);
        /* pf("%s ",sout); pline(lines[n].p, lines[n].n); */
        // start processing
        if (prev != -1) {            // previous line continue, prev != -1
            if (flag_quote) {
                if (match_quote(ptr, &j, len)) flag_quote = 0;
            }
            if (flag_ccms) {
                lines[n].p = NULL;
                j = len;
            }
        }
        if (flag_cms) {
            if (match_cms(ptr, &j, len)) {
                flag_cms = 0;
                ptr += j, len -= j, j = 0;    // remove leading C-style comment
                while (ptr[j] <= ' ' && j < len) j++;   // remove leading space after that
                start = j;
            } else lines[n].p = NULL; 
        }
            pf("last char %c prev,len = %d %d n+1 = %d\n", ptr[len-1], prev,len,n+1);
        if ((ptr[len-1] == '\\') && (len > 0)) {  // current line continue, set prev != -1
            prev = n;
        } else {
            prev = -1;
        }
            pf("last char %c prev,len = %d %d n+1 = %d\n", ptr[len-1], prev,len,n+1);
        i = (ptr + len) - buf;
        if (buf[i] == '\r' && buf[i+1] == '\n') i++;
        while (len > 0 && ptr[len-1] <= ' ') len--; // remove trailing space
            /* pf("j,len,%d %d\n", j, len); */
        /* pf("%s ",sout); pline(lines[n].p, lines[n].n); */
        while (j < len) { // all 3 flag cleared, processing remain part of line
            /* pf("j,len,%d %d\n", j, len); */
            while (ptr[j] != '"' && ptr[j] != '/' && j < len) j++;
            if (ptr[j] == '"') {
                j++;
                if (match_quote(ptr, &j, len)) continue;
                else { flag_quote = 1; break; }
            }
            if (ptr[j] == '/') {
                j++;
                if (n+1 == 41) pline(ptr+start,len-start);
                if (ptr[j] == '*') {
                    flag_cms = j;
                    j++;
                    if (match_cms(ptr, &j, len)) flag_cms = 0, cms = j;
                    else {
                        break;
                    }
                } else if (ptr[j] == '/') {
                    /* if (n+1 == 13) pf("start,j = %d %d  ^%c%c.*%c$ \n", start,j,ptr[start],ptr[start+1],ptr[len-1]); */
                    if (j == start + 1) { lines[n].p = NULL; }
                    flag_ccms = 1; break;
                }
            }
        }
        if (ptr[start] == '/' && ptr[start+1] == '*') {
            if (flag_cms || (j == len)) { lines[n].p = NULL; }
        } else if (flag_cms) { len = flag_cms - 1; }    // remove trailing C style comment
        if (lines[n].p != NULL) lines[n].p = ptr;
        if (prev == -1) {
            flag_quote = 0; // C string cannot span mutli-line
            flag_ccms = 0;  // so is C++ style comment
        }
        if (n+1 > 0) pf("flags.{q,c,cc} %d %d %d prev = %d\n",flag_quote,flag_cms,flag_ccms, prev);
        lines[n].n = len;
        pf("%s ",sout); pline(lines[n].p, lines[n].n);
    }
    return n;
}

/*
if previous line not continue,
   has a unmatching / *, find matching * /
if previous line continue,
   has a unmatching ", find matching "
   has a unmatching / *, find matching * /
   previous line is //, also //
after this processing, 
      either entrie line processed, and proceed to next line.
      or remain part of line, and all 3 flag been cleared, and previous line not matter.
*/

void printlines(int n) {
    pf("printlines: n = %d\n", n);
    for (int i = 0; i < n; i++) {
        if (lines[i].p == NULL) { putchar('\n'); continue; }
        lines[i].p[lines[i].n] = 0;
        /* printf("%2d %2d %s\n", i+1, lines[i].n, lines[i].p); */
        puts(lines[i].p);
    }
}

int main() {
    char *buf = filebuf;
    int total = readfile(0, &buf);
    /* fwrite(buf,1,SEGSIZE,stdout); */
    int n = splittolines(buf, total);
    printlines(n);
}
