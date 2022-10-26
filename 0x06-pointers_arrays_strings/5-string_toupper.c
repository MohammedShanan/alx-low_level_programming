/**
 * _islower - checks for lowercase character
 * @c: character to check
 * Return: 1 if lowercase, 0 if uppercase
 */

int _islower(int c)
{
if (c >= 'a' && c <= 'z')
{
return (1);
}
else
{
return (0);
}
}

/**
 * string_toupper - capitalize all letters in string
 * @str: string to manipulate
 * Return: string with all letters capitalized
 */

char *string_toupper(char *str)
{
int i;
i = 0;
while (str[i])
{
if (_islower(str[i]))
{
str[i] -= 32;
}
i++;
}
return (str);
}
