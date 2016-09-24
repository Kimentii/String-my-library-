#include "String.h"
#include <cstring>
#pragma warning (disable: 4996)
String::String(int s)
{
	if (s > 0)
	{
		m_cStr = new char[s];
		m_cSize = s;
		strcpy(this->m_cStr, "");
	}
	//cout << "\nString was made\n";
}
String::String(const String& s)
{
	this->m_cStr = new char[s.m_cSize+1];
	this->m_cSize = s.m_cSize;
	strcpy(this->m_cStr, s.m_cStr);
	//cout << "\nCopy constuctor\n";
}
String::String(const char *s)
{
	this->m_cSize = strlen(s)+1;
	this->m_cStr = new char[this->m_cSize];
	strcpy(this->m_cStr, s);
}
String:: ~String()
{
	if (m_cStr)
	{
		delete[] m_cStr;
		m_cStr = nullptr;
	}
	//cout << "\nDestuctor\n";
}
String String:: operator =(const String& s)
{
	if (this != &s)
	{
		delete[] this->m_cStr;
		this->m_cSize = s.m_cSize;
		this->m_cStr = new char[this->m_cSize];
		strcpy(this->m_cStr, s.m_cStr);
	}
	return *this;
}
String String::operator = (const char * str)
{
	delete[] this->m_cStr;
	this->m_cSize = strlen(str)+1;
	this->m_cStr = new char[this->m_cSize];
	strcpy(this->m_cStr, str);
	return *this;
}
char& String:: operator[](int i)
{
	if ((i >= 0) && (i < m_cSize))
		return m_cStr[i];
	else
		return m_cStr[0];
}
String String :: operator ()(int a, int b)
{
	if ((a >= 0) && (a < (m_cSize-1)) && (b >= 0) && (b < (m_cSize-1))&&(a<b))
	{
		String nS(b - a + 2);
		int i, j = 0;
		for (i = a; i <= b; i++, j++)
		{
			nS.m_cStr[j] = m_cStr[i];
		}
		nS.m_cStr[i] = '\0';
		return nS;
	}
	else
	{
		String s("");
		return s;
	}
}
String String :: operator +(const String& s)
{
	String bufS(m_cSize+s.m_cSize-1);
	strcpy(bufS.m_cStr, m_cStr);
	strcat(bufS.m_cStr, s.m_cStr);
	return bufS;
}
String String :: operator +(const char * s)
{
	String bufS(m_cSize + strlen(s));
	strcpy(bufS.m_cStr, m_cStr);
	strcat(bufS.m_cStr, s);
	return bufS;
}
String String :: operator +(const char c)
{
	String bufS(m_cSize +1);
	strcpy(bufS.m_cStr, m_cStr);
	int i = strlen(m_cStr);
	bufS.m_cStr[i++] = c;
	bufS.m_cStr[i] = '\0';
	return bufS;
}
String String ::operator +=(const String& s)
{
	return (*this) = (*this) + s;
}
String String::operator +=(const char * s)
{
	return (*this) = (*this) + s;
}
String String::operator +=(const char c)
{
	return (*this) = (*this) + c;
}
String  String::operator ++()
{
	for (int i = 0; m_cStr[i]; i++)
		this->m_cStr[i]++;
	return *this;
}
String  String::operator++(int)
{
	return ++(*this);
}
String  String::operator--()
{
	for (int i = 0; m_cStr[i]; i++)
		this->m_cStr[i]--;
	return *this;
}
String String::operator--(int)
{
	return --(*this);
}
String String ::operator-(char c)
{
	char* p = nullptr;
	String bufS(m_cSize);
	strcpy(bufS.m_cStr, m_cStr);
	while (1)
	{
		p=strchr(bufS.m_cStr, c);
		if (!p)break;
		for (int i = 0; p[i]; i++)
		{
			p[i] = p[i + 1];
		}
		bufS.m_cSize = bufS.m_cSize - 1;
	}
	return bufS;
}
String String ::operator-(const char* s)
{
	String bufS(m_cSize);
	strcpy(bufS.m_cStr, m_cStr);
	for (int i = 0; s[i] && bufS.m_cSize; i++)
	{
		bufS = bufS - s[i];
	}
	return bufS;
}
String String::operator-(const String& s)
{
	String bufS(m_cSize);
	strcpy(bufS.m_cStr, m_cStr);
	for (int i = 0; s.m_cStr[i]&&bufS.m_cSize; i++)
	{
		bufS=bufS - s.m_cStr[i];
	}
	return bufS;
}
String String ::operator -=(const String& s)
{
	return (*this) = (*this) - s;
}
String String::operator -=(const char * s)
{
	return (*this) = (*this) - s;
}
String String::operator -=(const char c)
{
	return (*this) = (*this) - c;
}
ostream& operator<<(ostream& os, const String& s)
{
	return os<<s.m_cStr;
}
istream& operator >> (istream& os, String& s)
{
	int i = 0;
	for ( ;i<(s.m_cSize-1); i++)
		os >> s.m_cStr[i];
	s.m_cStr[i] = '\0';
	return os;
}