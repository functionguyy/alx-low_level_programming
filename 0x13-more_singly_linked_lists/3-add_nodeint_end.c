#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint_end - adds a new node at the end of a singly linked list
 * @head: pointer to the pointer to the beginning of a singly linked list
 * @n: data item
 *
 * Return: returns the address of the new element or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	/* declare variables */
	listint_t *newNode, *currentNode;

	/* initialize variables */
	newNode = NULL;
	currentNode = NULL;

	/* confirm singly linked list argument is an actual address */
	if (head == NULL)
		return (newNode);

	/* request memory allocation on the heap */
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (newNode);

	/* add data item to new node */
	newNode->n = n;
	newNode->next = NULL;

	/* seek the end of the singly linked list */
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		currentNode = *head;
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}

	/* return address of the new node */
	return (newNode);
}
