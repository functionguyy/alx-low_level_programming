#include <stdlib.h>
#include "lists.h"
/**
* sum_listint - function that returns the sum of all the data (n) of a
* listint_t linked list
* @head: pointer to the list
*
* Return: the sum of all the data (n) or 0 if the list is empty
*/
int sum_listint(listint_t *head)
{
	int sum;

	sum = 0;
	if (head)
	{
		while (head != NULL)
		{
			sum += head->n;
			head = head->next;
		}
		return (sum);
	}
	return (0);
}
