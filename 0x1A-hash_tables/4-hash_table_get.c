#include <stddef.h>
#include <string.h>
#include "hash_tables.h"
/**
 * hash_table_get - function that retrieves a value associated with a key
 * @ht: the hash table to be looked into
 * @key: the key been looked for
 *
 * Return: value associated with the element, or NULL if key couldn't be found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *head, *cur_node;
	unsigned long int ht_array_idx;


	if (ht)
	{
		ht_array_idx = key_index((const unsigned char *)key, ht->size);

		head = ht->array[ht_array_idx];

		if (head)
		{
			while (head != NULL)
			{
				cur_node = head;
				head = cur_node->next;
				if (strcmp(cur_node->key, key) == 0)
					return (cur_node->value);
			}
		}

	}

	return (NULL);
}
