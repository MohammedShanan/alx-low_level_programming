#include "lists.h"
/**
 * list_len - return number of nodes in linked list
 * @h: linked list
 * Return: number of nodes in linked list
 */

size_t list_len(const list_t *h)
{
list_t *tmp;
tmp = h;
unsigned int count = 0;
while (tmp)
{
tmp = tmp->next;
count++;
}
return (count);
}
