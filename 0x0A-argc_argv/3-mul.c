#include <stdio.h>
#include <stdlib.h>
/**
 * main - program multiplies two numbers and print the result
 * @argc: count of arguments supplied to the program
 * @argv: array of pointers to the strings of the argument supplied to the
 * program
 *
 * Return: 0 for success or 1 for failed execution
 */

int main(int argc, char *argv[])
{
	int count, result, arg;


	result = 1;
	if (argc < 3 || argc - 1 > 2)
	{
		printf("Error\n");
		return (1);
	}

	for (count = 1; count < argc; count++)
	{
		arg = atoi(argv[count]);
		result = result * arg;
	}

	printf("%d\n", result);
	return (0);
}
