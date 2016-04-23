//---------------------------------------------------------------------------
// Greg Greenfield's - IO class - 10-07-2015
// Designed to create an Input/output file to help with the computer
// figure out what to select next
//---------------------------------------------------------------------------

#ifndef IOH
#define IOH

#include <fstream>

// a structure to recored the information to a file
struct Score
{
	char type;
	int total;
};

const char FILE_PATH[] = "F:\\iofile.txt";         // hard coded to control the output
fstream MyFile( FILE_PATH, ios :: binary | ios :: in | ios :: out );

class IO
{

	public:
		IO();
		void addPlayerSelection(char);
		int search(char);
		int getTotalChoice(char);
		char getLastChoice();
		char getProb();     //returns the highest choice probability

};
//---------------------------------------------------------------------------
#endif
