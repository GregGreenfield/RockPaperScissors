//---------------------------------------------------------------------------
// Greg Greenfield's - Link class - 10-07-2015
// This display is to link and setup the client and server
//---------------------------------------------------------------------------
#ifndef LinkH
#define LinkH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Waiting.h"
#include "Draw.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TButton *ContinueBut;
	TLabel *Label1;
	TEdit *IPAdd;
	TCheckBox *Host;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Exit1;
	void __fastcall ContinueButClick(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
