
/**
 * _strspn - return length of string that matches values consistently
 * @s: string to search
 * @accept: target matches
 * Return: number of bytes consecutively matched
 */

unsigned int _strspn(char *s, char *accept)
{
int i, j, counter;
counter = 0;
while (*(s + i))
{
for (j = 0; *(accept + j); j++)
{
if (*(s + i) == *(accept + j))
{
counter++;
break;
}
if (*(accept + j + 1) == '\0' && *(s + i) != *(accept + j))
{
return (counter);
}
}
i++;
}
return (counter);
}
