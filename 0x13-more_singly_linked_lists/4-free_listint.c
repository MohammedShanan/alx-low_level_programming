#include "lists.h"
/**
 * free_listint - frees a linked list
 * @head: linked list
 */

void free_listint(listint_t *head)
{
listint_t *tmp = NULL;
while (head)
{
tmp = head;
head = head->next;
free(tmp);
}
}
