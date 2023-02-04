#include <stdlib.h>
#include "lists.h"
/**
* add_nodeint - function adds a new node to the beginning of a linked list
* @head: pointer to the linked list.
* @n: value for the number member of the new node
* Description: function that adds a new node at the beginning of a listint_t
* list.
* Return: the address of the new element, or NULL if failed
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (new_node);
	}
	new_node->n = n;
	new_node->next = *head;
	*head = new_node;
	return (*head);
}
