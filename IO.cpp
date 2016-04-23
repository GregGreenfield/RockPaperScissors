//---------------------------------------------------------------------------
// Greg Greenfield's - IO class - 10-07-2015
// Designed to create an Input/output file to help with the computer
// figure out what to select next
//---------------------------------------------------------------------------

#pragma hdrstop

#include "IO.h"
//---------------------------------------------------------------------------
IO::IO() //Check if there is a file if there is not create one.
{
	Score temp;

	if( !MyFile )
	{
		fstream MyFile( FILE_PATH, ios :: binary | ios :: out );

		MyFile.open( FILE_PATH, ios :: binary | ios :: out | ios :: app );
		MyFile.clear();

		for (int i = 0; i < 5; i++)
		{
			temp.total = 0;

			if( i == 0 )
				temp.type = 'r';
			else if (i == 1)
				temp.type = 'p';
			else if (i == 2)
				temp.type = 's';
			else if (i == 3 || i == 4)
			{
				temp.type = 'n';
				if ( i == 3 )
					temp.total = 1;
				else
					temp.total = 2;
			}

			MyFile.write( ( const char* ) &temp, sizeof( Score ) );
		}
	}
	MyFile.close();
}
//--------------------------------------------------------------------------
int IO::search( char choice )  //search the file for the selection
{
	Score temp;
	int counter = 0;

	MyFile.open( FILE_PATH, ios :: binary | ios :: in );
	MyFile.clear();
	MyFile.seekp( 0, ios :: beg );
	MyFile.read( ( char* ) &temp, sizeof( Score ) );

	while ( !MyFile.eof() )
	{
		if ( temp.type == choice )
		{
			MyFile.close();

			return counter;
		}
		counter++;

		MyFile.read( ( char* ) &temp, sizeof( Score ) );
	}
	MyFile.close();
	return - 1;
}
//---------------------------------------------------------------------------
void IO::addPlayerSelection(char choice) // add the players selection to the file
{
	Score temp;
	Score temp2;
	int position;

	position = search(choice);

	MyFile.open( FILE_PATH, ios :: binary | ios :: in | ios :: out );
	MyFile.clear();
	MyFile.seekp( position * sizeof( Score ), ios :: beg );
	MyFile.read( ( char* ) &temp, sizeof( Score ) );

	temp.total = temp.total + 1;

	MyFile.clear();
	MyFile.seekp( position * sizeof( Score ), ios :: beg );
	MyFile.write( ( const char* ) &temp, sizeof( Score ) );
	MyFile.seekp( 3 * sizeof( Score ), ios :: beg );
	MyFile.read( ( char* ) &temp2, sizeof( Score ) );
	MyFile.seekp( 3 * sizeof( Score ), ios :: beg );
	MyFile.write( ( const char* ) &temp, sizeof( Score ) );
	MyFile.write( ( const char* ) &temp2, sizeof( Score ) );
	MyFile.close();
}
//---------------------------------------------------------------------------
int IO::getTotalChoice(char choice) //get the total of a specific selection
{
	Score temp;
	int position;

	position = search(choice);

	MyFile.open( FILE_PATH, ios :: binary | ios :: in | ios :: out );
	MyFile.clear();
	MyFile.seekp( position * sizeof( Score ), ios :: beg );
	MyFile.read( ( char* ) &temp, sizeof( Score ) );
	MyFile.close();

	return temp.total;
}
//---------------------------------------------------------------------------
char IO::getLastChoice() // checks the last to choices and if they are the same
{                        // return what it could be
	Score temp;
	Score temp2;

	MyFile.open( FILE_PATH, ios :: binary | ios :: in | ios :: out );
	MyFile.clear();
	MyFile.seekp( 3 * sizeof( Score ), ios :: beg );
	MyFile.read( ( char* ) &temp, sizeof( Score ) );
	MyFile.read( ( char* ) &temp2, sizeof( Score ) );
	MyFile.close();

	if (temp.type == 'r' && temp2.type == 'r')
		return 'r';
	else if (temp.type == 'p' && temp2.type == 'p')
		return 'p';
	else if (temp.type == 's' && temp2.type == 's')
		return 's';
	else
		return 'n';
}
//--------------------------------------------------------------------------
char IO::getProb()   // return the probability choice
{
	char lastChoices;
	double r,p,s;
	double total = 0;

	lastChoices = getLastChoice();
	r = getTotalChoice('r');
	p = getTotalChoice('p');
	s = getTotalChoice('s');

	total = r+p+s;

	r = (r/total) * 100;
	p = (p/total) * 100;
	s = (s/total) * 100;


	if (total > 10 )       // if there is more then 10 choices
	{
		if( r >= 50 )      // if any are greater then 50% of the choices
			return 'r';
		else if ( p >= 50 )
			return 'p';
		else if ( s >= 50 )
			return 's';

		if( lastChoices == 'r' )    //if the last two choices are the same
			return 'r';
		else if (lastChoices == 'p')
			return 'p';
		else if (lastChoices == 's')
			return 's';

		return 'c';
	}
	else
		return 'c';
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
