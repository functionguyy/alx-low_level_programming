#include <string.h>
/**
* _strncpy - copies a string
* @dest: destination string pointer
* @src: source string pointer
* @n: number of bytes
*
* Description: Function copies at most n bytes of the string pointed to by src.
* if the length of src is less than n, strncpy() writes additional null bytes
* to dest to ensure that a total of n bytes.
* Return: pointer to the resulting string dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int src_count;
	int loop_idx;

	src_count = strlen(src);
	loop_idx = 0;
	if (src_count < n)
	{
		while (src[loop_idx] != '\0')
		{
			dest[loop_idx] = src[loop_idx];
			loop_idx++;
		}
		while (loop_idx < n)
		{
			dest[loop_idx] = '\0';
			loop_idx++;
		}
	}
	else if (src_count > n)
	{
		while (loop_idx < n)
		{
			dest[loop_idx] = src[loop_idx];
			loop_idx++;
		}
	}

	return (dest);
}

