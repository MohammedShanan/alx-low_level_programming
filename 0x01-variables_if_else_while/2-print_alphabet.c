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
for (int i = a; i <= 'z'; i++)
{
putchar(i);    
}
putchar('\n');
return (0);
}