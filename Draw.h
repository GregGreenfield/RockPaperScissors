//---------------------------------------------------------------------------
// Greg Greenfield's - Draw class - 10-07-2015
// This display what options what a player can choose
//---------------------------------------------------------------------------
#ifndef DrawH
#define DrawH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <pngimage.hpp>
#include "Show.h"
#include "Loading.h"
#include "Game.h"
#include "BetweenPlay.h"
#include "Waiting.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TButton *RockBut;
	TButton *PaperBut;
	TButton *ScissorBut;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TLabel *PlayerLabel;
	TLabel *SecPlayer;
	TLabel *Label3;
	TLabel *PlayerWon;
	TLabel *SecPlayerNum;
	TLabel *RoundLabel;
	TLabel *RoundNum;
	TLabel *Label8;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Exit1;
	TButton *Button1;
	void __fastcall RockButClick(TObject *Sender);
	void __fastcall PaperButClick(TObject *Sender);
	void __fastcall ScissorButClick(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
	int playerNum;
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	void nextPlayer();
	void createGame(int,char);
	Game *current;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
