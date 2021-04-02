#include <iostream>
#include <cstdlib>
#include <time.h> 
#include <ctime> 
using namespace std;
unsigned int t3, t4;
void print(int *mas,int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}
void Bubble(int* mas,int size)
{
	unsigned int t1 = clock();
	int temp;
	for(int i=0;i<size;i++)
		for(int j=0;j<size-i-1;j++)
			if (mas[j] < mas[j + 1])
			{
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j+1] = temp;
			}
	unsigned int t2 = clock();
//	print(mas, size);
	cout << "Время сортировки пузырьком " << t2 - t1<<endl;
}
int getHoarBorder(int *mas, int sm, int em)
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
void sortHoar(int*mas, int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(mas, sm, em);
		sortHoar(mas, sm, hb);
		sortHoar(mas, hb + 1, em);
	}
};


int main()
{
	system("chcp 1251");
	setlocale(LC_CTYPE, "Russian");
	srand((unsigned int)time(NULL));
	int n,size1=0,size2=0;
	cout << "Введите размер массивов\n";
	cin >> n;
	int* mas1 = new int[n];
	int* mas2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		mas1[i] = rand() % 100;
		mas2[i] = rand() % 100;
		//cout << mas1[i] << " ";
		if (mas1[i] % 2 == 0)
			size1++;
		if (mas2[i] % 2 == 1)
			size2++;

	}
	cout << endl;
	//for (size_t i = 0; i < n; i++)
	//{
		//cout << mas2[i] << " ";
	//}
	int* mas3 = new int[size1+size2];
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
	for (int i = 0, j = size1; j < size1+size2; i++)
	{
		if (mas2[i] % 2 == 1)
		{
			mas3[j] = mas2[i];
			j++;
		}
	}
for (int i = 0; i < size1+size2; i++)
	{
	mas4[i] = mas3[i];
	}
	mas4 = mas3;
	t3 = clock();
	Bubble(mas3,size1+size2);
	t4 = clock();
	cout << "Время выполнения Хоара " << t4 - t3 << endl;
	t3 = clock();
	sortHoar(mas4,0,size1+size2-1);
	t4 = clock();
	cout << "Время выполнения Хоара "<<t4 - t3<<endl;
//	print(mas3, size1+size2);

	delete[] mas1;
	delete[] mas2;
	delete[] mas3;
}


