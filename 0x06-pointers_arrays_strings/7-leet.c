
/**
 * leet - encode string into 1337 leet
 * @str: string to manipulate
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
if (chars[indx] == str[i] || chars[indx] == str[i] - 32)
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
