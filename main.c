#include <stdio.h>
#include <stdlib.h>
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
	while (1)
	{
		// system("cls"); // slow
		move_cursor_to_top();
		draw_snake(board, &snake);
		display_board(board);
		Sleep(100);
	}
	

	return 0;

}