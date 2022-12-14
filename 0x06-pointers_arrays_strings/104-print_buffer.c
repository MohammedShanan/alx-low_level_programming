#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * print_buffer - prints a buffer.
 * @b: buffer to print
 * @size: size of the buffer
 */

void print_buffer(char *b, int size)
{
int i, counter = 0, indx = 0;
char *tmp_buffer = malloc(11 * sizeof(char));
if (size > 0)
{
while (counter < size)
{
for (i = 0; i < 10 && counter < size; i++)
{
if (b[counter] < 32)
tmp_buffer[i] = '.';
else
tmp_buffer[i] = b[counter];
counter++;
}
tmp_buffer[i] = '\0';
indx = counter - strlen(tmp_buffer);
printf("%08x: ", indx);
for (i = 0; i < 10; i++)
{
if (indx + i < size)
{
printf("%02x", b[indx + i]);
}
else
{
printf("  ");
}
if (i % 2 != 0)
{
printf(" ");
}
}
printf("%s\n", tmp_buffer);
}
}
else
printf("\n");
}
