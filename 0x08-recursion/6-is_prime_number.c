#include "main.h"
/**
 * _prime_checker - function that performs a primality test on an integer
 * @num: a whole number
 * @d: divisor number
 *
 * Description: The function preforms repeated division of consecutive numbers
 * from d till num is either divisble by d or equal to d
 * Return: 1 if input integer is a prime number or 0 otherwise
 */

int _prime_checker(int num, int d)
{
	if (num == d)
		return (1);
	else if (num % d == 0)
		return (0);
	else
		return (_prime_checker(num, (d + 1)));
}

/**
 * is_prime_number - function check if n is a prime number
 * @n: a whole number
 *
 * Return: 1 if n is a prime number or 0 otherwise
 */

int is_prime_number(int n)
{
	int r_val;

	/* prime number cannot be less than 2 */
	if (n < 2)
		return (0);

	/* perform primality test */
	r_val = _prime_checker(n, 2);

	return (r_val);
}
