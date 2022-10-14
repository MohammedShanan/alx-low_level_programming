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
int n, last_dig;

srand(time(0));
n = rand() - RAND_MAX / 2;
last_dig = n % 10;
if (last_dig < 6 && last_dig != 0)
{
printf("Last digit of %i is %i and is less than 6 and not 0", n, last_dig);
}
else if (last_dig > 5)
{
    printf("Last digit of %i is %i and is greater than 5", n, last_dig);
}
else
{
    printf("Last digit of %i is 0 and is 0", 0);
}
return (0);
}
