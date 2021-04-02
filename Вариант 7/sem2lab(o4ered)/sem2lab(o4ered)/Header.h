#pragma once
struct Number
{
	int info;
	Number* next;
};

void showQueue(Number** begin);
void addElement(Number** begin, Number** tail);
void delEndQueue(Number** begin, Number** tail, int number);