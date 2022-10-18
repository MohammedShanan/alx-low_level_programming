#include<stdio.h>

void _putchar(char c)
{
    fwrite(&c, sizeof(c), 1, stdout);
}