#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	const int size = 15;
	int mas[15];
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 11 - 5;
		cout << mas[i] << " ";
	}
	cout << endl;
	for(int j=0;j<size;j++)
	for (int i = 0; i < size; i++)
	{
		if (i != j && mas[j] == mas[i])
			mas[i] = 10;
	}
	int size2=0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] != 10)
			size2++;
	}
	int* mas2 = new int[size2];
	for (int i = 0, j = 0; i < size; i++)
	{
		if(mas[i]!=10)
		mas2[j++] = mas[i];
	}
	for (int i = 0; i < size2; i++)
		cout << mas2[i] << " ";
	

}

