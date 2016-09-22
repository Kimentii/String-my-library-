#include "String.h"
#include <cstring>
#pragma warning (disable: 4996)
int String::operator == (const String & tmp) const
{
	return strcmp(this->m_cStr, tmp.m_cStr);
	
}
int String::operator == (const char * tmp) const
{
	return strcmp(this->m_cStr, tmp);
}
bool String::operator !=(const String& s)
{
	if (strcmp(this->m_cStr, s.m_cStr))
		return true;
	else
		return false;
}
bool String::operator !=(const char* str)
{
	if (strcmp(this->m_cStr,str))
		return true;
	else
		return false;
}
bool String::operator > (const String& s)
{
	if (strcmp(this->m_cStr, s.m_cStr) > 0)
		return true;
	else
		return false;
}
bool String :: operator > (const char* s)
{
	if (strcmp(this->m_cStr, s) > 0)
		return true;
	else
		return false;
}
bool String::operator < (const String& s)
{
	if (strcmp(this->m_cStr, s.m_cStr) < 0)
		return true;
	else
		return false;
}
bool String :: operator < (const char* s)
{
	if (strcmp(this->m_cStr, s) < 0)
		return true;
	else
		return false;
}