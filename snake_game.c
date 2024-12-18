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

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}

	return 0;

}