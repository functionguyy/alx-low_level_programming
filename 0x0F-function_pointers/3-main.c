#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Perform simple math operations
 * @argc: number of command-line arguments
 * @argv: array of pointers to the command-line arguments
 *
 *
 * Description: usage calc num1 operator num2
 * Return: Alawys 0 for successful exection
 */
int main(int argc, char *argv[])
{
	/* declare variable */
	int num1, num2;
	int (*opFuncPtr)(int, int);

	/* initialize variables */
	num1 = 0;
	num2 = 0;
	opFuncPtr = NULL;

	/* process the command-line arguments passed to the program */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);


	opFuncPtr = get_op_func(argv[2]);

	if (opFuncPtr == NULL)
	{
		printf("Error\n");
		exit(99);
	}


	printf("%d\n", opFuncPtr(num1, num2));


	return (0);
}
