#include "hash_tables.h"
/**
 * hash_table_print - print key/values of hash table in order
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
unsigned long int i = 0;
hash_node_t *node;
char *comma = "";
if (ht == NULL || ht->array == NULL)
{
return;
}

printf("{");
while (i < ht->size)
{
node = (ht->array)[i];
while (node)
{
printf("%s'%s' : '%s'", comma, node->key, node->value);
comma = ", ";
node = node->next;
}

i++;
}
printf("}");
}
