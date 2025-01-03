## Why can't variable be used when declaring an array?
Unlike python, error occurs when I use variable in array. Becuase C language declaration is performed in compile-time, it can't reference value in row, col memory. Value assingment to memory is performed in run-time. By contrast, python can declare array with variable cause it supports dynamic declaration. Cause python interpretes line by line, when array declaration line is executed, interpreter can access memory of variable.
```c
int main()
{
	int row = 20;
	int col = 30;
	char board[row][col];

	return 0;
}
```
![image](https://github.com/user-attachments/assets/cb7f12ca-db44-4d94-a652-a9bc62f6c6e4)


Solution   
link: https://www.youtube.com/watch?v=5mUnnK_mNFs   
Use macro instead of variable

```c
#include <stdio.h>
#define ROW 20
#define COL 30

int main() 
{

	char board[ROW][COL];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if ((i == 0) || (i == ROW-1) || (j == 0) || (j == COL -1)) {
				board[i][j] = '#';
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}
```
## What is difference between runtime and compile time?
Compile time is process of build. When you make source code, it would be execuable by compile and linking. The period is called __compiletime__.
After execuable is created, it can be executed. When it exectued, the executable is loaded to memory and performed by cpu. This period is called __runtime__.


## Why should i avoid using cls?
To display the game screen, a while loop is used to repeatedly refresh the screen at regular intervals. This ensures the game updates dynamically, providing a smooth gameplay experience. However, the initial implementation using the cls command revealed significant performance issues.

__Probelm__
- The cls command requires the creation of a new shell (cmd.exe) process every time it is called.
- This additional process creation and termination slow down the execution speed.
- In a repetitive game loop, this performance bottleneck becomes particularly noticeable, leading to inefficiency.

__Cause__
- The system("cls") function does not directly clear the console from within the program. Instead, it invokes an external command (cmd.exe) to perform the operation, which adds unnecessary overhead.

__Solution__
- Replace system("cls") with a method that moves the console cursor to the desired position and overwrites the existing content.
- In Windows, this can be achieved using the SetConsoleCursorPosition API, which efficiently moves the cursor to a specific coordinate within the console. This avoids the need for external process creation, significantly improving performance and providing a smoother user experience.

```c
while (1)
{
	//system("cls"); // slow
	move_cursor_to_top();
	draw_snake(board, &snake);
	display_board(board);
	Sleep(100);
}
```
### __system("cls") version__   
![wincls-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/2724430f-f0f9-4be8-9537-327f12b27034)

### __win cursor version__
![win_cursor-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/6a411d91-679c-41b5-8863-f3906439685a)

## How can i manage game state message?
```c
switch (key)
{
case 'p':
    printf("Game Puase\n");
    printf("Press any key to resume");
    is_paused = true;
    break;
case KEY_ESC:
    printf("ESC");
    break;
}
```
![puasemessageremianproblem-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/bb7660b3-02b7-4130-b26e-84a768313223)

## Simplify snake moving
```c
switch (snake.direction)
{
case UP_DIRECTION:
	for (int i = 0; i < snake.length; i++)
	{
		snake.body[i].x -= 1;
	}
	break;
case DOWN_DIRECTION:
	for (int i = 0; i < snake.length; i++)
	{
		snake.body[i].x += 1;
	}
	break;
case LEFT_DIRECTION:
	for (int i = 0; i < snake.length; i++)
	{
		snake.body[i].y -= 1;
	}
	break;
case RIGHT_DIRECTION:
	for (int i = 0; i < snake.length; i++)
	{
		snake.body[i].y += 1;
	}
	break;
}
```
```c
void move_snake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    switch (snake->direction) {
        case UP_DIRECTION:    snake->body[0].x -= 1; break;
        case DOWN_DIRECTION:  snake->body[0].x += 1; break;
        case LEFT_DIRECTION:  snake->body[0].y -= 1; break;
        case RIGHT_DIRECTION: snake->body[0].y += 1; break;
    }
}
```

## Don Not Use Magic Number

```python

void initialize_snake(Snake *snake)
{
	snake->length = 2;
	snake->direction = 0; # need to fix 
	snake->body[0].x = ROW / 2;
	snake->body[0].y = COL / 2;
	snake->body[0].value = '@';
	snake->body[1].x = ROW / 2;
	snake->body[1].y = COL / 2 + 1;
	snake->body[1].value = 'o';
}
```

