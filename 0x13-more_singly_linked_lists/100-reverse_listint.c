#include "lists.h"
/**
 * reverse_listint - reverse a singly linked list
 * @head: pointer to the pointer to the first node in the singly linked list
 *
 * Return: returns pointer to the first node for the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	/* declare variables */
	listint_t *beforeNode, *afterNode;

	/* initialize variables */
	prevNode = NULL;
	nxtNode = NULL;

	if (head == NULL || *head == NULL)
		return (NULL);


	while (*head != NULL)
	{
		nxtNode = (*head)->next;
		(*head)->next = prevNode;
		prevNode = *head;
		*head = nxtNode;
	}
	head = prevNode;

	return (*head);
}
