#include <iostream>
#include <time.h>
using namespace std;
int getHoarBorder(int* mas, int sm, int em)
{

	int i = sm - 1, j = em + 1;
	int brd = mas[sm];
	int buf;
	while (i < j)
	{
		while (mas[--j] < brd);
		while (mas[++i] > brd);
		if (i < j)
		{
			buf = mas[j];
			mas[j] = mas[i];
			mas[i] = buf;
		};
	}

	return j;
}
void sortHoar(int* mas, int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(mas, sm, em);
		sortHoar(mas, sm, hb);
		sortHoar(mas, hb + 1, em);
	}
};
void mergeSort(int* mas, int start,int end)
{
	if (end - start < 2)
		return;
	if (end - start == 2)
	{
		if (mas[start] < mas[start + 1])
			swap(mas[start], mas[start + 1]);
	}
	mergeSort(mas,start,start+(end-start)/2);
	mergeSort(mas, start + (end - start) / 2,end);
	int b1 = start;
	int e1 = start + (end - start) / 2;
	int b2 = e1;
	int* temp = new int[end - start];
	for (int i = 0; i < end - start; i++)
	{
		if (b1 >= e1 || (b2 < end && mas[b2] >= mas[b1]))
		{
			temp[i] = mas[b2];
			++b2;

		}
		else {
			temp[i] = mas[b1];
			++b1;
		}
	}
	for (int i = start; i < end; ++i)
			mas[i] = temp[i - start];
}
void ShakerSort(int* mas, int n) {
	int left, right, i;
	left = 0;
	right = n - 1;
	while (left <= right) {
		for (i = right; i >= left; i--) {
			if (mas[i - 1] > mas[i]) {
				swap(mas[i - 1], mas[i]);
			}
		}
		left++;
		for (i = left; i <= right; i++) {
			if (mas[i - 1] > mas[i]) {
				swap(mas[i - 1], mas[i]);
			}
		}
		right--;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите размер массива\n";
	cin >> n;
	int* mas1 = new int[n];
	int* mas2 = new int[n];
	int* mas3 = new int[n];
	for (int i = 0; i < n; i++)
	{
		mas1[i] = rand() % (100);
		mas2[i] = mas1[i];
		mas3[i] = mas2[i];
	//	cout << mas1[i] << " ";
	}
	unsigned int time1 = clock();
	sortHoar(mas1,0,n-1);
	unsigned int time2 = clock();
	cout << "Время сортировки методом Хоара " << time2 - time1<<endl;
	unsigned int time3 = clock();
	mergeSort(mas2, 0, n);
	unsigned int time4 = clock();
	cout << endl;
	//for (int i = 0; i < n; i++)
	//	cout << mas2[i] << " ";
	cout << endl<<"Время сортировки методом слияния " << time4 - time3 << endl; 
	 time3 = clock();
	ShakerSort(mas3, n);
	 time4 = clock();
	 cout << endl<<"Время  шейерной сортировки " << time4 - time3 << endl;
	delete[]mas1;
	delete[]mas2;
	delete[]mas3;

}

