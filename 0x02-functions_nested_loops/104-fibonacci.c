#include <stdio.h>
#include"main.h"
#include <stdint.h>

/**
* main - print first 50 Fibonacci numbers
* Return: 0
*/

int main(void)
{
uint64_t a = 0, b = 1;
int i;
uint64_t sum;
for (i = 1; i < 98; i++)
{
sum = a + b;
printf("counter is %i,number is %lu\n", i,sum);
a = b;
b = sum;
}
sum = a + b;
printf("%lu\n", sum);
return (0);
}
