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
	int index = 0;

	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	if (index < n)
	{
		dest[index] = '\0';
	}

	return (dest);
}
