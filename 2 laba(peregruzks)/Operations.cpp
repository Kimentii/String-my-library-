#include "String.h"
#include <cstring>
#pragma warning (disable: 4996)
String::String(const String& s)							//����������� �����������.
{
	if (s.m_cSize > 0)
	{
		this->m_cStr = new char[s.m_cSize + 1];			//��������� ������ ��� ������.
		this->m_cSize = s.m_cSize;						//���������� ������� ������.
		strcpy(this->m_cStr, s.m_cStr);					//���������� ������.
		//cout << "\nCopy constuctor\n";
	}
}
String::String(const char* s)							//���������� �� ������.
{
	this->m_cSize = strlen(s)+1;						//���������� ������� ������.
	this->m_cStr = new char[this->m_cSize];				//��������� ������ ��� ������.
	strcpy(this->m_cStr, s);							//���������� ������.
	//cout << "constructor\n";
}
String::~String()										//����������
{
	if (m_cStr)											//���� ���� ��� �������.
	{
		delete[] m_cStr;								//������� ������.
		m_cStr = nullptr;								//��������� ���������.
	}
	//cout << "\nDestuctor\n";
}
String String::operator = (const String& s)				//���������� ��������� = �� �������.
{
	if (this != &s)										//���� ������� �� ����� �������������� ��������.
	{
		delete[] this->m_cStr;							//������� ������.
		this->m_cSize = s.m_cSize;						//������������ ������� ������.
		this->m_cStr = new char[this->m_cSize];
		strcpy(this->m_cStr, s.m_cStr);
	}
	return *this;
}
String String::operator = (const char* str)				//���������� ��������� = � �������.
{
	delete[] this->m_cStr;								//�������� ����������� ������.
	this->m_cSize = strlen(str)+1;						//������������ ������� ������.
	this->m_cStr = new char[this->m_cSize];				//��������� ������.
	strcpy(this->m_cStr, str);							//���������� �����.
	return *this;
}
char& String::operator [] (int i)						//���������� ��������� [].
{
	if ((i >= 0) && (i < m_cSize))						//���� ������ ���������� �����.
		return m_cStr[i];								//���������� ������ �� ������� � ���� �������.
	else
		return m_cStr[0];								//����� ���������� ������ �� 1 �������.
}
char* String::operator () (int a, int b)				//���������� ��������� ��������� ���������.
{
	if ((a >= 0) && (a < (m_cSize-1)) && (b >= 0) && (b < (m_cSize-1))&&(a<b))	//���� ������� ������ ��������. 
	{
		char*nS = new char [b - a + 2];					//��������� ������ �� ���������.
		int i, j = 0;
		for (i = a; i <= b; i++, j++)
		{
			nS[j] = m_cStr[i];							//������ ���������.
		}
		nS[i] = '\0';
		return nS;										//����������� ����� ������.
	}
	else
	{
		return "";										//����� ����������� ������� ������.
	}
}
String String::operator + (const String& s)				//���������� ��������� + � ��������.
{
	String nS((*this) + s.m_cStr);						//�������� � ����������� ����������� ����� ������� � �����.
	return nS;											//���������� ��������� ������.
}
String String::operator + (const char * s)				//���������� ��������� + � �������.
{
	char* bufS = new char[m_cSize + strlen(s)];			//�������� ����� ������.
	strcpy(bufS, m_cStr);								//���������� ������ ������.
	strcat(bufS, s);									//���������� ������� ������.
	String S(bufS);
	delete[] bufS;
	return S;											//����������� ������� � ������ �����.
}
String String::operator + (const char c)				//���������� ��������� + � ��������.
{
	char* bufS = new char[m_cSize +1];					//��������� ������ �� ����� ������.
	strcpy(bufS, m_cStr);								//���������� ������ �������.
	int i = strlen(m_cStr);
	bufS[i++] = c;										//���������� ������� � ����� ������.
	bufS[i] = '\0';										//����������� ����� ������.
	String nS(bufS);
	delete[] bufS;
	return nS;											//������� ������� � ��������� �������.
}
String String::operator += (const String& s)			//���������� ��������� += � ��������.
{
	return (*this) = (*this) + s;						//����� ���������� + ������� � ��������.
}
String String::operator += (const char * s)				//���������� ��������� += � �������.
{
	return (*this) = (*this) + s;						//����� ���������� + ������� � �������.
}
String String::operator += (const char c)				//���������� ��������� += � ��������.
{
	return (*this) = (*this) + c;						//����� ���������� + ������� � �������.
}
String String::operator ++ () 							//���������� ����������� ����������.
{
	for (int i = 0; m_cStr[i]; i++)						//���������� �������� �� 1 �� ���� ������� ������.
		this->m_cStr[i]++;
	return *this;
}
String String::operator ++ (int) 						//���������� ������������ ����������.
{
	return ++(*this);									//����� ����������� ����������.
}
String String::operator -- ()							//���������� ����������� ����������.
{
	for (int i = 0; m_cStr[i]; i++)						//���������� �������� ������� ������� �� 1.
		this->m_cStr[i]--;
	return *this;
}
String String::operator -- (int)						//���������� ������������ ����������.
{
	return --(*this);									//����� ���������� ����������� ����������.
}
String String::operator - (char c)						//���������� ��������� - � ��������
{
	char* p = nullptr;
	String nS(m_cStr);									//�������� ��������� �������.
	while (1)
	{
		p=strchr(nS.m_cStr, c);							//����� ������� � ������.
		if (!p)break;									//���� ������ �� ������, ����������� �����.
		for (int i = 0; p[i]; i++)						//���� ������, �� �������� ���.
		{
			p[i] = p[i + 1];
		}
		nS.m_cSize--;									//���������� ������� ������ �� 1.
		if (nS.m_cSize <= 1)break;						//���� ������ �����, �� �����  �� �����.
	}
	return nS;											//����������� ��������� �������.
}
String String::operator - (const char* s)				//���������� ��������� - � �������.
{
	String nS(*this);
	for (int i = 0; s[i] && nS.m_cSize>1; i++)			//�������� ���� �������� ������������ �� ������ ������.
	{
		nS = nS - s[i];
	}
	return nS;
}
String String::operator - (const String& s)				//���������� ��������� - � ��������.
{
	return (*this) - s.m_cStr;							//����� ���������� ��������� - ������� �� �������.
}
String String::operator -= (const String& s)			//���������� ��������� -= � ��������.
{
	return (*this) = (*this) - s;						//����� ���������� ��������� ������� � ��������.
}
String String::operator -= (const char * s)				//���������� ��������� -= � �������.
{
	return (*this) = (*this) - s;
}
String String::operator -= (const char c)				//���������� ��������� -= � ��������.
{
	return (*this) = (*this) - c;
}
ostream& operator << (ostream& os, const String& s)		//���������� ��������� ������.
{
		return os<<s.m_cStr;
}
istream& operator >> (istream& os, String& s)			//���������� ��������� �����.
{
	if (s.m_cSize > 0&&s.m_cStr)						//�������� ���������� �� ������.
	{
		int i = 0;
		for (; i < (s.m_cSize - 1); i++)
			os >> s.m_cStr[i];
		s.m_cStr[i] = '\0';
	}
	return os;
}
String operator + (const char* s, String& Str)			//���������� ���������� ��������� +.
{
	String nS(s);										//�������� ������� � ������ �������.
	nS += Str;											//����� ���������� += ��� ��������.
	return nS;
}
String operator + (char c, String& Str)					//���������� ����������� ��������� + � ��������.
{
	char* bufS = new char[Str.m_cSize + 1];				//�������� ����� ������.
	bufS[0] = c;										//���������� � ��� �������.
	bufS[1] = '\0';										//�������� �����, ����� strcat � �����.
	strcat(bufS, Str.m_cStr);							//������������ �����.
	String nS(bufS);
	delete[] bufS;
	return nS;
}