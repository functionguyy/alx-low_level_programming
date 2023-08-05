#include <stdio.h>
#include <stdlib.h>
/**
 * change_calc - function calculates the minimum number of coins to make change
 * for an amount of money
 * @cent: amount of money
 *
 * Return: number of coin to make change
 */

int change_calc(int cent)
{
	if (cent == 0)
		return (cent);
	else if (cent >= 25)
		cent = cent - 25;
	else if (cent < 25 && cent >= 10)
		cent = cent - 10;
	else if (cent < 10 && cent >= 5)
		cent = cent - 5;
	else if (cent < 5 && cent >= 2)
		cent = cent - 2;
	else
		cent = cent - 1;

	return (1 + change_calc(cent));
}

/**
 * main - program that prints the minimum number of coins to make change for an
 * amount of money
 * @argc: count of command line arguments supplied to the program
 * @argv: array of pointer to the strings of the arguments supplied to the
 * program
 *
 * Return: 0 for successful execution or 1 otherwise
 */

int main(int argc, char *argv[])
{
	int arg;

	if (argc > 2)
	{
		printf("Error\n");
		return (1);
	}

	arg = atoi(argv[1]);

	printf("%d\n", arg);

	if (arg < 0)
		arg = 0;
	else
		arg = change_calc(arg);

	printf("%d\n", arg);

	return (0);
}
