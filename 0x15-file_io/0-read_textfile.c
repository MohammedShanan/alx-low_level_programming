#include "main.h"
/**
 * read_textfile - read a certain size and prints to std output
 * @filename: file to read from
 * @letters: size to read
 * Return: actual size read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t bytes_read, bytes_wrote;
char *buff;
if (filename == NULL || letters == 0)
{
return (0);
}
fd = open(filename, O_RDONLY);
if (fd == -1)
{
return (0);
}
buff = malloc(letters);
if (buff == NULL)
{
close(fd);
return (0);
}
bytes_read = read(fd, buff, letters);
if (bytes_read == -1)
{
close(fd);
free(buff);
return (0);
}
bytes_wrote = write(STDOUT_FILENO, buff, bytes_read);
if (bytes_wrote == -1)
{
close(fd);
free(buff);
return (0);
}
close(fd);
return (bytes_read);
}
