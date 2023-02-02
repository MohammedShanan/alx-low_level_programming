#include "hash_tables.h"

/**
 * create_add_node - malloc, set values, and insert node into hash table
 * @ht: hash table
 * @key: key; can't be empty string
 * @value: value
 * @idx: index to insert in at hash table
 * Return: 1 if success, 0 if fail
 */
int create_add_node(hash_table_t *ht, const char *key, const char *value,
unsigned long int idx)
{
char *k, *v;
hash_node_t *node;
k = strdup(key);
if (k == NULL)
{
return (0);
}
v = strdup(value);
if (v == NULL)
{
free(k);
return (0);
}
node = malloc(sizeof(hash_node_t));
if (node == NULL)
{
free(k);
free(v);
return (0);
}
node->key = k;
node->value = v;
node->next = (ht->array)[idx];
(ht->array)[idx] = node;
return (1);
}
/**
 * hash_table_set - add element to hash table
 * @ht: hash table
 * @key: key; can't be empty string
 * @value: value
 * Return: 1 if success, 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
char *v;
unsigned long int indx;
hash_node_t *node;
if (!ht || !(ht->array) || !key || strlen(key) == 0)
{
return (0);
}
indx = key_index((const unsigned char *)key, ht->size);

node = (ht->array)[indx];
while (node)
{
if (strcmp(key, node->key) == 0)
{
v = strdup(value);
if (v == NULL)
{
return (0);
}
if (node->value)
{
free(node->value);
}

node->value = v;
return (1);
}

node = node->next;
}
return (create_add_node(ht, key, value, indx));
}
