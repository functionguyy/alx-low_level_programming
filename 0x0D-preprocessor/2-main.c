#include <stdio.h>

/**
 * main - program that prints the name of the file it was complied from,
 * followed by a new line
 *
 * Return: if successful;
 */
int main(void)
{
	/* write macro expansion output to stdout */
	printf("%s\n", __BASE_FILE__);

	/* return status of successful execution */
	return (0);
}
