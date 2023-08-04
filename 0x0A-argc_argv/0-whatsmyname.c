#include <stdio.h>
/**
 * main - prints the program name followed by a new line
 * @argc: count of the arguments supplied to the program
 * @argv: one dimensional array of pointer to the strings of the arguments
 * supplied to the program
 *
 * Return: always 0 on successful execution
 */

int main(int __attribute__((__unused__))argc, char *argv[])
{
	printf("%s\n", argv[0]);

	return (0);
}
