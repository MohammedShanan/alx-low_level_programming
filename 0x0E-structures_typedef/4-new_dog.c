#include <stddef.h>
#include <stdlib.h>
#include "dog.h"
/**
 * len - find length of string
 * @str: string
 * Return: length
 */
int len(char *str)
{
int i;

for (i = 0; *(str + i); i++)
;
return (i);
}
/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Return: copy of original source
 */

char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i]; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';
return (dest);
}
/**
 * new_dog - create a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: a pointer to a struct dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dt;
char *name_cp, *owner_cp;
dt = malloc(sizeof(dog_t));
if (dt == NULL)
{
return (NULL);
}
dt->age = age;
if (name != NULL)
{
name_cp = malloc(len(name) + 1);
if (name_cp == NULL)
{
free(dt);
return (NULL);
}
dt->name = _strcpy(name_cp, name_cp);
}
else
{
dt->name = NULL;
}
if (owner != NULL)
{
owner_cp = malloc(len(owner) + 1);
if (owner_cp == NULL)
{
free(name_cp);
free(dt);
return (NULL);
}
dt->owner = _strcpy(owner_cp, owner);
}
else
{
dt->owner = NULL;
}
return (dt);
}
