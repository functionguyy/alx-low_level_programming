/**
* cap_string - function capitalizes all words of a string
* @s: pointer to the string
*
* Return: pointer to the resulting string
*/
char *cap_string(char *s)
{
	char upper_ver;
	int loop_idx;

	loop_idx = 0;
	while (s[loop_idx] != '\0')
	{
		if (loop_idx == 0 && s[loop_idx] >= 'a' && s[loop_idx] <= 'z')
		{
			upper_ver = s[loop_idx] + 'A' - 'a';
			s[loop_idx] = upper_ver;
		}
		else if (s[loop_idx] == '\x20' || s[loop_idx] == '\t' || s[loop_idx]
				== '\n' || s[loop_idx] == ',' || s[loop_idx] ==
				'.' || s[loop_idx] == '!' || s[loop_idx] == '?'
				|| s[loop_idx] == '"' || s[loop_idx] == '(' ||
				s[loop_idx] == ')' || s[loop_idx] == '{' ||
				s[loop_idx] == '}')
		{
			if (s[loop_idx + 1] >= 'a' && s[loop_idx + 1] <= 'z')
			{
				upper_ver = s[loop_idx + 1] + 'A' - 'a';
				s[loop_idx + 1] = upper_ver;
			}
		}
		loop_idx++;

	}

	return (s);
}
