#include <stdio.h>
#include <stdint.h>
#include<string.h>
#include <stdlib.h>

int is_num(char *argvv);
char *subtract_one(char *n);
char *infinite_add(char *n1, char *n2);

/**
 *main - print the product of two integers
 * @argc: argument counter
 * @argv: pointer to array of arguments
 *Return: 0 on successes , 98 on error;
 */

int main(int argc, char *argv[])
{
    unsigned long int n1, n2;
    char *n = "235234693269436436223446526546334576437634765378653875874687649698659586695898579";
    char *m = "28658034365084365083426083109679137608216408631430814308651084650816406134060831608310853086103769013709675067130586570832760732096730978014607369739567864508634086304807450973045703428580934825098342095832409850394285098342509834209583425345267413639235755891879970464524226159074760914989935413350556875770807019893069201247121855122836389417022552166316010013074258781583143870461182707893577849408672040555089482160343085482612348145322689883025225988799452329290281169927532160590651993511788518550547570284574715925006962738262888617840435389140329668772644708";
    char *res1 = malloc(1000000000);
    char *res2 = malloc(1000000000);
    res1 = n;
    res2 = "0";
    while (*res1 != '\0')
    {
        res1 = subtract_one(res1);
        res2 = infinite_add(res2, m);
    }
        printf("%s\n", res2);
        free(res1), free(res2);
    // if (argc != 3)
    // {
    //     printf("Error\n");
    //     exit(98);
    // }
    // if (!is_num(argv[1]) || !is_num(argv[2]))
    // {
    //     printf("Error\n");
    //     exit(98);
    // }

    // n1 = atoi(argv[1]);
    // n2 = atoi(argv[2]);
    // printf("%lu\n", n1 * n2);
    return (0);
}

/**
 * is_num - iterate through each argv to test if it's a number
 * @argvv: a argv
 * Return: 1 only if entire string is a number, 0 if not
 */
int is_num(char *argvv)
{
    int j = 0;

    for (j = 0; argvv[j]; j++)
    {
        if (!(argvv[j] >= '0' && argvv[j] <= '9'))
            return (0);
    }
    return (1);
}
/**
 *  ctoi - change char to int
 * @c: charater to be changed
 * Return: an integere
 */
int ctoi(char c)
{
    char *num = malloc(2);
    num[0] = c;
    num[1] = '\0';

    return (atoi(num));
}

    /**
     * infinite_add - adds two numbers
     * @n1: first number
     * @n2: second number
     * @r: buffer for the result
     * @size_r: size of the buffer
     * Return: result buffer on success, 0 on error
     */

    char *infinite_add(char *n1, char *n2)
{
    int len_n1 = strlen(n1);
    int len_n2 = strlen(n2);
    int sum, len_buff, carry;
    char *buff;
    sum = carry = 0;
    len_buff = len_n1 > len_n2 ? len_n1 + 1: len_n2 + 1;
    buff = malloc(len_buff + 1);
    buff[len_buff] = '\0';
    len_n1 --, len_n2 --, len_buff--;
    while (len_buff)
    {
        if (len_n1 < 0 && len_n2 >= 0)
        {
            sum = ctoi(n2[len_n2--]) + carry;
        }
        else if (len_n2 < 0 && len_n1 >= 0)
        {
            sum = ctoi(n1[len_n1--]) + carry;
        }
        else if (len_n1 >= 0 && len_n2 >= 0)
        {
            sum = ctoi(n1[len_n1--]) + ctoi(n2[len_n2--]) + carry;
        }
        carry = sum / 10;
        buff[len_buff--] = (sum % 10) + '0';
        sum = 0;
    }
    if (carry == 0)
    {
        return (++buff);
    }
    buff[0] = carry + '0';
    return (buff);
}

/**
 *  subtract_one - subtract one from a number
 * @n: number
 * Return: number - 1
 */

char *subtract_one(char *n)
{
    int len_n, size_buff;
    int res;
    char *buff;
    len_n = strlen(n);
    size_buff = strlen(n);
    buff = malloc(size_buff + 1);
    buff[size_buff] = '\0';
    size_buff--, len_n--;
    if (n[len_n] >= '1')
    {
        res = ctoi(n[len_n]) - 1;
        buff = strdup(n);
        buff[size_buff] = res + '0';
    }
    else
    {
        while (n[len_n] == '0')
        {
            buff[size_buff--] = '9';
            len_n--;
        }
        res = ctoi(n[len_n]) - 1;
        buff[size_buff] = res + '0';
    }
    while (*buff == '0')
    {
        buff++;
    }
    return (buff);
}