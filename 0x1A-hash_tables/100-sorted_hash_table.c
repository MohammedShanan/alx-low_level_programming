#include "hash_tables.h"
/**
 * shash_table_create - create sorted hash table given size
 * @size: size
 * Return: pointer to table; NULL if error
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_node_t **array;
    shash_table_t *ht;
    unsigned long int i = 0;
    if (size == 0)
    {
        return (NULL);
    }

    ht = malloc(sizeof(shash_table_t));
    if (!ht)
    {
        return (NULL);
    }
    array = malloc(sizeof(*array) * size);
    if (!array)
    {
        free(ht);
        return (NULL);
    }
    while (i < size)
    {
        array[i] = NULL;
        i++;
    }
    ht->array = array;
    ht->size = size;
    ht->shead = NULL;
    ht->stail = NULL;
    return (ht);
}
/**
 * insert_to_sorted_list - compare abcs and insert
 * node into list (for printing)
 * @ht: sorted hash table
 * @node: node to insert
 * Return: 1 if success, 0 if fail
 */
int insert_to_sorted_list(shash_table_t *ht, shash_node_t *node)
{
    shash_node_t *tmp;
    if (!(ht->shead))
    {
        ht->shead = node;
        ht->stail = node;
        return (1);
    }

    if (strcmp(node->key, (ht->shead)->key) < 0)
    {
        node->snext = ht->shead;
        (ht->shead)->sprev = node;
        ht->shead = node;
        return (1);
    }

    if (strcmp(node->key, (ht->stail)->key) > 0)
    {
        node->sprev = ht->stail;
        (ht->stail)->snext = node;
        ht->stail = node;
        return (1);
    }
    tmp = ht->shead;
    while (tmp->snext)
    {
        if (strcmp(node->key, (tmp->snext)->key) > 0)
        {
            node->snext = tmp->snext;
            node->sprev = tmp;
            (tmp->snext)->sprev = node;
            tmp->snext = node;
            break;
        }

        tmp = tmp->snext;
    }
    return (1);
}
/**
 * create_add_node - malloc, set values, and insert node into hash table
 * @ht: sorted hash table
 * @key: key; can't be empty string
 * @value: value
 * @idx: index to insert in at hash table
 * Return: 1 if success, 0 if fail
 */
int create_add_node(shash_table_t *ht, const char *key, const char *value,
                    unsigned long int idx)
{
    char *k, *v;
    shash_node_t *node = NULL;
    k = strdup(key);
    if (!k)
    {
        return (0);
    }
    v = strdup(value);
    if (!v)
    {
        free(k);
        return (0);
    }
    node = malloc(sizeof(shash_node_t));
    if (!node)
    {
        free(k);
        free(v);
        return (0);
    }
    node->key = k;
    node->value = v;
    node->next = (ht->array)[idx];
    node->snext = NULL;
    node->sprev = NULL;
    (ht->array)[idx] = node;
    return (insert_to_sorted_list(ht, node));
}

/**
 * shash_table_set - add element to sorted hash table
 * @ht: hash table
 * @key: key; can't be empty string
 * @value: value
 * Return: 1 if success, 0 if fail
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int indx;
    shash_node_t *node;
    char *v;
    if (!ht || !(ht->array) || !key || strlen(key) == 0 || !value)
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
            if (!v)
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
/**
 * shash_table_get - given key, get value
 * @ht: hash table
 * @key: key
 * Return: value; or NULL if not found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int indx;
    shash_node_t *node;
    if (!ht || !key)
    {
        return (NULL);
    }
    indx = key_index((const unsigned char *)key, ht->size);
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
/**
 * shash_table_print - print key/values of hash table in ascending order
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;
    char *comma = "";

    if (!ht || !ht->array)
        return;

    putchar('{');
    node = ht->shead;
    while (node)
    {
        printf("%s'%s': '%s'", comma, node->key, node->value);
        comma = ", ";
        node = node->snext;
    }
    puts("}");
}

/**
 * shash_table_print_rev - print key/values of sorted hashtable in reverse order
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;
    char *comma = "";

    if (!ht || !ht->array)
        return;

    putchar('{');
    node = ht->stail;
    while (node)
    {
        printf("%s'%s': '%s'", comma, node->key, node->value);
        comma = ", ";
        node = node->sprev;
    }
    puts("}");
}

/**
 * shash_table_delete - free and delete sorted hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int idx = 0;
    shash_node_t *node, *next;

    if (!ht)
        return;

    if (!(ht->array))
    {
        free(ht);
        return;
    }

    while (idx < ht->size)
    {
        node = (ht->array)[idx];
        while (node)
        {
            next = node->next;
            if (node->key)
                free(node->key);
            if (node->value)
                free(node->value);
            node->key = NULL;
            node->value = NULL;
            free(node);
            node = next;
        }
        idx++;
    }
    free(ht->array);
    free(ht);
}
