#include <iostream>
#include <time.h>
using namespace std;
unsigned int t1,t2,t3, t4;
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
void ShakerSort(int* mas, int n) {
	int left, right, i;
	left = 0;
	right = n - 1;
	while (left <= right) {
		for (i = right; i > left; i--) {
			if (mas[i - 1] < mas[i]) {
				swap(mas[i - 1], mas[i]);
			}
		}
		left++;
		for (i = left; i <= right; i++) {
			if (mas[i - 1] < mas[i]) {
				swap(mas[i - 1], mas[i]);
			}
		}
		right--;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size1,size2=0;
	cout << "Введите размер исходного массива\n";
	cin >> size1;
	int* mas1 = new int[size1];

	for (int i = 0; i < size1; i++)
		mas1[i] = rand() % 100;
	//print(mas1, size1);
	for (int i = 0; i < size1; i++)
		if (i % 2 == 1 && i != size1 - 1 && mas1[i] % 2 == 1)
			size2++;
	int* mas2 = new int[size2];
	for (int i = 0,j=0; i < size1; i++)
		if (i % 2 == 1 && i != size1 - 1 && mas1[i] % 2 == 1)
		{
			mas2[j] = mas1[i];
			j++;
		}
	print(mas2, size2);
	int* mas3 = new int[size2];
	for (int i = 0; i < size2; i++)
		mas3[i] = mas2[i];
	t1 = clock();
	Bubble(mas2, size2);
	t2 = clock();
	print(mas2, size2);
	t3 = clock();
	ShakerSort(mas3, size2);
	t4 = clock();
	print(mas3, size2);
	cout << "Время сортировки пузырьком = " << t2 - t1 << endl;
	cout << "Время шейкерной сортировки  = " << t4 - t3 << endl;


	delete[]mas3;
	delete[]mas2;
	delete[]mas1;


}