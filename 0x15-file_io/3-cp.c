#include "main.h"
#define BUFSIZE 1024

int open_to_file(char *filename);
int open_from_file(char *filename);
void close_fd(int fd);
/**
 * main - program copies the content of a file to another file
 * @ac: number of command line argument passed to the program
 * @av: array of pointers to  string literals of the command line arguments
 *
 * Return: 0 if successful or exit with specified error status code
 */
int main(int ac, char *av[])
{
	/* declare variables */
	ssize_t nRead, nWrite;
	int fdFrom, fdTo;
	char buffer[BUFSIZE];


	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fdFrom = open_from_file(av[1]);
	fdTo = open_to_file(av[2]);

	while ((nRead = read(fdFrom, buffer, BUFSIZE)) > 0)
	{
		nWrite = write(fdTo, buffer, nRead);

		if (nWrite == -1 || nWrite < nRead)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			close_fd(fdFrom);
			close_fd(fdTo);
			exit(99);
		}
	}

	if (nRead == -1 || errno == EACCES)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close_fd(fdFrom);
		close_fd(fdTo);
		exit(98);
	}

	close_fd(fdFrom);
	close_fd(fdTo);
	return (0);
}
/**
 * open_from_file - opens or creates the file to be copied to
 * @filename: file name passed as a command line argument
 *
 * Description: if filename does not exist, or if it cannot read it, exit with
 * status code 98 and print message to POSIX standard error followed by new
 * line
 * Return: file descriptor if successful or exit with status code 98
 */
int open_from_file(char *filename)
{
	int fd;

	/* initialze variable */
	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}

	return (fd);
}
/**
 * close_fd - closes file descriptor
 * @fd: file descriptor
 *
 * Description: if it cannot close a file descriptor it will print error
 * message to POSIX standard error and exit with status 100
 * Return: returns Nothing if successful or exit with status code 100
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
/**
 * open_to_file - opens or creates the file to be copied to
 * @filename: file name passed as a commandline argument
 *
 * Description: if file name already exist truncate it
 * if filename does not exist and it cannot create it, exit with status 99 and
 * print error message POSIX standard error followed by new line. print error
 * message to POSIX standard error followed by a new line.
 * Return: file descriptor if successful or -1 if failure
 */
int open_to_file(char *filename)
{
	int fd;
	mode_t perm;


	perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	fd = open(filename, O_WRONLY | O_CREAT | O_EXCL | O_SYNC, perm);

	if (fd == -1 && errno == EEXIST)
		fd = open(filename, O_WRONLY | O_TRUNC | O_SYNC);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (fd);
}
