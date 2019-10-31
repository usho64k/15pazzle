#ifndef BOARD_H
#define BOARD_H

typedef enum e_direct
{
	E_DIR_UP,
	E_DIR_LEFT,
	E_DIR_DOWN,
	E_DIR_RIGHT,
	E_DIR_MAX
}E_DIRECTION;

void initialize_board(void);
void setup_board(void);
int move_board(E_DIRECTION e);
void get_board(int *b);

#endif
