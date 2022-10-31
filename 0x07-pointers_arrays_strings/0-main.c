
#include <stdio.h>
#include "main.h"
/**
 * _strpbrk - return pointer to byte in s that matches a byte in accept
 * @s: string to search
 * @accept: target matches
 * Return: pointer to index of string at first occurrence
 */
void print_chessboard(char (*a)[8])
{
	int i = 0, j = 0;

	while (i < 8)
	{
		for (j = 0; j < 8; j++)
		{
			putchar(*(*(a + i) + j));
		}
		putchar('\n');
		i++;
	}
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char board[8][8] = {
		{'r', 'k', 'b', 'q', 'k', 'b', 'k', 'r'},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		{'R', 'K', 'B', 'Q', 'K', 'B', 'K', 'R'},
	};
	print_chessboard(board);
	return (0);
}