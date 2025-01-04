#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "game.h"


void grow_snake(Snake* snake, char board[ROW][COL]);


int main() 
{
	// initialize board
	char board[ROW][COL];
	initialize_board(board);
	generate_feed(board);

	// initialize snake
	Snake snake;
	int length = 3;
	initialize_snake(&snake, length);
	
	// display
	bool is_paused = false;
	bool is_running = true;
	while (is_running)
	{
		// puase
		if (is_paused)
		{
			if (_kbhit()) handle_puase(&is_paused);
			continue;
		}

		// key input
		if (_kbhit()) handle_input(&snake, &is_paused, &is_running);

		// clear tail
		clear_tail(&snake, board);

		// move snake
		move_snake(&snake);

		// grow
		grow_snake(&snake, board);

		// check collision
		check_collision(&snake, board, &is_running);

		move_cursor(0, 0);
		draw_snake(board, &snake);
		display_board(board);
		Sleep(100);
	}

	return 0;

}


void grow_snake(Snake* snake, char board[ROW][COL])
{
	int head_x = snake->body[0].x;
	int head_y = snake->body[0].y;

	// grow
	if (board[head_x][head_y] == '0')
	{
		snake->body[snake->length].value = 'o';
		snake->length++;
	}
}