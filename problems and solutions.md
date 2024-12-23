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
