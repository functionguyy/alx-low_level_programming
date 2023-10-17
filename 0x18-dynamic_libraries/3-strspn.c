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
	for (loop_idx1 = 0; s[loop_idx1] != '\0'; loop_idx1++)
	{
		for (loop_idx2 = 0; accept[loop_idx2] != '\0';
				loop_idx2++)
		{
			flag = 0;
			if (s[loop_idx1] == accept[loop_idx2])
			{
				byte_count++;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	return (byte_count);
}
