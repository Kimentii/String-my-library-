#include <iostream>
using namespace std;
class String
{
	char* m_cStr;
	int m_cSize;
public:
	//Operations
	String(int s);
	String(const char* s = "");
	String(const String& s);
	~String();
	String operator = (const String& s);
	String operator = (const char * str);
	char operator[](int i);
	String operator ()(int a, int b);
	String operator +(const String& s);
	String operator +(const char * s);
	String operator +(const char c);
	String operator +=(const String& s);
	String operator +=(const char * s);
	String operator +=(const char c);
	String operator ++();
	String operator ++(int);
	String operator--();
	String operator--(int);
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& os, String& s);
	//Comparing
	bool operator !=(const String& s);
	bool operator !=(const char* str);
	bool operator > (const String& s);
	bool operator > (const char* s);
	bool operator < (const String& s);
	bool operator < (const char* s);
	int operator == (const String & tmp) const;
	int operator == (const char * tmp) const;
};