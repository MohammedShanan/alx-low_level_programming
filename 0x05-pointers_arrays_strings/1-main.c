#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s[] = "Holberton!";

    printf("%s\n", s);
    rev_string(s);
    printf("%s\n", s);
    return (0);
}