#ifndef mini_dirent_h
#define mini_dirent_h

//+doc the switch for defining the dirbuf.
// used internally
//+def dirbuf

#ifdef mini_opendir
#ifndef mini_dirbuf
#define mini_dirbuf
#endif
#endif

#ifdef mini_dirbuf

//+doc the dir stream bufsize
// The size of the buffer can be changed by setting mini_dirbufsize
// to it's size in Bytes. (default 2048)
// The buffer is allocated via malloc,
// therefore mini_buf must be set to a value greater than dirbufsize
//+def dirbufsize 
#ifndef mini_dirbufsize
#define mini_dirbufsize 2048
#endif

#ifndef mini_buf
#error mini_buf not set.
#endif

#if mini_buf < mini_dirbufsize
#error mini_buf < dirbufsize
#endif

#else // ifdef dirbuf
#define mini_dirbufsize 0
#endif

struct __dirstream{
	off_t tell;
	int fd;
	int buf_pos;
	int buf_end;
	int align;
	//volatile int lock[1];
	/* Any changes to this struct must preserve the property:
	 * offsetof(struct __dirent, buf) % sizeof(off_t) == 0 */
	char buf[mini_dirbufsize];
};

typedef struct __dirstream DIR;


struct dirent {
	ino_t d_ino;
	off_t d_off;
	unsigned short d_reclen;
	//unsigned char d_type;
	//char d_name[256];
	char d_name[];
};

#endif
