#include <stdio.h>
#include <stdlib.h>
/**
* op_add - perform addition operation on two integers
* @a: first integer
* @b: second integer
*
* Return: sum of a and b
*/

int op_add(int a, int b)
{
	return (a + b);
}

/**
* op_sub - preform subtraction operation on two integers
* @a: first integer
* @b: second integer
*
* Return: difference of a and b
*/
int op_sub(int a, int b)
{
	return (a - b);
}

/**
* op_mul - perform multiplication operation on two integers
* @a: first integer
* @b: second integer
*
* Return: product of a and b
*/
int op_mul(int a, int b)
{
	return (a * b);
}

/**
* op_div - perform division operation on two integers
* @a: first integer
* @b: second integer
*
* Return: result of the division of a by b
*/
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}
/**
* op_mod - perform modulo operation on two integers
* @a: first integer
* @b: second integer
*
* Return: remainder of the division of a by b
*/
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
