# 0x15. C - FILE I/O
## How to create, open, close, read and write files

### How to open a file
The `open()` system call is the first step required for a process to acess an
existing file.

You can open a file through a process by using any of the variations of the system
call defined with the following function prototypes:

```C
int open(const char *pathname, int flags);

/* Use this to set the user permission mode for the opened file */
int open(const char *pathname, int flags, mode_t mode);
```

To use any of the above prototypes in your programs, you should include the
following header files

```C
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
```

The `open()` system call opens the file specified by `pathname`. 


If `open()` successfully opened the file specified by `pathname`, it returns  
a non-negative integer value which is called a __file descriptor__. 

Reading, writing, setting input/output parameters, determining file status and
closing the file all use the file descriptor returned by `open()`

if `open()` failed to open the file specified by `pathname`, it will return
$-1$.

The `flags` argument of the `open()` call must include exactly one of the
following access modes parameters:

- `O_RDONLY` : open file for reading only (you can not save or write new data
		to the file)
- `O_WRONLY` : Open file for writing only (you can not read or output data
		that is already saved on the file but you can add to it)
- `O_RDWR` : Open file for writing and reading.

Zero or more **file creation flags** and **file status flags** can be
bitwise-or'd together with the access modes paramters in the `flags` argument. 

**file creation flags** affect how the `open()` call is executed while the
**file status flags** affect how subsequent input/ouput operations on the file is
executed.

The  file creation flags parameters are: `O_CREAT`, `O_EXCL`, `O_CLOEXEC`, `O_DIRECTORY`,
`O_NOCTTY`, `O_NOFOLLOW`, `O_TMPFILE`, and `O_TRUNC`.

For example, to make your `open()` call create a new regualr file if the
regualar file you specified in the `pathname` paramter does not exist, 
you can include `O_CREAT` in the `flags` argument.

- `O_CREAT` - if specified as a parameter of the `flags` argument of `open()`
will make the call create a new file if the file specified by the `pathname`
parameter  does not exist.

- `O_TRUNC` - if bitwised-or'd with either `O_RDWR` or `O_WRONLY` and
specified as parameters in the `flags` argument of `open()` will make the call 
delete everything previously saved on the file  specified by `pathname` if the file is a regular file.


(for the complete list of file status flags and more details run `man 2 open` on your bash shell and read
 the manual)

If `O_CREAT` or `O_TMPFILE` is set as a `flags` argument parameter then you must set 
the `mode` argument parameter as well. Otherwise you can omit it.

The parameter of the `mode` argument will set the permission access of future usage of the file.

The following symbolic constants are the provided parameters for  the `mode`
argument:

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


#### Opening a File in Writing only access mode 

