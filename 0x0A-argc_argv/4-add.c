#include <stdio.h>
#include <stdlib.h>
/**
 *main - add integers.
*Return: 0 on success 1 on error
*/

int main(int argc, char *argv[])
{
int i, sum = 0;
if (argc == 1)
{
printf("0\n");
return (0);
}
for (i = 1; argv[i]; i++)
{
if (!atoi(argv[i]))
{
printf("Error\n");
return (1);
}
sum += atoi(argv[i]);
}
printf("%i\n", sum);
return (0);
}
