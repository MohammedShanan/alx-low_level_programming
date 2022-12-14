/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, the return value is a short item count (or zero).
 */
int _putchar(char c);

/**
 * _isupper - checks for uppercase character
 * @c: character to check
 * Return: 1 if uppercase, 0 if lowercase
 */

int _isupper(int c);

/**
 * _isdigit - checks for digit character
 * @c: character to check
 * Return: 1 if it's a digit , 0 if otherwise
 */

int _isdigit(int c);

/**
 * add - add two integers
 * @a: two integer arguments
 * @b: two integer arguments
 * Return: product
 */

int mul(int a, int b);

/**
 * print_numbers - prints numbers from 0 to 9
 */

void print_numbers(void);

/**
 * print_numbers - prints numbers from 0 to 9 except 2 and 4
 */

void print_most_numbers(void);

/**
 * more_numbers - print 0 to 14 ten times
 */

void more_numbers(void);

/**
 * print_line - print the character "_" n times to draw a line
 * @n: number of _ to draw
 */

void print_line(int n);

/**
 * print_diagonal - print character "\" n times
 * @n: number of characters to draw
 */

void print_diagonal(int n);

/**
 * print_square - print a square of #'s given size
 * @size: size to draw
 */

void print_square(int size);

/**
 * print_triangle - print triangle with #'s with given size
 * @size: size of triangle to draw
 */

void print_triangle(int size);

/**
 * print_number - print an integer, without using long, arrays, or pointers
 * @n: number to be printed
 */

void print_number(int n);