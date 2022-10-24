#include<stdio.h>

int _strlen(char *s)
{
    int len;
    len = 0;
    while (*s)
    {
        len++;
        s++;
    }
    return (len);
}

int main(void)
{
    int x = 333;
    float y = 10.5;
    char *str = "test";
    printf("x is %i", x);
    if (x > 400)
    {
        putchar('k');
    }
    else
    {
        printf("no");
    }

    if (y > 9)
    {
        printf("y is %f", y);
    }
    int i;
    for (i = 0; i < y; i++)
    {
        puts("loop");
    }
    int len;
    if (i == 11)
    {
        len = _strlen(str);
    }
    
}