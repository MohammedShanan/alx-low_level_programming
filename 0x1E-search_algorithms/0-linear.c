#include <stdio.h>

/**
 *linear_search - search for a value inside an array using liner search.
* @array: array to be searched
* @size: size of the array
* @value: value to search for
*Return: the first index where value is located
*/

int linear_search(int *array, size_t size, int value)
{
size_t i;
if (array == NULL)
{
return (-1);
}
for (i = 0; i < size; i++)
{
printf("Value checked array[%d] = [%d]\n", (int)i, array[i]);
if (array[i] == value)
{
return ((int)i);
}
}
return (-1);
}
