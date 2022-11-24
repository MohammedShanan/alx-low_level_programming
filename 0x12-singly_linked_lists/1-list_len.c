#include "lists.h"
/**
 * list_len - return number of nodes in linked list
 * @h: linked list
 * Return: number of nodes in linked list
 */

size_t list_len(const list_t *h)
{
unsigned int count = 0;
while (h)
{
h = h->next;
count++;
}
return (count);
}
