//CString.cpp
#include "cstring.h"
#include <string>

//constructors
CString::CString() : m_c_data(NULL), m_i_length(0)
{ }

CString::CString(const char* data)
{
	this->m_i_length = strlen(data) + 1;

	this->m_c_data = new char[m_i_length];

	strcpy(m_c_data, data);
}

CString::CString(char data[])
{
	this->m_i_length = strlen(data);

	this->m_c_data = new char[m_i_length];

	strcpy(m_c_data, data);
}


//copy constructor
CString::CString(CString& s)
{
	m_i_length = s.m_i_length;
	m_c_data = new char[m_i_length];

	strcpy(m_c_data, s.m_c_data);
}


//destructor
CString::~CString()
{
	delete[] m_c_data;
}


//operator overloaders
CString& CString:: operator + (const CString& s)
{
	CString temp;

	temp.m_i_length = this->m_i_length;

	temp.m_c_data = new char[temp.m_i_length];

	strcpy(temp.m_c_data, this->m_c_data);

	delete[] this->m_c_data;

	this->m_i_length = this->m_i_length + s.m_i_length - 1;

	this->m_c_data = new char[this->m_i_length];

	strcpy(this->m_c_data, temp.m_c_data);

	strcat(m_c_data, s.m_c_data);

	return *this;
}

CString& CString:: operator = (const CString& s)
{
	delete[] this->m_c_data;

	this->m_i_length = s.m_i_length;

	this->m_c_data = new char[this->m_i_length];

	strcpy(this->m_c_data, s.m_c_data);

	return *this;
}

ostream& operator << (ostream& output, const CString& s)
{

	for (int i = 0; i < s.m_i_length; i++)
	{
		if (s.m_c_data != NULL)
		{
			s.m_c_data[sizeof(s.m_c_data) - 1] = '\0';
		}
	}

	output << s.m_c_data;

	return output;
}

istream& operator >> (istream& input, CString& s)
{
	input >> s.m_c_data;

	return input;

}

CString& CString:: operator += (const CString& s)
{
	CString temp;

	temp.m_i_length = this->m_i_length;

	temp.m_c_data = new char[temp.m_i_length];

	strcpy(temp.m_c_data, this->m_c_data);

	delete[] this->m_c_data;

	this->m_i_length = this->m_i_length + s.m_i_length - 1;

	this->m_c_data = new char[this->m_i_length];

	strcpy(this->m_c_data, temp.m_c_data);

	strcat(m_c_data, s.m_c_data);

	return *this;
}

CString& CString:: operator += (const char* data)
{
	CString s;

	s.m_i_length = strlen(data) + 1;
	s.m_c_data = new char[s.m_i_length];

	strcpy(s.m_c_data, data);

	CString temp;

	temp.m_i_length = this->m_i_length;

	temp.m_c_data = new char[temp.m_i_length];

	strcpy(temp.m_c_data, this->m_c_data);

	delete[] this->m_c_data;

	this->m_i_length = this->m_i_length + s.m_i_length - 1;

	this->m_c_data = new char[this->m_i_length];

	strcpy(this->m_c_data, temp.m_c_data);

	strcat(m_c_data, s.m_c_data);

	return *this;
}

CString& CString:: operator + (const char* data)
{
	CString s;

	s.m_i_length = strlen(data) + 1;
	s.m_c_data = new char[s.m_i_length];

	strcpy(s.m_c_data, data);

	CString temp;

	temp.m_i_length = this->m_i_length;

	temp.m_c_data = new char[temp.m_i_length];

	strcpy(temp.m_c_data, this->m_c_data);

	delete[] this->m_c_data;

	this->m_i_length = this->m_i_length + s.m_i_length - 1;

	this->m_c_data = new char[this->m_i_length];

	strcpy(this->m_c_data, temp.m_c_data);

	strcat(m_c_data, s.m_c_data);

	return *this;
}

char CString:: operator [] (int index)
{
	if (index >= this->m_i_length || index < 0)
	{
		cout << "INDEX OUT OF RANGE.";
	}

	else
	{
		return this->m_c_data[index];
	}

}


//functions
char* CString::get()
{
	return this->m_c_data;
}

int CString::find(const char* keyword)
{
	CString s(keyword);

	for (int i = 0; i < m_i_length; i++)
	{
		if (m_c_data[i] == s.m_c_data[0])
		{
			for (int j = 0; j < (s.m_i_length + i); j++)
			{
				while (m_c_data[j + i + 1] == s.m_c_data[j])
					return (i + 1);
			}
		}
	}
}

void CString::removespace()
{
	CString temp;

	int i = 0, j = 0;

	while (this->m_c_data[i])
	{
		if (this->m_c_data[i] != ' ')
		{
			this->m_c_data[j++] = this->m_c_data[i];
		}
		i++;
	}

	this->m_c_data[j] = '\0';

	temp.m_i_length = j + 1;

	temp.m_c_data = new char[temp.m_i_length];

	for (int k = 0; k <= j; k++)
	{
		temp.m_c_data[k] = this->m_c_data[k];
	}

	delete[] this->m_c_data;

	this->m_i_length = temp.m_i_length;

	this->m_c_data = new char[this->m_i_length];


	for (int l = 0; l <= j; l++)
	{
		this->m_c_data[l] = temp.m_c_data[l];
	}

}

CString CString:: leftstring(const char data)
{
	CString temp;

	temp.m_c_data = this->m_c_data;
	temp.m_i_length = this->m_i_length;

	temp.m_c_data = new char[temp.m_i_length];

	for (int i = 0; i < temp.m_i_length; i++)
	{
		if (this->m_c_data[i] == data)	//gets the part of the string before = operator
		{
			temp = this->substring(0, i);
			return temp;
		}
	}
}

CString CString::rightstring(const char data)
{
	CString temp;

	temp.m_c_data = this->m_c_data;
	temp.m_i_length = 2;

	temp.m_c_data = new char[temp.m_i_length];

	for (int i = 0; i < this->m_i_length; i++)
	{
		if (this->m_c_data[i] == data)	//gets the part of the string before = operator
		{
			temp = this->substring(i + 1, temp.m_i_length);
			return temp;
		}
	}
}

CString CString::substring(int index, int length)
{
	CString temp;

	
	while (length > m_i_length)
		length = m_i_length - index;

	temp.m_i_length = length;
	temp.m_c_data = new char[temp.m_i_length];

	for (int i = 0; i < length; i++)
	{
		temp.m_c_data[i] = this->m_c_data[i + index];
	}

	return temp;
}

void CString::set(char* data)
{
	this->m_c_data = data;
}

