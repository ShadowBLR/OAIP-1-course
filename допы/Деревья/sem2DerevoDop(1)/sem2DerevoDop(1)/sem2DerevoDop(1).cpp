#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
	unsigned int number;
	char name[30];
	char tarif[20];
	Node* left ;
	Node* right ;
}; 
int tempCount=0;
	Node* add(int number, char* name, char* tarif)
	{
		Node* temp=new Node();
		temp->number = number;
		for (int i = 0; i < strlen(name) + 1; i++)
			temp->name[i] = name[i];
		for (int i = 0; i < strlen(tarif) + 1; i++)
				temp->tarif[i] = tarif[i];
		temp->left = NULL;
		temp->right = NULL;
		return temp;

	}
	void addElement(Node*& currentRoot,Node* data)
	{
		if (currentRoot == NULL)
		{
			currentRoot = data;
			return;
		}
		if (data->number > currentRoot->number)
			addElement(currentRoot->right, data);
		else addElement(currentRoot->left,data);
	/*	if (data->number > currentRoot->number)
			if (currentRoot->right == NULL)
				currentRoot->right = data;
			else
			addElement(currentRoot->right,data);
		else if(data->number < currentRoot->number)
			if (currentRoot->left == NULL)
				currentRoot->left = data;
			else
				addElement(currentRoot->left, data);*/
	}
	void printThree(Node* currentRoot,int u)
	{
		if (currentRoot == NULL)
			return;
		else
		{
			
			printThree(currentRoot->right, ++u);
			for (int i = 0; i < u; i++)
				cout << " ";
			std::cout << currentRoot->number<<' ' <<currentRoot->name<<" "<<currentRoot->tarif<< std::endl;
			printThree(currentRoot->left, ++u);
		}
	}
	Node* create(Node*& root)
	{
		root = NULL;
		return root;
	}	
	void writeToFile(Node*&root,ofstream &fout)
	{
		if (root == NULL)
			return;
		fout.write((char*)&(root->number), sizeof(root->number));
		fout.write((char*) & (root->name), sizeof(20));
		fout.write((char*) & (root->tarif), sizeof(20));
		writeToFile(root->left,fout);
		writeToFile(root->right,fout);
		
	}
	void write(Node*& root)
	{
		ofstream fout("three.bin");
		writeToFile(root, fout);
		fout.close();
	}
	void readFromFile(Node*& root, ifstream &fin)
	{
		unsigned int n;
		char na[20];
		char ta[20];
		Node* temp = new Node;
		while (!fin.eof())
		{
			fin.read((char*) & (n), sizeof(n));
			if (fin.eof())
				break;
			fin.read((char*) & (na), sizeof(20));
			fin.read((char*) & (ta), sizeof(20));
			addElement(root, add(n, na, ta));
		}
	}
	void read(Node*&root)
		{
		ifstream fin("three.bin");
		readFromFile(root,fin);
		fin.close();
		}
	bool isSearch(Node*& root, int key)
	{
		if (root == NULL)
			return 0;
		if (key == root->number)
			return 1;
		if (key > root->number)
			isSearch(root->right, key);
		else isSearch(root->left, key);
	}
	Node* search(Node*& root,int key)
	{
		if (isSearch(root, key) == NULL)
		{
			cout << "Такого элемента нет\n";
			return NULL;
		}
		Node* temp = root;
		while (true)
		{
			if (key == temp->number)
				return temp;
			if (key > temp->number)
				temp = temp->right;
			else temp = temp->left;
		}
	}
	char**& push(char* value,char**&tar)
	{
		for (int i = 0; i < strlen(value) + 1; i++)
			tar[tempCount][i] = value[i];
		tempCount++;
		return tar;
	}
	void tarif(Node* &root,char**& tar)
	{
		if (root == NULL)
			return;
		tarif(root->left, tar);
		tarif(root->right,tar);
		tar=push(root->tarif,tar);
		return;
	}
	int countNode(Node* root)
	{
		if (root->left == NULL && root->right == NULL)
			return 1;

		int left, right;
		if (root->left != NULL)
			left = countNode(root->left);
		else
			left = 0;
		if (root->right != NULL)
			right = countNode(root->right);
		else
			right = 0;

		return left + right + 1;
	}
int main()
{
	setlocale(LC_ALL, "ru"); 
	int count=0;
	int choice;
	Node* root=NULL;
	do {
		cout << "1 -  создать дерево\n";
		cout << "2 - добавить элемент\n"; 
		cout << "3 - вывод на экран\n";
		cout << "4 - запись в файл\n";
		cout << "5 - чтение из файла\n";
		cout << "6 - поиск по ключу\n";
		cout << "7 - популярный тариф\n";
		cout << "8 - подсчет узлов\n";
		cout << "0 - exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:root = create(root);
			break;
		case 2:int n;
				char nam[20], tar[20];
				cin >> n >> nam >> tar;
				addElement(root, add(n, nam, tar));
				break;
		case 3:printThree(root,0);
			break;
		case 4:write(root);
			break;
		case 5:read(root);
			break;
		case 6:cout << "Введите ключ\n";
			int key;
			cin >> key;
			Node* tmp;tmp = search(root, key);
			if (tmp != NULL)
				cout << tmp->name<<endl<<tmp->tarif<<endl;
			break;
		case 7:
			char** tar1; int tmp1;
			tmp1 = 0;
			tar1= new char* [count];
			for (int i = 0; i < count; i++)
				tar1[i] = new char [20];
				tarif(root,tar1);
			int i1, i2, ind; i1 = 0; i2 = 0; ind = 0;
			for (int i = 0; i < count; i++)
			{
				for (int j = 0; j < count; j++)
				{
					if (strcmp(tar1[i], tar1[j]) == 0)
						i1++;
				}
				if (i1 > i2)
				{
					i2 = i1;
					ind = i;
				}
				i1 = 0;
			}
			cout << "Наиболее популярный тариф "<<tar1[ind]<<endl;
			break;
		case 8:count = countNode(root);
			cout << count<<endl;
			break;
		}
	} while (choice != 0);
	return 0;
}
