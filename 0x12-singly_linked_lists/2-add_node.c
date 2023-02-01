#include <string.h>
#include "lists.h"
/**
* add_node - Function adds a new node at the beginning of a linked list
* @head: pointer to pointer to the last added node
* @str: pointer to str
*
* Return: the address of new element or NULL if its fails
*/
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (str)
	{
		new_node->str = strdup(str);
		new_node->len = strlen(str);
	}
	new_node->next = *head;
	*head = new_node;
	return (*head);
}
