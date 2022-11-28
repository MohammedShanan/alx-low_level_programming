#include "lists.h"
/**
 * free_listint2 - frees a linked list, and sets head to NULL
 * @head: linked list
 */
void free_listint2(listint_t **head)
{
listint_t *tmp = NULL;
if (head == NULL)
{
return;
}
while (*head)
{
tmp = *head;
*head = tmp->next;
free(tmp);
}
}
