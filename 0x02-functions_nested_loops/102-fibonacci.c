#include <stdio.h>

/**
 * main - print first 50 Fibonacci numbers
 * Return: 0
 */

int main(void)
{
int a = 0, b = 1, i;
long sum;
for (i = 1; i < 50 ; i++)
{
sum = a + b;
printf("%li, ", sum);
a = b;
b = sum;
}
sum = a + b;
printf("%li\n", sum);
return (0);
}
