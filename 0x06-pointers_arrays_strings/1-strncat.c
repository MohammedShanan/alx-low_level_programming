
/**
 * _strncpy - copies n bytes of a source into buffer of a destination string,
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * @n: n bytes to be copied
 * Return: copied string
 */

char *_strncat(char *dest, char *src, int n)
{
int i, indx;
i = 0;
indx = 0;
while (dest[i])
{
i++;
}
while (src[indx] && indx < n)
{
dest[i] = src[indx];
i++, indx++;
}
dest[i] = '\0';
return (dest);
}
