#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/**
* main - adds positive numbers passed as command-line argument
* @argc: number of command-line arguments
* @argv: array of pointers to the command-line arguments
*
* Description: Print the result, followed by a new line 
* if no number is passed to the program, print 0, followed by a new line
* if one of the number contains symbols that are not digits, print Error,
* followed by a new line, and return 1
* You can assume that numbers and the addition of all the numbers can be
* stored in an int
* Return: 0 for success or 1 for failed execution
**/

int main(int argc, char *argv[])
{
	int i, res;
	char *p;
	long convN;

	errno = 0;
	res = 0;
	if (argc < 2)
	{
		printf("%d\n", 0);
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		convN = strtol(argv[i], &p, 10);
		if (errno != 0 || *p != '\0' || convN < 0)
		{
			printf("Error\n");
			return (1);
		}

		res = res + convN;
	}
	printf("%d\n", res);
	return (0);
}
