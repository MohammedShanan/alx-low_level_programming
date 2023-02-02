#include "hash_tables.h"
/**
 * hash_table_delete - free and delete hash table
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
unsigned long int i = 0;
hash_node_t *node, *tmp;
if (ht == NULL)
{
return;
}
if (ht->array == NULL)
{
free(ht);
return;
}
while (i < ht->size)
{
node = ((ht->array)[i]);
while (node)
{
if (node->key)
{
free(node->key);
}
if (node->value)
{
free(node->value);
}
node->key = NULL;
node->value = NULL;
tmp = node;
node = node->next;
free(tmp);
}
i++;
}
free(ht->array);
free(ht);
}
