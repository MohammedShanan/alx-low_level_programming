#include <stdio.h>
#include <stdlib.h>
/**
 *main - prints the minimum number of coins to make
*change for an amount of money.
* @argc: argument counter
* @argv: pointer to array of arguments
*Return: 0 on success 1 on error
*/

int main(int argc, char *argv[])
{
int n, coins = 0;
  
if (argv[1][0] == '-')
{
printf("0\n");
return (0);
}

/* convert string to int and calculate coins */
n = atoi(argv[1]);

coins += n / 25;
n = n % 25;
coins += n / 10;
n = n % 10;
coins += n / 5;
n = n % 5;
coins += n / 2;
n = n % 2;
coins += n / 1;

printf("%d\n", coins);
return (0);
}
