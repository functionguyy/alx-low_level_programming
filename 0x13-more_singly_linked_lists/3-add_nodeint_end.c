#include <stddef.h>
#include "lists.h"
#include <stdlib.h>
/**
* add_nodeint_end - function that adds a new node at the end
* @head: pointer to the beginning of the list
* @n: integer
*
* Return: address of the new element, or NULL if it failed
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *temp;


	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->next = NULL;
	new_node->n = n;
	if (*head == NULL)
	{

		*head = new_node;

	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;

		}
		temp->next = new_node;
	}
	return (*head);
}
