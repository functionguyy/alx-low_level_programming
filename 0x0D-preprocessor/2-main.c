#include <unistd.h>
#include <stdio.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to prints
 *
 * Return: On success 1. On error, -1 is returned, and errno is set
 * appropriately
 *
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - print a string to stdout
 * @str: char array string type
 */
void _puts(char *str)
{
	/* declare variable */
	int loopIndex;

	loopIndex = 0;

	while (str[loopIndex] != '\0')
	{
		_putchar(str[loopIndex]);
		loopIndex++;
	}
	_putchar('\n');
}
/**
 * main - program that prints the name of the file it was complied from,
 * followed by a new line
 *
 * Return: if successful;
 */
int main(void)
{
	/* declare variable */
	char *name;

	/* initialize variable with a common predefined macro */
	name = __BASE_FILE__;

	/* write macro expansion output to stdout */
	_puts(name);

	/* return status of successful execution */
	return (0);
}
