struct Stack
{
	int data;             //�������������� �������
	Stack* head;		 //������� ����� 
	Stack* next;		 //��������� �� ��������� �������
};

void show(Stack* myStk);         //��������
int pop(Stack* myStk);           //��������
void push(int x, Stack* myStk);	 //��������
void removeMoreThan100(Stack* myStk);
void clear(Stack* myStk);
void writeToFile(Stack* myStk);
void readFromFile(Stack* myStk);
