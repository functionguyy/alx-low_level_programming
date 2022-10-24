#include <stdio.h>

/**
* main - computes and prints the sum of all the multiples
* of 3 or 5 below 1024
* Return: 0 if successful
*/

int main(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 1024)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			j = j + i;
		}
		i++;
	}

	printf("%d\n", j);
	return (0);
}
