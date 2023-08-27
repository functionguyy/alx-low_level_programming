#include <stdlib.h>
#include <stdio.h>
/**
 * main - program that prints the opcode of it main function
 * @argc: count of all the arguments supplied to the program
 * @argv: array of pointer to the strings of all the argument supplied
 *
 * Description: usage: ./main number_of_bytes
 *
 * Return: Always 0 for successful execution
 */
int main(int argc, char *argv[])
{
	/* declare variables */
	int (*funcptr)(int, char **);
	unsigned char *p;
	int num_of_bytes, i;

	/* initialize variables */
	funcptr = main;
	p = (unsigned char *)*funcptr;
	i = 0;


	if (argc != 2)
	{
		printf("lol\n");
		exit(1);
	}

	num_of_bytes = atoi(argv[1]);

	if (num_of_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	while (i < num_of_bytes)
	{
		printf("%02x ", p[i]);
		i++;
	}

	putchar('\n');



	return (0);
}
