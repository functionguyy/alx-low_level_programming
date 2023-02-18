#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#define BUFSIZE 1024

int open_to_file(char *filename);
int open_from_file(char *filename);
void close_fd(int fd);

/**
* main - program copies the content of a file to another file
* @ac: number of program arguments
* @av: array of pointers to the program arguments
*
* Return: 0 if successful or exit with specified error status code
*/
int main(int ac, char *av[])
{
	int n_read, n_write, fd_from, fd_to;
	char buf[BUFSIZE];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_to = open_to_file(av[2]);
	fd_from = open_from_file(av[1]);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close_fd(fd_to);
		exit(98);
	}


	while ((n_read = read(fd_from, buf, BUFSIZE)) > 0)
	{

		n_write = write(fd_to, buf, n_read);

		if (n_write == -1 || n_write < n_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			close_fd(fd_from);
			close_fd(fd_to);
			exit(99);
		}
	}

	if (n_read == -1 && errno == EACCES)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close_fd(fd_from);
		close_fd(fd_to);
		exit(98);
	}

	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}

/**
* open_to_file - opens or creates the file to be copied to
* @filename: file name passed to the command
*
* Description: if file name already exist truncate it
* if filename does not exist and it cannot create exit with status 99 and
* print error message to POSIX standard error followed by new line.
* Return: file descriptor if successful or -1 if failure
*/
int open_to_file(char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_EXCL | O_SYNC, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IWGRP | S_IROTH);

	if (fd == -1 && errno == EEXIST)
	{
		fd = open(filename, O_WRONLY | O_TRUNC | O_SYNC);
	}
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);

}

/**
* open_from_file - opens the file to be copied from
* @filename: file passed to the command
*
* Description: if file does not exist, or if it can not read the file, exit
* with status code 98 and print error message to POSIX standard error followed
* by new line.
* Return: file descriptor if successful or exit with status code 98
*/
int open_from_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}

/**
* close_fd - closes file descriptor
* @fd1: file descriptor of first argument
* @fd2: file descriptor of second argument
*
* Description: if close_fd() can not close a file descriptor it will print
* error message to POSIX standard error and exit with status 100
* Return: nothing if successful or exit with status code 100
*/
void close_fd(int fd)
{
	int cfd;

	cfd = close(fd);
	if (cfd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
