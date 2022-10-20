#include <stdio.h>
#include <stdint.h>

/**
 * main - print largest prime factor of 612852475143
 * Return: 0 on success
 */

int main(void)
{
int largest_prime = 2;
unsigned long i;
unsigned long n = 612852475143;
while (n % 2 == 0)
{
n = n / 2;
}

for (i = 3; i <= n; i = i + 2)
{
if (n % i == 0)
{
largest_prime = i;
while (n % i == 0)
{
n = n / i;
}
}
}
largest_prime = largest_prime > 2 ? largest_prime : 2;
printf("%d\n", largest_prime);
return (0);
}
