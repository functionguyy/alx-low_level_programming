#include "main.h"
#include <errno.h>
#include <unistd.h>
#include <string.h>

int check_file_exist(int fd);
/**
 * create_file - creates a regular file
 * @filename: name of the file to create
 * @text_content: string to write
 *
 * Description: the created file will have permission: rw-------
 * if the file already exist, it does not change the file permissions.
 * if the file already exists, it truncates it.
 * if text_count is NULL it creates an empty file
 *
 * Return: 1 on success or -1 on failure (file can not be createdd, file can
 * not be written, write "fails", etc, .....)
 */
int create_file(const char *filename, char *text_content)
{
	/* declare variables */
	int fdi, sig;
	ssize_t charWriteCounti;
	size_t strCount;


	/* initialize the variables */
	fd = 0;
	charWriteCount = 0;
	strCount = 0;
	sig = 0;


	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);

	sig = check_file_exit(fd);

	if (sig == 1)
		fd = open(filename, O_RDWR | O_TRUNC);

	if (text_content == NULL)
		return (1);

	strCount = strlen(text_content);

	charWriteCount = write(fd, text_content, strCount);

	if (charWriteCount == -1 || charWriteCount < strCount)
		return (-1);

	close(fd);

	return (1);
}
/**
 * check_file_exist - check if the file exist
 * @n: integer
 *
 * Return: 1 if file exit or 0 otherwise
 */
int check_file_exist(int n)
{
	if (n == -1 && errno == EEXIST)
		return (1);

	return (0);
}
