#include "lists.h"
/**
 * add_dnodeint_end - add node to end of doubly linked list
 * @head: pointer to head of list
 * @n: node data
 * Return: address of new node, or Null if failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new_node, *tmp;
if (head == NULL)
{
return (NULL);
}
tmp = *head;
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
{
return (NULL);
}
new_node->n = n;
if (*head == NULL)
{
*head = new_node;
new_node->next = NULL;
new_node->prev = NULL;
return (new_node);
}
while (tmp->next)
{
tmp = tmp->next;
}
tmp->next = new_node;
new_node->prev = tmp;
new_node->next = NULL;
return (new_node);
}
