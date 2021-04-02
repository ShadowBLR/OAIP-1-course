#include <iostream>
using namespace std;
float recurs(float n, float x)
{
	if (n >= 1)
		return sin(x * n) + recurs(n - 1, x);
	else return 0;
}
int main()
{
	setlocale(LC_ALL, "ru");
	float n, x;
	cout << "Введите n";
	cin >> n;
	cout << "Введите x";
	cin >> x;
	cout<< recurs(n,x);
}


