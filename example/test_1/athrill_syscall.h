#ifndef _ATHRILL_SYSCALL_H_
#define _ATHRILL_SYSCALL_H_

typedef unsigned int sys_uint32;
typedef unsigned short sys_uint16;
typedef unsigned char sys_uint8;
typedef signed int sys_int32;
typedef signed short sys_int16;
typedef signed char sys_int8;
typedef unsigned int sys_addr;
#ifndef ATHRILL_FD_SETSIZE
#define ATHRILL_FD_SETSIZE      64
#endif /* ATHRILL_FD_SETSIZE */
typedef struct {
    unsigned char fd_bits [(ATHRILL_FD_SETSIZE+7)/8];
} sys_fd_set;
#define SYS_FD_SET_SIZE     sizeof(sys_fd_set)

typedef enum {
    sys_false = 0,
    sys_true,
} SysBoolType;
typedef sys_int32 sys_bool; 

struct sys_sockaddr_in {
    sys_uint8  sin_family;
    sys_uint16 sin_port;
    sys_uint32 sin_addr;
    sys_int8   sin_zero[8];
};
struct api_arg_socket {
    sys_int32 domain;
    sys_int32 type;
    sys_int32 protocol;
};

struct api_arg_sense {
    sys_int32   sockfd;
    sys_int32   api_id;
};

struct api_arg_connect {
    sys_int32 sockfd;
    sys_addr sockaddr;
    sys_uint32 addrlen;
};
struct api_arg_select {
    sys_int32    nfds;
    sys_addr     readfds;
    sys_addr     writefds;
    sys_addr     exceptfds;
};

struct api_arg_bind {
    sys_int32 sockfd;
    sys_addr sockaddr;
    sys_uint32 addrlen;
};

struct api_arg_listen {
    sys_int32 sockfd;
    sys_int32 backlog;
};

struct api_arg_accept {
    sys_int32 sockfd;
    sys_addr sockaddr;
    sys_addr addrlen;
};

struct api_arg_send {
    sys_int32 sockfd;
    sys_addr buf;
    sys_uint32 len;
    sys_int32 flags;
};
struct api_arg_recv {
    sys_int32 sockfd;
    sys_addr buf;
    sys_uint32 len;
    sys_int32 flags;
};
struct api_arg_shutdown {
    sys_int32 sockfd;
    sys_int32 how;
};
struct api_arg_system {
    sys_uint32 id;
};
struct api_arg_malloc {
    sys_uint32 size;
    sys_addr    rptr;
};
struct api_arg_calloc {
    sys_uint32 nmemb;
    sys_uint32 size;
    sys_addr    rptr;
};
struct api_arg_realloc {
    sys_addr ptr;
    sys_uint32 size;
    sys_addr    rptr;
};
struct api_arg_free {
    sys_addr ptr;
};

struct api_arg_open_r {
    sys_addr file_name;
    sys_int32 flags;
    sys_int32 mode;
};

struct api_arg_read_r {
    sys_int32 fd;
    sys_addr buf;
    sys_uint32 size;
};

struct api_arg_write_r {
    sys_int32 fd;
    sys_addr buf;
    sys_uint32 size;
};

struct api_arg_close_r {
    sys_int32 fd;
};

struct api_arg_lseek_r {
    sys_int32 fd;
    sys_uint32 offset;
    sys_int32 whence;
};


struct api_arg_set_virtfs_top {
    sys_addr top_dir;
};

struct api_arg_fflush {
    sys_addr fp;
};

struct api_arg_ev3_opendir {
    sys_addr path;
    // output
    sys_int32 dirid; // 8byte area to keep DIR pointer. caller must prepare the memory
};

// This function is different from original read dir. So, this api named ev3_readdir.
struct api_arg_ev3_readdir {
    sys_int32 dirid;
    // output
    sys_uint32 size;
    sys_uint16 date;
    sys_uint16 time;
    sys_uint8  attrib;
    sys_addr  name;
};

struct api_arg_ev3_closedir {
    sys_int32 dirid;
};

enum {
    SYS_SERIAL_DEFAULT = 0,
    SYS_SERIAL_UART = 1,
    SYS_SERIAL_BT = 2
};

struct api_arg_ev3_serial_open {
    sys_int32 port;
};

struct api_arg_exit {
	sys_int32 status;
};

