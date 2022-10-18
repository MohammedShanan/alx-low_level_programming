#include"main.h"

/**
 * print_alphabet_x10 - print lowercase alphabet ten times
 * Return: 0
 */

void print_alphabet_x10(void)
{
int counter = 0;
char a = 'a';
char i;
while (counter < 10)
{

for (i = a; i <= 'z'; i++)
{
_putchar(i);
}
_putchar('\n');
counter++;
}
}

