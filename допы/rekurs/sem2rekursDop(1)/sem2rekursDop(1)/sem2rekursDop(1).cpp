#include <iostream> 

using namespace std;

// доп. 1 к лр1
int A;
int dig[10];
void Recusion(int num)
{
	if (num == A)
	{
		for (int i = 0; i < A; i++)
			cout << dig[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < A; i++)
		{
			int n = 0;
			for (int j = 0; j < num; j++)
				if (dig[j] == 0)
					n = 0;
			if (n) continue;
			dig[num] = i;
			Recusion(num + 1);

		}
	}
}
int main()
{

	cout << "Please, enter the digit (0-9): ";
	cin >> A;
	if (A < 0 || A > 9)
	{
		cout << "Enter the digit, not number" << endl;
		cout << "Your digit is ";
		cin >> A;
	}

	int i, dig[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (i = 0; i < 10; i++)
	{
		cout << dig[i];
	}

	cout << endl;

	int* uk, * vuk, ia;

	uk = &dig[1];
	vuk = &dig[(10 - (i - A))];
	ia = *vuk - *uk;
	printf("Quantity of elements between the 1 element and the %d element is %d", A, ia);

	cout << endl;
	cout << endl;

	for (i = 0; i <= ia; i++)
	{
		cout << dig[i];
	}

	cout << endl;
	cout << endl;
	cout << endl;

	Recusion(0);

	system("pause");
	return 0;
}

