#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "game.h"


int main() 
{
	// initialize board
	char board[ROW][COL];
	initialize_board(board);
	generate_feed(board);

	// initialize snake
	Snake snake;
	initialize_snake(&snake);
	
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
		
		
		move_cursor(0, 0);
		draw_snake(board, &snake);
		display_board(board);
		Sleep(100);
	}

	return 0;

}

