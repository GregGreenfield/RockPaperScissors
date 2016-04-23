//---------------------------------------------------------------------------
// Greg Greenfield's - Loading class - 10-07-2015
// This is a display form to show what was selected and who won the round
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Loading.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm4::display(int maybe, char playerC, char computerC, char gType)
{                 // this displays the choices made.
	gameType = gType;

	if (gameType == 'c')
	{
		OtherPlayer->Caption = "Computer: ";
		if(maybe==2)
			resultLabel->Caption = "You're Winner!";
		else if (maybe==1)
			resultLabel->Caption = "You're Looser!";
		else if (maybe == -1)
			resultLabel->Caption = "It's Draw!";
	}
	else if  (gameType == 'p' || gameType == 'a')
	{
		OtherPlayer->Caption = "Second Player: ";
		if(maybe==2)
			resultLabel->Caption = "Player one wins!";
		else if (maybe==1)
			resultLabel->Caption = "Player two wins!";
		else if (maybe == -1)
			resultLabel->Caption = "It's a draw!";
	}

	if (playerC == 'r')
		PlayerLabel->Caption = "Rock";
	else if (playerC == 'p')
		PlayerLabel->Caption = "Paper";
	else if (playerC == 's')
		PlayerLabel->Caption = "Scissor";

	if (computerC == 'r')
		SecPlayerLabel->Caption = "Rock";
	else if (computerC == 'p')
		SecPlayerLabel->Caption = "Paper";
	else if (computerC == 's')
		SecPlayerLabel->Caption = "Scissor";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ConButtonClick(TObject *Sender)
{                                     //on continue button press
	if (gameType == 'c' || gameType == 'p')
	{
		Form3->Show();
		this->Hide();
	}
	if (gameType == 'a')
	{
		Form7->Show();
		this->Hide();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ExitButtonClick(TObject *Sender)
{                                     //on exit button press
	this->Hide();
	Application->CreateForm(__classid(TForm1), &Form1);
	Form1->Show();
	Form1->displayWon(Form3->current->testWon(),gameType);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

