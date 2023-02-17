#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int check_file_exist(int fd);

/**
* create_file - creates a regular file
* @filename: name of the file to create
* @text_content: string to write
*
* Description: the created file must have permissions: rw-------.
* if the file already exist, do not change the permissions.
* if the file already exists, truncate it.
* if the text_content is NULL create an empty file
* Return: 1 on success or -1 on failure (file can not be created, file can not
* be written, write "fails", etc, ...)
*/


int create_file(const char *filename, char *text_content)
{
	int fd, n_write, s_count, n;


	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);

	n = check_file_exist(fd);

	if (n == 1)
		fd = open(filename, O_RDWR | O_TRUNC);

	if (text_content == NULL)
		return (1);

	s_count = strlen(text_content);

	n_write = write(fd, text_content, s_count);

	if (n_write == -1 || n_write < s_count)
		return (-1);

	close(fd);

	return (1);
}

/**
* check_file_exist - check if the file exit
* @n: integer
*
* Return: 1 if file exist or 0 otherwise
*/
int check_file_exist(int n)
{
	if (n == -1 && errno == EEXIST)
	{
		return (1);
	}
	return (0);
}
