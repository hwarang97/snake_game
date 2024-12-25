#include <stdlib.h>
#include <stdio.h>
#include "game.h"

void initialize_board(char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if ((i == 0) || (i == ROW - 1) || (j == 0) || (j == COL - 1)) {
				board[i][j] = '#';
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}
}


void initialize_snake(char board[ROW][COL])
{
	board[ROW / 2][COL / 2] = '@';
	board[ROW / 2][COL / 2 + 1] = 'o';
}


void generate_feed(char board[ROW][COL])
{
	srand(time(NULL));
	while (1)
	{
		int feed_row = rand() % ROW;
		int feed_col = rand() % COL;
		if (board[feed_row][feed_col] == ' ')
		{
			board[feed_row][feed_col] = '0';
			break;
		}
	}
}


void display_board(char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}