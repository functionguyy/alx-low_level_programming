#include "main.h"
/**
* rot13 - function that encodes a string using ROT13
* @str: pointer to the string to be encoded
*
* Description: ROT13 is a simple letter substitution cipher that
* replaces a letter with the 13th letter after it in the alphabet.
* Return: pointer to the resulting string
*/
char *rot13(char *str)
{
	int loop_idx;
	int check_idx;
	char *rot13_in =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13_out =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	loop_idx = 0;
	while (str[loop_idx] != '\0')
	{
		check_idx = 0;
		while (rot13_in[check_idx] != '\0')
		{
			if (str[loop_idx] == rot13_in[check_idx])
			{
				str[loop_idx] = rot13_out[check_idx];
				break;
			}
			check_idx++;
		}
		loop_idx++;
	}
	return (str);

}
