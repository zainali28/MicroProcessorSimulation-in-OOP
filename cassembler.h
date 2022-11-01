#pragma once
#include "cstring.h"
#include "inputfilestream.h"

using namespace std;

class CAssembler
{
private:
	CString m_cs_type;
	unsigned char m_uc_machinecode[8];

public:

	//constructor prototype
	CAssembler();	//default
	CAssembler(CString& type);	//parameterised
	CAssembler(const char* type);	//parameterised


	//functions
	unsigned char* AssyToMachineTranslation(const CString& instruction);	//Assembly to Machine instructions
};