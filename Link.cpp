//---------------------------------------------------------------------------
// Greg Greenfield's - Link class - 10-07-2015
// This display is to link and setup the client and server
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Link.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::ContinueButClick(TObject *Sender)
{
	Application->CreateForm(__classid(TForm7), &Form7);

	try
	{
		if ( Host->Checked == true )
		{
			Form7->playerNumber = 1;
			Form7->Server1->Active = true;
			Form7->Client1->Host = IPAdd->Text;
			Form7->Server1->StartListening();
			Form7->Show();
			this->Hide();
		}
		else if ( Host->Checked == false )
		{
			Form7->playerNumber = 2;
			Form7->Server2->Active = true;
			Form7->Client2->Host = IPAdd->Text;
			Form7->Server2->StartListening();
			Form7->Show();
			this->Hide();
		}
	}
	catch(const Exception &e)
	{
    	ShowMessage("We were unable to reach the server! TRY AGAIN!");
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm8::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

