#include "lists.h"
#include <stdlib.h>
/**
 * pop_listint - deletes the head node of a singly linked list
 * @head: pointer to pointer that points to the singly linked list
 *
 * Return: data item in the deleted node
 */
int pop_listint(listint_t **head)
{
	/* declare variables */
	int n;
	listint_t *currentNode;

	/* initialize variables */
	n = 0;
	currentNode = NULL;

	if (head == NULL || *head == NULL)
		return (0);


	/* delete the head node */
	currentNode = *head;
	*head = currentNode->next;
	n = currentNode->n;
	free(currentNode);


	return (n);
}
