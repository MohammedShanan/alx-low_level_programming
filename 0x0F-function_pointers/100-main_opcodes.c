#include <stdlib.h>
#include <stdio.h>
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
printf("%x\n", *(*(f + i)));
}
return 0;
}
