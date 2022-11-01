#pragma once

#include"inputfilestream.h"
#include"outputfilestream.h"
#include "cstring.h"

using namespace std;

class ProgramMemory
{
private:
	unsigned char m_uc_InstructionMemory[100];


public:

	//contructor prototype
	ProgramMemory();	//default
	ProgramMemory(CString& s);	//parameterised
	ProgramMemory(char* s);	//parameterised


	//functions
	void load(CString& s);
	void load(char* s);
};
