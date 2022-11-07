#include <stdio.h>
/**
 * _strncat - concatenates src strings to dest strings, using the most n bytes
 * of src and does not null terminate src if it contains n or more bytes.
 * @dest: destination string
 * @src: source strings
 * @n: integer for he most src bytes to append to dest
 *
 * Return: pointer to the resulting dest string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (*(dest + i) != '\0')
	{
		i++;
	}

	j = 0;
	while (j < n && *(src + j) != '\0')
	{
		*(dest + i) = src[j];
		i++;
		j++;
	}
	
    	*(dest + i) = '\0';
	return (dest);
}
