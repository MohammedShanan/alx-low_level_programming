#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/**
 *main - Entry point
 *Return: 0
 */
int main(void)
{
    int tens;
    int ones;
    int t;
    int o;
    for (tens = '0'; tens <= '9'; tens++)
    {
        for (ones = '0'; ones <= '9'; ones++)
        {
            for (t = '0'; t <= '9'; t++)
            {

                for (o = ones + 1; o <= '9'; o++)
                {
                    if ((t == tens) && (o == ones))
                    {
                        continue;
                    }
                    putchar(tens);
                    putchar(ones);
                    putchar(' ');
                    putchar(t);
                    putchar(o);
                    if ((tens != '9' || ones != '8') || (t != '9' && o != '9'))
                    {
                        putchar(',');
                        putchar(' ');
                    }
                }
            }
        }
    }
    putchar('\n');
    return (0);
}
