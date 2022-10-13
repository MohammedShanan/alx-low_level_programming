#include <stdio.h>

/**
 *main - uses printf to write a line or string to the output stream
 *Return: 0
 */

int main(void)
{
	printf("size of a char: %i byte(s)\n",sizeof(char));
	printf("size of an int: %i byte(s)\n",sizeof(int));
	printf("size of a long int: %i byte(s)\n",sizeof(long));
	printf("size of a long long int : %i byte(s)\n",sizeof(unsigned int));
	printf("size of a float: %i byte(s)\n",sizeof(float));
	return (0);
}
