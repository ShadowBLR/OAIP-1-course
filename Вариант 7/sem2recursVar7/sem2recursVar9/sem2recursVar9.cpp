#include <iostream>
using namespace std;
int sum(int a, int b)
{
	if (b != 0)
		return a + b + sum(a + 1, b - 1);
	else return 0;
}
int raz(int a, int b)
{
	if (b != 0)
		return a - b - raz(a -1, b - 1);
	else return 0;
}
int multi(int a, int b)
{
	if (a>=1&&b>=1)
		return a + multi(a , b - 1);
	else return 0;
}
int power(int a, int b)
{
	if (b != 0)
		return a *power(a, b - 1);
	else return 1;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int a,b;
	cout << "Введите a\n";
	cin >> a;
	cout << "Введите b\n";
	cin >> b;
	cout<<power(a, b);
}

