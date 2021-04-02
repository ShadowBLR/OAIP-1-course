#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	cout << "Введите размер\n";
	int size; cin >> size;
	float temp = 1.0 + rand() % 10 / 10;
	int* mas = new int[size];
	for (int i = 0; i < size; i++)
		mas[i] = i + i * temp;
	for (int i = 0; i < size; i++) {
		swap(mas[i], mas[rand() % size]);
	}
	for (int i = 0; i < size; i++)
		cout << mas[i] << " ";
	int ind=0, max=mas[0], min=mas[0];
	for (int i = 0; i < size; i++)
	{
		if (max < mas[i])
		{
			max = mas[i];
			ind = i;
		}
		if (min > mas[i])
			min = mas[i];
	}
	cout << "Максимальный элемент = " << max << " его номер " << ind << endl;
	cout << "Минимальный элемент = " << min;
		delete[]mas; 
}

