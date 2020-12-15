#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "athrill_syscall.h"
unsigned int athrill_device_func_call;

int raise(int sig)
{
	return 0;
}

void exit(int status)
{
}

void __register_exitproc(void)
{

}


int _close  (int fd)
{
	return athrill_newlib_close_r(fd);
}

_off_t _lseek  (int fd, _off_t offset, int whence)
{
	return (_off_t) athrill_newlib_lseek_r(fd,offset,whence);
}

static int open_r_flags = 0;
static int open_r_mode = 0;
int _open  (char *file_name, int flags, int mode)
{
	open_r_flags = flags;
	open_r_mode = mode;
	return athrill_newlib_open_r(file_name, flags, mode);
}

_ssize_t _read  (int fd, void *buf, size_t size)
{
	_ssize_t ret;	
	while ( (ret = athrill_newlib_read_r(fd, buf, size)) == -1 ) {
		if ( errno != SYS_API_ERR_AGAIN && errno != 0 ) break;
	}
	
	return ret;	
}
_ssize_t _write  (int fd, const void *buf, size_t size)
{
	return (_ssize_t)athrill_newlib_write_r(fd, buf, size);
}


int filesys_opendir(const char *path) {
		
	return 0;
}

#define APP_HEAP_SIZE	(1024*1024)
char appheap[APP_HEAP_SIZE] __attribute__((section(".appheap")));

extern char heap_end;
extern char heap_start;
static char *current_heap_end = &heap_start;
void* _sbrk(int incr)
{
	char *prev_heap_end;

	if ((current_heap_end + incr) > &heap_end) {
		return ((void*)-1);
	}

	prev_heap_end = current_heap_end;
	current_heap_end += incr;

	return (void*) prev_heap_end;
}

void static_init(void) {
  void (**p)(void);
  extern unsigned int __init_array_start, __init_array_end; /* linker defined symbols, array of function pointers */
  unsigned int beg = (unsigned int)&__init_array_start;
  unsigned int end = (unsigned int)&__init_array_end;
 
  while(beg<end) {
    p = (void(**)(void))beg; /* get function pointer */
    (*p)(); /* call constructor */
    beg += sizeof(p); /* next pointer */
  }
}
