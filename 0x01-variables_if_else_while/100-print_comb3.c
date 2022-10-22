#include <stdio.h>
/**
*main - Enrty point of the program that prints all possible combinations of two
*digits.
*Numbers will be separated by comma and followed by a space
*the two digits will be different
*01 and 10 are considered the same combination of the two digits 0 and 1
*Return: 0 (success)
*/
int main(void)
{
	int i;
	int j;

	i = 48;
	while (i < 57)
	{
		j = i + 1;
		while (j <= 57)
		{
			putchar(i);
			putchar(j);
			if (i != 56)
			{
				putchar(',');
				putchar(' ');
			}
			j++;

		}
		i++;
	}
	putchar('\n');
	return (0);
}
