//---------------------------------------------------------------------------

#ifndef WaitingH
#define WaitingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include "IdContext.hpp"
#include "IdCustomTCPServer.hpp"
#include "IdTCPClient.hpp"
#include "IdTCPConnection.hpp"
#include "IdTCPServer.hpp"
#include <ComCtrls.hpp>
#include "Draw.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *StartBut;
	TIdTCPClient *Client1;
	TIdTCPClient *Client2;
	TIdTCPServer *Server1;
	TIdTCPServer *Server2;
	TLabel *Label2;
	TLabel *Played;
	TButton *Exit;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Exit1;
	void __fastcall ServerExecute(TIdContext *AContext);
	void __fastcall StartButClick(TObject *Sender);
	void __fastcall ExitClick(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
	int playedNum;
	int playerNumber;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
