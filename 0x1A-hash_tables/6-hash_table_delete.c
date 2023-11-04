#include <stdlib.h>
#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table of type hash_table_t
 * @ht: the hash_table
 *
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	/* declare variables */
	hash_node_t *cur_node, *head;
	unsigned long int idx;



	if (ht)
	{
		for (idx = 0; idx < ht->size; idx++)
		{
			head = ht->array[idx];
			while (head != NULL)
			{
				cur_node = head;
				head = head->next;
				free(cur_node->key);
				free(cur_node->value);
				free(cur_node);
			}
		}
		free(ht->array);
		free(ht);
	}
}
