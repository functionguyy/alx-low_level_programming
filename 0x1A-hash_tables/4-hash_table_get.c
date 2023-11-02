#include <stddef.h>
#include <string.h>
#include "hash_tables.h"
/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: hash table
 * @key: the key associated with a value in the hash table
 *
 * Return: value associated with the element, or NULL if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	/* declare variables */
	hash_node_t *head, *cur_node;
	unsigned long int ht_array_idx;


	if (ht)
	{
		/* get hash table array index for key */
		ht_array_idx = key_index((const unsigned char *)key, ht->size);

		head = ht->array[ht_array_idx];

		if (head)
		{
			/**
			 * search linked list attached to hash table array at
			 * index
			 */
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