typedef enum {
    SYS_API_ID_NONE = 0,
    SYS_API_ID_SOCKET,
    SYS_API_ID_SENSE,
    SYS_API_ID_BIND,
    SYS_API_ID_LISTEN,
    SYS_API_ID_ACCEPT,
    SYS_API_ID_CONNECT,
    SYS_API_ID_SELECT,
    SYS_API_ID_SEND,
    SYS_API_ID_RECV,
    SYS_API_ID_SHUTDOWN,
    SYS_API_ID_SYSTEM,
    SYS_API_ID_MALLOC,
    SYS_API_ID_CALLOC,
    SYS_API_ID_REALLOC,
    SYS_API_ID_FREE,
    // Add for ETRbocon
    SYS_API_ID_OPEN_R,
    SYS_API_ID_READ_R,
    SYS_API_ID_WRITE_R,
    SYS_API_ID_CLOSE_R,
    SYS_API_ID_LSEEK_R,
    SYS_API_ID_SET_VIRTFS_TOP,
    SYS_API_ID_EV3_OPENDIR,
    SYS_API_ID_EV3_READDIR,
    SYS_API_ID_EV3_CLOSEDIR,
    SYS_API_ID_EV3_SERIAL_OPEN,
	SYS_API_ID_EXIT,
    SYS_API_ID_NUM,
} AthrillSyscallApiIdType;

#define SYS_API_ERR_OK       0
#define SYS_API_ERR_PERM     -1
#define SYS_API_ERR_NOENT    -2
#define SYS_API_ERR_IO       -5
#define SYS_API_ERR_AGAIN   -11
#define SYS_API_ERR_NOMEM   -12
#define SYS_API_ERR_ACCESS  -13
#define SYS_API_ERR_FAULT   -14
#define SYS_API_ERR_EXSIT   -17
#define SYS_API_ERR_INVAL   -22
#define SYS_API_ERR_BADFD   -77
#define SYS_API_ERR_CONNREFUSED   -111
#define SYS_API_ERR_INPROGRESS    -115

typedef struct {
    sys_uint32 api_id;
    sys_int32 ret_value;
    sys_int32 ret_errno;
    union {
        struct api_arg_socket api_socket;
        struct api_arg_sense api_sense;
        struct api_arg_bind api_bind;
        struct api_arg_listen api_listen;
        struct api_arg_accept api_accept;
        struct api_arg_connect api_connect;
        struct api_arg_select api_select;
        struct api_arg_send api_send;
        struct api_arg_recv api_recv;
        struct api_arg_shutdown api_shutdown;
        struct api_arg_system api_system;
        struct api_arg_malloc api_malloc;
        struct api_arg_calloc api_calloc;
        struct api_arg_realloc api_realloc;
        struct api_arg_free api_free;
        struct api_arg_open_r api_open_r;
        struct api_arg_read_r api_read_r;
        struct api_arg_write_r api_write_r;
        struct api_arg_close_r api_close_r;
        struct api_arg_lseek_r api_lseek_r;
        struct api_arg_set_virtfs_top api_set_virtfs_top;
        struct api_arg_ev3_opendir api_ev3_opendir;
        struct api_arg_ev3_readdir api_ev3_readdir;
        struct api_arg_ev3_closedir api_ev3_closedir;
        struct api_arg_ev3_serial_open api_ev3_serial_open;
        struct api_arg_exit api_exit;
    } body;
} AthrillSyscallArgType;

#include <fcntl.h>

#define ATHRILL_OPEN_FLAGS_O_APPEND		0x0001
#define ATHRILL_OPEN_FLAGS_O_CREAT		0x0002
#define ATHRILL_OPEN_FLAGS_O_EXCL		0x0004
#define ATHRILL_OPEN_FLAGS_O_NOCTTY		0x0008
#define ATHRILL_OPEN_FLAGS_O_NONBLOCK	0x0010
#define ATHRILL_OPEN_FLAGS_O_SYNC		0x0020
#define ATHRILL_OPEN_FLAGS_O_TRUNC		0x0040
#define ATHRILL_OPEN_FLAGS_O_RDONLY		0x0080
#define ATHRILL_OPEN_FLAGS_O_WRONLY		0x0100
#define ATHRILL_OPEN_FLAGS_O_RDWR		0x0200

#define ATHRILL_OPEN_R_FLAG_TARGET2INF(flag, org_flags, target_flag)   \
do {    \
		if ((org_flags) & (target_flag)) {	\
			(flag) |= ATHRILL_OPEN_FLAGS_##target_flag;   \
		}	\
} while (0)

