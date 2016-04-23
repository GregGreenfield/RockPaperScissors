//---------------------------------------------------------------------------
// Greg Greenfield's - Game class - 10-07-2015
// Designed to create the game for a number of rounds
//
//---------------------------------------------------------------------------
#ifndef GameH
#define GameH

#include <iostream>
#include "Round.h"

class Game : public Round
{
	public:
		Game();
		Game(int,char);
		~Game(){ delete array;}
		void winning();
		void incRound();
		int getPScore(){return playerScore;}
		int getP2Score(){return player2Score;}
		int getCScore(){return computerScore;}
		int getCurRound(){return curRound;}
		char getGameType(){return gameType;}
		bool testContinue();
		int testWon();
		bool getWon(){return won;}
		Round *array;
	private:
		int curRound, playerScore, player2Score, computerScore, numRound, won;
		char gameType;
};
//---------------------------------------------------------------------------
#endif
