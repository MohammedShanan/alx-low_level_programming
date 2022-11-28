#include "lists.h"
/**
 * reverse_listint - reverse linked list
 * @head: pointer to head pointer of linked list
 * Return: pointer to first node of reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *current, *previous = NULL;
if (head == NULL)
{
return (NULL);
}
while (*head != NULL)
{
current = *head;/* a -> b -> c -> null | b -> c -> null | c -> null */
*head = current->next;/* b -> c -> null | c -> null | null */
current->next = previous;/* -> null | -> a -> null | -> b -> a -> null */
previous = current;/* a -> null | b -> a -> null | c -> b -> a -> null */
}
*head = previous;
return (*head);
}
