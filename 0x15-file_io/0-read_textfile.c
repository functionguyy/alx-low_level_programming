#include "main.h"
void *malloc_checked(unsigned int b);
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file to be read
 * @letters: numbers of letters it should read and print
 *
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	/* declare variables */
	char *buffer;
	ssize_t charReadCount, charWriteCount;
	int fd;

	/* initialize the variables */
	buffer = NULL;
	charReadCount = 0;
	charWriteCount = 0;
	fd = 0;



	if (filename == NULL)
		return (0);

	/* open file in read only mode */
	fd = open(filename, O_RDONLY);

	/* confirm the open call was successful */
	if (fd == -1)
		return (0);

	/* request memory allocation the heap */
	buffer = malloc_checked(sizeof(char) * letters);

	/* read the file content of the file open at fd */
	charReadCount = read(fd, buffer, letters);

	/* confirm the read calls are successful */
	if (charReadCount == -1)
		return (0);

	/* print content to the POSIX standard output */
	charWriteCount = write(STDOUT_FILENO, buffer, charReadCount);

	if (charWriteCount == -1 || charWriteCount < charReadCount)
		return (0);

	close(fd);
	free(buffer);

	return (charWriteCount);
}
/**
 * malloc_checked - allocates memory using malloc
 * @b: size of the memory bytes to be allocated
 *
 * Return: pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	/* declare variable */
	void *memory;


	/* initialize variable */
	memory = NULL;

	/* request memory allocation */
	memory = malloc(b);

	if (memory == NULL)
		exit(98);

	return (memory);
}
