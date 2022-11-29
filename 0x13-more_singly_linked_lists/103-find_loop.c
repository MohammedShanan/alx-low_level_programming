#include "lists.h"
/**
 * find_listint_loop - find loop start
 * @head: pointer to head pointer of linked list
 * Return: loop entry point
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *cat, *mouse;
cat = mouse = head;
while (cat && mouse && mouse->next)
{
cat = cat->next;
mouse = mouse->next->next;
if (cat == mouse)
{
cat = head;
while (cat != mouse)
{
cat = cat->next;
mouse = mouse->next;
}
return (cat);
}
}
return (NULL);
}
