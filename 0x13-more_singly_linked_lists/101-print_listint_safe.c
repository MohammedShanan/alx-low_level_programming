#include "lists.h"
/**
 * len_list_safe - find the length of the list
 * @head: pointer to head pointer of linked list
 * Return: length of ist
 */
size_t len_list_safe(const listint_t *head)
{
const listint_t *cat, *mouse;
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
 * detect_loop - detect if there is a loop or not
 * @head: pointer to head pointer of linked list
 * Return: loop entry point
 */
const listint_t *detect_loop(const listint_t *head)
{
const listint_t *cat, *mouse;
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
 * print_listint_safe - prints list with addresses
 * @head: pointer to head pointer of linked list
 * Return: number of nodes in list, exit(98) if failed
 */
size_t print_listint_safe(const listint_t *head)
{
size_t i = 0, len_l = 0;
const listint_t *tmp, *loop_start;
tmp = head;
if (head == NULL)
{
return (0);
}
loop_start = detect_loop(head);
if (loop_start != NULL)
{
len_l = len_list_safe(head);
while (i < len_l)
{
printf("[%p] %d\n", (void *)tmp, tmp->n);
tmp = tmp->next, i++;
}
printf("-> [%p] %d\n", (void *)loop_start, tmp->n);
}
else
{
while (tmp)
{
printf("[%p] %d\n", (void *)tmp, tmp->n);
tmp = tmp->next;
len_l++;
}
}
return (len_l);
}
