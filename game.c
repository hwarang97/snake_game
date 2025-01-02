#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

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


void initialize_snake(Snake *snake)
{
	snake->length = 2;
	snake->direction = 0;
	snake->body[0].x = ROW / 2;
	snake->body[0].y = COL / 2;
	snake->body[0].value = '@';
	snake->body[1].x = ROW / 2;
	snake->body[1].y = COL / 2 + 1;
	snake->body[1].value = 'o';
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


void move_cursor(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x, y };
	SetConsoleCursorPosition(hConsole, coord);
}


void draw_snake(char board[ROW][COL], Snake* snake)
{
	for (int i = 0; i < snake->length; i++)
	{
		board[snake->body[i].x][snake->body[i].y] = snake->body[i].value;
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


void handle_puase(bool* is_paused)
{
	if (_kbhit())
	{
		move_cursor(0, ROW + 2);
		printf("                                            ");
		*is_paused = false;
		_getch();
	}
}


void handle_input(Snake* snake, bool* is_paused, bool* is_running)
{
	char key = _getch();
	if (key == -32) // Special key
	{
		key = _getch();
		switch (key)
		{
		case KEY_UP:
			snake->direction = UP_DIRECTION;
			break;
		case KEY_DOWN:
			snake->direction = DOWN_DIRECTION;
			break;
		case KEY_LEFT:
			snake->direction = LEFT_DIRECTION;
			break;
		case KEY_RIGHT:
			snake->direction = RIGHT_DIRECTION;
			break;
		}
	}
	else // ASCII code
	{
		switch (key)
		{
		case 'p':
			move_cursor(0, ROW + 2);
			printf("Game Puased, Press any key to resume");
			*is_paused = true;
			break;
		case KEY_ESC:
			*is_running = false;
			break;
		}
	}
}