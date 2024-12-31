#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "game.h"

// Arrow key
typedef enum {
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 75,
	KEY_RIGHT = 77,
} KEY_INPUT;

// Direction
typedef enum {
	UP_DIRECTION = 8,
	LEFT_DIRECTION = 4,
	DOWN_DIRECTION = 5,
	RIGHT_DIRECTION = 6
} DIRECTION;


void pause(void);


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
	while (1)
	{
		// puase
		if (is_paused)
		{
			if (_kbhit())
			{
				move_cursor(0, ROW + 2);
				printf("                                            ");
				is_paused = false;
			}
			continue;
		}

		// key input
		if (_kbhit())
		{
			char key = _getch();
			if (key == -32) // Special key
			{
				key = _getch();
				switch (key)
				{
				case KEY_UP:
					snake.direction = UP_DIRECTION;
					break;
				case KEY_DOWN:
					snake.direction = DOWN_DIRECTION;
					break;
				case KEY_LEFT:
					snake.direction = LEFT_DIRECTION;
					break;
				case KEY_RIGHT:
					snake.direction = RIGHT_DIRECTION;
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
					is_paused = true;
					break;
				case KEY_ESC:
					printf("ESC");
					break;
				}
			}
		}
		


		move_cursor(0, 0);
		draw_snake(board, &snake);
		display_board(board);
		Sleep(100);
	}
	

	return 0;

}