#include <stdlib.h>

/**
 * _calloc - allocate memory and set all values to 0
 * @nmemb: size
 * @size: sizeof(datatype)
 * Return: pointer to calloc'd string
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{

void *p;
unsigned int i;
if (nmemb == 0 || size == 0)
{
return (NULL);
}
p = malloc(nmemb * size);
if (p == NULL)
{
return (NULL);
}
for (i = 0; i < nmemb * size; i++)
{
*((char *)p + 1) = 0;
}

return (p);
}
