//---------------------------------------------------------------------------
// Greg Greenfield's - start class - 10-07-2015
// This display will be for user to select how many rounds to play
// it will also show the number of times the choices have been made
//---------------------------------------------------------------------------
#ifndef StartH
#define StartH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <string.h>
#include "Draw.h"
#include "IO.h"
#include "Choice.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *RockLabel;
	TLabel *PaperLabel;
	TLabel *ScissorLable;
	TLabel *RockNum;
	TLabel *PaperNum;
	TLabel *ScissorNum;
	TLabel *Label5;
	TEdit *Rounds;
	TLabel *Label6;
	TButton *PlayBut;
	TButton *BackBut;
	TMainMenu *MainMenu1;
	TMenuItem *file1;
	TMenuItem *Exit1;
	void __fastcall PlayButClick(TObject *Sender);
	void __fastcall BackButClick(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
	IO *king;
	char gType;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	void updateChoices();
	void setType(char c){gType = c;};
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
