#include "String.h"
void fun(String s)
{
	cout << s << endl;
	return;
}
int main()
{
	char ss[80];
	String B("1234"), C(B);									   //Вызов конструктора с const char*, конструктор копирования.
	cout << "Enter A string:";
	cin.getline(ss, 80);
	String A(ss);
	cout << "'F' + A + 'ksis' + A: ";							//Перегрузка глобальных + с char и char*.
	cout << 'F' + A + "ksis" + A << endl;
	cout << "String A:" << A << endl << "String B:" << B << endl << "String C:" << C << endl;	//Перегрузка вывода.
	A++;														//Перегрузка постфиксного инкремента.
	++A;														//Перегрузка префиксного инкремента.
	A--;														//Перегрузка постфиксного декремента.
	cout << "String A after ++,++(int), --(int) and --:" << --A << endl;	//Перегрузка префиксного декремента.
	cout << "String A - '4':"<<A - '4'<<endl;
	cout << "String A - B:" << A - B<<endl;
	A += B;														//Перегрузка оператора += с объектом.
	A+= "ABC";													//Перегрукза оператора += со строкой.
	A += 'D';													//Перегрузка оператора += с символом.
	cout << "String A + B + 'ABC' + 'D':" << A << endl;			//Перегрукза оператора вывода.
	A -= 'D';													//Перегрузка оператора -= с символом.
	A -= "ABC";													//Перегрузка оператора -= со строкой.
	A -= B;														//Перегрузка оператора -= с объектом.
	cout << "String A - 'D' - 'ABC' - B:" << A << endl;
	A = B + A;													//Перегрузка оператора + с объектом.
	cout << "Strng A = B + A:" << A << endl;
	bool x = (A == "12345");									//Перегрузка оператора == со строкой.
	cout << "Is string A == '12345'? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A == B);												//Перегрузка оператора == с объектом.
	cout << "Is string A == B? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = ("12345" == A);											//Перегрузка глобального ==.
	cout << "Is string '12345' == A? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A > B);												//Перегрузка оператора > с объектом.
	cout << "Is string A > B? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A < B);												//Перегрузка оператора < с объектом.
	cout << "Is string A < B? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A > "99999");											//Перегрузка оператора > со строкой.
	cout << "Is string A > '99999'? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A < "99999");											//Перегрузка оператора < со строкой.
	cout << "Is string A < '99999'? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = ("99999" > A);											//Перегрузка глобального >.
	cout << "Is string '99999' > A? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = ("12345" < B);											//Перегрузка глобального <.
	cout << "Is string '12345' < B? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A != "12345");											//Перегрузка оператора != со строкой.
	cout << "Is string A != '12345'? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	cout << "String A:" << A << "     String C:" << C << endl;
	x = (A != C);												//Перегрузка оператора != с объектом.
	cout << "Is string A != C? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = ("12345" != C);											//Перегрузка глобально !=.
	cout << "Is string '12345' != C? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	cout << "String from 0 to 2 simbols from string A: " << A(0, 2) << endl;	//Выделение подстроки.
	cout << "String A + '678' + '9':" << A + "678" + "9" << endl;
	cout << "Simbol with number 3 from string A is:" << A[3] << endl;			//Вывол 3-го элемента.
	B = "99999";																//Перегрузка = со строкой.
	cout << "Now B is:" << B << endl;
	A = B;																		//Перегрузка = с объектом.
	cout << "Now A = B:" <<A<< endl;
	//fun("1234");															    //Нельязя, потому что конструктор explicit.
	fun(A);
	system("pause");
	return 0;
}