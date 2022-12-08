/**
* leet - function that encodes a string into 1337
* @s: pointer to string
*
* Return: pointer the resulting string
*/
char *leet(char *s)
{
	int loop_idx;

	loop_idx = 0;
	while (s[loop_idx] != '\0')
	{
		if (s[loop_idx] == 'a' || s[loop_idx] == 'A')
			s[loop_idx] = '4';
		else if (s[loop_idx] == 'e' || s[loop_idx] == 'E')
			s[loop_idx] = '3';
		else if (s[loop_idx] == 'o' || s[loop_idx] == 'O')
			s[loop_idx] = '0';
		else if (s[loop_idx] == 't' || s[loop_idx] == 'T')
			s[loop_idx] = '7';
		else if (s[loop_idx] == 'l' || s[loop_idx] == 'L')
			s[loop_idx] = '1';
		loop_idx++;
	}

	return (s);
}
