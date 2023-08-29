#include "lists.h"
#include <stdlib.h>
/**
 * free_listint - frees a listint_t list
 * @head: pointer to a singly linked list
 *
 * Return: Nothing
 */
void free_listint(listint_t *head)
{
	/* declare variables */
	listint_t *currentNode;

	/* initialize variables */
	currentNode = NULL;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		currentNode = head;
		head = head->next;
		free(currentNode);
	}
	free(head);
}
