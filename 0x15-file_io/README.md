# 0x15. C - FILE I/O
## How to create, open, close, read and write files

You can open a file through a process by using any of the system
call variations defined with the following function prototypes:
```C
int open(const char *pathname, int flags);

/* Use this variation if you want to set the user permission mode of the of the opened file */
int open(const char *pathname, int flags, mode_t mode);
```
OR

```C
int creat(const char *pathname, mode_t mode);
```
OR 

```C
int openat(int dirfd, const char *pathname, int flags);

/* Use this variation if you want to set the user permission mode of the of the opened file */
int openat(int dirfd, const char *pathname, int flags, mode_t mode);
```
To use any of the above prototypes in your programs, you have include the
following header files
```C

```
