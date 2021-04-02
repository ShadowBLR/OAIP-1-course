#include <iostream>
using namespace std;
struct Node
{
	int Num;
	Node* next;

};
int n;
Node* pTemp;
Node* Head = NULL, * pPrev;
void Add()
{
	if (Head == NULL)
	{
		Head = new Node();
		Head->Num = 1;
		Head->next = NULL;
	}
	pTemp = Head;
	for (int i = 2; i <= n; i++)
	{
		pTemp->next = new Node();
		pTemp = pTemp->next;
		pTemp->Num = i;
		pTemp->next = NULL;
	}
}
void Del()
{
	unsigned short k;
	cout << "\nВведите k\n ";
	pTemp = Head;
	cin >> k;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{

			pPrev = pTemp;
			pTemp = pTemp->next;
			if (pTemp == NULL)
				pTemp = Head;
		}
		pPrev->next = pTemp->next;
		cout << pTemp->Num << " ";
		delete[]pTemp;
		pTemp = pPrev->next;
		if (pTemp == NULL)
			pTemp = Head;

	}
}
void Show()
{
	Node* cur = Head;
	do
	{
		cout << cur->Num << " ";
		cur = cur->next;
	} while (cur != NULL);
}
int main()
{
	setlocale(LC_ALL, "ru");
	
	int  i;

	cout << "enter N\n";
	cin >> n;

	Add();

	Show();
	Del();
	cout << pTemp->Num;
	return 0;
}