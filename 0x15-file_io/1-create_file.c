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
int fd, bytes_wrote;
if (!filename)
{
return (-1);
}
fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
{
return (-1);
}
if (!text_content)
{
close(fd);
return (1);
}
bytes_wrote = write(fd, text_content, _strlen(text_content));
if (bytes_wrote == -1 || bytes_wrote != _strlen(text_content))
{
close(fd);
return (-1);
}
close(fd);
return (1);
}
