#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - prints the last digit of the random number 
 * number stored in the variable n
 * Return: Always 0 (success)
 */
int main(void)
{
	int n;
	int last_number;

	last_number = n % 10;
	

	srand(time(0));
	n = rand() - RAND-MAX / 2;
	
	if (last_number > 5)
	{
		printf("Last digit of %d is %d and is greater that 5\n", n, last_number); 

	} else if (last_number < 6 && last !=0)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, last_number);

	} else if (last == 0)
	{
		printf("Last digit of %d is %d and is 0\n", n, last_number);

	}
	return (0);
}
