#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	FILE* F1, * F2;

	fopen_s(&F1, "F1.txt", "r"); // открытие первого файла для чтения

	if (F1 == NULL) { // проверка файла при открытии
		printf("Ошибка открытия 1 файла\n");
		return -1;
	}

	fopen_s(&F2, "F2.txt", "w"); // открытие второго файла для чтения

	if (F2 == NULL) { // проверка файла при открытии
		printf("Ошибка открытия 2 файла\n");
		return -1;
	}

	char string[100];
	int number;

	printf("Введите число\n");
	scanf_s("%d", &number); // ввод числа с клавиатуры

	while (fgets(string, sizeof(string), F1) != NULL) { // проверка строки из 1 файла и запись строки во 2 файл
		if (strlen(string) > number) {
			fprintf_s(F2, "%s ", string);
		}
	}

	printf("Программа выполнена успешно");

	fclose(F1); // закрытие 1 файла
	fclose(F2); // закрытие 2 файла

}