//---------------------------------------------------------------------------
// Greg Greenfield's - Choice class - 10-07-2015
// Choice display showing other to choose against the computer
// against another player(hotseat) or the concept of tcp
//---------------------------------------------------------------------------
#ifndef ChoiceH
#define ChoiceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Start.h"
#include "Link.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TButton *PersonBut;
	TButton *ComputerBut;
	TCheckBox *LANBox;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Exit1;
	TLabel *Label;
	void __fastcall ComputerButClick(TObject *Sender);
	void __fastcall PersonButClick(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
