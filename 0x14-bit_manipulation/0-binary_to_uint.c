#include "main.h"
/**
 * binary_to_uint - convert binary to unsigned int
 * @b: binary
 * Return: unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
int i, num, mult = 1;
num = i = 0;
if (b == NULL)
{
return (0);
}
while (b[i])
{
if (b[i] < '0' || b[i] > '9')
{
return (0);
}
i++;
}
i--;
while (i >= 0)
{
num += (b[i] - '0') * mult;
mult *= 2;
i--;
}
return (num);
}
