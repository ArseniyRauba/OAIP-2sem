#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list {
	float num;
	list* next;
};

list* arrlist = nullptr; // указатель на начало списка
list* arr; // указатель на текущий элемент

void addElement();
void deleteElement();
void viewAll();
void average();
void write_to_file();
void read_from_file();

int main()
{
	int choice;

	do {
		cout << "Menu " << endl;
		cout << "1. Add element to list." << endl;
		cout << "2. Delete element." << endl;
		cout << "3. View all elements." << endl;
		cout << "4. Average of negative elements" << endl;
		cout << "5. Write list to file." << endl;
		cout << "6. Read list from file." << endl;
		cout << "7. Exit." << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			addElement();
			break;
		case 2:
			deleteElement();
			break;
		case 3:
			viewAll();
			break;
		case 4:
			average();
			break;
		case 5:
			write_to_file();
			break;
		case 6:
			read_from_file();
			break;
		case 7:
			cout << "Exit." << endl;
			break;
		default:
			cout << "Error." << endl;
			break;
		}
	} while (choice != 7);

	return 0;
}

//Функция для ввода элемента
void addElement()
{
	arr = new list; //Выделение памяти
	arr->next = arrlist;
	arrlist = arr;
	cout << "Enter number:";
	cin >> arr->num;
}

//Функция для удаления элемента
void deleteElement()
{
	int value;
	cin >> value;

	list* temp = arrlist, * temparrList = nullptr;

	arr = arrlist;

	while (arr)
	{
		if (arr->num != value)
		{
			temp = new list;
			temp->next = temparrList;
			temparrList = temp;
			temp->num = arr->num;

		}
		arr = arr->next;
	}

	arrlist = temparrList;

	while (temp)
	{
		arr = temp;
		temp = temp->next;
	}

	delete temp;
}

//Функция для отображения всех элементов списка
void viewAll()
{
	arr = arrlist;

	while (arr)
	{
		cout << arr->num << ' ';
		arr = arr->next;
	}

	cout << endl;
}

// Функция для среднего значения
void average()
{
	arr = arrlist;

	int counter=0;
	float avg=0;

	while (arr)
	{
		if (arr->num<0)
			avg += arr->num;
		arr = arr->next;
		counter++;
	}
	if (avg == 0)
		cout << "Element search error." << endl;

	else cout << "Average = " << avg/counter << endl;
}

//Функция для записи в файл
void write_to_file()
{
	ofstream file("file.txt");
	arr = arrlist;

	while (arr)
	{
		file << arr->num;
		arr = arr->next;
		file << ' ';
	}

	file << endl << endl;

	file.close();
}

//Функция для чтения из файла
void read_from_file()
{
	ifstream file("file.txt");
	string a;

	cout << endl;

	getline(file, a);
	cout << endl << a;

	getline(file, a);
	cout << endl << a << endl;

	file.close();
}
