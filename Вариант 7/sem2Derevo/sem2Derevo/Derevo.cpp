#include "TreeHeader.h"

void Tree::Push(int A, char* b)
{
	Element* E = root, * E1 = NULL; //������. �� ���. ��. - ������
	bool flag = true; //����������, � �������� ������ ��� � �������� ������� 
	while (E != NULL) //���� �� ������ ������� ��� ������� ������ ��������
	{
		E1 = E; //E1 - ��������� �� ��� �������, ������� ����� ��������� ��� ������ ��������
		if (A > E->x) //���� ����������� ��. ������ ��������
		{
			E = E->right; //����� ��. ���������� ������ ��������
			flag = true;
		}
		else
		{
			E = E->left; //����� ��. ���������� ����� ��������
			flag = false;
		}
	}
	E = new Element(); //�������� ������
	if (root == NULL) //������ ����� 0
		root = E; //����� ����. ���������� ������
	if (E1 != NULL) //�������� ������ �������� �� ����� 0
	{
		if (flag == true)
			E1->right = E; //���. ����. ���������� ������ ��������
		else E1->left = E;  //���. ����. ���������� ����� ��������
	}
	E->x = A; //�����. ��������

	E->s = new char[strlen(b) + 1]; //��������� ������
	strcpy_s(E->s, strlen(b) + 1, b); //�������� �, ������, � b

	E->left = NULL; //����� ���� ����� 0
	E->right = NULL; //����� � ������ ���� ����� 0
}

void Tree::Load(char* s) //������� ������ �� �����
{
	FILE* F;
	fopen_s(&F, s, "r");
	char buf[255];
	for (; !feof(F);) //���� �� ���������� ����
	{
		buf[0] = '\0'; //������� ������
		fgets(buf, 255, F);
		if (strlen(buf) > 0) //���� ����������� ������ �� ������
		{
			int i = 0;
			for (; i < strlen(buf); i++) //������ ����� ������. ���� ������ ����������� ����� � ������ (\t)
			{
				if (buf[i] == '\t')
				{
					buf[i] = '\0';
					break;
				}
			}
			int key = atoi(buf); //����������� ������ � ����� (����)
			buf[i] = '\t';
			int j = i + 1;
			for (; j < strlen(buf) - 1; j++) //i+1 - ������ ������ ������. j < strlen(buf)-1 - ����� �� ���������� ������� �� ����� ������
			{
				buf[j - (i + 1)] = buf[j]; //����� ������� ����.
			}
			buf[j - (i + 1)] = '\0'; //����� ������
			Push(key, buf); //���������� ������������ �������� � ������
		}
	}
	fclose(F);
}

int sum, c; //� - ���-�� ���������, sum - ����� ���������


Element* Search(Element* root, int A, Element** p, bool output) //����� ������� �� �����;  � - ������� ����; *p - ��������� �� �����.
{
	if (root != NULL) //���� ������ �� 0
	{
		Element* E = root; //������. �� ������� - ��� ������
		*p = NULL;
		while (E != NULL && E->x != A) //���� � �� 0 � ���� �������� �������� �� ����� �������� �����
		{
			*p = E;
			if (output == true)
				cout << E->x << "\t" << E->s << endl; //���� �������� ����. � ������ �������� ����.
			if (A > E->x)
				E = E->right; //����. ���������� ������ ��������
			else E = E->left; //����. ���������� ����� ��������
		}
		return E;
	}
	else return NULL; //������ �� �������
}


int depth(Element* E) //������ ������, ������� � ���� E (����� ������� �����)
{
	if (E == NULL) //���� ���� ����� 0
		return 0;
	else
	{
		int A = depth(E->left); //�-��� �������� ���� ���� (��������)
		int B = depth(E->right); //����������� �� ����������� ������� ������
		if (A > B)
			return A + 1; //���� +������(1)
		else  return B + 1;
	}
}

int HeightTree(Element* E)
{
	int x = 0, y = 0;
	if (E == NULL) return 0;     //������ ������ ��� ����� �� �����
	if (E->left) x = HeightTree(E->left); //������ ������ ���������
	if (E->right) y = HeightTree(E->right);  //������ ������� ���������
	if (x > y) return x + 1;    //+1 �� ����� � ������ ���������
	else return y + 1;   //+1 �� ����� � ������� ���������
}

void show_level(Element* E, int d, int i) //d - ������� �������, i - ��������� ������� //�-��� ��� ���������� ������
{
	if (E != NULL) //����. �� ����� 0
	{
		if (d == i) //���� ����� �� ������ �������
			cout << E->x << "\t" << E->s << endl;
		else {
			show_level(E->left, d + 1, i);//��� ����� �����
			show_level(E->right, d + 1, i);//��� ������ �����
		}
	}
}


void ScanDown(Element* E, void f(Element*)) //���������� �����
{
	if (E != NULL)
	{
		f(E); //������������ ������� ���� ������
		ScanDown(E->left, f); //���������� ����� ������ ���������
		ScanDown(E->right, f); //���������� ����� ������� ���������
	}
}


void ScanMixed(Element* E, void f(Element*)) //��������� �����
{
	if (E != NULL)
	{
		ScanMixed(E->left, f); //����� ������ ���������
		f(E);//�����.����.
		ScanMixed(E->right, f); //����� ������� ���������
	}
}

void ScanPrev(Element* E, void f(Element*)) //��������� �����
{
	if (E != NULL)
	{
		ScanPrev(E->left, f); //����� ������ ���������
		ScanPrev(E->right, f); //����� ������� ���������
		f(E);//�����.����.
	}
}

void Print(Element* E)
{
	cout << E->x << "\t" << E->s << endl; //����� ������ ��������
}

void Delete(Element* E, Element** p, Element** r) //��������� �� �����. � ������. �� ������
{
	if (E != NULL)
	{
		Delete(E->left, &E, r); //������� ����� �������
		Delete(E->right, &E, r); //������
								 //�������� ������ ��������
		if (*p != NULL)//���� �� ������������ �������
		{
			if (E == (*p)->left) //�������� �� ��������� ������� ����� ��������
				(*p)->left = NULL; //�������
			else (*p)->right = NULL;
		}
		if (E == *r) //���� ��������� ����. �������� ������
			(*r) = NULL;//����� ���. ��������
		delete E; //����������� ������ �� �������� ��������
	}
}

bool IsBalanced(Element* E) //������� �������� �����������. ������
{
	if (E == NULL)
		return true;
	else if (IsBalanced(E->left) && IsBalanced(E->right)) //���� �������������� ������ � ����� ����������
	{
		int l = depth(E->left); //����������� ������� ������ ���������
		int r = depth(E->right);
		if (abs(l - r) <= 1) //���� ������ ������� ������ ������ ���� ����� 1
			return true; //������ ��������������
		else return false;
	}
	else return false;
}
