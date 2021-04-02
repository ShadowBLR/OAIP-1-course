struct Stack
{
	char data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};

void show(Stack* myStk);         //прототип
int pop(Stack* myStk);           //прототип
void push(char x, Stack* myStk,int count);	 //прототип
void removeMoreThan100(Stack* myStk);
void clear(Stack* myStk);
void writeToFile(Stack* myStk);
//void readFromFile(Stack* myStk);
void showNewStack(Stack*myStk, int count);

