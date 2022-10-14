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
int i;
for (i = a; i <= 'z'; i++)
{
if (i != 'q' && i != 'e')
{
putchar(i);
}
}
putchar('\n');
return (0);
}
