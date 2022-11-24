#include "lists.h"
/**
 * free_list - free linked list
 * @head: linked list
 */
void free_list(list_t *head)
{
list_t *tmp = NULL;
while (head)
{
tmp = head;
head = head->next;
free(tmp->str);
free(tmp);
}
}
