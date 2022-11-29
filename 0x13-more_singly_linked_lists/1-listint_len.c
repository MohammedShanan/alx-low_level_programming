#include "lists.h"
/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: list
 * Return: number of nodes in list
 */
size_t listint_len(const listint_t *h)
{
size_t counter;
const listint_t *tmp = NULL;
tmp = h;
for (counter = 0; tmp; counter++)
{
tmp = tmp->next;
}
return (counter);
}
