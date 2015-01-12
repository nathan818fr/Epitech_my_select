/*
** my_strerror.h for myutils in /home/poirie-n/blinux/poirie_n/repo/MyProjects/C_Lib_MyUtils/include
** 
** Made by Nathan Poirier
** Login   <poirie-n@epitech.net>
** 
** Started on  Sun Dec 14 15:45:57 2014 Nathan Poirier
** Last update Sun Dec 14 15:51:44 2014 Nathan Poirier
*/

#ifndef MYUTILS_STRERROR_H_
# define MYUTILS_STRERROR_H_

# include <errno.h>
# include <stdio.h>

typedef struct	s_my_strerror
{
  int		errnum;
  const char	*msg;
}		t_my_strerror;

static const	t_my_strerror	my_strerror_list[] =
  {
# ifdef E2BIG
    {E2BIG, "Argument list too long"},
# endif
# ifdef EACCES
    {EACCES, "Permission denied"},
# endif
# ifdef EADDRINUSE
    {EADDRINUSE, "Address already in use"},
# endif
# ifdef EADDRNOTAVAIL
    {EADDRNOTAVAIL, "Address not available"},
# endif
# ifdef EAFNOSUPPORT
    {EAFNOSUPPORT, "Address family not supported"},
# endif
# ifdef EAGAIN
    {EAGAIN, "Resource  temporarily  unavailable (may be the same value as EWOULDBLOCK)"},
# endif
# ifdef EALREADY
    {EALREADY, "Connection already in progress"},
# endif
# ifdef EBADE
    {EBADE, "Invalid exchange"},
# endif
# ifdef EBADF
    {EBADF, "Bad file descriptor"},
# endif
# ifdef EBADFD
    {EBADFD, "File descriptor in bad state"},
# endif
# ifdef EBADMSG
    {EBADMSG, "Bad message"},
# endif
# ifdef EBADR
    {EBADR, "Invalid request descriptor"},
# endif
# ifdef EBADRQC
    {EBADRQC, "Invalid request code"},
# endif
# ifdef EBADSLT
    {EBADSLT, "Invalid slot"},
# endif
# ifdef EBUSY
    {EBUSY, "Device or resource busy"},
# endif
# ifdef ECANCELED
    {ECANCELED, "Operation canceled"},
# endif
# ifdef ECHILD
    {ECHILD, "No child processes"},
# endif
# ifdef ECHRNG
    {ECHRNG, "Channel number out of range"},
# endif
# ifdef ECOMM
    {ECOMM, "Communication error on send"},
# endif
# ifdef ECONNABORTED
    {ECONNABORTED, "Connection aborted"},
# endif
# ifdef ECONNREFUSED
    {ECONNREFUSED, "Connection refused"},
# endif
# ifdef ECONNRESET
    {ECONNRESET, "Connection reset"},
# endif
# ifdef EDEADLK
    {EDEADLK, "Resource deadlock avoided"},
# endif
# ifdef EDEADLOCK
    {EDEADLOCK, "Synonym for EDEADLK"},
# endif
# ifdef EDESTADDRREQ
    {EDESTADDRREQ, "Destination address required"},
# endif
# ifdef EDOM
    {EDOM, "Mathematics argument out of domain of function"},
# endif
# ifdef EDQUOT
    {EDQUOT, "Disk quota exceeded"},
# endif
# ifdef EEXIST
    {EEXIST, "File exists"},
# endif
# ifdef EFAULT
    {EFAULT, "Bad address"},
# endif
# ifdef EFBIG
    {EFBIG, "File too large"},
# endif
# ifdef EHOSTDOWN
    {EHOSTDOWN, "Host is down"},
# endif
# ifdef EHOSTUNREACH
    {EHOSTUNREACH, "Host is unreachable"},
# endif
# ifdef EIDRM
    {EIDRM, "Identifier removed"},
# endif
# ifdef EILSEQ
    {EILSEQ, "Illegal byte sequence"},
# endif
# ifdef EINPROGRESS
    {EINPROGRESS, "Operation in progress"},
# endif
# ifdef EINTR
    {EINTR, "Interrupted function call"},
# endif
# ifdef EINVAL
    {EINVAL, "Invalid argument"},
# endif
# ifdef EIO
    {EIO, "Input/output error"},
# endif
# ifdef EISCONN
    {EISCONN, "Socket is connected"},
# endif
# ifdef EISDIR
    {EISDIR, "Is a directory"},
# endif
# ifdef EISNAM
    {EISNAM, "Is a named type file"},
# endif
# ifdef EKEYEXPIRED
    {EKEYEXPIRED, "Key has expired"},
# endif
# ifdef EKEYREJECTED
    {EKEYREJECTED, "Key was rejected by service"},
# endif
# ifdef EKEYREVOKED
    {EKEYREVOKED, "Key has been revoked"},
# endif
# ifdef EL2HLT
    {EL2HLT, "Level 2 halted"},
# endif
# ifdef EL2NSYNC
    {EL2NSYNC, "Level 2 not synchronized"},
# endif
# ifdef EL3HLT
    {EL3HLT, "Level 3 halted"},
# endif
# ifdef EL3RST
    {EL3RST, "Level 3 halted"},
# endif
# ifdef ELIBACC
    {ELIBACC, "Cannot access a needed shared library"},
# endif
# ifdef ELIBBAD
    {ELIBBAD, "Accessing a corrupted shared library"},
# endif
# ifdef ELIBMAX
    {ELIBMAX, "Attempting to link in too many shared libraries"},
# endif
# ifdef ELIBSCN
    {ELIBSCN, "lib section in a.out corrupted"},
# endif
# ifdef ELIBEXEC
    {ELIBEXEC, "Cannot exec a shared library directly"},
# endif
# ifdef ELOOP
    {ELOOP, "Too many levels of symbolic links"},
# endif
# ifdef EMEDIUMTYPE
    {EMEDIUMTYPE, "Wrong medium type"},
# endif
# ifdef EMFILE
    {EMFILE, "Too many open files"},
# endif
# ifdef EMLINK
    {EMLINK, "Too many links"},
# endif
# ifdef EMSGSIZE
    {EMSGSIZE, "Message too long"},
# endif
# ifdef EMULTIHOP
    {EMULTIHOP, "Multihop attempted"},
# endif
# ifdef ENAMETOOLONG
    {ENAMETOOLONG, "Filename too long"},
# endif
# ifdef ENETDOWN
    {ENETDOWN, "Network is down"},
# endif
# ifdef ENETRESET
    {ENETRESET, "Connection aborted by network"},
# endif
# ifdef ENETUNREACH
    {ENETUNREACH, "Network unreachable"},
# endif
# ifdef ENFILE
    {ENFILE, "Too many open files in system"},
# endif
# ifdef ENOBUFS
    {ENOBUFS, "No buffer space available"},
# endif
# ifdef ENODATA
    {ENODATA, "No  message  is  available  on the STREAM head read queue"},
# endif
# ifdef ENODEV
    {ENODEV, "No such device"},
# endif
# ifdef ENOENT
    {ENOENT, "No such file or directory"},
# endif
# ifdef ENOEXEC
    {ENOEXEC, "Exec format error"},
# endif
# ifdef ENOKEY
    {ENOKEY, "Required key not available"},
# endif
# ifdef ENOLCK
    {ENOLCK, "No locks available"},
# endif
# ifdef ENOLINK
    {ENOLINK, "Link has been severed"},
# endif
# ifdef ENOMEDIUM
    {ENOMEDIUM, "No medium found"},
# endif
# ifdef ENOMEM
    {ENOMEM, "Not enough space"},
# endif
# ifdef ENOMSG
    {ENOMSG, "No message of the desired type"},
#endif
# ifdef ENONET
    {ENONET, "Machine is not on the network"},
# endif
# ifdef ENOPKG
    {ENOPKG, "Package not installed"},
# endif
# ifdef ENOPROTOOPT
    {ENOPROTOOPT, "Protocol not available"},
# endif
# ifdef ENOSPC
    {ENOSPC, "No space left on device"},
# endif
# ifdef ENOSR
    {ENOSR, "No STREAM resources"},
# endif
# ifdef ENOSTR
    {ENOSTR, "Not a STREAM"},
# endif
# ifdef ENOSYS
    {ENOSYS, "Function not implemented"},
# endif
# ifdef ENOTBLK
    {ENOTBLK, "Block device required"},
# endif
# ifdef ENOTCONN
    {ENOTCONN, "The socket is not connected"},
# endif
# ifdef ENOTDIR
    {ENOTDIR, "Not a directory"},
# endif
# ifdef ENOTEMPTY
    {ENOTEMPTY, "Directory not empty"},
# endif
# ifdef ENOTSOCK
    {ENOTSOCK, "Not a socket"},
# endif
# ifdef ENOTSUP
    {ENOTSUP, "Operation not supported"},
# endif
# ifdef ENOTTY
    {ENOTTY, "Inappropriate I/O control operation"},
# endif
# ifdef ENOTUNIQ
    {ENOTUNIQ, "Name not unique on network"},
# endif
# ifdef ENXIO
    {ENXIO, "No such device or address"},
# endif
# ifdef EOPNOTSUPP
    {EOPNOTSUPP, "Operation not supported on socket"},
# endif
# ifdef EOVERFLOW
    {EOVERFLOW, "Value too large to be stored in data type"},
# endif
# ifdef EPERM
    {EPERM, "Operation not permitted"},
# endif
# ifdef EPFNOSUPPORT
    {EPFNOSUPPORT, "Protocol family not supported"},
# endif
# ifdef EPIPE
    {EPIPE, "Broken pipe"},
# endif
# ifdef EPROTO
    {EPROTO, "Protocol error"},
# endif
# ifdef EPROTONOSUPPORT
    {EPROTONOSUPPORT, "Protocol not supported"},
# endif
# ifdef EPROTOTYPE
    {EPROTOTYPE, "Protocol wrong type for socket"},
# endif
# ifdef ERANGE
    {ERANGE, "Result too large"},
# endif
# ifdef EREMCHG
    {EREMCHG, "Remote address changed"},
# endif
# ifdef EREMOTE
    {EREMOTE, "Object is remote"},
# endif
# ifdef EREMOTEIO
    {EREMOTEIO, "Remote I/O error"},
# endif
# ifdef ERESTART
    {ERESTART, "Interrupted system call should be restarted"},
# endif
# ifdef EROFS
    {EROFS, "Read-only filesystem"},
# endif
# ifdef ESHUTDOWN
    {ESHUTDOWN, "Cannot send after transport endpoint shutdown"},
# endif
# ifdef ESPIPE
    {ESPIPE, "Invalid seek"},
# endif
# ifdef ESOCKTNOSUPPORT
    {ESOCKTNOSUPPORT, "Socket type not supported"},
# endif
# ifdef ESRCH
    {ESRCH, "No such process"},
# endif
# ifdef ESTALE
    {ESTALE, "Stale file handle"},
# endif
# ifdef ESTRPIPE
    {ESTRPIPE, "Streams pipe error"},
# endif
# ifdef ETIME
    {ETIME, "Timer expired"},
# endif
# ifdef ETIMEDOUT
    {ETIMEDOUT, "Connection timed out"},
# endif
# ifdef ETXTBSY
    {ETXTBSY, "Text file busy"},
# endif
# ifdef EUCLEAN
    {EUCLEAN, "Structure needs cleaning"},
# endif
# ifdef EUNATCH
    {EUNATCH, "Protocol driver not attached"},
# endif
# ifdef EUSERS
    {EUSERS, "Too many users"},
# endif
# ifdef EWOULDBLOCK
    {EWOULDBLOCK, "Operation would block"},
# endif
# ifdef EXDEV
    {EXDEV, "Improper link"},
# endif
# ifdef EXFULL
    {EXFULL, "Exchange full"},
# endif
    {0, "Success"}
  };

#endif /* !MYUTILS_STRERROR_H_ */
