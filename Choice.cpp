//---------------------------------------------------------------------------
// Greg Greenfield's - Choice class - 10-07-2015
// Choice display showing other to choose against the computer
// against another player(hotseat) or the concept of tcp
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Choice.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//when the computer button has been pressed
//set the game type to 'c' and show start form(form2)
void __fastcall TForm5::ComputerButClick(TObject *Sender)
{
	Application->CreateForm(__classid(TForm2), &Form2);
	Form2->setType('c');
	Form2->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
//when the prerson button has been pressed
//check if the check box has been press if yess then go to link form(Form8)
// if it is not press then set 'p' to game type and go to Start form(Form2)
void __fastcall TForm5::PersonButClick(TObject *Sender)
{
	if ( LANBox->Checked )
	{
		Application->CreateForm(__classid(TForm8), &Form8);
		Form8->Show();
		this->Hide();
	}
	else if ( !LANBox->Checked )
	{
		Application->CreateForm(__classid(TForm2), &Form2);
		Form2->setType('p');
		Form2->Show();
		this->Hide();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

