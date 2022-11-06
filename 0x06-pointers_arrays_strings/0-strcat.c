/**
 *_strcat - concatenate two strings
 *@dest: pointer arg 1
 *@src: pointer arg 2
 *Return: pointer to the resulting  concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (*(dest + i) != '\0')
	{
		i++;
	}
	while (*(src + j) != '\0')
	{
		*(dest + i) = src[j];
		i++;
		j++;

	}
	*(dest + i) = '\0';
	return (dest);
}
