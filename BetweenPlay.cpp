//---------------------------------------------------------------------------
// Greg Greenfield's - between play class - 10-07-2015
// This is to allow for to switch between players
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BetweenPlay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Player2ButClick(TObject *Sender)
{
	this->Hide();
	Form3->Show();
}
//---------------------------------------------------------------------------


