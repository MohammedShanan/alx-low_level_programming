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
 * char_toupper - capitalize a letter
 * @c: letter to capitalize
 * Return: string with all letters capitalized
 */

void char_toupper(char *c)
{
if (_islower(*c))
{
*c -= 32;
}
}

/**
 * is_Separator - check if the
 * character is a separator or not
 * @c: character to be checked
 * Return: 1 if separator 0 if not
 */

int is_Separator(char c)
{
char sep[] = {'\n', '\t', ' ',
'\"', '.', '?', '!', ';', '{', '}', '(', ')', ','};
int i = 0;
while (sep[i])
{
if (c == sep[i])
{
return (1);
}
i++;
}
return (0);
}

/**
 * cap_string - capitalize first letter of each word
 * @s: string to manipulate
 * Return: string
 */

char *cap_string(char *s)
{
int indx;
indx = 0;
while (s[indx + 1])
{
if (is_Separator(s[indx]))
{
char_toupper(s + indx + 1);
}
indx++;
}
return (s);
}