#define ATHRILL_OPEN_R_FLAG_INF2TARGET(flag, inf_flags, target_flag)   \
do {    \
		if ((inf_flags) & ATHRILL_OPEN_FLAGS_##target_flag) {	\
			(flag) |= (target_flag);   \
		}	\
} while (0)

static inline int athrill_newlib_open_r_flag(int org_flags)
{
	int flags = 0x0;
	ATHRILL_OPEN_R_FLAG_TARGET2INF(flags, org_flags, O_APPEND);
	ATHRILL_OPEN_R_FLAG_TARGET2INF(flags, org_flags, O_CREAT);
	ATHRILL_OPEN_R_FLAG_TARGET2INF(flags, org_flags, O_EXCL);
	ATHRILL_OPEN_R_FLAG_TARGET2INF(flags, org_flags, O_NOCTTY);
	ATHRILL_OPEN_R_FLAG_TARGET2INF(flags, org_flags, O_NONBLOCK);
	ATHRILL_OPEN_R_FLAG_TARGET2INF(flags, org_flags, O_SYNC);
	ATHRILL_OPEN_R_FLAG_TARGET2INF(flags, org_flags, O_TRUNC);
	ATHRILL_OPEN_R_FLAG_TARGET2INF(flags, org_flags, O_RDONLY);
	ATHRILL_OPEN_R_FLAG_TARGET2INF(flags, org_flags, O_WRONLY);
	ATHRILL_OPEN_R_FLAG_TARGET2INF(flags, org_flags, O_RDWR);
	return flags;
}

static inline int athrill_syscall_open_r_flag(int inf_flags)
{
	int flags = 0x0;
	ATHRILL_OPEN_R_FLAG_INF2TARGET(flags, inf_flags, O_APPEND);
	ATHRILL_OPEN_R_FLAG_INF2TARGET(flags, inf_flags, O_CREAT);
	ATHRILL_OPEN_R_FLAG_INF2TARGET(flags, inf_flags, O_EXCL);
	ATHRILL_OPEN_R_FLAG_INF2TARGET(flags, inf_flags, O_NOCTTY);
	ATHRILL_OPEN_R_FLAG_INF2TARGET(flags, inf_flags, O_NONBLOCK);
	ATHRILL_OPEN_R_FLAG_INF2TARGET(flags, inf_flags, O_SYNC);
	ATHRILL_OPEN_R_FLAG_INF2TARGET(flags, inf_flags, O_TRUNC);
	ATHRILL_OPEN_R_FLAG_INF2TARGET(flags, inf_flags, O_RDONLY);
	ATHRILL_OPEN_R_FLAG_INF2TARGET(flags, inf_flags, O_WRONLY);
	ATHRILL_OPEN_R_FLAG_INF2TARGET(flags, inf_flags, O_RDWR);
	return flags;
}

#ifndef ATHRILL_SYSCALL_DEVICE

#ifdef DISABLE_EV3RT_API
#else
#include "ev3api.h"
#include "string.h"
#include "driver_interface_filesys.h"
#endif /* DISABLE_EV3RT_API */
#include <errno.h>
extern sys_addr athrill_device_func_call __attribute__ ((section(".athrill_device_section")));


#if 0
/* compiler optimization changes the order of putting the values in valiables.
   it caused parameter is not set when athrill_device_func_call is set.
   to avoid this, change sysacall from macro to function in another file */
#define ATHRILL_SYSCALL(api_argp)   \
do {    \
    athrill_device_func_call = (sys_addr)(api_argp);    \
} while (0) 

#else

extern void athrill_syscall(AthrillSyscallArgType *param);
#define ATHRILL_SYSCALL(api_argp) athrill_syscall(api_argp);
// to supress warning 
#define volatile
#endif

#define ATHRILL_SYSCALL_SOCKET_DOMAIN_AF_INET   0
#define ATHRILL_SYSCALL_SOCKET_TYPE_STREAM   0
#define ATHRILL_SYSCALL_SOCKET_PROTOCOL_ZERO   0
static inline sys_int32 athrill_posix_socket(sys_int32 domain, sys_int32 type, sys_int32 protocol)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_SOCKET;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_socket.domain = domain;
    args.body.api_socket.type = type;
    args.body.api_socket.protocol = protocol;

    ATHRILL_SYSCALL(&args);
    
    return args.ret_value;
}

