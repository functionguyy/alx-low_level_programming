#include <stdio.h>
/**
 * main - prints the number of arguments passed to it followed by a new line
 * @argc: count of the arguments supplied to the program
 * @argv: one dimensional array of pointer to the strings of the arguments
 * supplied to the program
 *
 * Return: always 0 on successful execution
 */

int main(int argc, char __attribute__((__unused__)) *argv[])
{
	printf("%d\n", argc);

	return (0);
}
