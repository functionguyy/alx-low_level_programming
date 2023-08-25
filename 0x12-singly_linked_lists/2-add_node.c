#include <string.h>
#include "lists.h"
/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: pointer to pointer to the last added node
 * @str; pointer to str
 *
 * Return: the address of new element or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	/* declare variables */
	list_t *newNode;


	/* initialize variables */
	newNode = NULL;

	/* confirm list */
	if (head == NULL)
		return (newNode);


	/* request memory allocation on heap */
	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (newNode);

	if (str)
	{
		newNode->str = strdup(str);
		newNode->len = strlen(str);
	}

	/* add new node to beginning of the list */
	newNode->next = *head;
	*head = newNode;

	return (*head);
}
