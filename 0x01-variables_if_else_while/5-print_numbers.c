#include <stdio.h>
/**
*main - Entry point of the program that prints all single digit numbers
*of base 10 starting from 0, followed by a new line
*Return: 0 if successful
*/
int main(void)
{
	int i;

	i = 0;
	while (i <= 9)
	{
		printf("%d", i);
		i++;
	}
	putchar('\n');
	return (0);
}

