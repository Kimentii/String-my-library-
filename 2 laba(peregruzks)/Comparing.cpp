#include "String.h"
#include <cstring>
#pragma warning (disable: 4996)
bool String::operator == (const String& tmp) const			//Перегрузка оператора == с объектом.
{
	if (!strcmp(this->m_cStr, tmp.m_cStr))					//Если строки равны.
		return true;										//Вернуть true.
	else
		return false;										//Иначе вернуть false.
	
}
bool String::operator == (const char* tmp) const			//Перегрузка оператора == со строкой.
{
	if (!strcmp(this->m_cStr, tmp))							//Если строки равны.
		return true;										//Вернуть true.
	else
		return false;										//Иначе вернуть false.
}
bool String::operator != (const String& s)					//Перегрузка оператора != с объектом.
{
	if (strcmp(this->m_cStr, s.m_cStr))
		return true;
	else
		return false;
}
bool String::operator != (const char* str)					//Перегрузка оператора != со строкой.
{
	if (strcmp(this->m_cStr,str))
		return true;
	else
		return false;
}
bool String::operator > (const String& s)					//Перегрукзка оператора > с объеектом.
{
	if (strcmp(this->m_cStr, s.m_cStr) > 0)
		return true;
	else
		return false;
}
bool String :: operator > (const char* s)					//Перегрузка оператора > со строкой.
{
	if (strcmp(this->m_cStr, s) > 0)
		return true;
	else
		return false;
}
bool String::operator < (const String& s)					//Перегрузка оператора < с объектом.
{
	if (strcmp(this->m_cStr, s.m_cStr) < 0)
		return true;
	else
		return false;
}
bool String :: operator < (const char* s)					//Перегрузка опертаора < с строкой.
{
	if (strcmp(this->m_cStr, s) < 0)
		return true;
	else
		return false;
}
bool operator == (const char* s, String& Str)
{
	if (!strcmp(s, Str.m_cStr))
		return true;
	else
		return false;
}
bool operator != (const char* s, String& Str)
{
	if (!(strcmp(s, Str.m_cStr)))
		return false;
	else
		return true;
}
bool operator > (const char* s, String& Str)
{
	if (strcmp(s, Str.m_cStr) > 0)
		return true;
	else
		return false;
}
bool operator < (const char* s, String& Str)
{
	if (strcmp(s, Str.m_cStr) < 0)
		return true;
	else
		return false;
}