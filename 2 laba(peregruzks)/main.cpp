#include "String.h"
void fun(String s)
{
	cout << s << endl;
	return;
}
int main()
{
	char ss[80];
	String B("1234"), C(B);									   //����� ������������ � const char*, ����������� �����������.
	cout << "Enter A string:";
	cin.getline(ss, 80);
	String A(ss);
	cout << "'F' + A + 'ksis' + A: ";							//���������� ���������� + � char � char*.
	cout << 'F' + A + "ksis" + A << endl;
	cout << "String A:" << A << endl << "String B:" << B << endl << "String C:" << C << endl;	//���������� ������.
	A++;														//���������� ������������ ����������.
	++A;														//���������� ����������� ����������.
	A--;														//���������� ������������ ����������.
	cout << "String A after ++,++(int), --(int) and --:" << --A << endl;	//���������� ����������� ����������.
	cout << "String A - '4':"<<A - '4'<<endl;
	cout << "String A - B:" << A - B<<endl;
	A += B;														//���������� ��������� += � ��������.
	A+= "ABC";													//���������� ��������� += �� �������.
	A += 'D';													//���������� ��������� += � ��������.
	cout << "String A + B + 'ABC' + 'D':" << A << endl;			//���������� ��������� ������.
	A -= 'D';													//���������� ��������� -= � ��������.
	A -= "ABC";													//���������� ��������� -= �� �������.
	A -= B;														//���������� ��������� -= � ��������.
	cout << "String A - 'D' - 'ABC' - B:" << A << endl;
	A = B + A;													//���������� ��������� + � ��������.
	cout << "Strng A = B + A:" << A << endl;
	bool x = (A == "12345");									//���������� ��������� == �� �������.
	cout << "Is string A == '12345'? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A == B);												//���������� ��������� == � ��������.
	cout << "Is string A == B? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = ("12345" == A);											//���������� ����������� ==.
	cout << "Is string '12345' == A? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A > B);												//���������� ��������� > � ��������.
	cout << "Is string A > B? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A < B);												//���������� ��������� < � ��������.
	cout << "Is string A < B? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A > "99999");											//���������� ��������� > �� �������.
	cout << "Is string A > '99999'? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A < "99999");											//���������� ��������� < �� �������.
	cout << "Is string A < '99999'? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = ("99999" > A);											//���������� ����������� >.
	cout << "Is string '99999' > A? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = ("12345" < B);											//���������� ����������� <.
	cout << "Is string '12345' < B? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = (A != "12345");											//���������� ��������� != �� �������.
	cout << "Is string A != '12345'? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	cout << "String A:" << A << "     String C:" << C << endl;
	x = (A != C);												//���������� ��������� != � ��������.
	cout << "Is string A != C? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	x = ("12345" != C);											//���������� ��������� !=.
	cout << "Is string '12345' != C? ";
	if (x)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	cout << "String from 0 to 2 simbols from string A: " << A(0, 2) << endl;	//��������� ���������.
	cout << "String A + '678' + '9':" << A + "678" + "9" << endl;
	cout << "Simbol with number 3 from string A is:" << A[3] << endl;			//����� 3-�� ��������.
	B = "99999";																//���������� = �� �������.
	cout << "Now B is:" << B << endl;
	A = B;																		//���������� = � ��������.
	cout << "Now A = B:" <<A<< endl;
	//fun("1234");															    //�������, ������ ��� ����������� explicit.
	fun(A);
	system("pause");
	return 0;
}