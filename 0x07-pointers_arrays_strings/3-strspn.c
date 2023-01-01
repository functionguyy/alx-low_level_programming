#include <string.h>
/**
* _strspn - Function that gets the length of prefix substring
* @s: the source string to be searched
* @accept: the accepted string to check in source string
*
* Return: number of bytes in the initial segment of s which consist only
* of bytes from accept
*/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int loop_idx1, loop_idx2, byte_count;
	int flag;

	byte_count = 0;
	loop_idx1 = 0;
	while (s[loop_idx1] != '\0')
	{
		loop_idx2 = 0;
		while (accept[loop_idx2] != '\0')
		{
			flag = 0;
			if (s[loop_idx1] == accept[loop_idx2])
			{
				byte_count++;
				flag = 1;
				break;
			}
			loop_idx2++;
		}
		if (flag == 0)
		{
			break;
		}
		loop_idx1++;
	}
	return (byte_count);
}
