#include <iostream>
using namespace std;

struct queue {
	int elements;
	queue* next;
};
struct queue1 {
	int elements1;
	queue1* next;
};

struct queue2 {
	int elements2;
	queue2* next;
};

void input(queue** begin, queue** end, int element);
void output(queue* begin,int size);
void del(queue** begin, queue** end);
void newQueue(queue** begin, queue** end, queue** begin1, queue** begin2, queue** end1, queue** end2, int size);

int main() {

	queue* begin = NULL, * end, * t, * t1, * t2, *begin1=NULL,*end1, * begin2 = NULL, * end2;
	t = new queue;
	t1 = new queue;
	t2 = new queue;
	int element, size;

	cout << "Enter size of queue: ";
	cin >> size;
	cout << "Enter a element: ";
	cin >> element;

	t->elements = element;
	t->next = NULL;
	begin = end = t;

	t1->next = NULL;
	begin1 = end1 = t;
	t2->next = NULL;
	begin2 = end2 = t;

	for (int i=1; i < size; i++) {
		cout << "Enter a element: ";
		cin >> element;
		if (element % 2 == 0) {
			input(&begin1, &end1, element);
		}
		else {
			input(&begin2, &end2, element);
		}
		input(&begin, &end, element);
	}

	cout << "Elements of queue: " << endl;
	if (begin == NULL) {
		cout << "Queue is empty" << endl;
	}
	else {
		output(begin,size);
	}

	//newQueue(&begin, &end, &begin1, &begin2,&end1,&end2, size);
	
	output(t1,size);
	output(t2,size);

	cout << "Delete: " << t->elements;
	del(&begin, &end);
}

void input(queue** begin, queue** end, int element) {
	queue* t = *begin;
	t->next = NULL;
	if (*begin == NULL) {
		*begin = *end = t;
	}
	else {
		t->elements = element;
		(*end)->next = t;
		*end = t;
	}
}

void output(queue*begin,int size) {
	queue* t = begin;
	if (t == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}
	else {
		for (int i = 1; i <= size;i++) {
			cout << t->elements << endl;
			t = t->next;
		}
	}
}

void del(queue** begin, queue** end) {
	queue* t = *begin;
	if (t == NULL) {
		cout << "Queue is empty." << endl;
		return;
	}
	else
	{
		*begin = (*begin)->next; //начало очереди переназначается на след. элемент//
		delete t; //удаление//
	}

	if (t == NULL) { //если после удаления начало очереди - NULL//
		*end = NULL; //конец очереди обнуляется//
	}

}

//void newQueue(queue**begin, queue**end, int element) {
	
//	queue1* begin1 = NULL, * end1,*t;
//	/*queue2* begin2 = NULL, * end2,*t;*/
//
//	/*begin1 = end1 = t;*/
//	//queue1* t = new queue1;
//	//t->next = NULL;
//	//queue2* t = new queue2;
//	//t->next = NULL;
//	/*queue* t = *begin;*/
//
//	int a = 0;
//	while (t != NULL) {  
//		a++;
//		t=t->next;
//	}
//	for (int j = 0; j < a; j++) {
//		if (element % 2 == 0) {
//			queue1* t = new queue1;
//			t->next = NULL;
//			if (begin1 == NULL) {
//				begin1 = end1 = t;
//			}
//			else {
//				t->elements1 = element;
//				end1->next = t;
//				end1 = t;
//			}
//		}
//	/*	else {
//			queue2* t = new queue2;
//			t->next = NULL;
//			if (begin2 == NULL) {
//				begin2 = end2 = t;
//			}
//			else {
//				t->elements2 = element;
//				end2->next = t;
//				end2 = t;
//			}
//		}*/
//	}
//	cout << "Elements of queue 1:" << endl;
//	if (t == NULL) {
//		cout << "Queue is empty" << endl;
//		return;
//	}
//	else {
//		while (t != NULL) {
//			cout << t->elements1 << endl;
//			t = t->next;
//		}
//	}
//
//	/*cout << "Elements of queue 2:" << endl;
//	if (t == NULL) {
//		cout << "Queue is empty" << endl;
//		return;
//	}
//	else {
//		while (t != NULL) {
//			cout << t->elements2 << endl;
//			t = t->next;
//		}
//	}*/
//}


//void newQueue(queue** begin, queue** end, int element, int size) {
//	queue1* begin1 = NULL, * end1;
//	queue1* t = new queue1;
//	t->next = NULL;
//
//	if (element % 2 == 0) {
//		if (begin1 == NULL) {
//			begin1 = end1 = t;
//		}
//		else {
//			t->elements1 = element;
//				end1->next = t;
//				end1 = t;
//		}
//	}
//
//	/*if (t == NULL) {
//		cout << "Queue is empty" << endl;
//		return;
//	}
//	else {
//		while (t != NULL) {
//			cout << t->elements1<< endl;
//			t = t->next;
//		}
//	}*/
//}

//void newQueue(queue** begin, queue** end, queue** begin1, queue** begin2, queue** end1, queue** end2, int size) {
//	queue* t = *begin;
//	/*queue** begin1 = begin1, begin2 = begin2, queue** end1, queue** end2;*/
//	if (t == NULL) {
//		cout << "Queue is empty." << endl;
//		return;
//	}
//	for (int i = 1; i <= size; i++) {
//		if (t->elements % 2 == 0) {
//			input(begin1, end1, t->elements);
//		}
//		else {
//			input(begin2, end2, t->elements);
//		}
//		t = t->next;
//	}
//}
