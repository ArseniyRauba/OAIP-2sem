#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
#define size 30

//Обьявление функций
void enter();//для ввода
void print();//для вывода
void clear();//для очистки
void search();//для поиска
void write();//для записи в файл
void read();//для чтения из файла

//структура для хранения информации о студенте
struct Student{
	char name[10], secName[10], surname[10], specialization[30], faculty[50], date[8];
	int group;
	float averageScore;
};
struct Student list_of_student[size];
struct Student del;

int current_size = 0, choice;

void enter() { //функция для ввода
	setlocale(LC_ALL, "rus");
	cout << "Ввод информации: ";
	if (current_size < size) {

		cout << "Строка номер: ";
		cout << current_size + 1 << endl;

		cout << "Введите фамилию:";
		cin >> list_of_student[current_size].secName;

		cout << "Введите имя:";
		cin >> list_of_student[current_size].name;

		cout << "Введите отчество:";
		cin >> list_of_student[current_size].surname;

		cout << "Введите дату поступления:";
		cin >> list_of_student[current_size].date;

		cout << "Введите факультет:";
		cin >> list_of_student[current_size].faculty;

		cout << "Введите специальность:";
		cin >> list_of_student[current_size].specialization;

		cout << "Введите группу:";
		cin >> list_of_student[current_size].group;

		cout << "Введите средний балл:";
		cin >> list_of_student[current_size].averageScore;

		current_size++;
	}
	else cout << "Введено максимальное кол-во строк";
}

void print() {//функция для вывода
	setlocale(LC_ALL, "rus");
	int sw, n;
	cout << "1-вывод 1 студента" << endl;
	cout << "2-вывод всех студентов" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимого студента " << endl;   cin >> n;  cout << endl;

		cout << "ФИО: ";
		cout << list_of_student[n - 1].secName << " " << list_of_student[n - 1].name << " " << list_of_student[n - 1].surname << endl;

		cout << "Дата поступления: ";
		cout << list_of_student[n - 1].date << endl;

		cout << "Факультет: ";
		cout << list_of_student[n - 1].faculty << endl;

		cout << "Специальность: ";
		cout << list_of_student[n - 1].specialization << endl;

		cout << "Группа: ";
		cout << list_of_student[n - 1].group << endl;

		cout << "Средний балл: ";
		cout << list_of_student[n - 1].averageScore << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "ФИО: ";
			cout << list_of_student[i].secName << " " << list_of_student[i].name << " " << list_of_student[i].surname << endl;

			cout << "Дата поступления: ";
			cout << list_of_student[i].date << endl;

			cout << "Факультет: ";
			cout << list_of_student[i].faculty << endl;

			cout << "Специальность: ";
			cout << list_of_student[i].specialization << endl;

			cout << "Группа: ";
			cout << list_of_student[i].group << endl;
			
			cout << "Средний балл: ";
			cout << list_of_student[i].averageScore << endl;
		}
	}

}

void clear() {//функция для очистки
	setlocale(LC_ALL, "rus");
	if (current_size == 0)
	{
		cout << "Вы еще не ввели ни одного студента" << endl << endl;
		return;
	}

	int delchoice;
	cout << "1 - удалить информацию об определенной студенте" << endl
		<< "2 - удалить информацию о всех записанных студентах" << endl
		<< "Выберите вариант выполнения программы: ";
	cin >> delchoice;
	if (delchoice == 1)
	{
		int del;
		cout << "Какого студента хотите удалить";
		cin >> del;
		for (int i = (del - 1); i < current_size ; i++)
		{
			list_of_student[i] = list_of_student[i + 1];
		}
		current_size--;
		cout << "Информация о выбранном студенте успешно удалена!" << endl << endl;
	}

	if (delchoice == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			list_of_student[i].secName[0] = '\0';
			list_of_student[i].name[0] = '\0';
			list_of_student[i].surname[0] = '\0';
			list_of_student[i].date[0] = '\0';
			list_of_student[i].faculty[0] = '\0';
			list_of_student[i].specialization[0] = '\0';
			list_of_student[i].group = 0;
			list_of_student[i].averageScore = 0.0;
		}
		current_size = 0;
		cout << "Информация обо всех студентах успешно удалена! " << endl << endl;
	}
 
}

void search() {//функция для поиска
	setlocale(LC_ALL, "rus");
	char stud[30];
	bool found = false;

	if (current_size == 0)
	{
		cout << "Вы еще не ввели ни одного студента" << endl << endl;
		return;
	}

	cout << "Введите фамилию студента, о котором вам нужна информация: ";
	cin >> stud;
	for (int i = 0; i < current_size; i++)
	{
		if (strcmp(list_of_student[i].secName, stud) == 0)
		{
			found = true;
			cout << "ФИО: ";
			cout << list_of_student[i].secName << " " << list_of_student[i].name << " " << list_of_student[i].surname << endl;

			cout << "Дата поступления: ";
			cout << list_of_student[i].date << endl;

			cout << "Факультет: ";
			cout << list_of_student[i].faculty << endl;

			cout << "Специальность: ";
			cout << list_of_student[i].specialization << endl;

			cout << "Группа: ";
			cout << list_of_student[i].group << endl;

			cout << "Средний балл: ";
			cout << list_of_student[i].averageScore << endl;
			break;
		}
	}

	if (!found)
	{
		cout << "Студент с фамилией " << stud << " не найден" << endl << endl;
	}

}

void write() {//функция для записи в файл
	setlocale(LC_ALL, "rus");
	if (current_size == 0)
	{
		cout << "Вы еще не ввели ни одного студента" << endl << endl;
		return;
	}

	ofstream fout("file.txt");

	if (!fout.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		return;
	}

	for (int i = 0; i < current_size; i++) {

		fout << "ФИО: ";
		fout << list_of_student[i].secName << list_of_student[i].name << list_of_student[i].surname << endl;

		fout << "Дата поступления: ";
		fout << list_of_student[i].date << endl;

		fout << "Факультет: ";
		fout << list_of_student[i].faculty << endl;

		fout << "Специальность: ";
		fout << list_of_student[i].specialization << endl;

		fout << "Группа: ";
		fout << list_of_student[i].group << endl;

		fout << "Средний балл: ";
		fout << list_of_student[i].averageScore << endl;
	}

	cout << "Данные успешно записаны!" << endl << endl;
	fout.close();
}

void read() {//функция для чтения из файла
	setlocale(LC_ALL, "rus");
	char buff[50];
	ifstream fin("file.txt");

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла! " << endl;
		return;
	}

	while (fin.getline(buff, 50))
	{
		cout << buff << endl;
	}

	fin.close();
}


int main() {//основная функция

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "rus");

	int choice;

	do {//вывод меню выбора
		cout << "1 - добавить нового студента" << endl;
		cout << "2 - вывод введенных студентов" << endl;
		cout << "3 - удалить введенных студентов" << endl;
		cout << "4 - вывод информации по фамилии" << endl;
		cout << "5 - запись введенных данных в файл" << endl;
		cout << "6 - прочитать данные из файла" << endl;
		cout << "7 - выход из программы" << endl;
		cout << "Введите вариант выполнения программы: ";
		cin >> choice;
		cout << endl;

		switch (choice) {//обработка выбора
		case 1:
			enter();
			break;
		case 2:
			print();
			break;
		case 3:
			clear();
			break;
		case 4:
			search();
			break;
		case 5:
			write();
			break;
		case 6:
			read();
			break;
		case 7:
			system("exit");
			break;
		}
	} while (choice != 7);
}