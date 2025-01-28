#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
	char data;
	Node* next;
};

struct Queue
{
	Node* head;
	Node* tail;
};

void CreateQueue(Queue* q);
void Symbol(Queue* Letter, Queue* Number);

int main()
{
	Queue Letter;
	Queue Number;
	CreateQueue(&Letter);
	CreateQueue(&Number);
	Symbol(&Letter, &Number);
	return 0;
}


void CreateQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void Enqueue(Queue* q, char data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	if (q->tail == NULL)
	{
		q->head = newNode;
		q->tail = newNode;
	}
	else
	{
		q->tail->next = newNode;
		q->tail = newNode;
	}
}

void Symbol(Queue* Letter, Queue* Number)
{
	ifstream f("First.txt");
	ofstream g("Second.txt");
	string line;
	char symbol;
	getline(f, line);
	cout << "Stroke: " << line << endl;
	for (int i = 0; i < line.length(); i++) {
		symbol = line[i];
		if ((symbol >= 97 && symbol <= 122) || (symbol >= 65 && symbol <= 90)) {
			Enqueue(Letter, symbol);
		}
		if (symbol >= 48 && symbol <= 57) {
			Enqueue(Number, symbol);
		}
	}

	Node* line1 = Letter->head;
	Node* line2 = Number->head;
	cout << "Letters: " << endl;
	while (line1) {
		cout << line1->data;
		g << line1->data;
		line1 = line1->next;
	}
	cout << endl;
	cout << "Numbers: " << endl;
	while (line2) {
		cout << line2->data;
		g << line2->data;
		line2 = line2->next;
	}
	cout << endl;

	f.close();
	g.close();
}
