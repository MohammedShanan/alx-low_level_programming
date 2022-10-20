#include"main.h"
#include<math.h>

void print_number(int n)
{
    int power_ten, length = 0;
    char digit;
    int temp = n;
    if (n < 0)
    {
        _putchar('-');
        n = n * -1;
    }
    while (temp / 10 != 0)
    {
        temp /= 10;
        length++;
    }
    while (n / 10 != 0 || n <= 9)
    {
        power_ten = pow(10, length);
        digit = '0' + (n / power_ten);
        _putchar(digit);
        n = n % power_ten;
        length--;
    }
}