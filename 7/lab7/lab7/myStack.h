#pragma once
struct Stack1
{
	int data1;     //информационный элемент
	Stack1* next;   //указатель на следующий элемент
};

struct Stack2
{
	int data2;
	Stack2* next;
};

struct Stack3
{
	int data3;
	Stack3* next;
};

char popStack1(Stack1*& myStk1);
char popStack2(Stack2*& myStk2);
void push1(int x, Stack1*& myStk1);
void push2(int y, Stack2*& myStk2);
void push3(Stack3*& myStk3, Stack1*& myStk1, Stack2*& myStk2);
void toFile(Stack1*& myStk1);
void fromFile(Stack1*& myStk1);