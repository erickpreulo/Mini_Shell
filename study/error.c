#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int	main(int ac, char **av)
{
	int i;

	i = 1;
	while (i <= 106)
	{
		printf("ERROR  [%d] : %s\n",i, strerror(i) );
		i++;
	}
	// strerror : sao varias mensagens de erros ja preparadas!
// ERROR  [1] : Operation not permitted
// ERROR  [2] : No such file or directory
// ERROR  [3] : No such process
// ERROR  [4] : Interrupted system call
// ERROR  [5] : Input/output error
// ERROR  [6] : Device not configured
// ERROR  [7] : Argument list too long
// ERROR  [8] : Exec format error
// ERROR  [9] : Bad file descriptor
// ERROR  [10] : No child processes
// ERROR  [11] : Resource deadlock avoided
// ERROR  [12] : Cannot allocate memory
// ERROR  [13] : Permission denied
// ERROR  [14] : Bad address
// ERROR  [15] : Block device required
// ERROR  [16] : Resource busy
// ERROR  [17] : File exists
// ERROR  [18] : Cross-device link
// ERROR  [19] : Operation not supported by device
// ERROR  [20] : Not a directory
// ERROR  [21] : Is a directory
// ERROR  [22] : Invalid argument
// ERROR  [23] : Too many open files in system
// ERROR  [24] : Too many open files
// ERROR  [25] : Inappropriate ioctl for device
// ERROR  [26] : Text file busy
// ERROR  [27] : File too large
// ERROR  [28] : No space left on device
// ERROR  [29] : Illegal seek
// ERROR  [30] : Read-only file system
// ERROR  [31] : Too many links
// ERROR  [32] : Broken pipe
// ERROR  [33] : Numerical argument out of domain
// ERROR  [34] : Result too large
// ERROR  [35] : Resource temporarily unavailable
// ERROR  [36] : Operation now in progress
// ERROR  [37] : Operation already in progress
// ERROR  [38] : Socket operation on non-socket
// ERROR  [39] : Destination address required
// ERROR  [40] : Message too long
// ERROR  [41] : Protocol wrong type for socket
// ERROR  [42] : Protocol not available
// ERROR  [43] : Protocol not supported
// ERROR  [44] : Socket type not supported
// ERROR  [45] : Operation not supported
// ERROR  [46] : Protocol family not supported
// ERROR  [47] : Address family not supported by protocol family
// ERROR  [48] : Address already in use
// ERROR  [49] : Can't assign requested address
// ERROR  [50] : Network is down
// ERROR  [51] : Network is unreachable
// ERROR  [52] : Network dropped connection on reset
// ERROR  [53] : Software caused connection abort
// ERROR  [54] : Connection reset by peer
// ERROR  [55] : No buffer space available
// ERROR  [56] : Socket is already connected
// ERROR  [57] : Socket is not connected
// ERROR  [58] : Can't send after socket shutdown
// ERROR  [59] : Too many references: can't splice
// ERROR  [60] : Operation timed out
// ERROR  [61] : Connection refused
// ERROR  [62] : Too many levels of symbolic links
// ERROR  [63] : File name too long
// ERROR  [64] : Host is down
// ERROR  [65] : No route to host
// ERROR  [66] : Directory not empty
// ERROR  [67] : Too many processes
// ERROR  [68] : Too many users
// ERROR  [69] : Disc quota exceeded
// ERROR  [70] : Stale NFS file handle
// ERROR  [71] : Too many levels of remote in path
// ERROR  [72] : RPC struct is bad
// ERROR  [73] : RPC version wrong
// ERROR  [74] : RPC prog. not avail
// ERROR  [75] : Program version wrong
// ERROR  [76] : Bad procedure for program
// ERROR  [77] : No locks available
// ERROR  [78] : Function not implemented
// ERROR  [79] : Inappropriate file type or format
// ERROR  [80] : Authentication error
// ERROR  [81] : Need authenticator
// ERROR  [82] : Device power is off
// ERROR  [83] : Device error
// ERROR  [84] : Value too large to be stored in data type
// ERROR  [85] : Bad executable (or shared library)
// ERROR  [86] : Bad CPU type in executable
// ERROR  [87] : Shared library version mismatch
// ERROR  [88] : Malformed Mach-o file
// ERROR  [89] : Operation canceled
// ERROR  [90] : Identifier removed
// ERROR  [91] : No message of desired type
// ERROR  [92] : Illegal byte sequence
// ERROR  [93] : Attribute not found
// ERROR  [94] : Bad message
// ERROR  [95] : EMULTIHOP (Reserved)
// ERROR  [96] : No message available on STREAM
// ERROR  [97] : ENOLINK (Reserved)
// ERROR  [98] : No STREAM resources
// ERROR  [99] : Not a STREAM
// ERROR  [100] : Protocol error
// ERROR  [101] : STREAM ioctl timeout
// ERROR  [102] : Operation not supported on socket
// ERROR  [103] : Policy not found
// ERROR  [104] : State not recoverable
// ERROR  [105] : Previous owner died
// ERROR  [106] : Interface output queue is full
}