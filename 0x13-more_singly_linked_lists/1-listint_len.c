#include "lists.h"
/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: list
 * Return: number of nodes in list
 */
size_t listint_len(const listint_t *h)
{
int counter = 0;
listint_t *tmp = NULL;
tmp = h;
for (;tmp; counter++)
{
tmp = tmp->next;
}
return (counter);
}
