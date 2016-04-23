#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>

#include <stdio.h>
USEFORM("Start.cpp", Form2);
USEFORM("Show.cpp", Form1);
USEFORM("Loading.cpp", Form4);
USEFORM("Draw.cpp", Form3);
USEFORM("Choice.cpp", Form5);
USEFORM("Between.cpp", Form6);
USEFORM("Waiting.cpp", Form7);
USEFORM("Link.cpp", Form8);

int _tmain(int argc, _TCHAR* argv[])
{
    Application->Initialize();
	Application->CreateForm(__classid(TForm5), &Form5);
	Application->Run();
	return 0;
}
