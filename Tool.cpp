//---------------------------------------------------------------------------
// Greg Greenfield's - Tool class - 10-07-2015
// This is a polymorphim tool class to set up the rock/paper/scissors
// and uses the tool class as a abstract class.
//---------------------------------------------------------------------------
#pragma hdrstop

#include "Tool.h"

int Rock::fight( char c )
{
	if (c == 's')
		return 2;
	else if (c == 'p')
		return 1;
	else
		return -1;
}
int Paper::fight( char c )
{
	if (c == 'r')
		return 2;
	else if (c == 's')
		return 1;
	else
		return -1;
}
int Scissor::fight( char c )
{
	if (c == 'p')
		return 2;
	else if (c == 'r')
		return 1;
	else
		return -1;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
