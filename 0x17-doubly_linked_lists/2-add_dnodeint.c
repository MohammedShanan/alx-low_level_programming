#include "lists.h"
/**
 * add_dnodeint - add node to front of doubly linked list
 * @head: pointer to head of list
 * @n: node data
 * Return: address of new node, or Null if failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
dlistint_t *new_node;
if (head == NULL)
{
return (NULL);
}
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
{
return (NULL);
}
new_node->n = n;
if (*head == NULL)
{
new_node->next = NULL;
new_node->prev = NULL;
*head = new_node;
return (new_node);
}
new_node->prev = NULL;
new_node->next = *head;
(*head)->prev = new_node;
*head = new_node;
return (new_node);
}
