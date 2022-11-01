
#pragma once

#include <iostream>
#include "cstring.h"

using namespace std;

class InputFileStream
{
private:
	CString m_cs_instruction;	//path to file
	char m_c_buffer[128];	//buffer to temporarily store the data to reduce operation speed
	FILE* m_F_infile;

public:
	//friend classes
	friend class ProgramMemory;
	friend class CAssembler;

	//constructor prototype
	InputFileStream();	//default
	InputFileStream(const CString& input);	//parameterised
	InputFileStream(const char* data);	//parameterised
	

	//functions
	void open(const CString& input);	//opens the file
	void open(const char* data);	//opens the file
	void close();	//closes the stream
	void getline(CString& instruction);	//extracts strings line by line
	char* getInstrc(CString& instruction);
};

