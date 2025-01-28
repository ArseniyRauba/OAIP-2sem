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
void input1(queue1** begin1, queue1** end1, int element);
void input2(queue2** begin2, queue2** end2, int element);
void output(queue* begin);
void output1(queue1* begin1);
void output2(queue2* begin2);
void del(queue** begin, queue** end);
void newQueue(queue** t, int element, int size);

int main() {

	queue* begin = NULL, * end, * t;
	t = new queue;
	int element, size;

	cout << "Enter size of queue: ";
	cin >> size;
	cout << "Enter a element: ";
	cin >> element;

	t->elements = element;
	t->next = NULL;
	begin = end = t;


	for (int i = 1; i < size; i++) {
		cout << "Enter a element: ";
		cin >> element;
		input(&begin, &end, element);
	}

	cout << "Elements of queue: " << endl;
	if (begin == NULL) {
		cout << "Queue is empty" << endl;
	}
	else {
		output(begin);
	}

	newQueue(&t, element, size);

	/*cout << "Delete: " << t->elements;
	del(&begin, &end);*/

}

void input(queue** begin, queue** end, int element) {
	queue* t = new queue;
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

void input1(queue1** begin1, queue1** end1, int element) {
	queue1* t1 = new queue1;
	t1->next = NULL;
	t1->elements1 = element;
	if (*begin1 == NULL) {
		*begin1 = *end1 = t1;
	}
	else {
		
		(*end1)->next = t1;
		*end1 = t1;
	}
}

void input2(queue2** begin2, queue2** end2, int element) {
	queue2* t2= new queue2;
	t2->next = NULL;
	t2->elements2 = element;
	if (*begin2 == NULL) {
		*begin2 = *end2 = t2;
	}
	else {
		(*end2)->next = t2;
		*end2 = t2;
	}
}

void output(queue* begin) {
	queue* t = begin;
	if (t == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}
	else {
		while (t != NULL) {
			cout << t->elements << endl;
			t = t->next;
		}
	}
}

void output1(queue1* begin1) {
	queue1* t1 = begin1;
	if (t1 == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}
	else {
		while (t1 != NULL) {
			cout << t1->elements1 << endl;
			t1 = t1->next;
		}
	}
}

void output2(queue2* begin2) {
	queue2* t2 = begin2;
	if (t2 == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}
	else {
		while (t2 != NULL) {
			cout << t2->elements2 << endl;
			t2 = t2->next;
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

void newQueue(queue**t,int element,int size) {
	queue1* begin1 = NULL, * end1, * t1;
	t1 = new queue1;

	queue2* begin2 = NULL, * end2, * t2;
	t2 = new queue2;

	while (*t != NULL) {
		if ((*t)->elements % 2 == 0) {
			input1(&begin1, &end1, (*t)->elements);
		}
		else {
			input2(&begin2, &end2,(*t)->elements);
		}
		*t = (*t)->next;
	}
	cout << "Queue1 (%2==0):" << endl;
	output1( begin1);
	cout << "Queue2 (%2!=0):" << endl;
	output2(begin2);
}