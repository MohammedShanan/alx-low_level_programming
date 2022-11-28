#include "lists.h"
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *tmp, *previous, *next;
unsigned int i = 1;
tmp = *head;
if (*head == NULL)
{
return (-1);
}
if (index == 0)
{
*head = tmp->next;
free(tmp);
return (1);
}
while (tmp)
{
previous = tmp;
tmp = tmp->next;
if (tmp == NULL) /*check is index is out of range*/
{
return (-1);
}
next = tmp->next;
if (i == index)
{
previous->next = next;
free(tmp);
return (1);
}
i++;
}
return (-1);
}
