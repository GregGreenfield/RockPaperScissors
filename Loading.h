//---------------------------------------------------------------------------
// Greg Greenfield's - Loading class - 10-07-2015
// This is a display form to show what was selected and who won the round
//---------------------------------------------------------------------------
#ifndef LoadingH
#define LoadingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <pngimage.hpp>
#include "Draw.h"
#include "Waiting.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *OtherPlayer;
	TLabel *resultLabel;
	TLabel *PlayerLabel;
	TLabel *SecPlayerLabel;
	TButton *ConButton;
	TButton *ExitButton;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Exit1;
	void __fastcall ConButtonClick(TObject *Sender);
	void __fastcall ExitButtonClick(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
	char gameType;
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
	void display(int, char, char, char);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
