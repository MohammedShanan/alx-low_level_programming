#include"main.h"

/**
 * jack_bauer - print every minute of a day
 * Description: print minutes 00:00 to 23:59
 */

void jack_bauer(void)
{
int hours_tens;
int hours_ones;
int mins_tens;
int mins_ones;
for (hours_tens = '0'; hours_tens <= '2'; hours_tens++)
{
for (hours_ones = '0'; hours_ones <= (hours_tens < '2' ? '9' : '3'); hours_ones++)
{
for (mins_tens = '0'; mins_tens <= '5'; mins_tens++)
{
for (mins_ones = '0'; mins_ones <= '9'; mins_ones++)
{
_putchar(hours_tens);
_putchar(hours_ones);
_putchar(':');
_putchar(mins_tens);
_putchar(mins_ones);
_putchar('\n');
}
}
}
}
}
