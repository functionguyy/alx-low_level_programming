#include "main.h"
#include <string.h>
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: returns the converted number, or 0 if there is one or more chars in
 * the string b that is not 0 or 1 or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	/* declare variables */
	unsigned int count, i;
	unsigned int u_number;


	if (b == NULL)
		return (0);

	/* initialize variables */
	count = strlen(b);
	i = 0;
	u_number = 0;

	while (i < count)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		/**
		 * shift the leftmost bit of the current value of the converted
		 * number by 1 place
		 */
		u_number <<= 1;

		/**
		 * add the integer value of the current bit at current loop position of
		 * the binary
		 */
		u_number += b[i] - '0';
		i++;
	}


	return (u_number);
}
