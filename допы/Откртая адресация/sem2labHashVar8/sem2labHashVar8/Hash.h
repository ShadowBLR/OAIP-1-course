#pragma once
#include <cstddef>
#define HASHDEL (void*) -1
struct Object//���-�������
{
	void** data;
	Object(int size, char* (*getkey)(void*))//�����������
	{
		N = 0;
		this->size = size;
		this->getKey = getkey;
		this->data = new void* [size];//������ ����������
		for (int i = 0; i < size; ++i)
			data[i] = NULL;
	};
	int size;  int N;
	char* (*getKey)(void*);//������� ����
	bool insert(void*);//�������� �������
	int searchInd(char* key);//����� ������� �� �����
	void* search(char* key);//���� ������ �������,�� ���������� ���,���� ���,�� ���������� 0
	void* deleteByKey(char* key);//������� �� �����
	bool deleteByValue(void*);
	void scan(void(*f)(void*));
};
static void* DEL = (void*)HASHDEL;//����������� ���������� DEL -1
Object create(int size, char* (*getkey)(void*));//�������� �������
#undef HASHDEL
