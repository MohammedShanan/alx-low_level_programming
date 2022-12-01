#include "main.h"
/**
 * print_binary - converts unsigned int to binary
 * @n: unsigned int
 * Return: binary
 */
void print_binary(unsigned long int n)
{
unsigned long int cp_n = n, mask = 1;
int len_n = 0;
while (cp_n > 0)
{
len_n++;
cp_n >>= 1;
}
len_n--;
if (len_n > 0)
mask = mask << len_n;
while (mask > 0)
{
_putchar(n & mask ? '1' : '0');
mask >>= 1;
}
}
