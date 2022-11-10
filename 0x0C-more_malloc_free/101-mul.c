#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/**
 *main - print the product of two integers
* @argc: argument counter
* @argv: pointer to array of arguments
*Return: 0 on successes , 98 on error;
*/

int main(int argc, char const *argv[])
{
unsigned long int n1, n2;
if (argc != 3)
{
printf("Error\n");
exit(98);
}
n1 = atoi(argv[1]);
n2 = atoi(argv[2]);
printf("%lu\n", n1 *n2);
return (0);
}
