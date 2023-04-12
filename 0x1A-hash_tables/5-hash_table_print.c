#include <stdio.h>
#include "hash_tables.h"
/**
 * hash_table_print - function that prints hash table
 * @ht: the hash table
 *
 * Description: Should print the key/value in the order that they appear in the
 * array of hash table: Order: array,list
 * Return: print hash table, if ht is NULL don't print anything.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *head;
	unsigned long int i;
	int flag;

	flag = 0;
	if (ht)
	{
		printf("{");
		for (i = 0; i < ht->size; i++)
		{
			head = ht->array[i];
			if (head == NULL)
				continue;
			while (head != NULL)
			{
				/* signify first non-null hash table array cell */
				if (flag == 0)
					flag = 1;
				else
					printf(",");
				printf("'%s': '%s'", head->key, head->value);
				head = head->next;
			}
		}
	}
		printf("}\n");
}
