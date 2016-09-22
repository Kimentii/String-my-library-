#include "String.h"
int main()
{
	String a("Str1"), b("Str2"), c("Str3");
	//cin >> a;
	a += b+=c;
	cout << a<<endl;
	cout << b;
	/*char* s = "sex";
	String c;
	char k = 'k';
	c = k;
	cout << c;*/
	//String c;
	//cout << c;
	//c++;
	//cout << c;
	//c--;
	//cout << --c;
	//a--;
	/*String c = a;
	bool x = (c != a);
	cout << x<<endl;
	x = (a !="12345");
	cout << x<<endl;
	if (a > "123")cout << "Ok\n";
	if (a < "123456")cout << "Ok 2\n";
	String b(6);
	cin >> b;
	if (a > b)cout << "more\n";
	if (a < b)cout << "less\n";*/
	//cout << endl << a[5] << endl;
	//String b = a(3,3);
	//cout << endl << b<<endl;
	system("pause");
	return 0;
}