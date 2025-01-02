#define ROW 20
#define COL 30
#define KEY_ESC 27


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
void move_cursor(int x, int y);
void draw_snake(char board[ROW][COL], Snake *snake);
void display_board(char board[ROW][COL]);

// handle
void handle_puase(bool* is_paused);
void handle_input(Snake* snake, bool* is_paused, bool* is_running);