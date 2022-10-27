#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get_arr_size(int len)
{
    int array_size;

    array_size = len / 9;
    if (array_size * 9 < len)
    {
        array_size += 1;
    }
    return (array_size);
}

void create_num_array(char *s, int new_arr[], int size, int len)
{
    int start, end, counter = 0, i = 0;
    char *tmp = malloc(10 * sizeof(char));
    size -= 1;
    start = len - 9 <= 0 ? 0 : len - 9;
    end = len - 1;
    while (size >= 0)
    {
        while (start + i <= end)
        {
            *(tmp + i) = s[start + i];
            i++;
        }
        tmp[i] = '\0';
        i = 0;
        end = start - 1;
        start = start - 9 <= 0 ? 0 : start - 9;
        new_arr[size] = atoi(tmp);
        size--;
    }
    free(tmp);
}
void number_to_buffer(char *buff, int buff_size, int arr[])
{
    int buff_counter = 0, arr_counter = 0;
    unsigned int digit;
    double tens = 1;

    while (tens * 10 <= arr[arr_counter])
    {
        tens *= 10;
    }

    while (tens >= 1)
    {
        digit = arr[arr_counter] / tens;
        buff[buff_counter] = digit + '0';
        arr[arr_counter] = arr[arr_counter] - tens * digit;
        tens /= 10;
        buff_counter++;
    }
}
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len_n1 = strlen(n1);
    int len_n2 = strlen(n2);
    int size_n1 = get_arr_size(len_n1);
    int size_n2 = get_arr_size(len_n2);
    int size_sum = size_n1 > size_n2 ? size_n1 + 1 : size_n2 + 1;
    int *arr1 = malloc(size_n1 * sizeof(int));
    int *arr2 = malloc(size_n2 * sizeof(int));
    int *sum_array = malloc(size_sum * sizeof(int));
    int carry = 0;
    unsigned int sum = 0;
    create_num_array(n1, arr1, size_n1, len_n1);
    create_num_array(n2, arr2, size_n2, len_n2);
    if (arr1 == NULL || arr2 == NULL || sum_array == NULL)
    {
        free(arr1);
        free(arr2);
        free(sum_array);
        return (0);
    }

    size_n1 -= 1;
    size_n2 -= 1;
    size_sum -= 1;
    while (size_n1 >= 0 && size_n2 >= 0)
    {
        sum = arr1[size_n1] + arr2[size_n2] + carry;
        carry = sum / 1000000000;
        sum_array[size_sum] = sum;
        size_n1--;
        size_n2--;
        size_sum--;
    }
    if (size_n1 > size_n2)
    {
        while (size_n1 >= 0)
        {
            sum = arr1[size_n1] + carry;
            carry = sum / 1000000000;
            sum_array[size_sum] = sum;
            size_n1--;
            size_sum--;
        }
    }
    else if (size_n1 < size_n2)
    {
        while (size_n2 >= 0)
        {
            sum = arr2[size_n2] + carry;
            carry = sum / 1000000000;
            sum_array[size_sum] = sum;
            size_n2--;
            size_sum--;
        }
    }
    if (size_sum == 0)
    {
        sum_array[size_sum] = carry;
    }

    number_to_buffer(r, size_r, sum_array);
    return (r);
}