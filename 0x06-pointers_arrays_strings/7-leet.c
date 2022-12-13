/**
* leet - function that encodes a string into 1337
* @s: pointer to string
*
* Description: Letters 'a' and 'A' should be replaced by 4, letters 'e'
* and 'E' should be replaced by 3, letter 'o' and 'O' should be replaced
* by 0, letters 't' and 'T' should be replaced by 7, letters 'l' and 'L'
* should be replaced by 1.
* Return: pointer the resulting string
*/
char *leet(char *s)
{
	int loop_idx;
	int check_idx;
	char *arr = "4433007711";
	char *leet_arr = "aAeEoOtTlL";

	loop_idx = 0;
	while (s[loop_idx] != '\0')
	{
		for (check_idx = 0; leet_arr[check_idx] != '\0';
				check_idx++)
			if (s[loop_idx] == leet_arr[check_idx])
				s[loop_idx] = arr[check_idx];

		loop_idx++;
	}

	return (s);
}
