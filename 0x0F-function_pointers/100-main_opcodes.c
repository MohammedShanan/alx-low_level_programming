#include <stdlib.h>
#include <stdio.h>
/**
 *main - print n bytes form main opcode as specfied by user
* @argc: argument counter
* @argv: pointer to array of arguments
*Return: 0 on success 1 or 2 on error
*/

int main(int argc, char *argv[])
{
int b, i;
int (*f)(int, char **);
if (argc != 2)
{
printf("Error\n");
return (1);
}
b = atoi(argv[1]);
if (b < 0)
{
printf("Error\n");
return (2);
}
f = main;
for (i = 0; i < b; i++)
{
printf("%p\n", *(*(f + i)));
}
return (0);
}
