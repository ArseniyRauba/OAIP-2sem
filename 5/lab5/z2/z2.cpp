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

union student { // объединение
	char name[10];
	char secName[10];
	char surname[10];
	char subjects[100];
	int score[3];
	float average_score;
};

//структура для хранения информации о студенте
struct Student {
	student name;
	student secName;
	student surname;
	student subjects;
	student score;
	student average_score;
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
		cin >> list_of_student[current_size].secName.secName;

		cout << "Введите имя:";
		cin >> list_of_student[current_size].name.name;

		cout << "Введите отчество:";
		cin >> list_of_student[current_size].surname.surname;

		cout << "Введите предметы:";
		cin >> list_of_student[current_size].subjects.subjects;

		cout << "Введите отметки:";
		for (int i = 0; i < 3; i++) {
			cin >> list_of_student[current_size].score.score[i];
		}

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

	if (sw == 1) {
		cout << "Номер выводимого студента " << endl;   cin >> n;  cout << endl;

		cout << "ФИО: ";
		cout << list_of_student[n - 1].secName.secName << " " << list_of_student[n - 1].name.name << " " << list_of_student[n - 1].surname.surname << endl;

		cout << "Предметы: ";
		cout << list_of_student[n - 1].subjects.subjects << endl;

		cout << "Отметки: ";
		for (int i = 0; i < 3; i++) {
			cout << list_of_student[n - 1].score.score[i];
		}
		cout << endl;
		for (int i=0; i < 3; i++) {
			list_of_student[n - 1].average_score.average_score = list_of_student[n - 1].average_score.average_score + list_of_student[n - 1].score.score[i];
		}

		cout << "Средний балл: " << (list_of_student[n - 1].average_score.average_score)/3 << endl;

	}
	if (sw == 2) {
		for (int i = 0; i < current_size; i++)
		{
			cout << "ФИО: ";
			cout << list_of_student[i].secName.secName << " " << list_of_student[i].name.name << " " << list_of_student[i].surname.surname << endl;

			cout << "Предметы: ";
			cout << list_of_student[i].subjects.subjects << endl;

			cout << "Отметки: ";
			for (int i = 0; i < 3; i++) {
				cout << list_of_student[i].score.score[i];
			}
			cout << endl;

			for (int i=0; i < 3; i++) {
				list_of_student[i].average_score.average_score = list_of_student[i].average_score.average_score + list_of_student[i].score.score[i];
			}

			cout << "Средний балл: " << list_of_student[n - 1].average_score.average_score << endl;
			
		}
	}

}

void clear() {//функция для очистки
	setlocale(LC_ALL, "rus");

	if (current_size == 0)
	{
		cout << "Вы еще не ввели ни одного ученика" << endl << endl;
		return;
	}

	int delchoice;
	cout << "1 - удалить информацию об определенной ученике" << endl
		<< "2 - удалить информацию о всех записанных учениках" << endl
		<< "Выберите вариант выполнения программы: ";
	cin >> delchoice;

	if (delchoice == 1)
	{
		int del;
		cout << "Какого студента хотите удалить";
		cin >> del;
		for (int i = (del - 1); i < current_size; i++)
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
			list_of_student[i].secName.secName[0] = '\0';
			list_of_student[i].name.name[0] = '\0';
			list_of_student[i].surname.surname[0] = '\0';
			list_of_student[i].subjects.subjects[0] = '\0';
			list_of_student[i].average_score.average_score = 0;
		}
		current_size = 0;
		cout << "Информация обо всех учениках успешно удалена! " << endl << endl;
	}

}

void search() {//функция для поиска
	setlocale(LC_ALL, "rus");
	char stud[30];
	bool found = false;

	if (current_size == 0)
	{
		cout << "Вы еще не ввели ни одного ученика" << endl << endl;
		return;
	}

	cout << "Введите фамилию ученика, о котором вам нужна информация: ";
	cin >> stud;
	for (int i = 0; i < current_size; i++)
	{
		if (strcmp(list_of_student[i].secName.secName, stud) == 0)
		{
			found = true;
			cout << "ФИО: ";
			cout << list_of_student[i].secName.secName << " " << list_of_student[i].name.name << " " << list_of_student[i].surname.surname << endl;

			cout << "Предметы: ";
			cout << list_of_student[i].subjects.subjects << endl;

			cout << "Отметки: ";
			for (int i = 0; i < 3; i++) {
				cout << list_of_student[i].score.score[i];
			}
			cout << endl;
		
			cout << "Средний балл: ";
			cout << list_of_student[i].average_score.average_score << endl;
			break;
		}
	}

	if (!found)
	{
		cout << "Ученик с фамилией " << stud << " не найден" << endl << endl;
	}

}

void write() {//функция для записи в файл
	setlocale(LC_ALL, "rus");
	if (current_size == 0)
	{
		cout << "Вы еще не ввели ни одного ученика" << endl << endl;
		return;
	}

	ofstream fout("file.txt");

	if (!fout.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		return;
	}

	for (int i = 0; i < current_size; i++) {

		fout << "ФИО: ";
		fout << list_of_student[i].secName.secName << list_of_student[i].name.name << list_of_student[i].surname.surname << endl;

		fout << "ФИО: ";
		fout << list_of_student[i].secName.secName << " " << list_of_student[i].name.name << " " << list_of_student[i].surname.surname << endl;

		fout << "Предметы: ";
		fout << list_of_student[i].subjects.subjects << endl;

		fout << "Отметки: ";
		for (int i = 0; i < 3; i++) {
			fout << list_of_student[i].score.score[i];
		}
		fout << endl;
		for (int i=0; i < 3; i++) {
			list_of_student[i].average_score.average_score = list_of_student[i].average_score.average_score + list_of_student[i].score.score[i];
		}

		fout << "Средний балл: " << list_of_student[i].average_score.average_score << endl;;
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
		cout << "1 - добавить нового ученика" << endl;
		cout << "2 - вывод введенных учеников" << endl;
		cout << "3 - удалить введенных учеников" << endl;
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