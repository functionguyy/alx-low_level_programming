#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - prints the last digit of the random number
 * number stored in the variable n
 * Return: Always 0 (success)
 */
int main(void)
{
	int n;
	int ln;

	ln = n % 10;
	srand(time(0));
	n = rand()  -  RAND_MAX / 2;
	if (ln > 5)
	{
		printf("Last digit of %d is %d and is greater that 5\n", n, ln);

	} else if (last_number < 6 && last != 0)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, ln);

	} else if (last == 0)
	{
		printf("Last digit of %d is %d and is 0\n", n, ln);

	}
	return (0);
}
