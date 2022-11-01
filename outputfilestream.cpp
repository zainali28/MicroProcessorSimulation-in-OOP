#include "outputfilestream.h"

using namespace std;

OutputFileStream::OutputFileStream() : m_cs_instruction(""), m_F_outfile(NULL)
{
	for (int i = 0; i < sizeof(this->m_c_buffer); i++)
	{
		m_c_buffer[i] = 0;
	}
}

OutputFileStream::OutputFileStream(const CString& output)
{
	for (int i = 0; i < sizeof(this->m_c_buffer); i++)
	{
		m_c_buffer[i] = 0;
	}

	CString const mode("w");

	this->m_F_outfile = fopen(output.m_c_data, mode.m_c_data);
}

OutputFileStream::OutputFileStream(const char* data)	//parameterised
{
	CString output(data);

	for (int i = 0; i < sizeof(this->m_c_buffer); i++)
	{
		m_c_buffer[i] = 0;
	}

	CString const mode("w");

	this->m_F_outfile = fopen(output.m_c_data, mode.m_c_data);
}


//functions
void OutputFileStream::open(CString& output)
{

	for (int i = 0; i < 100; i++)
	{
		m_c_buffer[i] = { NULL };
	}


	CString const mode("w");

	this->m_F_outfile = fopen(output.m_c_data, mode.m_c_data);

}

void OutputFileStream::close()
{
	fclose(this->m_F_outfile);
}




//operator overloaders
void OutputFileStream::operator << (const CString& data)
{
	fprintf(this->m_F_outfile, "%s", data.m_c_data);
}

void OutputFileStream::operator << (const int data)
{
	fwrite(this->m_c_buffer, sizeof(this->m_c_buffer), 1, this->m_F_outfile);
}