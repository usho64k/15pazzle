#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "board.h"

static const unsigned int randInt[] = {
	  60,  71, 118,  87,  21,  49,  94,  33,
	 149,  78,  22,  85,  42,  43,  54, 144,
	  88,  86,   4, 139,  80,  95,  84, 123,
	 155, 107,  35,  70,  87,  35, 157,  21,
	  28, 132,  39,  73, 111,  79,  32, 115,
	 140,  57,  94,   0, 155,   0};
static const unsigned int *pRnd = randInt;

static E_DIRECTION getDirection(void);

void main(void)
{
	initialize_board();
	setup_board();
	while(1)
	{
		int i,boardinf[16];
		
		move_board(getDirection());
		get_board(boardinf);
		
		printf(" x:00, 01, 02, 03, \n");
		printf("-------------------\n");
		for(i = 0; i < 16; i++)
		{
			if(i % 4 == 0)
			{
				printf("%02d:",i / 4);
			}
			printf("%02d, ",boardinf[i]);
			if(i % 4 == 3)
			{
				printf("\n");
			}
		}
		printf("\n");
	}
}

unsigned int getRandNext(void)
{
	unsigned int ret = *pRnd;
	if(pRnd < randInt + sizeof(randInt))
	{
		pRnd++;
	}
	else
	{
		pRnd = randInt;
	}
	return *pRnd;
}

static E_DIRECTION getDirection(void)
{
	unsigned int dir = getRandNext() % 4;
	switch(dir)
	{
	case 0:
		return E_DIR_UP;
	case 1:
		return E_DIR_LEFT;
	case 2:
		return E_DIR_DOWN;
	case 3:
		return E_DIR_RIGHT;
	}
}
