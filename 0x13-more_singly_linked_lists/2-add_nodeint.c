#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint - adds a new node at the beginning of a singly linked list
 * @head: pointer to the pointer of a singly linked list
 * @n: data item for the new node
 *
 * Description: function adds a new node at beginning of a listint_t list.
 * Return: returns the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	/* declare variables */
	listint_t *newNode;

	/* initialize variables */
	newNode = NULL;

	/* request memory allocation on heap */
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (newNode);

	/* add data item to the new node */
	newNode->n = n;

	/* add new node at the beginning of the singly linked list */
	newNode->next = *head;
	*head = newNode;


	/* return the address of the new node */
	return (newNode);
}
