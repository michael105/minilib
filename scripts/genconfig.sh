#
# Script, updated from "make header" / genheaders.pl
# The functions are callen from minilib.conf 
# (or another config file)
# The output of this script generates minilib.conf.h
# 

testing(){
		echo SET TESTING gghstd >&4
		export TESTING=asodf
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


mini_HEADERGUARDS(){
		echo "#define HEADERGUARDS"
}


HEADERGUARDS(){
		echo "#define HEADERGUARDS"
}



# Everything below will be silently overwritten,
# when make header ist invoked

# --- define_functions-start: generate --- #
mini_fopen(){ 
  echo "#define mini_fopen generate" 
}
mini_fflush(){ 
  echo "#define mini_fflush generate" 
}
mini_printl(){ 
  echo "#define mini_printl generate" 
}
mini_unlink(){ 
  echo "#define mini_unlink generate" 
}
mini_isprint(){ 
  echo "#define mini_isprint generate" 
}
mini_strcat(){ 
  echo "#define mini_strcat generate" 
}
mini_fread(){ 
  echo "#define mini_fread generate" 
}
mini_fputc(){ 
  echo "#define mini_fputc generate" 
}
mini_stat(){ 
  echo "#define mini_stat generate" 
}
mini_dup(){ 
  echo "#define mini_dup generate" 
}
mini_uitodec(){ 
  echo "#define mini_uitodec generate" 
}
mini_fprintf(){ 
  echo "#define mini_fprintf generate" 
}
mini_select(){ 
  echo "#define mini_select generate" 
}
mini_malloc(){ 
  echo "#define mini_malloc generate" 
}
mini_fclose(){ 
  echo "#define mini_fclose generate" 
}
mini_vfprintf(){ 
  echo "#define mini_vfprintf generate" 
}
mini_print(){ 
  echo "#define mini_print generate" 
}
mini_lseek(){ 
  echo "#define mini_lseek generate" 
}
mini_strcpy(){ 
  echo "#define mini_strcpy generate" 
}
mini_fsetpos(){ 
  echo "#define mini_fsetpos generate" 
}
mini_prints(){ 
  echo "#define mini_prints generate" 
}
mini_fgetpos(){ 
  echo "#define mini_fgetpos generate" 
}
mini_memcmp(){ 
  echo "#define mini_memcmp generate" 
}
mini_memset(){ 
  echo "#define mini_memset generate" 
}
mini_getpid(){ 
  echo "#define mini_getpid generate" 
}
mini_snprintf(){ 
  echo "#define mini_snprintf generate" 
}
mini_creat(){ 
  echo "#define mini_creat generate" 
}
mini_ftell(){ 
  echo "#define mini_ftell generate" 
}
mini_tcgetattr(){ 
  echo "#define mini_tcgetattr generate" 
}
mini_srand(){ 
  echo "#define mini_srand generate" 
}
mini_isspace(){ 
  echo "#define mini_isspace generate" 
}
mini__mprints(){ 
  echo "#define mini__mprints generate" 
}
mini_tcsetattr(){ 
  echo "#define mini_tcsetattr generate" 
}
mini_ftruncate(){ 
  echo "#define mini_ftruncate generate" 
}
mini_close(){ 
  echo "#define mini_close generate" 
}
mini_getcwd(){ 
  echo "#define mini_getcwd generate" 
}
mini_open(){ 
  echo "#define mini_open generate" 
}
mini_itodec(){ 
  echo "#define mini_itodec generate" 
}
mini_puts(){ 
  echo "#define mini_puts generate" 
}
mini_dprintf(){ 
  echo "#define mini_dprintf generate" 
}
mini__itobin(){ 
  echo "#define mini__itobin generate" 
}
mini_itoHEX(){ 
  echo "#define mini_itoHEX generate" 
}
mini_fstat(){ 
  echo "#define mini_fstat generate" 
}
mini_perror(){ 
  echo "#define mini_perror generate" 
}
mini_time(){ 
  echo "#define mini_time generate" 
}
mini_read(){ 
  echo "#define mini_read generate" 
}
mini_atoi(){ 
  echo "#define mini_atoi generate" 
}
mini_ferror(){ 
  echo "#define mini_ferror generate" 
}
mini_dtodec(){ 
  echo "#define mini_dtodec generate" 
}
mini_rand(){ 
  echo "#define mini_rand generate" 
}
mini_dup3(){ 
  echo "#define mini_dup3 generate" 
}
mini_strncmp(){ 
  echo "#define mini_strncmp generate" 
}
mini_fileno(){ 
  echo "#define mini_fileno generate" 
}
mini_ioctl(){ 
  echo "#define mini_ioctl generate" 
}
mini_mprotect(){ 
  echo "#define mini_mprotect generate" 
}
mini_memfrob(){ 
  echo "#define mini_memfrob generate" 
}
mini_putchar(){ 
  echo "#define mini_putchar generate" 
}
mini_feof(){ 
  echo "#define mini_feof generate" 
}
mini_strerror(){ 
  echo "#define mini_strerror generate" 
}
mini_def(){ 
  echo "#define mini_def generate" 
}
mini_rename(){ 
  echo "#define mini_rename generate" 
}
mini_strlen(){ 
  echo "#define mini_strlen generate" 
}
mini_sprintf(){ 
  echo "#define mini_sprintf generate" 
}
mini_getenv(){ 
  echo "#define mini_getenv generate" 
}
mini_fputs(){ 
  echo "#define mini_fputs generate" 
}
mini_printf(){ 
  echo "#define mini_printf generate" 
}
mini_dup2(){ 
  echo "#define mini_dup2 generate" 
}
mini_itohex(){ 
  echo "#define mini_itohex generate" 
}
mini_clearerror(){ 
  echo "#define mini_clearerror generate" 
}
mini_rewind(){ 
  echo "#define mini_rewind generate" 
}
mini_memcpy(){ 
  echo "#define mini_memcpy generate" 
}
mini_fwrite(){ 
  echo "#define mini_fwrite generate" 
}
mini_write(){ 
  echo "#define mini_write generate" 
}
mini_fseek(){ 
  echo "#define mini_fseek generate" 
}
mini_fprintfs(){ 
  echo "#define mini_fprintfs generate" 
}
mini_fsync(){ 
  echo "#define mini_fsync generate" 
}
mini_gettimeofday(){ 
  echo "#define mini_gettimeofday generate" 
}
mini_vsnprintf(){ 
  echo "#define mini_vsnprintf generate" 
}
mini_free(){ 
  echo "#define mini_free generate" 
}
mini_strcmp(){ 
  echo "#define mini_strcmp generate" 
}
mini_dprints(){ 
  echo "#define mini_dprints generate" 
}
mini_strncpy(){ 
  echo "#define mini_strncpy generate" 
}
mini__itohex(){ 
  echo "#define mini__itohex generate" 
}
# --- define_functions-end: generate --- #

