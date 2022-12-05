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
 * create_file - creates file with permissions rw------- and writes content in
 * if file already exists, don't change permissions and just truncate it
 * @filename: name to give to new file
 * @text_content: writes this content into file
 * Return: 1 on success, -1 on error
 */

int create_file(const char *filename, char *text_content)
{
int fd, chars_wrote;
if (filename == NULL)
{
return (-1);
}
fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 600);
if (fd == -1)
{
return (-1);
}
if (text_content == NULL)
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
