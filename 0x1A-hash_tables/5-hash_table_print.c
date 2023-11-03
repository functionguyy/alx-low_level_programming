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
	unsigned long int idx;
	hash_node_t *head;
	int start;

	idx = 0;
	start = 1;

	if (ht)
	{
		putchar('{');
		for (idx = 0; idx < ht->size; idx++)
		{
			/* get the element at current idx */
			head = ht->array[idx];

			if (head)
			{
				while (head != NULL)
				{
					if (start)
						start = 0;
					else
						printf(", ");

					printf("'%s': '%s'", head->key, head->value);
					head = head->next;
				}
			}
		}
		puts("}");
	}
}
