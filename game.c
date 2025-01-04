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
				board[i][j] = WALL;
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}
}

void initialize_snake(Snake *snake, int length)
{
	snake->length = length;
	snake->direction = LEFT_DIRECTION;
	snake->body[0].x = ROW / 2;
	snake->body[0].y = COL / 2;
	snake->body[0].value = HEAD;

	for (int i = 1; i < snake->length; i++)
	{
		snake->body[i].x = ROW / 2;
		snake->body[i].y = COL / 2 + i;
		snake->body[i].value = TAIL;
	}
	
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
			board[feed_row][feed_col] = FEED;
			break;
		}
	}
}


void move_snake(Snake* snake)
{
	// snake[snake->length] is element for grow
	for (int i = snake->length; i > 0; i--)
	{
		snake->body[i].x = snake->body[i - 1].x;
		snake->body[i].y = snake->body[i - 1].y;
	}

	switch (snake->direction)
	{
	case UP_DIRECTION:
		snake->body[0].x -= 1;
		break;
	case DOWN_DIRECTION:
		snake->body[0].x += 1;
		break;
	case LEFT_DIRECTION:
		snake->body[0].y -= 1;
		break;
	case RIGHT_DIRECTION:
		snake->body[0].y += 1;
		break;
	}
}


void clear_tail(Snake* snake, char board[ROW][COL])
{
	int last_position = snake->length - 1;
	int last_x = snake->body[last_position].x;
	int last_y = snake->body[last_position].y;

	board[last_x][last_y] = ' ';
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


void grow_snake(Snake* snake, char board[ROW][COL])
{
	int head_x = snake->body[0].x;
	int head_y = snake->body[0].y;

	// grow
	if (board[head_x][head_y] == FEED)
	{
		snake->body[snake->length].value = TAIL;
		snake->length++;
		generate_feed(board);
	}
	
}


void check_collision(Snake* snake, char board[ROW][COL], bool* is_running)
{
	int head_x = snake->body[0].x;
	int head_y = snake->body[0].y;

	// collision with wall
	if (board[head_x][head_y] == WALL)
	{
		move_cursor(0, ROW + 2);
		printf("Game Over! You hit the wall");
		*is_running = false;
	}

	// collision with tail
	if (board[head_x][head_y] == TAIL)
	{
		move_cursor(0, ROW + 2);
		printf("Game Over! Your ran into yourself");
		*is_running = false;
	}
}