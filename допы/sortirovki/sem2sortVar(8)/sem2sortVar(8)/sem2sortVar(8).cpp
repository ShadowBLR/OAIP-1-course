#include <iostream>
#include <cstdlib>
#include <time.h> 
#include <ctime> 
using namespace std;
unsigned int t3, t4;
void selectSort(int* mas, int size)
{
	int k, i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++)
			if (mas[j] < mas[k])
				k = j;
		int c = mas[k];
		mas[k] = mas[i];
		mas[i] = c;
	}

}
void shell(int* mas, int size)
{
	int i, j, d, count;
	d = size;
	d = d / 2;
	while (d > 0)
	{
		for (i = 0; i < size - d; i++)
		{
			j = i;
			while (j >= 0 && mas[j] > mas[j + d])
			{
				count = mas[j];
				mas[j] = mas[j + d];
				mas[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
}
int main()
{
	system("chcp 1251");
	setlocale(LC_CTYPE, "Russian");
	srand((unsigned int)time(NULL));
	int n, size1 = 0, size2 = 0;
	cout << "Введите размер массивов\n";
	cin >> n;
	int* mas1 = new int[n];
	int* mas2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		mas1[i] = rand() % 100;
		mas2[i] = rand() % 100;
		cout << mas1[i] << " ";
		if (mas1[i] % 2 == 0)
			size1++;
		if (mas2[i] % 2 == 0)
			size2++;

	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
			cout << mas2[i] << " ";
	}
	int* mas3 = new int[size1 + size2];
	int* mas4 = new int[size1 + size2];
	for (int i = 0, j = 0; j < size1; i++)
	{
		if (mas1[i] % 2 == 0)
		{
			mas3[j] = mas1[i];
			j++;
		}
	}
	cout << endl;
	for (int i = 0, j = size1; j < size1 + size2; i++)
	{
		if (mas2[i] % 2 == 0)
		{
			mas3[j] = mas2[i];
			j++;
		}
	}
	for (int i = 0; i < size1 + size2; i++)
	{
		mas4[i] = mas3[i];
		cout << mas3[i] << " ";
	}
	t3 = clock();
	selectSort(mas3, size1 + size2);
	t4 = clock();
	cout << "Время сортировки выбором = " << t4 - t3;
	cout << "\n";
	for (int i = 0; i < size1 + size2; i++)
		cout << mas3[i] << " ";
	t3 = clock();
	shell(mas4, size1 + size2);
	t4 = clock();
	cout << "Время сортировки Шелла = " << t4 - t3;
	cout << endl;
	for (int i = 0; i < size1 + size2; i++)
		cout << mas4[i] << " " ;
	delete[] mas1;
	delete[] mas2;
	delete[] mas3;
}