static inline sys_int32 athrill_posix_sense(sys_int32 sockfd, AthrillSyscallApiIdType api_id)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_SENSE;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_sense.sockfd = sockfd;
    args.body.api_sense.api_id = api_id;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}

#define ATHRILL_SYSCALL_SOCKADDR_FAMILIY_PF_INET 0
#define ATHRILL_SYSCALL_IPADDR(arg3, arg2, arg1, arg0)  \
    ( \
        ((arg3) << 24) | \
        ((arg2) << 16) | \
        ((arg1) << 8) | \
        ((arg0) << 0) \
    )

static inline sys_int32 athrill_posix_bind(sys_int32 sockfd, const struct sys_sockaddr_in *addr, sys_uint32 addrlen)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_BIND;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_bind.sockfd = sockfd;
    args.body.api_bind.sockaddr = (sys_addr)addr;
    args.body.api_bind.addrlen = addrlen;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}

static inline sys_int32 athrill_posix_listen(sys_int32 sockfd, sys_int32 backlog)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_LISTEN;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_listen.sockfd = sockfd;
    args.body.api_listen.backlog = backlog;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}

static inline sys_int32 athrill_posix_accept(sys_int32 sockfd, struct sys_sockaddr_in *addr, sys_uint32 *addrlen)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_ACCEPT;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_accept.sockfd = sockfd;
    args.body.api_accept.sockaddr = (sys_addr)addr;
    args.body.api_accept.addrlen = (sys_addr)addrlen;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}

static inline sys_int32 athrill_posix_connect(sys_int32 sockfd, const struct sys_sockaddr_in *addr, sys_uint32 addrlen)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_CONNECT;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_connect.sockfd = sockfd;
    args.body.api_connect.sockaddr = (sys_addr)addr;
    args.body.api_connect.addrlen = addrlen;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}

static inline sys_int32 athrill_posix_select(sys_int32 nfds, sys_fd_set *readfds, sys_fd_set *writefds, sys_fd_set *exceptfds)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_SELECT;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_select.nfds = nfds;
    args.body.api_select.readfds = (sys_addr)readfds;
    args.body.api_select.writefds = (sys_addr)writefds;
    args.body.api_select.exceptfds = (sys_addr)exceptfds;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}

#define ATHRILL_POSIX_MSG_DONTWAIT 0
static inline sys_uint32 athrill_posix_send(sys_int32 sockfd, const sys_addr buf, sys_uint32 len, sys_int32 flags)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_SEND;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_send.sockfd = sockfd;
    args.body.api_send.buf = buf;
    args.body.api_send.len = len;
    args.body.api_send.flags = flags;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}
static inline sys_uint32 athrill_posix_recv(sys_int32 sockfd, sys_addr buf, sys_uint32 len, sys_int32 flags)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_RECV;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_recv.sockfd = sockfd;
    args.body.api_recv.buf = buf;
    args.body.api_recv.len = len;
    args.body.api_recv.flags = flags;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}

#define ATHRILL_POSIX_SHUT_RDWR 0
static inline sys_int32 athrill_posix_shutdown(sys_int32 sockfd, sys_int32 how)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_SHUTDOWN;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_shutdown.sockfd = sockfd;
    args.body.api_shutdown.how = how;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}

static inline sys_int32 athrill_posix_system(sys_uint32 id)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_SYSTEM;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_system.id = id;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}

static inline sys_addr athrill_posix_malloc(sys_uint32 size)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_MALLOC;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_malloc.size = size;

    ATHRILL_SYSCALL(&args);

    return args.body.api_malloc.rptr;
}
static inline sys_addr athrill_posix_calloc(sys_uint32 nmemb, sys_uint32 size)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_CALLOC;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_calloc.nmemb = nmemb;
    args.body.api_calloc.size = size;

    ATHRILL_SYSCALL(&args);

    return args.body.api_calloc.rptr;
}
static inline sys_addr athrill_posix_realloc(sys_addr ptr, sys_uint32 size)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_REALLOC;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_realloc.ptr = ptr;
    args.body.api_realloc.size = size;

    ATHRILL_SYSCALL(&args);

    return args.body.api_realloc.rptr;
}
static inline void athrill_posix_free(sys_addr ptr)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_FREE;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_free.ptr = ptr;

    ATHRILL_SYSCALL(&args);

    return;
}

