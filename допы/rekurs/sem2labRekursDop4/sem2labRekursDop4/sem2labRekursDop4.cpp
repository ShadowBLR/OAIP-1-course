#include <iostream>
#include <time.h>
using namespace std;
int rekurs(const int n,int&k)
{
	if (k == n + 26)
		return n + 26;
	return(rekurs(n, ++k));
}
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int n;
	cout << "Введите n "; cin >> n;
	unsigned char* mas = new unsigned char[n * n + 26];
	for (int i = 0; i < n * n + 26; i++)
		mas[i] = rand() % 127;
	cout << mas<<endl;
	cout << mas[25 + n]<<endl;
	int k = 0;
	cout<<mas[rekurs(n,k)-1];
}

