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
	int k;

	i = 48;
	while (i < 56)
	{
		j = i + 1;
		while (j <= 56)
		{
			k = j + 1;
			while (k <= 57)
			{
				putchar(i);
				putchar(j);
				putchar(k);
				if (i != 55)
				{
					putchar(',');
					putchar(' ');
				}
				k++;

			}
			j++;
		}
		i++;
	}
	putchar('\n');
	return (0);
}
