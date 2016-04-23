//---------------------------------------------------------------------------
// Greg Greenfield's - show class - 10-07-2015
// This is a display form to show who won the game
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Show.h"
#include "Draw.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm1::displayWon(int maybe, char gType)
{                              // display who won
	gameType = gType;
	if (gType == 'c')
	{
		if(maybe==2)
			Label1->Caption = "You're a Winner!";
		else if (maybe==1)
			Label1->Caption = "You Drew!";
		else
			Label1->Caption = "You're a Looser!";
	}
	else if (gType == 'p' || gType == 'a')
	{
		if (maybe == 2)
			Label1->Caption = "Player 1 is the winner!";
		else if (maybe == 1)
			Label1->Caption = "You both suck as you drew!";
		else
			Label1->Caption = "Player 2 is the winner!";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConButtonClick(TObject *Sender)
{                                   //on continue button press
	if (gameType == 'c' || gameType == 'p')
	{
		this->Hide();
		Form2->updateChoices();
		Form2->Show();
	}
	if (gameType == 'a')
	{
		this->Hide();
		Form5->Show();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

