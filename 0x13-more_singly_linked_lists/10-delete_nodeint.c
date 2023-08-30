#include "lists.h"
/**
 * delete_nodeint_at_index - deletes the node at index of a singly linked list
 * @head: pointer to pointer that points to the singly linked list
 * @index: the index of the node that should be deleted
 *
 * Return: returns 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	/* declare variables */
	unsigned int ncount;
	listint_t *nodeBeforeTarget, *target;

	/* initialize variables */
	ncount = 0;
	nodeBeforeTarget = NULL;
	target = NULL;

	if (head == NULL)
		return (-1);

	if (index == 0)
	{
		/* delete the first noode */
		pop_listint(head);
		return (1);
	}

	/* check if list is empty */
	if (*head == NULL)
		return (-1);

	/* count how many nodes are in the list */
	ncount = listint_len(*head) - 1;

	/* check if given index is out of range */
	if (index > ncount)
		return (-1);

	nodeBeforeTarget = get_nodeint_at_index(*head, index - 1);
	target = nodeBeforeTarget->next;

	if (index == ncount)
		nodeBeforeTarget->next = NULL;
	else
		nodeBeforeTarget->next = target->next;
	free(target);

	return (1);
}
/**
 * pop_listint - deletes the head node of a singly linked list
 * @head: pointer to pointer that points to the singly linked list
 *
 * Return: data item in the deleted node
 */
int pop_listint(listint_t **head)
{
	/* declare variables */
	int n;
	listint_t *currentNode;

	/* initialize variables */
	n = 0;
	currentNode = NULL;

	if (head == NULL || *head == NULL)
		return (0);

	/* delete the head node */
	currentNode = *head;
	*head = currentNode->next;
	free(currentNode);

	return (n);
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
/**
 * get_nodeint_at_index - returns the nth node of a singly linked list
 * @head: pointer to a singly linked list
 * @index: index of the node to be returned
 *
 * Description: index is the index of the node, starting at 0
 * Return: returns the nth node of a singly linked list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	/* declare variables */
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
