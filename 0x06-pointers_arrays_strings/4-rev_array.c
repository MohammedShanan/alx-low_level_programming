/**
 * reverse_array - reverse array elements
 * @a: array
 * @n: number of elements in array
 */

void reverse_array(int *a, int n)
{
int i, tmp;
n = n - 1;
for (i = 0; i < n; i++)
{
tmp = a[i];
a[i] = a[n];
a[n] = tmp;
n--;
}
}
