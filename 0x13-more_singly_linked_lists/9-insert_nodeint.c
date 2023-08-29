#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the pointer to a singly linked list
 * @idx: the index of the list where the new node should be added
 * @n: data item for the new node
 *
 * Return: returns the address of the new node or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	/* declare variables */
	unsigned int count;
	listint_t *newNode;

	/* initialize variables */
	count = 0;
	newNode = NULL;

	if (head == NULL)
		return (NULL);

	if (idx == 0)
	{
		newNode = add_nodeint(head, n);
		return (newNode);
	}

	if (*head == NULL)
		return (NULL);

	/* get the count of the nodes in the list */
	count = listint_len(*head);

	if (idx < count)
		newNode = add_nodeint_middle(head, idx - 1, n);


	if (idx == count)
		newNode = add_nodeint_end(head, n);


	return (newNode);
}
/**
 * add_nodeint - adds a new node at the beginning of a singly linked list
 * @head: pointer to the pointer of singly linked list
 * @n: data item for the new node
 *
 * Description: function adds a new node at beginning of a listint_t list.
 * Return: returns the address of the new element, or NULL if it failed
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

	/* return the address of the new node  */
	return (newNode);
}
/**
 * add_nodeint_middle - add a new node at a given position in a singly linked
 * list
 * @head: pointer to the pointer of singly linked list
 * @index: the of the list where the new node should be added.
 * @n: data item for the new node
 *
 * Return: the address of the new node or NULL if it failed.
 */
listint_t *add_nodeint_middle(listint_t **head, unsigned int index, int n)
{
	/* declare variables */
	listint_t *nthNodeBeforeIndex, *tempNode, *newNode;

	/* initialize variables */
	nthNodeBeforeIndex = NULL;
	tempNode = NULL;
	newNode = NULL;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	/* assign data item */
	newNode->n = n;

	/* get the node before index */
	nthNodeBeforeIndex = get_nodeint_at_index(*head, index);
	tempNode = nthNodeBeforeIndex->next;
	nthNodeBeforeIndex->next = newNode;
	newNode->next = tempNode;

	return (newNode);
}

/**
 * get_nodeint_at_index - returns the nth node of a singly linked list
 * @head: pointer to singly linked list
 * @index: index of the node to be returned
 *
 * Description: index is the index of the node, starting 0
 * Return: returns the nth node of singly linked list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	/*declare variables */
	unsigned int count;
	listint_t *nthNode;

	/* initialize variables */
	count = 0;
	nthNode = NULL;


	/* seek the nth node */
	while (head != NULL)
	{
		nthNode = head;
		head = nthNode->next;
		if (count == index)
			return (nthNode);
		count++;
	}

	return (NULL);
}
/**
 * listint_len - returns the number of elements in a singly linked list
 * @h: pointer to the singly linked list
 *
 * Description: returns the number of elements in a linked listint_t list
 * Return: returns the number of elements in a singly linked list
 */
size_t listint_len(const listint_t *h)
{
	/* declare variables */
	size_t n;


	/* initialize variables */
	n = 0;


	while (h != NULL)
	{
		n++;
		h = h->next;
	}

	return (n);
}
