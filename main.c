#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main() 
{

	char board[ROW][COL];
	initialize_board(board);
	initialize_snake(board);
	generate_feed(board);
	display_board(board);

	return 0;

}