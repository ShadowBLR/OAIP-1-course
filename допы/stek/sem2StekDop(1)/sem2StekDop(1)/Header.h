struct Stack
{
	char data;             //�������������� �������
	Stack* head;		 //������� ����� 
	Stack* next;		 //��������� �� ��������� �������
};

void show(Stack* myStk);         //��������
int pop(Stack* myStk);           //��������
void push(char x, Stack* myStk,int count);	 //��������
void removeMoreThan100(Stack* myStk);
void clear(Stack* myStk);
void writeToFile(Stack* myStk);
//void readFromFile(Stack* myStk);
void showNewStack(Stack*myStk, int count);

