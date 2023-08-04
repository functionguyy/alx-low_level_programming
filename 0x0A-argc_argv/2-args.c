#include <stdio.h>
/**
 * main - program that prints all arguments it receives
 * @argc: count of the all the argument supplied to the program
 * @argv: array of pointer to the strings of all the argument supplied to the
 * program
 *
 * Return: Always 0 for successful execution
 */

int main(int argc, char *argv[])
{
	int count;

	for (count = 0; count < argc; count++)
	{
		printf("%s\n", argv[count]);
	}

	return (0);
}
