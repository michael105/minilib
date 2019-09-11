#
# Script, updated from "make header" / genheaders.pl
# The functions are callen from minilib.conf 
# (or another config file)
# The output of this script generates minilib.conf.h
# 

mini_errno(){
		#echo SET TESTING gghstd >&4
		#export TESTING=asodf
		echo "#define mini_errno $1"
}

mini_start(){
		echo "#define mini_start $1"
}
mini_exit(){
		echo "#define mini_exit $1"
}

LDSCRIPT(){
		export LDSCRIPT="ld_script_$1" 
}

shrinkelf(){
		export opt_shrinkelf=1
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

# The (optimization)-flag, gcc is callen with.
# Either leave it blank, or set it to e.g. '-Os'
# -O2 and higher optimizations seem to give trouble.
# -Os, -O0, -O1 passed all tests here and might be save.
OPTFLAG(){
		export OPTFLAG=$1
}

mini_HEADERGUARDS(){
		echo "#define HEADERGUARDS"
}


HEADERGUARDS(){
		echo "#define HEADERGUARDS"
}



# Everything below will be silently overwritten,
# when make header ist invoked

# --- define_functions-start: generate --- #
mini_printsl(){ 
  echo "#define mini_printsl generate" 
}
mini_puts(){ 
  echo "#define mini_puts generate" 
}
mini_dup2(){ 
  echo "#define mini_dup2 generate" 
}
mini_dprintf(){ 
  echo "#define mini_dprintf generate" 
}
mini_prints(){ 
  echo "#define mini_prints generate" 
}
mini_creat(){ 
  echo "#define mini_creat generate" 
}
mini_fsync(){ 
  echo "#define mini_fsync generate" 
}
mini_lseek(){ 
  echo "#define mini_lseek generate" 
}
mini_uitodec(){ 
  echo "#define mini_uitodec generate" 
}
mini_fsetpos(){ 
  echo "#define mini_fsetpos generate" 
}
mini_isprint(){ 
  echo "#define mini_isprint generate" 
}
mini__mprints(){ 
  echo "#define mini__mprints generate" 
}
mini_clearerror(){ 
  echo "#define mini_clearerror generate" 
}
mini_fopen(){ 
  echo "#define mini_fopen generate" 
}
mini_fprintf(){ 
  echo "#define mini_fprintf generate" 
}
mini__strcmp(){ 
  echo "#define mini__strcmp generate" 
}
mini_strcmp(){ 
  echo "#define mini_strcmp generate" 
}
mini_fprint(){ 
  echo "#define mini_fprint generate" 
}
mini_setvbuf(){ 
  echo "#define mini_setvbuf generate" 
}
mini_getpid(){ 
  echo "#define mini_getpid generate" 
}
mini_dtodec(){ 
  echo "#define mini_dtodec generate" 
}
mini_def(){ 
  echo "#define mini_def generate" 
}
mini_uname(){ 
  echo "#define mini_uname generate" 
}
mini_dup3(){ 
  echo "#define mini_dup3 generate" 
}
mini_tcsetattr(){ 
  echo "#define mini_tcsetattr generate" 
}
mini_print(){ 
  echo "#define mini_print generate" 
}
mini_memfrob(){ 
  echo "#define mini_memfrob generate" 
}
mini_read(){ 
  echo "#define mini_read generate" 
}
mini_select(){ 
  echo "#define mini_select generate" 
}
mini_sprintf(){ 
  echo "#define mini_sprintf generate" 
}
mini_snprintf(){ 
  echo "#define mini_snprintf generate" 
}
mini_getc(){ 
  echo "#define mini_getc generate" 
}
mini_itodec(){ 
  echo "#define mini_itodec generate" 
}
mini_itohex(){ 
  echo "#define mini_itohex generate" 
}
mini_ferror(){ 
  echo "#define mini_ferror generate" 
}
mini_dup(){ 
  echo "#define mini_dup generate" 
}
mini_setbuf(){ 
  echo "#define mini_setbuf generate" 
}
mini_fileno(){ 
  echo "#define mini_fileno generate" 
}
mini_basename(){ 
  echo "#define mini_basename generate" 
}
mini_ftell(){ 
  echo "#define mini_ftell generate" 
}
mini_fwrites(){ 
  echo "#define mini_fwrites generate" 
}
mini_unlink(){ 
  echo "#define mini_unlink generate" 
}
mini_printf(){ 
  echo "#define mini_printf generate" 
}
mini_itobin(){ 
  echo "#define mini_itobin generate" 
}
mini_memcpy(){ 
  echo "#define mini_memcpy generate" 
}
mini_ioctl(){ 
  echo "#define mini_ioctl generate" 
}
mini_fseek(){ 
  echo "#define mini_fseek generate" 
}
mini_strlen(){ 
  echo "#define mini_strlen generate" 
}
mini_rand(){ 
  echo "#define mini_rand generate" 
}
mini_printl(){ 
  echo "#define mini_printl generate" 
}
mini_getdents(){ 
  echo "#define mini_getdents generate" 
}
mini_readdir(){ 
  echo "#define mini_readdir generate" 
}
mini_vsnprintf(){ 
  echo "#define mini_vsnprintf generate" 
}
mini_close(){ 
  echo "#define mini_close generate" 
}
mini_strcpy(){ 
  echo "#define mini_strcpy generate" 
}
mini_time(){ 
  echo "#define mini_time generate" 
}
mini__itohex(){ 
  echo "#define mini__itohex generate" 
}
mini_stat(){ 
  echo "#define mini_stat generate" 
}
mini_strcat(){ 
  echo "#define mini_strcat generate" 
}
mini_fgetpos(){ 
  echo "#define mini_fgetpos generate" 
}
mini_putc(){ 
  echo "#define mini_putc generate" 
}
mini_getcwd(){ 
  echo "#define mini_getcwd generate" 
}
mini_isspace(){ 
  echo "#define mini_isspace generate" 
}
mini_fflush(){ 
  echo "#define mini_fflush generate" 
}
mini_gettimeofday(){ 
  echo "#define mini_gettimeofday generate" 
}
mini_write(){ 
  echo "#define mini_write generate" 
}
mini_fwrite(){ 
  echo "#define mini_fwrite generate" 
}
mini_closedir(){ 
  echo "#define mini_closedir generate" 
}
mini_strncmp(){ 
  echo "#define mini_strncmp generate" 
}
mini_free(){ 
  echo "#define mini_free generate" 
}
mini_fgetc(){ 
  echo "#define mini_fgetc generate" 
}
mini_fputc(){ 
  echo "#define mini_fputc generate" 
}
mini_memcmp(){ 
  echo "#define mini_memcmp generate" 
}
mini_rewind(){ 
  echo "#define mini_rewind generate" 
}
mini_fstat(){ 
  echo "#define mini_fstat generate" 
}
mini_atoi(){ 
  echo "#define mini_atoi generate" 
}
mini_itoHEX(){ 
  echo "#define mini_itoHEX generate" 
}
mini_dprints(){ 
  echo "#define mini_dprints generate" 
}
mini_opendir(){ 
  echo "#define mini_opendir generate" 
}
mini_fclose(){ 
  echo "#define mini_fclose generate" 
}
mini_rename(){ 
  echo "#define mini_rename generate" 
}
mini_srand(){ 
  echo "#define mini_srand generate" 
}
mini_memset(){ 
  echo "#define mini_memset generate" 
}
mini_fputs(){ 
  echo "#define mini_fputs generate" 
}
mini_strncpy(){ 
  echo "#define mini_strncpy generate" 
}
mini_open(){ 
  echo "#define mini_open generate" 
}
mini_strerror(){ 
  echo "#define mini_strerror generate" 
}
mini_fread(){ 
  echo "#define mini_fread generate" 
}
mini_writes(){ 
  echo "#define mini_writes generate" 
}
mini_perror(){ 
  echo "#define mini_perror generate" 
}
mini_vfprintf(){ 
  echo "#define mini_vfprintf generate" 
}
mini_malloc(){ 
  echo "#define mini_malloc generate" 
}
mini__itobin(){ 
  echo "#define mini__itobin generate" 
}
mini_fprints(){ 
  echo "#define mini_fprints generate" 
}
mini_getenv(){ 
  echo "#define mini_getenv generate" 
}
mini_fprintfs(){ 
  echo "#define mini_fprintfs generate" 
}
mini_tcgetattr(){ 
  echo "#define mini_tcgetattr generate" 
}
mini_mprotect(){ 
  echo "#define mini_mprotect generate" 
}
mini_ftruncate(){ 
  echo "#define mini_ftruncate generate" 
}
mini_chdir(){ 
  echo "#define mini_chdir generate" 
}
mini_putchar(){ 
  echo "#define mini_putchar generate" 
}
mini_feof(){ 
  echo "#define mini_feof generate" 
}
# --- define_functions-end: generate --- #

