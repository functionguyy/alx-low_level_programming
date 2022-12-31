/**
* _memset - function that fills memory with a constant byte.
* @b: constant byte
* @s: pointer to string
* @n: number of memory byte to fill
*
* Return: pointer to the memory area s
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int loop_idx;

	for (loop_idx = 0; loop_idx < n; loop_idx++)
	{
		*(s + loop_idx) = b;
	}
	return (s);
}
