//---------------------------------------------------------------------------
// Greg Greenfield's - between play class - 10-07-2015
// This is to allow for to switch between players
//---------------------------------------------------------------------------
#ifndef BetweenPlayH
#define BetweenPlayH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Draw.h"
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Player2But;
	void __fastcall Player2ButClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
