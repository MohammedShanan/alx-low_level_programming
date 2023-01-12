#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes node at given idx
 * @head: pointer to head of doubly linked list
 * @index: index
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
unsigned int i = 0;
dlistint_t *tmp;
if (head == NULL || *head == NULL)
return (-1);
tmp = *head;
if (index == 0)
{
*head = tmp->next;
if (tmp->next != NULL)
{
tmp->next->prev = NULL;
}
free(tmp);
return (1);
}
while (i < index && tmp)
{
tmp = tmp->next;
i++;
}
if (tmp == NULL)
{
return (-1);
}
tmp->prev->next = tmp->next;
if (tmp->next != NULL)
{
tmp->next->prev = tmp->prev;
}
free(tmp);
return (1);
}
