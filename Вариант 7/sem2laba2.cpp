#include <iostream>
using namespace std;
int mn(int n, ...);
int main()
{/*Написать функцию mn с переменным числом параметров, которая находит минимальное из чисел типа int. */
	setlocale(LC_ALL, "ru");
	cout << mn(4,15,3,14,29) << endl;
	cout << mn(2,13,4) << endl;
	cout << mn(5,12,13,14,2,4) << endl;
}
int mn(int n, ...)
{
	int *p = &n;
	int min = *(++p);
	for (int i = 1; i <= n; i++)
		if (min > p[i])
			min = p[i];
	return min;
}

