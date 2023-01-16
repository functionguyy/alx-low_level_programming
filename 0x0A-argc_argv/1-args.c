#include <stdio.h>
/**
* main - print the number of arguments passed into the program
* @argc: Count of command line argument passed to the program
* @argv: Array containg the command line strings passed to the program
*
* Return: Always zero for success
**/

int main(int argc, char __attribute__((__unused__)) *argv[])
{
	printf("%d\n", argc - 1);

	return (0);
}
