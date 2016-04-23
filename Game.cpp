//---------------------------------------------------------------------------
// Greg Greenfield's - Game class - 10-07-2015
// Designed to create the game for a number of rounds
//
//---------------------------------------------------------------------------
#pragma hdrstop
#include "Game.h"
#include <iostream>

Game::Game()       //setup's
{
	array = new Round;
	gameType = 'c';
	curRound = 0;
	playerScore = 0;
	player2Score = 0;
	computerScore = 0;
}
Game::Game(int x, char c)   //setup's
{
	if (x == 0)
		x = 100;

		array = new Round[x];

	gameType = c;
	curRound = 0;
	playerScore = 0;
	player2Score = 0;
	computerScore = 0;
	if (x == 0)
		numRound = 100;
	else
		numRound = x;

	for (int i = 0; i < x; i++)
		array->setRoundNum(i,gameType);
}

void Game::winning()   //check who won and add score
{
	int score = array->fight();

	if (gameType == 'c')
	{
		if (array->fight() == 2)
			playerScore = playerScore+1;
		else if (array->fight() == 1 )
			computerScore = computerScore+1;
	}
	else
	{
		if (score == 2)
			playerScore = playerScore + 1;
		else if (score == 1)
			player2Score = player2Score + 1;
	}
}

void Game::incRound(){curRound=curRound + 1;}   // increment round

bool Game::testContinue()  //test to continue
{
	if (curRound < numRound)
		return true;
	else
	{
		won = testWon();
		return false;
	}
}

int Game::testWon()      //test who won
{
	if (gameType == 'c')
	{
		if (playerScore > computerScore)
			return 2;
		else if (playerScore == computerScore)
			return 1;
		else
			return 0;
	}
	else
	{
		if (playerScore > player2Score)
			return 2;
		else if (playerScore == player2Score)
			return 1;
		else
			return 0;
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
