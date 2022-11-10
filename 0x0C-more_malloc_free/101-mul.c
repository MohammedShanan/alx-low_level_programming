#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int is_num(char *argvv);

/**
 *main - print the product of two integers
* @argc: argument counter
* @argv: pointer to array of arguments
*Return: 0 on successes , 98 on error;
*/


int main(int argc, char *argv[])
{
unsigned long int n1, n2;
if (argc != 3)
{
printf("Error\n");
exit(98);
}
if (!is_num(argv[1]) || !is_num(argv[2]))
{
printf("Error\n");
exit(98);
}

n1 = atoi(argv[1]);
n2 = atoi(argv[2]);
printf("%lu\n", n1 *n2);
return (0);
}

/**
 * is_num - iterate through each argv to test if it's a number
 * @argvv: a argv
 * Return: 1 only if entire string is a number, 0 if not
 */
int is_num(char *argvv)
{
int j = 0;

for (j = 0; argvv[j]; j++)
{
if (!(argvv[j] >= '0' && argvv[j] <= '9'))
return (0);
}
return (1);
}
