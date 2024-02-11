#include <stdio.h>
#include "search_algos.h"
/**
 *
 *
 *
 *
 *
 *
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *head, *express;
	int key

	if (!list)
		return (NULL);

	head = list;
	key = value;
	express = head->express;
	
	while (head)
	{
		if (key == head->n)
			return (head);

		if (key > head->n && k >= express->n)
		{
			head = express;
			express = head->express;
			continue;
		}

		head = head->next;
	}

	return (NULL);
}
