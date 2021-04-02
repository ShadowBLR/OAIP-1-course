#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	cout << "Размер массива ";
	int size;
	cin >> size;
	int* mas = new int[size];
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 30;
		cout << mas[i] << " ";
	}
	cout << endl;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 4; i++)
			if (mas[i] > mas[i + 1])
				swap(mas[i], mas[i + 1]);
		for (int k = size - 1; k > 6; k--)
			if (mas[k] > mas[k - 1])
				swap(mas[k], mas[k - 1]);
	}
	for (int i = 0; i < size; i++)
		cout << mas[i] << " ";
	delete[]mas;
}

