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

**file creation flags** affect how the `open()` call is excuted while the
**file status flags** affect how other input/ouput operations on the file is
executed.

The file creation flags are: `O_CREAT`, `O_EXCL`, `O_CLOEXEC`, `O_DIRECTORY`,
`O_NOCTTY`, `O_NOFOLLOW`, `O_TMPFILE`, and `O_TRUNC`.

(for the list of file status flags run `man 2 open` on your bash shell and read
 the manua)

The _mode_ argument must 


```C
/* To open the file specified by this file path /0x15-file_io/README.md for
 * writing only either by creating it(if it does not already exist).
 */

#include
#include <fcntl.h>

int fd;
char *pathname = "/0x15-file_io/README.md";

fd = open(pathname, O_WRONLY | O_CREAT)

```



The `creat()` system call is equivalent to calling `open()` with the `flag`
argument set as `O_CREATE|O_WRONLY|O_TRUNC`
