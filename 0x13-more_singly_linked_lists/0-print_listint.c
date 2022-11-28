#include "lists.h"
/**
 * print_listint - prints all elements of a list
 * @h: list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
int counter = 0;
for (; h->next; counter++)
{
printf("%i\n", h->n);
h = h->next;
}
return (counter);
}
