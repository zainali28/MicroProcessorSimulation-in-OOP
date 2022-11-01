#include "cassembler.h"


//constructors
CAssembler::CAssembler() : m_cs_type("")	//dafault
{

	for (int i = 0; i < 8; i++)
	{
		m_uc_machinecode[i] = 0;
	}
}

CAssembler::CAssembler(CString& type) : m_cs_type(type)	//parameterised
{

	for (int i = 0; i < 8; i++)
	{
		m_uc_machinecode[i] = 0;
	}
}

CAssembler::CAssembler(const char* type)	//parameterised
{
	CString type_(type);

	m_cs_type = type_;

	for (int i = 0; i < 8; i++)
	{
		m_uc_machinecode[i] = 0;
	}
}


//functions
unsigned char* CAssembler::AssyToMachineTranslation(const CString& instruction)
{



	if (instruction.m_c_data != NULL)
	{ 

		//if (left == "RA" && right.length() == 2)	//Testing all conditions of left and right string
		//{
		//	number = stoi(right);
		//	instrMem[instrno] = (0x08 + number);
		//}
		//if (left == "RA" && right == "RA+RB;")
		//{
		//	instrMem[instrno] = 0x00;
		//}
		//if (left == "RA" && right == "RA-RB;")
		//{
		//	instrMem[instrno] = 0x04;
		//}
		//if (left == "RB" && right.length() == 2)
		//{
		//	number = stoi(right);
		//	instrMem[instrno] = 0x18 + number;
		//}
		//if (left == "RB" && right == "RA-RB;")
		//{
		//	instrMem[instrno] = 0x14;
		//}

		//else
		//	;

	}
	else
		;


	return this->m_uc_machinecode;
}