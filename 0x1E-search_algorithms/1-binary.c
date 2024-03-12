#include <stdio.h>
/**
 * print_array- prints an array.
 * @array: array to be printed
 * @start: starting index
 * @end: last index
 */
void print_array(int *array, size_t start, size_t end)
{
size_t i;
for (i = start; i < end; i++)
{
printf("%d, ", array[i]);
}
printf("%i\n", array[end]);
}
/**
 *_binary_search- search for a value inside an array using binary search.
* @array: array to be searched
* @start: starting index
* @end: last index
* @value: value to search for
*Return: the first index where value is located
*/

int _binary_search(int *array, size_t start, size_t end, int value)
{
size_t half = (start + end) / 2;
printf("Searching in array: ");
print_array(array, start, end);
if (start >= end)
{
return (-1);
}
if (array[half] == value)
{
return (half);
}
else if (array[half] < value)
{
return (_binary_search(array, half + 1, end, value));
}
else
{
return (_binary_search(array, start, half - 1, value));
}
}

/**
 *binary_search- search for a value inside an array using binary search.
* @array: array to be searched
* @size: size of the array
* @value: value to search for
*Return: the first index where value is located
*/

int binary_search(int *array, size_t size, int value)
{
if (array == NULL)
{
return (-1);
}
return (_binary_search(array, 0, size - 1, value));
}
