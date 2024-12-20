# Requirements
1. Display
   ---
   |Symbol            |Description |
   | :--------------- | :--------- |
   |#                 |wall        |
   |0                 |feed        |
   |@                 |snake's head|
   |o                 |snake's tail|           
  
   Board can be created by quadratic array.
   - First and Last ros is filled with '#'.
   - First and Last col is filled with '#'.
   - Other elements is filled with ' '.   
  
   Snake's is located center at first.
   - Center position(ROW//2, COL//2) of array is filled with '@'.
  
   Snake's tail is located right side of the head.
   - Right side of center(ROW//2, COL//2 + 1) of array is filled with 'o'.
   
   Feed is randomly created in board.
   - Select random row, col by random library.
   - Feed is not created on wall, snake. Check board[row][col] == ' '.
  
   Display Board
   - make display_board function.

2. User input
   ---
    - arrow key: move 
    - p: pause
    - esc: exit   
    
    User preeses arrow key to control snake. When user press 'p', game is paused. When user press 'esc', game is done.

    
3. Game logic
   ---
    - snake move
    - collision
    - grow
    - speed up
    - score

Snake moving direction is depends on pressed arrow key. If there is no arrow key input, snake keeps going one direction. When snake have feed, snake is longer, speed up and score is counted. When snake encounters with self or wall, game is over.


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
