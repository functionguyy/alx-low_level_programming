#include "lists.h"
/**
 * sum_listint - returns the sum of all the data (n) of a singly linked list
 * @head: pointer to the singly linked list
 *
 * Return: the sum of all the data (n) or 0 if the list empty
 *
 */
int sum_listint(listint_t *head)
{
	/* declare variables */
	int sum;
	listint_t *currentNode;


	/* initialize variable */
	sum = 0;
	currentNode = NULL;


	/* account for empty list */
	if (head == NULL)
		return (sum);


	/* sum the data items in the list */
	while (head != NULL)
	{
		currentNode = head;
		sum += currentNode->n;
		head = currentNode->next;
	}

	return (sum);
}
