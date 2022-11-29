#include "lists.h"
/**
 * len_list - find the length of the list
 * @head: pointer to head pointer of linked list
 * Return: length of ist
 */
size_t len_list(listint_t *head)
{
listint_t *cat, *mouse;
size_t counter = 0;
cat = mouse = head;
while (cat && mouse && mouse->next)
{
cat = cat->next;
mouse = mouse->next->next;
counter++;
if (cat == mouse)
{
cat = head;
while (cat != mouse)
{
cat = cat->next;
mouse = mouse->next;
counter++;
}
return (counter);
}
}
return (counter);
}
/**
 * find_loop_start - find loop start
 * @head: pointer to head pointer of linked list
 * Return: loop entry point
 */
listint_t *find_loop_start(listint_t *head)
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
/**
 * free_listint_safe - free linked list
 * @h: pointer to head pointer of linked list
 * Return: number of nodes in list freed
 */
size_t free_listint_safe(listint_t **h)
{
size_t i, len_l;
listint_t *tmp, *loop_start;
if (*h == NULL)
{
return (0);
}
loop_start = find_loop_start(*h);
if (loop_start != NULL)
{
len_l = len_list(*h);
for (i = 0; i < len_l; i++)
{
tmp = *h;
*h = i < len_l - 1 ? tmp->next : NULL;
free(tmp);
}
}
else
{
for (len_l = 0; *h; len_l++)
{
tmp = *h;
*h = tmp->next;
free(tmp);
}
}
return (len_l);
}
