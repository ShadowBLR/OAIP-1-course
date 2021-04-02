#include <iostream>
#include <time.h>
using namespace std;
unsigned int t1, t2, t3, t4;
void Bubble(int* mas, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (mas[j] < mas[j + 1])
			{
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
}
void print(int* mas, int size)
{
	cout << "\n";
	for (int i = 0; i < size; i++)
		cout << mas[i] << " ";
	cout << endl;
}
void insertSort(int* mas, int size)
{
	int t, i, j;
	for (i = 1; i < size; i++)
	{
		t = mas[i];
		for (j = i - 1; j >= 0 && mas[j] < t; j--)
			mas[j + 1] = mas[j];
		mas[j + 1] = t;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size1, size2 = 0;
	cout << "Введите размер исходного массива\n";
	cin >> size1;
	int* mas1 = new int[size1];
	int* mas2 = new int[size1];
	int max = 0;
	for (int i = 0; i < size1; i++)
	{
		mas1[i] = rand() % 100;
		mas2[i] = rand() % 50;
		if (mas2[i] > max)
			max = mas2[i];
	}
	for (int i = 0; i < size1; i++)
		if (mas1[i] > max)
			size2++;
	int* mas3 = new int[size2];
	int* mas4 = new int[size2];
	for (int i = 0, j = 0; i < size1; i++)
		if (mas1[i] > max)
			mas3[j++] = mas1[i];
	for (int i = 0; i < size2; i++)
		mas4[i] = mas3[i];
	print(mas3, size2);
	t1 = clock();
	Bubble(mas3, size2);
	t2 = clock();
	print(mas3, size2);
	t3 = clock();
	insertSort(mas4, size2);
	t4 = clock();
	print(mas4, size2);
	cout << "Время сортировки пузырьком = " << t2 - t1 << endl;
	cout << "Время шейкерной сортировки  = " << t4 - t3 << endl;


	delete[]mas3;
	delete[]mas2;
	delete[]mas1;


}
