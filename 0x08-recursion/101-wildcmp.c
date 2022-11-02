/**
 * _strlen_recursion - get the length of a string
 * @s: string
 * Return: length of the string
 */

int _strlen_recursion(char *s)
{
if (!*s)
{
return (0);
}
return (1 + _strlen_recursion(++s));
}

/**
 * _wildcmp - compare if string with wildcard mattches
 * @str1: one string
 * @str2: one string
 * @len1: length of str1
 * @len2: length of str2
 * Return: 1 if matched, 0 if not
 */

int _wildcmp(char *str1, char *str2, int len1, int len2)
{
if ((*str1 && *str2) || *str2 == '*')
{
if (len1 < len2 && *str2 == '*')
{
return (_wildcmp(str1, ++str2, len1, --len2));
}
else if (*str1 == *str2)
{
return (_wildcmp(++str1, ++str2, --len1, --len2));
}
else if (*str2 == '*')
{
return (_wildcmp(++str1, str2, --len1, len2));
}
else if (*str1 != *str2 && *(str2 - 1) == '*' && *(str2 + 1) == '*')
{
return (_wildcmp(++str1, str2, --len1, len2));
}
else
{
return (0);
}
}
if (len1 == len2)
{
return (1);
}
return (0);
}

/**
 * wildcmp - compare if string with wildcard mattches
 * @s1: one string
 * @s2: one string
 * Return: 1 if matched, 0 if not
 */

int wildcmp(char *s1, char *s2)
{
int len1 = _strlen_recursion(s1);
int len2 = _strlen_recursion(s2);
return (_wildcmp(s1, s2, len1, len2));
}
