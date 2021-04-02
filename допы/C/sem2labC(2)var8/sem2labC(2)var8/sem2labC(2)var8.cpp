//перемножить две матрицы из a и b txt
//1 лаба
#include <stdio.h>      

#include <fstream> 
#include <iostream> 
#include <cstring>


int main()
{
	using namespace std;

	int n;
	FILE* f;
	errno_t err;
	err = fopen_s(&f, "a.txt", "r");
	fscanf_s(f, "%d", &n);
	int** arr = new int* [n];
	int* brr = new int[n];
	int* crr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf_s(f, "%d", &arr[i][j]);
			//f >> arr[i][j];
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	fclose(f);
	err = fopen_s(&f, "b.txt", "r");
	for (int i = 0; i < n; i++)
	{
		fscanf_s(f, "%d", &brr[i]);
		//f2 >> brr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += arr[i][j] * brr[j];
		}
		crr[i] = sum;
	}
	/*for (int i = 0; i < n; i++)
	{
		cout << crr[i]<<' ';
	}*/
	fclose(f);
	err = fopen_s(&f, "c.txt", "w");
	for (int i = 0; i < n; i++)
		fprintf_s(f, "%d\n", crr[i]);
	fclose(f);
}
