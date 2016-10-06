#include "String.h"
#include <cstring>
#pragma warning (disable: 4996)
String::String(const String& s)							//Конструктор копирования.
{
	if (s.m_cSize > 0)
	{
		this->m_cStr = new char[s.m_cSize + 1];			//Выделение памяти под строку.
		this->m_cSize = s.m_cSize;						//Присвоение размера строки.
		strcpy(this->m_cStr, s.m_cStr);					//Перезапись строки.
		//cout << "\nCopy constuctor\n";
	}
}
String::String(const char* s)							//Коструктор со стркой.
{
	this->m_cSize = strlen(s)+1;						//Присвоение размера строки.
	this->m_cStr = new char[this->m_cSize];				//Выделение памяти под строку.
	strcpy(this->m_cStr, s);							//Перезапись строки.
	//cout << "constructor\n";
}
String::~String()										//Деструктор
{
	if (m_cStr)											//Если есть что удалять.
	{
		delete[] m_cStr;								//Удалить строку.
		m_cStr = nullptr;								//Зануление указателя.
	}
	//cout << "\nDestuctor\n";
}
String String::operator = (const String& s)				//Перегрузка оператора = со строкой.
{
	if (this != &s)										//Если элемент не равен передоваемомоу элементу.
	{
		delete[] this->m_cStr;							//Удалить строку.
		this->m_cSize = s.m_cSize;						//Присваивание размера строки.
		this->m_cStr = new char[this->m_cSize];
		strcpy(this->m_cStr, s.m_cStr);
	}
	return *this;
}
String String::operator = (const char* str)				//Перегрузка оператора = с строкой.
{
	delete[] this->m_cStr;								//Удаление существущей строки.
	this->m_cSize = strlen(str)+1;						//Установление размера строки.
	this->m_cStr = new char[this->m_cSize];				//Выделение памяти.
	strcpy(this->m_cStr, str);							//Перезапись стрки.
	return *this;
}
char& String::operator [] (int i)						//Перегрузка оператора [].
{
	if ((i >= 0) && (i < m_cSize))						//Если введен правильный номер.
		return m_cStr[i];								//Возвращаем ссылку на элемент с этим номером.
	else
		return m_cStr[0];								//Иначе возвращаем ссылку на 1 элемент.
}
char* String::operator () (int a, int b)				//Перегрузка оператора выделения подстроки.
{
	if ((a >= 0) && (a < (m_cSize-1)) && (b >= 0) && (b < (m_cSize-1))&&(a<b))	//Если введены верные значения. 
	{
		char*nS = new char [b - a + 2];					//Выделение памяти на подстроку.
		int i, j = 0;
		for (i = a; i <= b; i++, j++)
		{
			nS[j] = m_cStr[i];							//Запись подстроки.
		}
		nS[i] = '\0';
		return nS;										//Возвращение новой строки.
	}
	else
	{
		return "";										//Иначе возвращение нулевой строки.
	}
}
String String::operator + (const String& s)				//Перегрузка оператора + с объектом.
{
	String nS((*this) + s.m_cStr);						//Посылаем в конструктор копирования сумму объекта и стоки.
	return nS;											//Возвращаем созданный объект.
}
String String::operator + (const char * s)				//Перегрузка оператора + с строкой.
{
	char* bufS = new char[m_cSize + strlen(s)];			//Создание новой строки.
	strcpy(bufS, m_cStr);								//Перезапись первой строки.
	strcat(bufS, s);									//Добавление воторой строки.
	String S(bufS);
	delete[] bufS;
	return S;											//Возвращение объекта с суммой строк.
}
String String::operator + (const char c)				//Перегрузка оператора + с символом.
{
	char* bufS = new char[m_cSize +1];					//Выделение памяти на новую строку.
	strcpy(bufS, m_cStr);								//Перезапись строки объекта.
	int i = strlen(m_cStr);
	bufS[i++] = c;										//Добавление символа в новую строку.
	bufS[i] = '\0';										//Обозначение конца строки.
	String nS(bufS);
	delete[] bufS;
	return nS;											//Возврат объекта с суммарной строкой.
}
String String::operator += (const String& s)			//Перегрузка оператора += с объектом.
{
	return (*this) = (*this) + s;						//Вызов перегрузки + объекта с объектом.
}
String String::operator += (const char * s)				//Перегрузка оператора += с строкой.
{
	return (*this) = (*this) + s;						//Вызов перегрузки + объекта с строкой.
}
String String::operator += (const char c)				//Перегрузка оператора += с символом.
{
	return (*this) = (*this) + c;						//Вызов перегрузки + объекта с строкой.
}
String String::operator ++ () 							//Перегрузка префиксного инкремента.
{
	for (int i = 0; m_cStr[i]; i++)						//Увеличение аскикода на 1 во всех вмволах строки.
		this->m_cStr[i]++;
	return *this;
}
String String::operator ++ (int) 						//Перегрузка постфиксного инкремента.
{
	return ++(*this);									//Вызов префиксного инкремента.
}
String String::operator -- ()							//Перегрузка префиксного декремента.
{
	for (int i = 0; m_cStr[i]; i++)						//Уменьшение аскикода каждого символа на 1.
		this->m_cStr[i]--;
	return *this;
}
String String::operator -- (int)						//Перегрузка постфиксного декремента.
{
	return --(*this);									//Вызов перегрузки префиксного декремента.
}
String String::operator - (char c)						//Перегрузка оператора - с символом
{
	char* p = nullptr;
	String nS(m_cStr);									//Создание буферного объекта.
	while (1)
	{
		p=strchr(nS.m_cStr, c);							//Поиск символа в строке.
		if (!p)break;									//Если символ не найден, прекращение цикла.
		for (int i = 0; p[i]; i++)						//Если найден, то удаление его.
		{
			p[i] = p[i + 1];
		}
		nS.m_cSize--;									//Уменьшение размера строки на 1.
		if (nS.m_cSize <= 1)break;						//Если строка пуста, то выход  из цикла.
	}
	return nS;											//Возврещение буферного объекта.
}
String String::operator - (const char* s)				//Перегрузка оператора - с строкой.
{
	String nS(*this);
	for (int i = 0; s[i] && nS.m_cSize>1; i++)			//Удаление всех символов содержащихся во второй строке.
	{
		nS = nS - s[i];
	}
	return nS;
}
String String::operator - (const String& s)				//Перегрузка оператора - с объектом.
{
	return (*this) - s.m_cStr;							//Вызов перегрузки оператора - объекта со строкой.
}
String String::operator -= (const String& s)			//Перегрузка оператора -= с объектом.
{
	return (*this) = (*this) - s;						//Выхов перегрузки оператора объекта с объектом.
}
String String::operator -= (const char * s)				//Перегрузка оператора -= с строкой.
{
	return (*this) = (*this) - s;
}
String String::operator -= (const char c)				//Перегрузка оператора -= с символом.
{
	return (*this) = (*this) - c;
}
ostream& operator << (ostream& os, const String& s)		//Перегрузка оператора вывода.
{
		return os<<s.m_cStr;
}
istream& operator >> (istream& os, String& s)			//Перегрузка оператора ввода.
{
	if (s.m_cSize > 0&&s.m_cStr)						//Проверка существует ли строка.
	{
		int i = 0;
		for (; i < (s.m_cSize - 1); i++)
			os >> s.m_cStr[i];
		s.m_cStr[i] = '\0';
	}
	return os;
}
String operator + (const char* s, String& Str)			//Глобальная перегрузка оператора +.
{
	String nS(s);										//Создание объекта с первой строкой.
	nS += Str;											//Вызов перегрузки += для объектов.
	return nS;
}
String operator + (char c, String& Str)					//Глобальная пергегрузка оператора + с символом.
{
	char* bufS = new char[Str.m_cSize + 1];				//Создание новой строки.
	bufS[0] = c;										//Добавление в нее символа.
	bufS[1] = '\0';										//Закрытие сроки, чтобы strcat её видел.
	strcat(bufS, Str.m_cStr);							//Скрепливание строк.
	String nS(bufS);
	delete[] bufS;
	return nS;
}