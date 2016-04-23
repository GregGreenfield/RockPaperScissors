//---------------------------------------------------------------------------
// Greg Greenfield's - Waiting class - 10-07-2015
// This display is to allow for connections between clients and servers.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Waiting.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdContext"
#pragma link "IdCustomTCPServer"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma link "IdTCPServer"
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
	Application->CreateForm(__classid(TForm3), &Form3);    //create game
	Form3->createGame(0,'a');
	playedNum = 0;
	Played->Caption = playedNum;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::ServerExecute(TIdContext *AContext)
{                         //what to do when server executes
	UnicodeString selection = AContext->Connection->Socket->ReadString(1);
	AContext->Connection->Disconnect();

	try
	{
		Form3->current->array->setP2Selection(selection[1]);
		playedNum = playedNum + 1;
		Played->Caption = playedNum;
	}
	catch(const Exception &e)
	{
		ShowMessage("Error executing the server!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm7::StartButClick(TObject *Sender)
{                        // On the start/check button press

	if(StartBut->Caption == "Check")
	{

		if( playedNum >= 2)
		{
			playedNum = 0;              // updates details for the next round
			Played->Caption = playedNum;
			Form7->StartBut->Caption = "Next Round";
			Form3->current->incRound();
			Form3->current->winning();
			Form3->PlayerWon->Caption = Form3->current->getPScore();
			Form3->SecPlayerNum->Caption = Form3->current->getP2Score();
			Form3->RoundNum->Caption = Form3->current->getCurRound() + 1;

			if (Form3->current->testContinue())
			{
				this->Hide();
				Application->CreateForm(__classid(TForm4), &Form4);
				Form4->Show();                   //does the fight and display
				Form4->display(Form3->current->array->fight(), Form3->current->array->getPChoice(),
				Form3->current->array->getP2Choice(), Form3->current->getGameType());
			}
			else
			{
				this->Hide();                   //what to do when the max
				if(playerNumber == 1)           //round has been hit
				{
					Server1->StopListening();
					Server1->Active = false;
				}
				if(playerNumber == 2)
				{
					Server2->StopListening();
					Server2->Active = false;
				}
				Application->CreateForm(__classid(TForm1), &Form1);
				Form1->Show();                     //display who won
				Form1->displayWon(Form3->current->testWon(),Form3->current->getGameType());
			}
		}
	}
	else
		Form3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm7::ExitClick(TObject *Sender)
{
	this->Hide();                   //Stop the servers
	if(playerNumber == 1)
	{
		Server1->StopListening();
		Server1->Active = false;
	}
	if(playerNumber == 2)
	{
		Server2->StopListening();
		Server2->Active = false;
	}

	if(Form3->current->getCurRound() == 0)
	{
		this->Hide();
		Form5->Show();
	}
	else
	{
		this->Hide();                 // show who won if needed
		Application->CreateForm(__classid(TForm1), &Form1);
		Form1->Show();
		Form1->displayWon(Form3->current->testWon(),Form3->current->getGameType());
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

