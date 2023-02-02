#include "hash_tables.h"
/**
 * hash_table_get - given key, get value
 * @ht: hash table
 * @key: key
 * Return: value; or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
hash_node_t *node;
unsigned long int indx;
indx = key_index((const unsigned char *)key, ht->size);
if (ht == NULL || !key)
{
return (NULL);
}
node = (ht->array)[indx];
while (node)
{
if (strcmp(key, node->key) == 0)
{
return (node->value);
}
node = node->next;
}
return (NULL);
}
