#include"main.h"

/**
 * jack_bauer - print every minute of a day
 * Description: print minutes 00:00 to 23:59
 */

void jack_bauer(void)
{
int h_tens;
int h_ones;
int mins_tens;
int mins_ones;
for (h_tens = '0'; h_tens <= '2'; h_tens++)
{
for (h_ones = '0'; h_ones <= (h_tens < '2' ? '9' : '3'); h_ones++)
{
for (mins_tens = '0'; mins_tens <= '5'; mins_tens++)
{
for (mins_ones = '0'; mins_ones <= '9'; mins_ones++)
{
_putchar(h_tens);
_putchar(h_ones);
_putchar(':');
_putchar(mins_tens);
_putchar(mins_ones);
_putchar('\n');
}
}
}
}
}
