#include <iostream>
using namespace std;
int mn(int n, ...);
void diht(double (*f)(double));
double f1(double x);
double f2(double x);
int main()
{/**/
	setlocale(LC_ALL, "ru");
	cout << mn(4,15,3,14,29) << endl;
	cout << mn(2,13,4) << endl;
	cout << mn(5,12,13,14,2,4) << endl;
/*2--------------------------------------------
x3 + 2x – 4
x2 – 1*/
	diht(f1);
	diht(f2);
}
void diht(double (*f)(double))
{
	double a, b, c, e = 0.001;
	a = 0;
	cin >> b;
	while (b - a > e) {
		c = (a + b) / 2;
		if (f(b) * f(c) < 0)
			a = c;
		else
			b = c;
	}
	cout << (a + b) / 2 << endl;	
	return ;
}
double f1(double x)
{
	return pow(x, 3) + x * x - 4;
}
double f2(double x)
{
	return x * x - 1;
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

