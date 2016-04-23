//---------------------------------------------------------------------------
// Greg Greenfield's - start class - 10-07-2015
// This display will be for user to select how many rounds to play
// it will also show the number of times the choices have been made
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Start.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
// When first loaded update the number of options that has been selected.
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	king = new IO();
	RockNum->Caption = king->getTotalChoice('r');
	PaperNum->Caption = king->getTotalChoice('p');
	ScissorNum->Caption = king->getTotalChoice('s');
	delete king;
}
//---------------------------------------------------------------------------
// function to update the selections from the IO file
void TForm2::updateChoices()
{
	king = new IO();
	RockNum->Caption = king->getTotalChoice('r');
	PaperNum->Caption = king->getTotalChoice('p');
	ScissorNum->Caption = king->getTotalChoice('s');
}

//---------------------------------------------------------------------------
void __fastcall TForm2::PlayButClick(TObject *Sender)
{
	Application->CreateForm(__classid(TForm3), &Form3);
	int numRounds = Rounds->Text.ToInt();
	Form3->createGame(numRounds,gType);
	Form2->Hide();
	Form3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BackButClick(TObject *Sender)
{
	Form5->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

