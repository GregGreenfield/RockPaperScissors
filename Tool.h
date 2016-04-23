//---------------------------------------------------------------------------
// Greg Greenfield's - Tool class - 10-07-2015
// This is a polymorphim tool class to set up the rock/paper/scissors
// and uses the tool class as a abstract class.
//---------------------------------------------------------------------------
#ifndef ToolH
#define ToolH

class Tool
{
	protected:
		char type;
	public:
		Tool(){};
		Tool(char c){ type = c; }
		virtual int fight(char)=0;
		char getType(){return type;}
};

class Rock : public Tool
{
	public:
		Rock(){};
		Rock(char c): Tool( c ){};
		int fight(char);
};

class Paper : public Tool
{
	public:
		Paper(){};
		Paper(char c): Tool( c ){};
		int fight(char);
};

class Scissor : public Tool
{
	public:
		Scissor(){};
		Scissor(char c): Tool( c ){};
		int fight(char);
};
//---------------------------------------------------------------------------
#endif
