#include "lists.h"
#include <stdlib.h>
/**
 * free_listint2 - function frees a singly linked list
 * @head: pointer to pointer to the head of the list
 *
 * Return: Nothing
 */
void free_listint2(listint_t **head)
{
	/* declare variables */
	listint_t *currentNode;

	/* initialize variables */
	currentNode = NULL;


	if (head == NULL)
		return;

	while (*head != NULL)
	{
		currentNode = *head;
		*head = currentNode->next;
		free(currentNode);
	}
}
