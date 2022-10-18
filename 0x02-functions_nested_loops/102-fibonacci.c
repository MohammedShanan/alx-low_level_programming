#include <stdio.h>

/**
 * main - print first 50 Fibonacci numbers
 * Return: 0
 */

int main(void)
{
int a = 0, b = 1 , i, sum;
for (i = 1; i < 50 ; i++)
{
sum = a + b;
printf("%li, ", sum);
a = b;
b = sum;
}
printf("%li\n", a + b);
return (0);
}
