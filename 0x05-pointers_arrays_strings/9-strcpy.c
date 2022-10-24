char *_strcpy(char *dest, char *src)
{
    int i;
    i = 0;
    while (*src)
    {
       dest[i] = *src;
        src++, i++;
    }
    dest[i] = '\0';
    return (dest);
}