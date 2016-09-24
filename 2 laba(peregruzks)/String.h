#include <iostream>
using namespace std;
class String
{
	char* m_cStr;
	int m_cSize;
public:
	//Operations
	String(int s);												//Конструктор с параметром int.
	String(const char* s = "");									//Конструктор с параметром строки.
	String(const String& s);									//Конструктор с параметром объекта.
	~String();													//Деструкор.
	String operator = (const String& s);						//Перегрузка = с объектом.
	String operator = (const char * str);						//Перегрузка операции = с передачей строки.
	char& operator[](int i);									//Перегрузка [].
	String operator ()(int a, int b);							//Выделение подстроки.
	String operator +(const String& s);							//Перегрузка + с объектом.
	String operator +(const char * s);							//Перегрузка + со строкой.
	String operator +(const char c);							//Перегрузка + с символом.
	String operator +=(const String& s);						//Перегрузка +=  с объктом.
	String operator +=(const char * s);							//Перегрузка += со срокой.
	String operator +=(const char c);							//Перегрузка += с символом.
	String operator ++();										//Префиксный инкремент.
	String operator ++(int);									//Постфиксный инкремент.
	String operator--();										//Префиксный декремент.
	String operator--(int);										//Постфиксный декремент.
	String operator-(char);										//Перегрузка оператора "-" с символом.
	String operator-(const char* s);							//Перегрузка - со строкой.
	String operator-(const String& s);							//Перегрузка оператора "-" с объектом.
	String operator -=(const String& s);						//Перегрузка -= с объкутом.
	String operator -=(const char * s);							//Перегрузка -= со строкой.
	String operator -=(const char c);							//Перегрузка -= с символом.
	friend ostream& operator<<(ostream& os, const String& s);	//Перегрузка вывода.
	friend istream& operator>>(istream& os, String& s);			//Перегрузка ввода.
	//Comparing
	bool operator !=(const String& s);							//Пеоегрузка != с объктом.
	bool operator !=(const char* str);							//Перегрузка != со строкой.
	bool operator > (const String& s);							//Перегрузка > с объкутом.
	bool operator > (const char* s);							//Перегрузка < со строкой.
	bool operator < (const String& s);							//Перегрузка < с объектом.
	bool operator < (const char* s);							//Перегрузка > со строкой.
	bool operator == (const String & tmp) const;				//Перегрузка == с объкутом.
	bool operator == (const char * tmp) const;					//Перегрузка == со строкой.
};