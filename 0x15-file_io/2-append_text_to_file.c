#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
/**
* append_text_to_file - appends text at the end of a file
* @filename: name of the file
* @text_content: string to add to the end of the file
*
* Return: 1 on success and -1 on failure
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, n_write, s_count;


	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_APPEND | O_SYNC);
	if (fd == -1 || errno == EACCES)
	{
		return (-1);
	}
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}
	n_write = write(fd, tex_content, s_count);

	if (n_write == -1 || n_write < s_count)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
