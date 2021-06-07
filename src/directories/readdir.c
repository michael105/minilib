#ifndef readdir_c
#define readdir_c

//+doc read a directory.
// return the next dirent, or 0, if the end is reached.
// return 0 on error and set errno,
// if mini_errno is not defined, return -errno on error
//+depends dirbuf getdents
//+def
struct dirent *readdir(DIR *dir){
		struct dirent *de;

		if (dir->buf_pos >= dir->buf_end) {
				int len = getdents( dir->fd, (struct dirent*) dir->buf, sizeof(dir->buf));
				if (len <= 0) {
#ifdef mini_errno
						if (len < 0 && len != -ENOENT){
								errno = -len;
								//len = -1;
						}
#endif
						return(0);

				}
				dir->buf_end = len;
				dir->buf_pos = 0;
		}
		de = (void *)(dir->buf + dir->buf_pos);
		dir->buf_pos += de->d_reclen;
		dir->tell = de->d_off;
		return de;
}


#endif
