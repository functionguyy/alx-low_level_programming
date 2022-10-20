#include <stdio.h>
/**
*main - Entry point of the program that prints the alphabet in lowercase
*followed by a new line. all letters will be printed except q and e
*Return:0 if successful
*/
int main(void)
{
	char i;

	i = 'a';
	while (i <= 'z')
	{
		if (i != 'q' && i != 'e')
		{
			putchar(i);
		}
		i++;
	}
	putchar ('\n');
	return (0);
}
