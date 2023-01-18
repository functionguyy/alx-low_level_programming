#include <stdio.h>
#include <stdlib.h>
/**
* main - multiplies two numbers passed as command-line arguments
* @argc: number of command-line arguments
* @argv: array of pointers to the command-line arguments 
*
* Return: 0 for success or 1 for failed execution
**/

int main(int argc, char *argv[])
{
	int i, res, num;

	res = 1;
	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}
	for (i = 1; i < argc; i++)
	{
		num = atoi(argv[i]);
		res = res * num;
	}

	printf("%d\n",res);
	return (0);
}
