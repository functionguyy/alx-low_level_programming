#include <stdio.h>
/**
* main - prints all command line arguments it receives
* @argc: count of command line argument passed to the program
* @argv: array of command line argument strings
*
* Return: Always 0 for successful
**/

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
