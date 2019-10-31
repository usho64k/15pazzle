#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "main.h"

#define MAX_CELLS	4
typedef struct t_pos
{
	int x;
	int y;
}T_POS;

static int board[MAX_CELLS][MAX_CELLS];
static T_POS myPos;


static int chk_duplicate(int inp);

void initialize_board(void)
{
	int i,j;
	for(i = 0; i < MAX_CELLS; i++)
	{
		for(j = 0; j < MAX_CELLS; j++)
		{
			board[i][j] = 0;
		}
	}
}

void setup_board(void)
{
	int i,j;
	for(i = 0; i < MAX_CELLS; i++)
	{
		for(j = 0; j < MAX_CELLS; j++)
		{
			//set to board[i][j]'s num.
			unsigned int inp;
			int f_duplicate = 1;
			if((i == (MAX_CELLS - 1)) && (j == (MAX_CELLS - 1)))
			{
				//Processes completed. last is constance, is 0.
				myPos.x = MAX_CELLS - 1;
				myPos.y = MAX_CELLS - 1;
				return;
			}
			//check next number.
			do{
				inp = getRandNext() % 16;
				f_duplicate = chk_duplicate(inp);
			}while(f_duplicate == 1);
			board[i][j] = inp;
		}
	}
}

static int chk_duplicate(int inp)
{
	int i,j;
	for(i = 0; i < MAX_CELLS; i++)
	{
		for(j = 0; j < MAX_CELLS; j++)
		{
			if(inp == board[i][j])
			{
				return 1;	//duplicate
			}
		}
	}
	return 0;	//no duplicate
}

int move_board(E_DIRECTION e)
{
	int x = myPos.x;
	int y = myPos.y;
	
	switch(e)
	{
	case E_DIR_UP:
		if(y != 0)
		{
			board[x][y] = board[x][y - 1];
			board[x][y - 1] = 0;
			myPos.y = y - 1;
			return 0;
		}
		break;
	case E_DIR_LEFT:
		if(x != 0)
		{
			board[x][y] = board[x - 1][y];
			board[x - 1][y] = 0;
			myPos.x = x - 1;
			return 0;
		}
		break;
	case E_DIR_DOWN:
		if(y != (MAX_CELLS - 1))
		{
			board[x][y] = board[x][y + 1];
			board[x][y + 1] = 0;
			myPos.y = y + 1;
			return 0;
		}
		break;
	case E_DIR_RIGHT:
		if(x != (MAX_CELLS - 1))
		{
			board[x][y] = board[x + 1][y];
			board[x + 1][y] = 0;
			myPos.x = x + 1;
			return 0;
		}
		break;
	default:
		return -1;
	}
	return -2;
}

void get_board(int *b)
{
	int i,j;
	for(i = 0; i < MAX_CELLS; i++)
	{
		for(j = 0; j < MAX_CELLS; j++)
		{
			*b++ = board[i][j];
		}
	}
}
