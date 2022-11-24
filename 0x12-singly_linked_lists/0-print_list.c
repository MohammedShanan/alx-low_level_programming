#include "lists.h"
/**
 * print_list - prints all elements of list_t list
 * @h: linked list
 * Return: number of nodes in linked list
 */

size_t print_list(const list_t *h)
{

unsigned int count = 0;
while (h)
{
if (h->str)
{
printf("[%i] %s", h->len, h->str);
}
else
{
printf("[0] (nil)");
}
h = h->next;
count++;
}
return (count);
}
