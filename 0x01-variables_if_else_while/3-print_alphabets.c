#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/**
 *main - Entry point
 *Return: 0
*/
int main(void)
{
char a = 'a';
char A = 'A';
for (int i = a; i <= 'z'; i++)
{
putchar(i);
}
for (int i = A; i <= 'Z'; i++)
{
putchar(i);
}
putchar('\n');
return (0);
}
