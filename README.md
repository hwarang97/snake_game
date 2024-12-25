# Requirements
Display
   ---
   |Symbol            |Description |
   | :--------------- | :--------- |
   |#                 |wall        |
   |0                 |feed        |
   |@                 |snake's head|
   |o                 |snake's tail|           
  
   Board can be created by 2D array.
   - First and Last row is filled with '#'.
   - First and Last col is filled with '#'.
   - Other elements is filled with ' '.   
  
   Snake's is located center at first.
   - Center position(ROW//2, COL//2) of array is filled with '@'.
  
   Snake's tail is located right side of the head.
   - Right side of center(ROW//2, COL//2 + 1) of array is filled with 'o'.
   
   Feed is randomly created in board.
   - Select random row, col by random library.
   - Feed is not created on wall, snake. Check board[row][col] == ' '.
   - If board[row][col] is not filled with ' ', re-select row, col until board[row][col] == ' '.
  
   Display Board
   - Make display_board function containg above utils.

User input
   ---
 |Key     |Action            | Game State                      |
 | :----- | :--------------- | :------------------------------ |
 |Up      |Snake moves up    |Change snake's direction to up   |
 |Down    |Snake moves down  |Change snake's direction to down |
 |left    |Snake moves left  |Change snake's direction to down |
 |Right   |Snake moves right |Change snake's direction to right|
 |p       |Pause the game    |Pause                            |
 |esc     |Exit the game     |Exit                             |

   Real time and Non blocking input
   - Use kbhit(), _getch() function
  
   Restriction
   - Can not move inverse direction (In up direction state, snake can't move down direction immediately)
    
Game logic
   ---
   Snake Move
   - Arrow key input updates direction (UP, DOWN, LEFT, RIGHT).
   - If no input, snake moves in the current direction.
   - Update snake's head position based on the current direction.
   - Snake's body and tail follow the head.
  
   Collision
   - If snake's head collides with wall(#), the game ends.
   - If snake's head collides with its body(o), the game ends.

   Grow
   - When snake eats feed(0), its length increases.
   - A new tail is added to the last tail.

   Speed Up
   - Game speed increases with each feed eaten.
   - Delay time decreases as score inceases, with a minimum threshold.

   Score
   - Each feed eaten adds 10 points to the score.
   - Final score is displayed at the end of the game.
