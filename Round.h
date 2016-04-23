//---------------------------------------------------------------------------
// Greg Greenfield's - Round class - 10-07-2015
// This is a child of game to manipulate what occurs in a round
//
//---------------------------------------------------------------------------
#ifndef RoundH
#define RoundH

#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "Tool.h"
#include "IO.h"

class Round
{
	public:
		Round(){};
		~Round(){delete king; delete player; delete player2; delete computer;}
		void setRoundNum(int,char);
		int getRoundNum();
		void setSelection(char);
		void setP2Selection(char);
		char getPChoice(){ return player->getType();}
		char getP2Choice(){ return player2->getType();}
		void setComputer();
		char getCChoice(){return computer->getType();}
		int fight();

	private:
		IO *king;
		Tool *player;
		Tool *player2;
		Tool *computer;
		int roundNum;
		char gameType;

};
//---------------------------------------------------------------------------
#endif
