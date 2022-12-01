#include "main.h"
/**
 * get_bit - get bit at index
 * @n: number
 * @index: index within binary number
 * Return: bit 0 or 1, or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
unsigned int max_bits;
max_bits = malloc(sizeof(unsigned long int) * 8);
if (index > max_bits)
{
return (-1);
}
return ((n >> index) & 1);
}
