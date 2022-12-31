/**
* _memcpy - function that copies memory area
* @dest: destination string
* @src: source string
* @n: number of memory bytes to copy
*
* Return: pointer to destination string
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int loop_idx;

	for (loop_idx = 0; loop_idx < n; loop_idx++)
	{
		*(dest + loop_idx) = *(src + loop_idx);
	}
	return (dest);

}
