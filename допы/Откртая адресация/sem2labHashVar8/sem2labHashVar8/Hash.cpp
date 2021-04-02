#include "Hash.h"
#include <iostream>
#include <string>
int HashFunction(char* key, int size)    //Хеширование ключа
{
	int h, a = 31415, b = 27183;
	for (h = 0; *key != 0; key++, a = a * b % (size - 1))
		h = (a * h + *key) % size;
	return (h < 0) ? (h + size) : h;
}
//-------------------------------
int Next_hash(char* key, int size, int l)
{
	int h, a = 31415, b = 27183;
	for (h = 0; *key != 0; key++, a = a * b % (size - 1))
		h = (a * h + *key) % size;
	return (h < 0) ? (h + size) : h;
}
//-------------------------------
Object create(int size, char* (*getkey)(void*))
{
	return *(new Object(size, getkey));
}
bool Object::insert(void* d)
{
	int l = 0;
	bool b = false;
	if (N != size)
		for (int i = 0, j = HashFunction(getKey(d), size);
			i != size && !b;  j = Next_hash(getKey(d), size, l++))
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
	return b;
}
//-------------------------------
int Object::searchInd(char* key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size); data[j] != NULL && i != size && !b; j = Next_hash(key, size, ++i))
			if (data[j] != DEL)
				if (strcmp(getKey(data[j]), key) == 0)
				{
					t = j; b = true;
				}
	return t;
}
//-------------------------------
void* Object::search(char* key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(char* key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				f((this->data)[i]);
	}
}
