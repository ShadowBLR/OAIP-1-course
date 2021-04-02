#pragma once
#include <cstddef>
#define HASHDEL (void*) -1
struct Object//хеш-таблица
{
	void** data;
	Object(int size, char* (*getkey)(void*))//конструктор
	{
		N = 0;
		this->size = size;
		this->getKey = getkey;
		this->data = new void* [size];//массив указателей
		for (int i = 0; i < size; ++i)
			data[i] = NULL;
	};
	int size;  int N;
	char* (*getKey)(void*);//вернуть ключ
	bool insert(void*);//добавить элемент
	int searchInd(char* key);//поиск индекса по ключу
	void* search(char* key);//если найден элемент,то возвращает его,если нет,то возвращает 0
	void* deleteByKey(char* key);//удалить по ключу
	bool deleteByValue(void*);
	void scan(void(*f)(void*));
};
static void* DEL = (void*)HASHDEL;//присваиваем переменной DEL -1
Object create(int size, char* (*getkey)(void*));//создание таблицы
#undef HASHDEL
