#include "main.h"
void cp(char *file_1, char *file_2);
int errors(int exit_status, char *filename, int fd);
/**
 * main - copies one file to another
 * @argc: argument counter
 * @argv: pointer to array of arguments
 * Return: 0 (success), 97-100 (exit value errors)
 */
int main(int argc, char *argv[])
{
if (argc != 3)
{
errors(97, NULL, 0);
}
cp(argv[1], argv[2]);
return (0);
}
/**
 * cp - copies one file to another
 * @file_1: name of the first file
 * @file_2: name of the second file
 */
void cp(char *file_1, char *file_2)
{
int fd_1, fd_2, bytes_read, bytes_wrote;
char *buff[1024];
fd_1 = open(file_1, O_RDONLY);
if (fd_1 == -1)
{
errors(98, file_1, fd_1);
}
fd_2 = open(file_2, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_2 == -1)
{
errors(99, file_2, fd_2);
}
while ((bytes_read = read(fd_1, buff, 1024)))
{
if (bytes_read == -1)
{
errors(98, file_1, fd_1);
}
bytes_wrote = write(fd_2, buff, 1024);
if (bytes_wrote == -1)
{
errors(99, file_2, fd_2);
}
}
close(fd_2) == -1 ? (errors(100, NULL, fd_2)) : close(fd_2);
close(fd_1) == -1 ? (errors(100, NULL, fd_1)) : close(fd_1);
}
/**
 * errors - prints error messages and exits with exit value
 * @exit_status: exit status value
 * @filename: file name
 * @fd: file descriptor
 **/
int errors(int exit_status, char *filename, int fd)
{
switch (exit_status)
{
case 97:
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(exit_status);
case 98:
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
exit(exit_status);
case 99:
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
exit(exit_status);
case 100:
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(exit_status);
default:
return (0);
}
}
