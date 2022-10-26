
/**
 * rot13 - encode string using rot13
 * @s: string to encode
 * Return: encoded string
 */

char *rot13(char *s)
{
int i = 0, n;
while (s[i])
{
while (s[i] >= 'a' && s[i] <= 'z')
{
n = s[i] % 'a';
n = n + 13;
n = n % 26;
s[i] = 'a' + n;
i++;
}
if (s[i] >= 'A' && s[i] <= 'Z')
{
n = s[i] % 'A';
n = n + 13;
n = n % 26;
s[i] = 'A' + n;
}

i++;
}
return (s);
}
