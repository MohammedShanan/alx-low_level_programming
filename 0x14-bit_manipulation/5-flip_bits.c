#include "main.h"
/**
 * flip_bits - determine how many bits to flip to get from one num to another
 * @n: number
 * @m: number2
 * Return: how many bits differ
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int diff;
unsigned int bits = 0;
diff = n ^ m;
do{
bits += (diff & 1);
diff >>= 1;
} while (diff > 0);
return (bits);
}
