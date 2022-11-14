#include <stddef.h>
#include <stdio.h>
#include "dog.h"
/**
 * print_dog - print a strcut dog variable
 * @d: a pointer to a struct dog
 */
void print_dog(struct dog *d)
{
if (d != NULL)
{
d->name == NULL ? printf("Name: (nil)\n") : printf("Name: %s\n", d->name);
d->name == NULL ? printf("Age: (nil)\n") : printf("Age: %s\n", d->age);
d->name == NULL ? printf("Owner: (nil)\n") : printf("Owner: %s\n", d->owner);
}
}
