#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * get_arr_size - create an array to store the number
 * @len: number digits in the number
 * Return: size of the array
 */
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

/**
 * create_num_array - create an array to store the number
 * @s: number
 * @new_arr: array to be created
 * @size: size of the array
 * @len: number of digits in the number
 * Return: 1 success, 0 on error
 */

int create_num_array(char *s, int new_arr[], int size, int len)
{
int start, end, i = 0;
char *tmp = malloc(10 * sizeof(char));
if (tmp == NULL)
{
return (0);
}

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
return (1);
}

/**
 * num_to_buff - write large number from array to buffer
 * @buff: buffer to write to
 * @buff_size: size of the buffer
 * @arr: array containing the number
 * @size_arr: size of the array
 * Return: 1 on success, 0 on error
 */

int num_to_buff(char *buff, int buff_size,
unsigned int arr[], int size_arr)
{
int buff_counter = 0, arr_counter = 0, i = 0;
unsigned int digit;
double tens = 1;
while (tens <= arr[arr_counter])
{
tens *= 10;
i++;
}
if (i + 9 * (size_arr - 1) > (buff_size - 1))
{
return (0);
}

while (arr_counter < size_arr && buff_counter < buff_size)
{
tens = 1;
while (tens * 10 <= arr[arr_counter])
{
tens *= 10;
}

while (tens >= 1 && buff_counter < buff_size)
{
digit = arr[arr_counter] / tens;
buff[buff_counter] = digit + '0';
arr[arr_counter] = arr[arr_counter] - tens * digit;
tens /= 10;
buff_counter++;
}
arr_counter++;
}
buff[buff_counter] = '\0';
return (1);
}

/**
 * sum_arrays - sum two arrays
 * @arr1: first number
 * @arr2: second number
 * @size_arr1: size of first array
 * @size_arr2: size of second array
 * @size_sum: a pointer to the size of the first
 * Return: a pointer to the sum array
 */

unsigned int *sum_arrays(int arr1[], int arr2[],
int size_arr1, int size_arr2, int *size_sum)
{
int carry = 0;
unsigned int max_num = 1000000000, sum = 0;
int counter = *size_sum - 1;
unsigned int *sum_array = malloc(*size_sum * sizeof(int));

size_arr1 -= 1, size_arr2 -= 1;
while (size_arr1 >= 0 || size_arr2 >= 0)
{
if (size_arr1 < 0)
{
sum = arr2[size_arr2] + carry;
}
else if (size_arr2 < 0)
{
sum = arr1[size_arr1] + carry;
}
else
{
sum = arr1[size_arr1] + arr2[size_arr2] + carry;
}
carry = sum / max_num;
sum_array[counter] = sum != max_num ? sum % max_num : max_num;
size_arr1--, size_arr2--, counter--;
}
if (carry == 0 || *(sum_array + 1) == max_num)
{
sum_array++, *size_sum -= 1;
}
else
{
sum_array[0] = 1;
}
return (sum_array);
}

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer for the result
 * @size_r: size of the buffer
 * Return: result buffer on success, 0 on error
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int len_n1 = strlen(n1);
int len_n2 = strlen(n2);
int size_arr1 = get_arr_size(len_n1);
int size_arr2 = get_arr_size(len_n2);
int size_sum = size_arr1 > size_arr2 ? size_arr1 + 1 : size_arr2 + 1;
int *arr1 = malloc(size_arr1 * sizeof(int));
int *arr2 = malloc(size_arr2 * sizeof(int));
unsigned int *sum_array;
if (arr1 == NULL || arr2 == NULL)
{
free(arr1), free(arr2);
return (0);
}
create_num_array(n1, arr1, size_arr1, len_n1);
create_num_array(n2, arr2, size_arr2, len_n2);

sum_array = sum_arrays(arr1, arr2, size_arr1, size_arr2, &size_sum);
if (num_to_buff(r, size_r, sum_array, size_sum) == 0)
{
return (0);
}
return (r);
}
