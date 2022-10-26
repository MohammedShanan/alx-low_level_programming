#include<stdio.h>
char *rot13(char *s)
{
    int i = 0, n;
    while (s[i])
    {
        while (s[i] >= 'a' && s[i] <= 'z')
        {
            n = (s[i] + 13) % ('a' + 26);
            printf("n is %i char is %c\n", n, s[i]);

            s[i] = 'a' + n;
            i++;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            n = (s[i] + 13) % ('A' + 26);
            printf("n is %i char is %c\n", n, s[i]);
            s[i] = 'A' + n ;
            
        }
        
        i++;
    }
    return (s);
}