```C
/* Open the file specified by this file path "/0x15-file_io/README.md" for
 * writing only, either by creating it (if the file does not already exist), or by
 * truncating its length to 0 (if it does exist). In the case where the file
 * doesn't exist, if the call open() creates a new file, the permission access
 * mode to permit reading and writing by owner, and to permit reading only by
 * group members and others.
 */

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
#### Opening a File using an Existence Check

```C
/* The following example uses the open() function to try to create the
 * LOCKFILE file and open it for writing. since the open() function specifies
 * the O_EXCL flag, the call fails if the file already exists. In that case,
 * the program assumes that someone else is updating the file
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define LOCKFILE "/etc/ptmp"

int main()
{
       
	int pfd; /* integer for file descriptor returned by open() call. */

	if ((pfd = open(LOCKFILE, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1 )
	{
 		fprintf(stderr, "Cannot open /etc/ptmp. Try again later. \n");
		exit(1);

	}
}
```


#### Using openat() to open a file
```C
int openat(int dirfd, const char *pathname, int flags);

/* Use to set the user permission mode for the opened file */
int openat(int dirfd, const char *pathname, int flags, mode_t mode);
```

The `openat()` system call operates in exactly the same way as `open()`,
except for some differences (run `man 2 open` on your bash terminal and read
man page for more details)

**NB**: the `dirfd` argument paramter is the value returned by `open()` when
`O_PATH` file status flag is specified as a parameter in its `flags` argument.

### How to create a file

You can use `open()` to create a new regular file if you specify `O_CREAT`
file creation flag as a parameter of the its `flags` argumment.

```C

/* Open file specified in pathname in read and write mode or 
 * create a new regular file if file specified in pathname does not exit
 * and open it in read and write mode  
 */
int fd;
fd = open(pathname, O_RDWR | O_CREAT, mode);
```
you can also create a new file with the `creat()` system call.

```C
int creat(const char *pathname, mode_t mode);
```

The `creat()` system call is equivalent to calling `open()` with the `flag`
argument parameters set as `O_CREATE|O_WRONLY|O_TRUNC`

What this means is that if the file specified in the `pathname` paramter exist
and your program call has write permission to the file, `creat()` will delete
all the data in the file and set its size to 0.

Although the use of `open()` to create a regular file is preferable to the use
of `creat()`..

There are also some other system calls that are used to create special types
of files:

- `mknod`: create regular files, FIFO(first-in-first-out) files, or special files
- `mkfifo`: create named pipe (FIFO) files
- `pipe`: create unnamed pipe
- `socket`: create sockets
- `mkdir`: create directories
- `symlink`: create symbolic link

### How to write to a file 
`write()` system call is used to write to file by using a file descriptor to
indentify the file it should write to. The prototype of `write()` is defined
as:
```C
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
```
`ssize_t` and `size_t` are respectively unsigned and signed integer data types.

`fd` takes the file descriptor parameter of the file you want to
write. `buf` takes the pointer to the data to be written and `count` takes the
value of the total number of bytes in `buf` to be written to the file.

Then `write()` writes up to `count` bytes from the buffer starting at `buf` to
the file referred to by `fd`.

for example to write some data to the standard output device (file descriptor 1) you can do this:
```C
#include <unistd.h>

int main()
{
	char *buf = "hello";

	write(1, buf, 6); 

	return (0);
}
```

If `write()` executes successfully, it returns the number of bytes written

```C
#include <stdio.h>
#include <unistd.h>

int main()
{
	int count;
	char *buf = "hello";

	count = write(1,buf,6);
	printf("Total bytes written: %d\n", count);

	return (0);

}
```

A successful return from `write()` does not make any guarantee that data has
been committed to disk. The only way to make sure is to call `fsync(fd)`after
you are done writing al your data. (run `man 2 fsync` on your bash terminal for more details)

A successful `write()` may transfer fewer than `count` bytes. In event of a
partial write, the caller can make another `write()` call to transfer the
remaining bytes. The subsequent call will transfer further bytes or may result
in an error. (Run `man 2 write on your bash terminal and read Notes section for more details).

if `write()` fails to execute, it returns $-1$ and `errno` is set to indicate the cause of error

if `count` is zero and `fd` refers to a regular file, then `write()` may
return a failure status if one of the errors specified in the write(2) man
page is detected, if no error is detectd, or error detection is not performed,
$0$ will be returned without causing any other effect. For non-regular files,
the results are unspecified..


### How to read a file

`read()` system call is used to read a file by using a file descriptor to
indentify the file it should read from. The prototype of `read()` is defined
as:
```C
ssize_t read(int fd, void *buf, size_t count);
```
where `ssize_t` is a `signed integer` and `size_t` is an `unsigned integer`

`read()` attempts to read up to `count` bytes from file descriptor `fd` into the
buffer starting at `buf`


### Resources

- [Program on open() system call](https://dextutor.com/open-system-call/)
- [write()/read() system call](https://dextutor.com/write-read-system-call/)
- [Using the open() system call](https://stackoverflow.com/questions/596306/using-the-open-system-call)
- [file descriptors explained in simple terms](https://stackoverflow.com/questions/5256599/what-are-file-descriptors-explained-in-simple-terms/5256705#5256705)
- [file descriptors](https://bottomupcs.com/ch01s03.html)
- [Everything is a file](https://en.wikipedia.org/wiki/Everything_is_a_file)
- [Open() system call explained](https://pubs.opengroup.org/onlinepubs/9699919799/functions/open.html)
- [file descriptor explained](https://www.computerhope.com/jargon/f/file-descriptor.htm)
- [Using file descriptors](https://sites.ualberta.ca/dept/chemeng/AIX-43/share/man/info/C/a_doc_lib/aixprggd/genprogc/fdescript.htm)
- [File creation and removal](https://sites.ualberta.ca/dept/chemeng/AIX-43/share/man/info/C/a_doc_lib/aixprggd/genprogc/file_create_remove.htm#A9F59BBA707judy)
- [System call vs Function call](https://pediaa.com/what-is-the-difference-between-system-call-and-function-call/#:~:text=In%20brief%2C%20system%20calls%20are%20associated%20with%20kernel,by%20a%20program%20to%20perform%20a%20specific%20task.)

