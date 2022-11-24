#include "lists.h"
#include <string.h>
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
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
 * add_node - add node to beginning of linked list
 * @head: linked list
 * @str: data for new node
 * Return: address of new element, or NULL if failed
 */

list_t *add_node(list_t **head, const char *str)
{
list_t *node = malloc(sizeof(list_t));
if (str == NULL)
{
return (NULL);
}
if (node == NULL)
{
return (NULL);
}
node->str = strdup(str);
if (node->str == NULL)
{
return (NULL);
}
node->len = _strlen(node->str);
if (head == NULL)
{
node->next = NULL;
}
else
{
node->next = *head;
}
*head = node;
return (*head);
}
