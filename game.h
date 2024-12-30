#define ROW 20
#define COL 30


typedef struct
{
	int x, y;
	char value;
} Body;

typedef struct
{
	int length;
	int direction;
	Body body[100];
} Snake;


void initialize_board(char board[ROW][COL]);
void initialize_snake(Snake *snake);
void generate_feed(char board[ROW][COL]);
void draw_snake(char board[ROW][COL], Snake *snake);
void display_board(char board[ROW][COL]);