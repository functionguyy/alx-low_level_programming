#include "main.h"
/**
 * _pow_recursion - function that returns the value of x raised to the power of
 * y
 * @x: integer
 * @y: power integer
 *
 * Description: if y is lower than 0, the function should return -1
 * Return: value of x raised to the power of y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	else
		return (_pow_recursion(x, (y - 1)) * x);
}
