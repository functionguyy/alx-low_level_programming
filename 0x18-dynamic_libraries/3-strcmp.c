/**
* _strcmp - compares two strings
* @s1: pointer to the first string
* @s2: pointer to the second string
*
* Description: Functions compares the two strings s1 and s2. The locale is not
* taken into account.
* Return: integer less than, equal to, or greater than zero if s1 is found,
* respectively, to be less than, to match, or be greater than s2.
*/
int _strcmp(char *s1, char *s2)
{
	int result;
	int loop_idx;

	loop_idx = 0;
	result = 0;
	while (result == 0 && s1[loop_idx] != '\0' && s2[loop_idx] != '\0')
	{
		if (s1[loop_idx] < s2[loop_idx])
		{
			result = s1[loop_idx] - s2[loop_idx];
		}
		else if (s1[loop_idx] > s2[loop_idx])
		{
			result = s1[loop_idx] - s2[loop_idx];
		}
		loop_idx++;
	}
	return (result);

}
