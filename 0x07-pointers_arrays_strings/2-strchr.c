#define NULL 0
/**
 *_strchr - locates a character in a string
 * @s: string to search
 * @c: character to be located
 * Return: pointer to dest
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return ('\0');
}

