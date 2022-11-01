

#include "inputfilestream.h"

using namespace std;


//constructor defintion
InputFileStream::InputFileStream()
{
	m_cs_instruction = "";

	for (int i = 0; i < sizeof(this->m_c_buffer); i++)
	{
		m_c_buffer[i] = { NULL };
	}

	m_F_infile = NULL;
}

InputFileStream::InputFileStream(const CString& input)	//parameterised
{

	for (int i = 0; i < 100; i++)
	{
		m_c_buffer[i] = { NULL };
	}


	CString const mode("r+");

	this->m_F_infile = fopen(input.m_c_data, mode.m_c_data);

	if (this->m_F_infile == NULL)
	{
		cout << "NO FILE FOUND OF THIS NAME.";
	}

	else
	{
		while (!feof(this->m_F_infile))
		{
			fread(this->m_c_buffer, sizeof(this->m_c_buffer), 1, this->m_F_infile);
			cout << this->m_c_buffer;
		}
	}
}

InputFileStream::InputFileStream(const char* data)	//parameterised
{
	CString input(data);

	for (int i = 0; i < 100; i++)
	{
		m_c_buffer[i] = { NULL };
	}


	CString const mode("r+");

	this->m_F_infile = fopen(input.m_c_data, mode.m_c_data);

	if (this->m_F_infile == NULL)
	{
		cout << "NO FILE FOUND OF THIS NAME.";
	}

	else
	{
		while (!feof(this->m_F_infile))
		{
			fread(this->m_c_buffer, sizeof(this->m_c_buffer), 1, this->m_F_infile);
			cout << this->m_c_buffer;
		}
	}
}



//functions
void InputFileStream::open(const CString& input)
{

	for (int i = 0; i < 100; i++)
	{
		m_c_buffer[i] = { NULL };
	}


	CString const mode("r+");

	this->m_F_infile = fopen(input.m_c_data, mode.m_c_data);

	if (this->m_F_infile == NULL)
	{
		cout << "NO FILE FOUND OF THIS NAME.";
	}

	else
		;

}

void InputFileStream::open(const char* data)
{
	CString input(data);

	for (int i = 0; i < 100; i++)
	{
		m_c_buffer[i] = { NULL };
	}


	CString const mode("r+");

	this->m_F_infile = fopen(input.m_c_data, mode.m_c_data);

	if (this->m_F_infile == NULL)
	{
		cout << "NO FILE FOUND OF THIS NAME.";
	}

	else
		;

}

void InputFileStream::close()
{
	fclose(this->m_F_infile);
}

void InputFileStream:: getline(CString& instruction)
{
	instruction.m_i_length = sizeof(this->m_c_buffer);

	instruction.m_c_data = new char[instruction.m_i_length];

	while (fgets(instruction.m_c_data, sizeof(instruction.m_c_data), this->m_F_infile) != NULL)
	{
		instruction.m_c_data[sizeof(instruction.m_c_data) - 1] = '\0'; // eat the newline fgets() stores
	}


	//InputFileStream in;

	//destination.m_i_length = 128;
	//destination.m_c_data = new char[destination.m_i_length];

	//while (!feof(this->m_F_infile))
	//{
	//	fread(in.m_c_buffer, sizeof(this->m_c_buffer), 1, this->m_F_infile);

	//	for (int i = 0; i < sizeof(this->m_c_buffer); i++)
	//	{
	//		destination.m_c_data[i] = this->m_c_buffer[i];
	//	}
	//}
}

char* InputFileStream::getInstrc(CString& instruction)
{
	char* ch = NULL;

	return ch;
}