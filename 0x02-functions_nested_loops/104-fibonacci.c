#include <stdio.h>
#include"main.h"
#include <stdint.h>

/**
* main - print first 50 Fibonacci numbers
* Return: 0
*/

int main(void)
{
unsigned long a = 0, b = 1;
int i;
unsigned long sum;
long a_part1, a_part2, b_part1, b_part2;
for (i = 1; i < 93; i++)
{
sum = a + b;
printf("%lu, ", sum);
a = b;
b = sum;
}
a  
for (i = 1; i < 99; i++)
{
  
}
sum = a + b;
printf("%lu\n", sum);
return (0);
}
