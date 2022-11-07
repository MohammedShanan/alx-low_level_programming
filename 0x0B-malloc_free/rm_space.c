#include<stdlib.h>
char *rm_ext_space(char *s)
{
    int i, indx = 0, len = _strlen(s) + 1, len_tmp = 0;
    char *tmp = malloc(len);
    char *new_s;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0' || len_tmp == 0))
        {
            continue;
        }
        tmp[len_tmp++] = s[i];
    }
    tmp[len_tmp] = '\0';
    new_s = malloc(len_tmp);
    if (new_s == NULL)
    {
        return (NULL);
    }
    for (indx = 0; indx <= len_tmp; indx++)
    {
        new_s[indx] = tmp[indx];
    }
    free(tmp);
    return (new_s);
}