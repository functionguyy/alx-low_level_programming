# 0x15. C - FILE I/O
## How to create, open, close, read and write files

You can open a file through a process by using any of the system
call variations defined with the following function prototypes:
```C
int open(const char *pathname, int flags);

/* Use this to set the user permission mode for the opened file */
int open(const char *pathname, int flags, mode_t mode);
```
OR

```C
int creat(const char *pathname, mode_t mode);
```
OR 

```C
int openat(int dirfd, const char *pathname, int flags);

/* Use to set the user permission mode for the opened file */
int openat(int dirfd, const char *pathname, int flags, mode_t mode);
```
To use any of the above prototypes in your programs, you have include the
following header files
```C
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
```
The `open()` system call opens the file specified by `pathname`. 

If the `open()` call successfully opened the file specified by `pathname`, 
a non-negative integer value is returned.

if the `open()` call failed to open the file specified by `pathname`, $-1$ is
returned. 

The `open()` call will fail if the file specified by `pathname` does not
exist.

To make the `open()` call create a new file if the file specified by
`pathname` does not exist, you must include `O_CREATE` in the `flags` argument.

The `flags` argument of the `open()` call must include exactly one of the
following access modes:

- `O_RDONLY` : open file for reading only (you can not save or write new data
		to the file)
- `O_WRONLY` : Open file for writing only (you can not read or output data
		that is already saved on the file but you can add to it)
- `O_RDWR` : Open file for writing and reading.

Zero or more **file creation flags** and **file status flags** can be
bitwise-or'd in `flags` argument.  

**file creation flags** affect how the `open()` call is executed while the
**file status flags** affect how subsequent input/ouput operations on the file is
executed.

The file creation flags are: `O_CREAT`, `O_EXCL`, `O_CLOEXEC`, `O_DIRECTORY`,
`O_NOCTTY`, `O_NOFOLLOW`, `O_TMPFILE`, and `O_TRUNC`.

- `O_CREAT` - if specified in `flags` the `open()` call will create a new file
if the file specified by `pathname` does not exist.

- `O_TRUNC` - if specified in `flags` argument together with `O_RDWR` or
`O_WRONLY`, the `open()` call  will delete everything previously saved on the file 
specified by `pathname` if the file is a regular file.


(for the complete list of file status flags and more details run `man 2 open` on your bash shell and read
 the manual)

If `O_CREAT` or `O_TMPFILE` is set in the `flags` argument then you must set
the `mode` argument parameter as well. You can omit it otherwise.

`mode` sets the permission access of future usage of the file.

The following symbolic constants are provided for mode:
|Symbolic constant | Meaning
| ---------------- | -------- 
| `S_IRWXU` | User (file owner) has read, write, and execute permission
  `S_IRUSR` | User has read permission
  `S_IWUSR` | User has write permission
  `S_IXUSR` | User has execute permission
  `S_IRWXG` | Group has read, write, and execute permission
  `S_IRGRP` | Group has read permission
  `S_IWGRP` | Group has write permission
  `S_IXGRP` | Group has write permission
  `S_IRWXO` | Others have read, write, and execute permission
  `S_IROTH` | Others have read permission
  `S_IWOTH` | Others have write permission
  `S_IXOTH` | Others have execute permission

```C
/* To open the file specified by this file path /0x15-file_io/README.md for
 * writing only either by creating it (if it does not already exist), or by
 * truncating its length to 0 (if it does exist). In the case where the file
 * doesn't exist, if the call open() creates a new file, the permission access
 * mode to permit reading and writing by owner, and to permit reading only by
 * group members and others.
 */

#include
#include <fcntl.h>


int main(void)
{
	int fd;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	char *pathname = "/0x15-file_io/README.md";

	fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode);

	return (0);
}

```



The `creat()` system call is equivalent to calling `open()` with the `flag`
argument set as `O_CREATE|O_WRONLY|O_TRUNC`
