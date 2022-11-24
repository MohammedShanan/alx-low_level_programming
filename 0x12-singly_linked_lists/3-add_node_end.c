#include "lists.h"
#include <string.h>
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(const char *s)
{
int len;
len = 0;
while (*s)
{
len++;
s++;
}
return (len);
}

/**
 * add_node_end - add node to end of linked list
 * @head: linked list
 * @str: data for new node
 * Return: address of new element, or NULL if failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
list_t *node;
list_t *last_node = NULL;
last_node = *head;
if (str == NULL)
{
return (NULL);
}
if (strdup(str) == NULL)
{
return (NULL);
}
node = malloc(sizeof(list_t));
if (node == NULL)
{
return (NULL);
}
node->str = strdup(str);
node->len = _strlen(node->str);
node->next = NULL;
if (*head == NULL)
{
*head = node;
}
else
{
while (last_node->next)
{
last_node = last_node->next;
}
last_node->next = node;
}
return (node);
}
