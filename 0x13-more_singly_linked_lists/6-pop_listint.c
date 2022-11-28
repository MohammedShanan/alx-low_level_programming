#include "lists.h"
/**
 * pop_listint - deletes the head node, and returns the head node’s data
 * @head: linked list
 * Return: deleted head node's data
 */
int pop_listint(listint_t **head)
{
listint_t *node;
int n;
node = *head;
if (node == NULL)
{
return (0);
}
*head = node->next;
n = node->n;
free(node);
return (n);
}
