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
 * number_to_buffer - write large number from array to buffer
 * @buff: buffer to write to
 * @buff_size: size of the buffer
 * @arr: array containing the number
 * @size_arr: size of the array
 * Return: 1 on success, 0 on error
 */

int number_to_buffer
(char *buff, int buff_size, 
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
arr[arr_counter] = arr[arr_counter] - tens *digit;
tens /= 10;
buff_counter++;
}
arr_counter++;
}
buff[buff_counter] = '\0';
return (1);
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
int size_n1 = get_arr_size(len_n1);
int size_n2 = get_arr_size(len_n2);
int size_sum = size_n1 > size_n2 ? size_n1 + 1 : size_n2 + 1;
int counter = size_sum - 1;
int *arr1 = malloc(size_n1 * sizeof(int));
int *arr2 = malloc(size_n2 * sizeof(int));
unsigned int *sum_array = malloc(size_sum * sizeof(int));
int carry = 0;
unsigned int max_num = 1000000000;
unsigned int sum = 0;
unsigned int result = 0;

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
while (size_n1 >= 0 || size_n2 >= 0)
{
if (size_n1 < 0)
{
sum = arr2[size_n2] + carry;
}
else if (size_n2 < 0)
{
sum = arr1[size_n1] + carry;
}
else
{
sum = arr1[size_n1] + arr2[size_n2] + carry;
}
carry = sum / max_num;
result = sum != max_num ? sum % max_num : max_num;
sum_array[counter] = result;
size_n1--;
size_n2--;
counter--;
}
if (carry == 0 || *(sum_array + 1) == max_num)
{
sum_array++;
size_sum--;
}
else
{
sum_array[0] = 1;
}

if (number_to_buffer(r, size_r, sum_array, size_sum) == 0)
{
return (0);
}
return (r);
}
