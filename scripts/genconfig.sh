#
# Script, updated from "make header" / genheaders.pl
# The functions are callen from minilib.conf 
# (or another config file)
# The output of this script generates minilib.conf.h
# 

mini_start(){
		echo "#define mini_start $1"
}
mini_exit(){
		echo "#define mini_exit $1"
}

ARCH(){
		echo "#define MINILIB_ARCH $1"
		export MINI_ARCH=$1
}
OS(){
		echo "#define MINILIB_OS $1"
		export MINI_OS=$1
}
mini_buf(){
		echo "#define mini_buf $1"
}

mini_INCLUDESRC(){
		echo "#define INCLUDESRC"
}

INCLUDESRC(){
		echo "#define INCLUDESRC"
}

# Everything below will be silently overwritten,
# when make header ist invoked

# --- define_functions-start: generate --- #
mini_isspace(){ 
  echo "#define mini_isspace generate" 
}
mini_strlen(){ 
  echo "#define mini_strlen generate" 
}
mini_fstat(){ 
  echo "#define mini_fstat generate" 
}
mini_fileno(){ 
  echo "#define mini_fileno generate" 
}
mini_getenv(){ 
  echo "#define mini_getenv generate" 
}
mini_malloc(){ 
  echo "#define mini_malloc generate" 
}
mini_time(){ 
  echo "#define mini_time generate" 
}
mini_ftruncate(){ 
  echo "#define mini_ftruncate generate" 
}
mini_strcat(){ 
  echo "#define mini_strcat generate" 
}
mini_fclose(){ 
  echo "#define mini_fclose generate" 
}
mini_free(){ 
  echo "#define mini_free generate" 
}
mini_isprint(){ 
  echo "#define mini_isprint generate" 
}
mini_dup2(){ 
  echo "#define mini_dup2 generate" 
}
mini_memfrob(){ 
  echo "#define mini_memfrob generate" 
}
mini_write(){ 
  echo "#define mini_write generate" 
}
mini_strncmp(){ 
  echo "#define mini_strncmp generate" 
}
mini_putchar(){ 
  echo "#define mini_putchar generate" 
}
mini_fsync(){ 
  echo "#define mini_fsync generate" 
}
mini_creat(){ 
  echo "#define mini_creat generate" 
}
mini_strncpy(){ 
  echo "#define mini_strncpy generate" 
}
mini_print(){ 
  echo "#define mini_print generate" 
}
mini_getpid(){ 
  echo "#define mini_getpid generate" 
}
mini_unlink(){ 
  echo "#define mini_unlink generate" 
}
mini_memset(){ 
  echo "#define mini_memset generate" 
}
mini_fprintf(){ 
  echo "#define mini_fprintf generate" 
}
mini_stat(){ 
  echo "#define mini_stat generate" 
}
mini_printf(){ 
  echo "#define mini_printf generate" 
}
mini_tcsetattr(){ 
  echo "#define mini_tcsetattr generate" 
}
mini_getcwd(){ 
  echo "#define mini_getcwd generate" 
}
mini_def(){ 
  echo "#define mini_def generate" 
}
mini_lseek(){ 
  echo "#define mini_lseek generate" 
}
mini_itodec(){ 
  echo "#define mini_itodec generate" 
}
mini_prints(){ 
  echo "#define mini_prints generate" 
}
mini_dtodec(){ 
  echo "#define mini_dtodec generate" 
}
mini_close(){ 
  echo "#define mini_close generate" 
}
mini_strcpy(){ 
  echo "#define mini_strcpy generate" 
}
mini_itohex(){ 
  echo "#define mini_itohex generate" 
}
mini_fopen(){ 
  echo "#define mini_fopen generate" 
}
mini_atoi(){ 
  echo "#define mini_atoi generate" 
}
mini_rename(){ 
  echo "#define mini_rename generate" 
}
mini_memcmp(){ 
  echo "#define mini_memcmp generate" 
}
mini_uitodec(){ 
  echo "#define mini_uitodec generate" 
}
mini_tcgetattr(){ 
  echo "#define mini_tcgetattr generate" 
}
mini_printl(){ 
  echo "#define mini_printl generate" 
}
mini_dup(){ 
  echo "#define mini_dup generate" 
}
mini__itobin(){ 
  echo "#define mini__itobin generate" 
}
mini_gettimeofday(){ 
  echo "#define mini_gettimeofday generate" 
}
mini_puts(){ 
  echo "#define mini_puts generate" 
}
mini_strerror(){ 
  echo "#define mini_strerror generate" 
}
mini_mprotect(){ 
  echo "#define mini_mprotect generate" 
}
mini_fputs(){ 
  echo "#define mini_fputs generate" 
}
mini_open(){ 
  echo "#define mini_open generate" 
}
mini_strcmp(){ 
  echo "#define mini_strcmp generate" 
}
mini_dup3(){ 
  echo "#define mini_dup3 generate" 
}
mini_sprintf(){ 
  echo "#define mini_sprintf generate" 
}
mini_memcpy(){ 
  echo "#define mini_memcpy generate" 
}
mini_fputc(){ 
  echo "#define mini_fputc generate" 
}
mini_select(){ 
  echo "#define mini_select generate" 
}
mini_ioctl(){ 
  echo "#define mini_ioctl generate" 
}
mini_read(){ 
  echo "#define mini_read generate" 
}
# --- define_functions-end: generate --- #

