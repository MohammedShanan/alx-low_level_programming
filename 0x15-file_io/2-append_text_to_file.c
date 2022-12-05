#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */

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

/**
 * append_text_to_file - append text and only if file exists
 * @filename: file
 * @text_content: appends this content into file
 * Return: 1 on success, -1 on error
 */

int append_text_to_file(const char *filename, char *text_content)
{
int fd, chars_wrote;
if (!filename)
{
return (-1);
}
fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
{
return (-1);
}
if (!text_content)
{
close(fd);
return (1);
}
chars_wrote = write(fd, text_content, _strlen(text_content));
if (chars_wrote == -1 || chars_wrote != _strlen(text_content))
{
close(fd);
return (-1);
}
close(fd);
return (1);
}
