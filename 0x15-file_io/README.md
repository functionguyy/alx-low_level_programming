# 0x15. C - FILE I/O
## How to create, open, close, read and write files

You can open a file through a process by using any of the system
call variations defined with the following function prototypes:
```C
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```
OR

```C
int creat(const char *pathname, mode_t mode);
```
OR 

```C
int openat(int dirfd, const char *pathname, int flags);
int openat(int dirfd, const char *pathname, int flags, mode_t mode); /*use
								       this to
								       set the
								       permission
								       mode of
								       the
								       opened
								       file*/
```
To use any of the above prototypes in your programs, you have include the
following header files
```C

```
