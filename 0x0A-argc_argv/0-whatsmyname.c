#include <stdio.h>
/**
* main - prints the program name argument, followed by a new line
* @argc: count of command line argument passed to the program
* @argv: array of command line argument string
*
* Return: Always 0 for successful
**/

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
