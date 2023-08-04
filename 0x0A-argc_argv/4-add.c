#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/**
 * main - program adds positive numbers passed as command-line argument
 * @argc: count of command line argument supplied to the program
 * @argv: array of pointer to the strings of the command line argument passed
 * to the program
 *
 * Return: 0 for successful execution or 1 otherwise
 */

int main(int argc, char *argv[])
{
	int count, result;
	char *error;
	long strtoN;


	error = "";
	errno = 0;
	result = 0;
	if (argc < 2)
	{
		printf("%d\n", 0);
		return (0);
	}
	for (count = 1; count < argc; count++)
	{
		/* convert string digit to long int */
		strtoN = strtol(argv[count], &error, 10);

		/* check if strtol encountered an invalid character */
		if (errno != 0 || *error != '\0' || strtoN < 0)
		{
			printf("Error\n");
			return (1);
		}

		result += strtoN;
	}
	printf("%d\n", result);
	return (0);
}
