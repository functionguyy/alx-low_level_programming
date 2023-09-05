#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: string to add to the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	/* declare variables */
	int fd;
	ssize_t charWriteCount, strCount;

	/* initialize variables */
	charWriteCount = 0;
	strCount = 0;
	fd = 0;


	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND | O_SYNC);
	if (fd == -1 || errno == EACCES)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	strCount = strlen(text_content);
	charWriteCount = write(fd, text_content, strCount);

	if (charWriteCount == -1 || charWriteCount < strCount)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
