//---------------------------------------------------------------------------
// Greg Greenfield's - Rock Paper Scissors game - 10-07-2015
// This Create a game of rock paper scissors that you can choose to play against
// the computer(working), hot seat player(Working), TCP(Trail stage);
//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include <tchar.h>

//---------------------------------------------------------------------------
USEFORM("Start.cpp", Form2);
USEFORM("Show.cpp", Form1);
USEFORM("Loading.cpp", Form4);
USEFORM("Draw.cpp", Form3);
USEFORM("Choice.cpp", Form5);
USEFORM("Between.cpp", Form6);
USEFORM("Waiting.cpp", Form7);
USEFORM("Link.cpp", Form8);
#pragma argsused
WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{

	Application->Initialize();
	Application->CreateForm(__classid(TForm5), &Form5);
	Application->Run();

	return 0;
}
//---------------------------------------------------------------------------
