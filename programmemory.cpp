#include "programmemory.h"

using namespace std;


//contructor
ProgramMemory:: ProgramMemory()	//default
{
	for (int i = 0; i < 100; i++)
	{
		m_uc_InstructionMemory[i] = 0;
	}
}

ProgramMemory:: ProgramMemory(CString& s)	//parameterised
{
	for (int i = 0; i < 100; i++)
	{
		m_uc_InstructionMemory[i] = 0;
	}
}

ProgramMemory::ProgramMemory(char* s)	//parameterised
{
	for (int i = 0; i < 100; i++)
	{
		m_uc_InstructionMemory[i] = 0;
	}
}


//functions
void ProgramMemory::load(CString& s)
{
	int instrno = 0;

	InputFileStream in;

	in.open(s);

	while (!feof(in.m_F_infile))
	{
		fread(in.m_c_buffer, sizeof(in.m_c_buffer), 1, in.m_F_infile);
		instrno++;
	}

	for (int i = 0; i < instrno; i++)
	{
		this->m_uc_InstructionMemory[i] = in.m_c_buffer[i];
		 
	}


}

void ProgramMemory::load(char* s)
{

}