#include <stdlib.h>
#include "lists.h"
/**
 * add_dnodeint - function that adds a new node at the beginning of a
 * dlistint_t list
 * @head: pointer to the beginning of the list
 * @n: integer data for the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */



dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	if (head == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* if list is not empty */
	(*head)->prev = new_node;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
