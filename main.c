#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "game.h"


void check_collision(Snake* snake, char board[ROW][COL], bool *is_running);


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

		// check collision
		check_collision(&snake, board, &is_running);

		move_cursor(0, 0);
		draw_snake(board, &snake);
		display_board(board);
		Sleep(100);
	}

	return 0;

}


void check_collision(Snake* snake, char board[ROW][COL], bool *is_running)
{
	int head_x = snake->body[0].x;
	int head_y = snake->body[0].y;

	// collision with wall
	if (board[head_x][head_y] == '#')
	{
		move_cursor(0, ROW + 2);
		printf("Game Over! You hit the wall");
		*is_running = false;
	}

	// collision with tail
	if (board[head_x][head_y] == 'o')
	{
		move_cursor(0, ROW + 2);
		printf("Game Over! Your ran into yourself");
		*is_running = false;
	}
}