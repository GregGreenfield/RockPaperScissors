//---------------------------------------------------------------------------
// Greg Greenfield's - Round class - 10-07-2015
// This is a child of game to manipulate what occurs in a round
//
//---------------------------------------------------------------------------
#pragma hdrstop

#include "Round.h"

void Round::setRoundNum(int num, char g) //set round number and type
{ roundNum = num; gameType = g; }

int Round::getRoundNum(){ return roundNum; }

void Round::setSelection(char c) //set player selection
{
	king = new IO();

	if (c == 'r')
	{
		player = new Rock(c);
		king->addPlayerSelection('r');
	}
	else if (c == 'p')
	{
		player = new Paper(c);
		king->addPlayerSelection('p');
	}
	else if (c == 's')
	{
		player = new Scissor(c);
		king->addPlayerSelection('s');
	}
	delete king;
}

void Round::setP2Selection(char c)  //set player 2 selection
{
	if (c == 'r')
		player2 = new Rock(c);
	else if (c == 'p')
		player2 = new Paper(c);
	else if (c == 's')
		player2 = new Scissor(c);
}

void Round::setComputer()         //set the computers choice
{
	king = new IO();

	char compChoice = king->getProb();   //get prob

	if (compChoice == 'c')
	{
		int random;
		srand (time(NULL));

		random = rand() % 90 + 1;

		if(random >= 60)
			computer = new Rock('r');
		else if (random <= 59 && random >=30)
			computer = new Scissor('s');
		else if (random >= 1)
			computer = new Paper('p');
	}
	else
	{
		if(compChoice == 'r')
			computer = new Rock('p');
		else if (compChoice == 's')
			computer = new Scissor('r');
		else if (compChoice == 'p')
			computer = new Paper('s');
   }
	delete king;
}

int Round::fight() //get result
{
	if (gameType == 'c')
		return player->fight(computer->getType());
	else
		return player->fight(player2->getType());
}
//--------------------------------------------------------------------------
#pragma package(smart_init)
