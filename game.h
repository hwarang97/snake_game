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


// init
void initialize_board(char board[ROW][COL]);
void initialize_snake(Snake *snake);

// feed
void generate_feed(char board[ROW][COL]);

// display
void move_cursor_to_top(void);
void draw_snake(char board[ROW][COL], Snake *snake);
void display_board(char board[ROW][COL]);