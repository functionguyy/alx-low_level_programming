#include <stdlib.h>
#include "lists.h"
/**
 * sum_dlistint - function that returns the sum of all the data (n) of a
 * dlistint_t linked list
 * @head: pointer to the beginning of the list
 *
 * Return: sum of all the data (n) or 0 if the list is empty
 */


int sum_dlistint(dlistint_t *head)
{
	int sum;
	dlistint_t *cur_node;

	sum = 0;
	cur_node = NULL;

	if (head)
	{
		while (head != NULL)
		{
			cur_node = head;
			sum += cur_node->n;
			head = cur_node->next;
		}
		return (sum);
	}
	return (0);
}
