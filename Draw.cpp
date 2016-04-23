//---------------------------------------------------------------------------
// Greg Greenfield's - Draw class - 10-07-2015
// This display what options what a player can choose
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Draw.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	current = new Game();
}
//---------------------------------------------------------------------------
//This function is to create the game.
void TForm3::createGame(int x, char c)
{
	current = new Game(x,c); //set's up the game/rounds
	PlayerWon->Caption = current->getPScore(); //places players one score on form
	SecPlayerNum->Caption = current->getCScore(); //places other players score
	RoundNum->Caption = current->getCurRound() + 1; //places round number

	if (c == 'c')
		SecPlayer->Caption = "Computer: ";   //set caption to computer
	else if (c == 'p')
	{
		SecPlayer->Caption = "Second player: "; //setup hot seat
		playerNum = 1;
		nextPlayer();
	}
	else if (c == 'a')                         //tcp
	{
		SecPlayer->Caption = "Second player: ";
		playerNum = Form7->playerNumber;
	}
}
//---------------------------------------------------------------------------
//to change to the next player for the hotseat
void TForm3::nextPlayer()
{
	if (playerNum == 1)
		Label3->Caption = "Player one's choice!";
	else if (playerNum == 2)
		Label3->Caption = "player two's choice!";
}
//---------------------------------------------------------------------------
//what happens on a rock selection
void __fastcall TForm3::RockButClick(TObject *Sender)
{

	Button1->SetFocus();
	if ( current->getGameType() == 'c' )        //on computer opp
	{
		current->array->setSelection('r');      //set selection
		current->array->setComputer();          //set computer
		current->winning();                     // check who won
		current->incRound();                    //Increment round
		PlayerWon->Caption = current->getPScore();  //update captions
		SecPlayerNum->Caption = current->getCScore();
		RoundNum->Caption = current->getCurRound() + 1;

		if (current->testContinue())    //test to continue
		{
			this->Hide();
			Application->CreateForm(__classid(TForm4), &Form4);
			Form4->Show();                              //update the display
			Form4->display( current->array->fight(), current->array->getPChoice(), current->array->getCChoice(), current->getGameType());
		}
		else
		{
			this->Hide();
			Application->CreateForm(__classid(TForm1), &Form1);
			Form1->Show();                         //update the display
			Form1->displayWon(current->testWon(),current->getGameType());
		}
	}
	else if (current->getGameType() == 'p')    //on hotseat
	{
		if (playerNum == 1)                   //on player1
		{
			current->array->setSelection('r');     //set player selection

			if (playerNum == 1)               //change  to player 2
				playerNum = 2;
			else if (playerNum == 2)
				playerNum = 1;

			nextPlayer();

			this->Hide();
			Application->CreateForm(__classid(TForm6), &Form6);
			Form6->Show();
		}
		else if (playerNum == 2)          //on player 2
		{
			current->array->setP2Selection('r');    //set player2 and update
			current->incRound();
			current->winning();
			PlayerWon->Caption = current->getPScore();
			SecPlayerNum->Caption = current->getP2Score();
			RoundNum->Caption = current->getCurRound() + 1;

			nextPlayer();
			if (playerNum == 1)
				playerNum = 2;
			else if (playerNum == 2)
				playerNum = 1;

			if (current->testContinue())      // test to continue and display
			{
				this->Hide();
				Application->CreateForm(__classid(TForm4), &Form4);
				Form4->Show();
				Form4->display( current->array->fight(), current->array->getPChoice(), current->array->getP2Choice(), current->getGameType());

			}
			else                            //or show who won
			{
				this->Hide();
				Application->CreateForm(__classid(TForm1), &Form1);
				Form1->Show();
				Form1->displayWon(current->testWon(),current->getGameType());
			}
		}
	}
	else if (current->getGameType() == 'a')    //on tcp
	{
		if (Form7->playerNumber == 1)
		{
			try
			{
				current->array->setSelection('r');     //set selection
				Form7->StartBut->Caption = "Check";

				Form7->Client1->Connect();
				Form7->Client1->Socket->Write("r");       //send to server
				Form7->Client1->Disconnect();

            	Form7->playedNum = Form7->playedNum + 1;
				Form7->Played->Caption = Form7->playedNum;
			}
			catch( const Exception &e )
			{
				ShowMessage("We were unable to connect to the server!");
			}

			Form7->Show();
			this->Hide();
		}
		else if (Form7->playerNumber == 2)
		{
            try
			{
				current->array->setSelection('r');          //set selection
				Form7->StartBut->Caption = "Check";

				Form7->Client2->Connect();
				Form7->Client2->Socket->Write("r");        //send to server
				Form7->Client2->Disconnect();

            	Form7->playedNum = Form7->playedNum + 1;
				Form7->Played->Caption = Form7->playedNum;
			}
			catch( const Exception &e )
			{
				ShowMessage("We were unable to connect to the server!");
			}

			Form7->Show();
			this->Hide();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::PaperButClick(TObject *Sender)
{             // for comments on paper see rock as they do the same thing
	Button1->SetFocus();
	if ( current->getGameType() == 'c' )
	{
		current->array->setSelection('p');
		current->array->setComputer();
		current->winning();
		current->incRound();
		PlayerWon->Caption = current->getPScore();
		SecPlayerNum->Caption = current->getCScore();
		RoundNum->Caption = current->getCurRound() + 1;

		if (current->testContinue())
		{
			this->Hide();
			Application->CreateForm(__classid(TForm4), &Form4);
			Form4->Show();
			Form4->display(current->array->fight(), current->array->getPChoice(), current->array->getCChoice(), current->getGameType());
		}
		else
		{
			this->Hide();
			Application->CreateForm(__classid(TForm1), &Form1);
			Form1->Show();
			Form1->displayWon(current->testWon(),current->getGameType());
		}
	}
	else if (current->getGameType() == 'p')
	{
		if (playerNum == 1)
		{
			current->array->setSelection('p');

			if (playerNum == 1)
				playerNum = 2;
			else if (playerNum == 2)
				playerNum = 1;

			nextPlayer();

			this->Hide();
			Application->CreateForm(__classid(TForm6), &Form6);
			Form6->Show();
		}
		else if (playerNum == 2)
		{
			current->array->setP2Selection('p');
			current->incRound();
			current->winning();
			PlayerWon->Caption = current->getPScore();
			SecPlayerNum->Caption = current->getP2Score();
			RoundNum->Caption = current->getCurRound() + 1;

			nextPlayer();
			if (playerNum == 1)
				playerNum = 2;
			else if (playerNum == 2)
				playerNum = 1;

			if (current->testContinue())
			{
				this->Hide();
				Application->CreateForm(__classid(TForm4), &Form4);
				Form4->display(current->array->fight(), current->array->getPChoice(), current->array->getP2Choice(), current->getGameType());
				Form4->Show();
			}
			else
			{
				this->Hide();
				Application->CreateForm(__classid(TForm1), &Form1);
				Form1->Show();
				Form1->displayWon(current->testWon(),current->getGameType());
			}
		}

	}
	else if (current->getGameType() == 'a')
	{
		if (Form7->playerNumber == 1)
		{
			try
			{
				current->array->setSelection('p');
				Form7->StartBut->Caption = "Check";

				Form7->Client1->Connect();
				Form7->Client1->Socket->Write("p");
				Form7->Client1->Disconnect();

            	Form7->playedNum = Form7->playedNum + 1;
				Form7->Played->Caption = Form7->playedNum;
			}
			catch( const Exception &e )
			{
				ShowMessage("We were unable to connect to the server!");
			}

			Form7->Show();
			this->Hide();
		}
		else if (Form7->playerNumber == 2)
		{
            try
			{
				current->array->setSelection('p');
				Form7->StartBut->Caption = "Check";

				Form7->Client2->Connect();
				Form7->Client2->Socket->Write("p");
				Form7->Client2->Disconnect();

            	Form7->playedNum = Form7->playedNum + 1;
				Form7->Played->Caption = Form7->playedNum;
			}
			catch( const Exception &e )
			{
				ShowMessage("We were unable to connect to the server!");
			}

			Form7->Show();
			this->Hide();
		}

	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ScissorButClick(TObject *Sender)
{         // for comments on paper see rock as they do the same thing
	Button1->SetFocus();
	if ( current->getGameType() == 'c' )
	{
		current->array->setSelection('s');
		current->array->setComputer();
		current->winning();
		current->incRound();
		PlayerWon->Caption = current->getPScore();
		SecPlayerNum->Caption = current->getCScore();
		RoundNum->Caption = current->getCurRound() + 1;

		if (current->testContinue())
		{
			this->Hide();
			Application->CreateForm(__classid(TForm4), &Form4);
			Form4->display(current->array->fight(), current->array->getPChoice(), current->array->getCChoice(), current->getGameType());
			Form4->Show();
		}
		else
		{
			this->Hide();
			Application->CreateForm(__classid(TForm1), &Form1);
			Form1->Show();
			Form1->displayWon(current->testWon(),current->getGameType());
		}
	}
	else if (current->getGameType() == 'p')
	{
		if (playerNum == 1)
		{
			current->array->setSelection('s');

			if (playerNum == 1)
				playerNum = 2;
			else if (playerNum == 2)
				playerNum = 1;

			nextPlayer();

			this->Hide();
			Application->CreateForm(__classid(TForm6), &Form6);
			Form6->Show();
		}
		else if (playerNum == 2)
		{
			current->array->setP2Selection('s');
			current->incRound();
			current->winning();
			PlayerWon->Caption = current->getPScore();
			SecPlayerNum->Caption = current->getP2Score();
			RoundNum->Caption = current->getCurRound() + 1;

			nextPlayer();
			if (playerNum == 1)
				playerNum = 2;
			else if (playerNum == 2)
				playerNum = 1;

			if (current->testContinue())
			{
				this->Hide();
				Application->CreateForm(__classid(TForm4), &Form4);
				Form4->display(current->array->fight(), current->array->getPChoice(), current->array->getP2Choice(), current->getGameType());
				Form4->Show();
			}
			else
			{
				this->Hide();
				Application->CreateForm(__classid(TForm1), &Form1);
				Form1->Show();
				Form1->displayWon(current->testWon(),current->getGameType());
			}
		}

	}
	else if (current->getGameType() == 'a')
	{
		if (Form7->playerNumber == 1)
		{
			try
			{
				current->array->setSelection('s');
				Form7->StartBut->Caption = "Check";

				Form7->Client1->Connect();
				Form7->Client1->Socket->Write("s");
				Form7->Client1->Disconnect();

            	Form7->playedNum = Form7->playedNum + 1;
				Form7->Played->Caption = Form7->playedNum;
			}
			catch( const Exception &e )
			{
				ShowMessage("We were unable to connect to the server!");
			}

			Form7->Show();
			this->Hide();
		}
		else if (Form7->playerNumber == 2)
		{
            try
			{
				current->array->setSelection('s');
				Form7->StartBut->Caption = "Check";

				Form7->Client2->Connect();
				Form7->Client2->Socket->Write("s");
				Form7->Client2->Disconnect();

            	Form7->playedNum = Form7->playedNum + 1;
				Form7->Played->Caption = Form7->playedNum;
			}
			catch( const Exception &e )
			{
				ShowMessage("We were unable to connect to the server!");
			}

			Form7->Show();
			this->Hide();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

