#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "3-calc.h"
/**
* main - Perform simple math operations
* @argc: number of command-line arguments
* @argv: array of pointers to the command-line arguments
*
* Description: Usage calc num1 operator num2
* You can assume num1 and num2 are integers, so use the atoi function to
* convert them from the string input to int
* operator is one of the following: + - * / %
* The program prints the result of the operation, followed by a new line
* You can assume that the result of all operations can be stored in an int
* if the number of arguments is wrong, print Error, followed by an new line,
* and exit with status 98
* if the operator is none of the above, print Error, followed by a new line,
* and exit with status 99
* if the user tries to divde(/ or %) by 0, print Error, followed by a new
* line, and exit with status 100
* Return: Always 0 for successful execution
*/
int main(int argc, char *argv[])
{
	int num1, num2;
	int (*op_func_ptr)(int, int);


	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	op_func_ptr = get_op_func(argv[2]);

	if (!(op_func_ptr))
	{
		printf("Error\n");
		exit(99);
	}

	printf("%d\n", (op_func_ptr)(num1, num2));

	return (0);
}
