#include "main.h"
/**
 * print_binary - converts unsigned int to binary
 * @n: unsigned int
 * Return: binary
 */
void print_binary(unsigned long int n)
{
unsigned long int cp_n = n;
int len_n = 0;
while (cp_n > 0 || !len_n)
{
len_n++;
cp_n >>= 1;
}
len_n--;
while (len_n >= 0)
{
_putchar(n & (1 << len_n) ? '1' : '0');
len_n--;
}
}
