﻿#include "Heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод 1 кучи на экран" << endl;
		cout << "2 - добавить элемент в 1 кучу" << endl;
		cout << "3 - удалить минимальный элемент 1 кучи" << endl;
		cout << "4 - вывод 2 кучи на экран" << endl;
		cout << "5 - добавить элемент во 2 кучу" << endl;
		cout << "6 - объединение 2-ух куч" << endl;
		cout << "7 - удалить i-й элемент 1 кучи" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2: {	
			AAA* a = new AAA;
			cout << "введите ключ" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:   h1.extractMax();
			break;
		case 4:
			break;
		case 5: 
			break;
		case 6:
			break;
		case 7:
			break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}
