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
 * Return: uppercase letter
 */

char char_toupper(char c)
{
if (_islower(c))
{
c -= 32;
}
return (c);
}

/**
 * leet - encode string into 1337 leet
 * @s: string to manipulate
 * Return: string
 */

char *leet(char *str)
{
char encode_1337[5] = {'4', '3', '0', '7', '1'};
char chars[5] = {'A', 'E', 'O', 'T', 'L'};
int i, indx;
i = 0;
while (str[i])
{
indx = 0;
while (indx < 5)
{
if (chars[indx] == char_toupper(str[i]))
{
str[i] = encode_1337[indx];
break;
}
indx++;
}
i++;
}
return (str);
}
