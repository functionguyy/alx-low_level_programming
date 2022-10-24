#include <stdio.h>

/**
* main - Entry point of main program
* Description: Print the sum of even Fibonacci numbers up to a fib value
* not exceeding 4,000,000.
* Return: 0
*/

int main(void)
{
	int i;
	int j;
	int total;
	int k;

	i = 1;
	j = 2;
	total = 0;

	while (j < 4000000)
	{
		if (j % 2 == 0)
		{
			total += j;
		}

		k = j;
		j += i;
		i = k;
	}
	printf("%i\n", total);
	return (0);
}
