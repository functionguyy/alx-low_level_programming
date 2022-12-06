/**
* string_toupper - function that changes all lowercase letters of a string to
* uppercase.
* @s: pointer to the string array
*
* Return: pointer the resulting string
*/
char *string_toupper(char *s)
{
	int loop_idx;
	char upper_ver;

	loop_idx = 0;
	while (s[loop_idx++] != '\0')
	{
		if (s[loop_idx] >= 'a' && s[loop_idx] <= 'z')
		{
			upper_ver = s[loop_idx] + 'A' - 'a';
			s[loop_idx] = upper_ver;
		}
	}

	return (s);
}
