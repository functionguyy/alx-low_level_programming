#include <stdio.h>
#include "hash_tables.h"
/**
 * hash_table_print - print a hash_table of data structure hash_table_t
 * @ht: the hash table
 *
 * Return: nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	/* declare variables */
	unsigned long int size, idx;
	hash_node_t *head, *cur_node;
	int start;

	idx = 0;
	start = 1;
	putchar('{');
	if (ht)
	{
		size = ht->size;

		for (idx = 0; idx < size; idx++)
		{
			/* get the element at current idx */
			head = ht->array[idx];

			if (head)
			{
				if (start)
					start = 0;
				else
					putchar(',');

				cur_node = head;
				printf("'%s': '%s'", cur_node->key, cur_node->value);


			}
		}

	}
	puts("}");
}
