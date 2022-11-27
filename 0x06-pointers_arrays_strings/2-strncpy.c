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
	int idx = 0, i = 0;

	while (src[idx] != '\0')
	{
		idx++;
	}

	while (i <= n)
	{
		if ((src[i] == '\0') && (idx < n))
		{
			dest[i] = '\0';
			return (dest);
		}
		else
		{
			dest[i] = src[i];
		}

		i++;
	}

	return (dest);
}