static inline int athrill_newlib_open_r(const char *file, int flags, int mode)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_OPEN_R;
    args.ret_value = -1;
    args.body.api_open_r.file_name = (sys_addr)file;
    args.body.api_open_r.flags = athrill_newlib_open_r_flag(flags);
    args.body.api_open_r.mode = mode;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;

}

static inline int athrill_newlib_read_r(int fd, char *buf, sys_uint32 cnt)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_READ_R;
    args.ret_value = -1;
    args.body.api_read_r.fd = fd;
    args.body.api_read_r.buf = (sys_addr)buf;
    args.body.api_read_r.size = (sys_uint32)cnt;

    ATHRILL_SYSCALL(&args);
    errno = args.ret_errno;
    return args.ret_value;

}

static inline int athrill_newlib_write_r(int fd, const char *buf, sys_uint32 cnt)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_WRITE_R;
    args.ret_value = -1;
    args.body.api_write_r.fd = fd;
    args.body.api_write_r.buf = (sys_addr)buf;
    args.body.api_write_r.size = (sys_uint32)cnt;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;

}

static inline int athrill_newlib_close_r(int fd)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_CLOSE_R;
    args.ret_value = -1;
    args.body.api_close_r.fd = fd;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;

}

static inline int athrill_newlib_lseek_r(int fd, sys_int32 offset, int whence)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_LSEEK_R;
    args.ret_value = -1;
    args.body.api_lseek_r.fd = fd;
    args.body.api_lseek_r.offset = offset;
    args.body.api_lseek_r.whence = whence;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;

}


static inline sys_int32 athrill_set_virtfs_top(sys_addr top_dir)
{
    volatile AthrillSyscallArgType args;
    
    args.api_id = SYS_API_ID_SET_VIRTFS_TOP;
    args.ret_value = 0;
    args.body.api_set_virtfs_top.top_dir = top_dir;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}


static inline sys_int32 athrill_ev3_opendir(sys_addr path)
{
    volatile AthrillSyscallArgType args;

    // allocate 64bit memory for store DIR * pointer
    args.api_id = SYS_API_ID_EV3_OPENDIR;
    args.ret_value = 0;
    args.body.api_ev3_opendir.path = path;

    ATHRILL_SYSCALL(&args);

    return args.body.api_ev3_opendir.dirid;

}

#ifdef DISABLE_EV3RT_API
#else
static inline sys_int32 athrill_ev3_readdir(sys_int32 dirid, fatfs_filinfo_t *fileinfo)
{
    volatile AthrillSyscallArgType args;

    // allocate 64bit memory for store DIR * pointer
    args.api_id = SYS_API_ID_EV3_READDIR;
    args.ret_value = 0;
    args.body.api_ev3_readdir.dirid = dirid;
    args.body.api_ev3_readdir.name = (sys_addr)fileinfo->fname;

    ATHRILL_SYSCALL(&args);

    if ( args.ret_value != E_OK ) return args.ret_value;

    fileinfo->fsize = args.body.api_ev3_readdir.size;
    fileinfo->fdate = args.body.api_ev3_readdir.date;
    fileinfo->ftime = args.body.api_ev3_readdir.time;
    fileinfo->fattrib = args.body.api_ev3_readdir.attrib;

    return E_OK;

}
#endif

static inline sys_int32 athrill_ev3_closedir(sys_int32 dirid)
{
    volatile AthrillSyscallArgType args;

    // allocate 64bit memory for store DIR * pointer
    args.api_id = SYS_API_ID_EV3_CLOSEDIR;
    args.ret_value = 0;
    args.body.api_ev3_closedir.dirid = dirid;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;

}

static inline sys_int32 athrill_ev3_serial_open(sys_int32 port)
{
    volatile AthrillSyscallArgType args;

    args.api_id = SYS_API_ID_EV3_SERIAL_OPEN;
    args.ret_value = 0;
    args.body.api_ev3_serial_open.port = (sys_addr)port;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;

}
static inline sys_int32 athrill_posix_exit(sys_int32 status)
{
    volatile AthrillSyscallArgType args;
    args.api_id = SYS_API_ID_EXIT;
    args.ret_value = SYS_API_ERR_INVAL;
    args.body.api_exit.status = status;

    ATHRILL_SYSCALL(&args);

    return args.ret_value;
}

#endif /* ATHRILL_SYSCALL_DEVICE */

#endif /* _ATHRILL_SYSCALL_H_ */
