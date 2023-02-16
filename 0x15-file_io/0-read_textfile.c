#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
/**
* read_textfile - reads a text file and prints it to the POSIX standard output
* @filename: file to be read
* @letters: numbers of letters it should read and print
*
* Return: the actual number of letters it could read and print
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	int n_read, fd, n_write;


	if (filename == NULL)
	{
		return (0);
	}

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		return (0);
	}

	buf = malloc(sizeof(char) * letters);

	if (buf == NULL)
	{
		return (0);
	}

	n_read = read(fd, buf, letters);

	if (n_read == -1)
	{
		return (0);
	}

	n_write = write(STDOUT_FILENO, buf,  n_read);

	if (n_write == -1 || n_write < n_read)
	{
		return (0);
	}
	
	close(fd);

	free(buf);

	return (n_write);
}
