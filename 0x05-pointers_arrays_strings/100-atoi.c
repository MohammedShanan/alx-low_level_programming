
char *get_num_indx(char *s)
{
    int i;
    for (i = 0; *s; i++)
    {
        if (*s >= '0' && *s <= '9')
        {
            return (s);
        }
    }
    return (s);
}

int num_len(char *indx)
{
    int len;
    len = 0;
    while (*indx)
    {
        if (!(*indx >= '0') && !(*indx >= '9'))
        {
            break;
        }
        
        indx++, len++;
    }
    return (len);
}

int num_tens_deg(int len)
{
    int tens = 1;
    while (len - 1)
    {
        tens *= 10;
        len--;
    }
    return (tens);
}

int num_sign(char *s, char *stop)
{
    int i, sign;
    sign = 0;
    for ( i = 0; s != stop; i++)
    {
        if (*s == '-')
        {
            sign++;
        }
    }
    return (sign % 2 == 0 ? 1 : -1);
}

int _atoi(char *s)
{
    char *num_indx;
    int num, i, tens_deg, num_lens, digit;

    num_indx = get_num_indx(s);
    num_lens = num_len(num_indx);
    num = 0;
    tens_deg = num_tens_deg(num_lens);
    for ( i = 0; num_lens; i++)
    {
        digit = (*num_indx + i) % '0';
        num += tens_deg * digit;
        num_lens--;
    }
    return (num * num_sign(s, num_indx));
}
