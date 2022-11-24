#include "lists.h"
/**
 * print_list - prints all elements of list_t list
 * @h: linked list
 * Return: number of nodes in linked list
 */

size_t print_list(const list_t *h)
{
list_t *tmp = h;
int count = 0;
while (tmp)
{
if (tmp->str)
{
printf("[%i] %s", tmp->len, tmp->str);
}
else
{
printf("[0] (nil)", tmp->len, tmp->str);
}
tmp = tmp->next;
}
return (count);
}
