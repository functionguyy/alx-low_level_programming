#include <string.h>
/**
* _strchr - Function that locates a character in a string
* @s: pointer to the source string
* @c: search character byte
*
* Return: pointer
*/
char *_strchr(char *s, char c)
{
	unsigned int loop_idx, string_len;
	char *add;

	add = NULL;
	string_len = strlen(s) + 1;
	for (loop_idx = 0; loop_idx <= string_len; loop_idx++)
	{
		if (*(s + loop_idx) == c)
		{
			add = (s + loop_idx);
			break;
		}
	}
	return (add);

}
