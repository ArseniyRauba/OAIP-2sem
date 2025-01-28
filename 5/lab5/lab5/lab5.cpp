#include <iostream>
#include <Windows.h>
using namespace std;

void railway_station();
void print();
void search();
void delete_info();

enum Edays{ //перечисление
	monday=1, tuesday,wednesday,thusday,friday,saturday,sunday
}day;

struct Time{ //битовое поле для времени
	int hours: 4;
	int minutes: 4;
};

struct Train { //структура для хранения информации
	string number;
	string destination;
	string days;
	string departure_time;
	string arrival_time;
};

const int maxTrains = 50;
int trainCount = 1;
Train trains[maxTrains]; 
 
void railway_station() {//ф-ция для ввода
	setlocale(LC_ALL, "rus");
	cout << "Ввод информации: ";
	for (int i = 0; i < trainCount; i++) {

		cout << "Введите номер поезда:";
		cin >> trains[i].number;

		cout << "Введите место прибывания:";
		cin >> trains[i].destination;

		int choice;
		cout << "Введите день (1 - пн, 2 - вт, 3 - ср, 4 - чт, 5 - пт, 6 - сб, 7 - вс):";
		cin >> choice;

		switch(choice) {
		case 1:
			trains[i].days = monday;
			break;
		case 2:
			trains[i].days = tuesday;
			break;
		case 3:
			trains[i].days = wednesday;
			break;
		case 4:
			trains[i].days = thusday;
			break;
		case 5:
			trains[i].days = friday;
			break;
		case 6:
			trains[i].days = saturday;
			break;
		case 7:
			trains[i].days = sunday;
			break;
		default:
			cout << "Error" << endl;
			break;
		}

		cout << "Введите время отправления:";
		cin >> trains[i].departure_time;

		cout << "Введите прибывания:";
		cin >> trains[i].arrival_time;
	}
}

void print() {//ф-ция для вывода
	setlocale(LC_ALL, "rus");
	int sw, n;
	cout << "1-вывод 1 расписания" << endl;
	cout << "2-вывод всех расписаний" << endl;
	cin >> sw;
	if (sw == 1) {

		cout << "Номер поезда: ";
		cout << trains[trainCount].number << endl;

		cout << "Место назначения: ";
		cout << trains[trainCount].destination << endl;

		cout << "День: ";
		cout << trains[trainCount].days << endl;

		cout << "Время отправления: ";
		cout << trains[trainCount].departure_time << endl;

		cout << "Время прибытия: ";
		cout << trains[trainCount].arrival_time << endl;
	}
	if (sw == 2) {

		for (int i = 0; i < trainCount; i++) {

			cout << "Расписание номер: " << i + 1;

			cout << "Номер поезда: ";
			cout << trains[i].number << endl;

			cout << "Место назначения: ";
			cout << trains[i].destination << endl;

			cout << "День: ";
			cout << trains[i].days << endl;

			cout << "Время отправления: ";
			cout << trains[i].departure_time << endl;

			cout << "Время прибытия: ";
			cout << trains[i].arrival_time << endl;
		}
	}

}

void search() {//ф-ция для поиска
	setlocale(LC_ALL, "rus");
	string nameStation;
	bool found = false;

	if (trainCount == 0)
	{
		cout << "Вы еще не ввели ни одного студента" << endl << endl;
		return;
	}

	cout << "Введите место назначения поезда, о котором вам нужна информация: ";
	cin >> nameStation;
	for (int i = 0; i < trainCount; i++)
	{
		if (trains[1].destination == nameStation) {
			found = true;
			cout << "Номер поезда: ";
			cout << trains[trainCount].number << endl;

			cout << "Место назначения: ";
			cout << trains[trainCount].destination << endl;

			cout << "День: ";
			cout << trains[trainCount].days << endl;

			cout << "Время отправления: ";
			cout << trains[trainCount].departure_time << endl;

			cout << "Время прибытия: ";
			cout << trains[trainCount].arrival_time << endl;
			break;
		}
	}

	if (!found)
	{
		cout << "Поезд не найден ";
	}

}

void delete_info() {//ф-ция для удаления
	setlocale(LC_ALL, "rus");
	if (trainCount == 0)
	{
		cout << "Вы еще не ввели ни одного поезда" << endl << endl;
		return;
	}

	int delchoice;
	cout << "1 - удалить информацию об определенном поезде" << endl
		<< "2 - удалить информацию о всех записанных поездах" << endl
		<< "Выберите вариант выполнения программы: ";
	cin >> delchoice;
	if (delchoice == 1)
	{
		int del;
		cout << "Какой поезд хотите удалить";
		cin >> del;
		for (int i = (del - 1); i < trainCount; i++)
		{
			trains[i] = trains[i + 1];
		}
		trainCount--;
		cout << "Информация о выбранном поезде успешно удалена!" << endl << endl;
	}

	if (delchoice == 2)
	{
		for (int i = 0; i < trainCount; i++)
		{
			trains[i].number[0] = '\0';
			trains[i].destination[0] = '\0';
			trains[i].days[0] = '\0';
			trains[i].departure_time[0] = '\0';
			trains[i].arrival_time[0] = '\0';
		}
		trainCount = 0;
		cout << "Информация обо всех поездах успешно удалена! " << endl << endl;
	}

}

int main() {//основная функция

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "rus");

	int choice;

	do {//вывод меню выбора
		cout << "1 - добавить расписание поезда" << endl;
		cout << "2 - вывод введенных расписаний" << endl;
		cout << "3 - удалить введенные расписания" << endl;
		cout << "4 - поиск по пункту назначения" << endl;
		cout << "5 - выход из программы" << endl;
		cout << "Введите вариант выполнения программы: ";
		cin >> choice;
		cout << endl;

		switch (choice) {//обработка выбора
		case 1:
			railway_station();
			break;
		case 2:
			print();
			break;
		case 3:
			delete_info();
			break;
		case 4:
			search();
			break;
		case 5:
			system("exit");
			break;
		}
	} while (choice != 7);
}