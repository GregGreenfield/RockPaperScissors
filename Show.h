//---------------------------------------------------------------------------
// Greg Greenfield's - show class - 10-07-2015
// This is a display form to show who won the game
//---------------------------------------------------------------------------
#ifndef ShowH
#define ShowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <pngimage.hpp>
#include "Draw.h"
#include "Start.h"
#include "Choice.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *ConButton;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Exit1;
	void __fastcall ConButtonClick(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
	char gameType;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void displayWon(int,char);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
