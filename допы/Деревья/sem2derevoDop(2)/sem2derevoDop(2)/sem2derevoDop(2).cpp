#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
	int number;
	Node* left;
	Node* right;
};

Node* add(int number)
{
	Node* temp = new Node();
	temp->number = number;
	temp->left = NULL;
	temp->right = NULL;
	return temp;

}
void insert(Node*& currentRoot, Node* data)
{
	if (currentRoot == NULL)
	{
		currentRoot = data;
		return;
	}
	if(data->number < currentRoot->number&&currentRoot->left==NULL)
		insert(currentRoot->left, data);
	else
		insert(currentRoot->right, data);
	
}
void printThree(Node* currentRoot, int u)
{
	if (currentRoot == NULL)
		return;
	else
	{

		printThree(currentRoot->right, ++u);
		for (int i = 0; i < u; i++)
			cout << " ";
		std::cout << currentRoot->number << std::endl;
		printThree(currentRoot->left, ++u);
	}
}
Node* create(Node*& root)
{
	root = NULL;
	return root;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int choice;
	Node* root = NULL;
	do {
		cout << "1 - создать дерево\n";
		cout << "2 - добавить элемент\n";
		cout << "3 - вывод на экран\n";
		cout << "0 - exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:root = create(root);
			break;
		case 2:int n;
			cin >> n;
			insert(root, add(n));
			break;
		case 3:printThree(root, 0);
			break;
		}
	} while (choice != 0);
	return 0;
}

