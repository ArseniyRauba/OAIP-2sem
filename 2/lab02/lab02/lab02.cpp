#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	FILE* fileA, * fileB;

	fopen_s(&fileA, "fileA.txt", "r"); // открытие первого файла для чтения

	if (fileA == NULL) { // проверка файла при открытии
		printf("Ошибка открытия 1 файла\n");
		return -1;
	}

	fopen_s(&fileB, "fileB.txt", "w"); // открытие второго файла для чтения

	if (fileB == NULL) { // проверка файла при открытии
		printf("Ошибка открытия 2 файла\n");
		return -1;
	}

	int num, unique_num = 0;
	int unique_numbers[100];

	while (fscanf_s(fileA, "%d", &num) != EOF) {
		int counter = 0;

		for (int i = 0; i < unique_num; i++) {
			if (unique_numbers[i] == num) { // проверка на повторяющиеся цифры
				counter = 1;
				break;
			}
		}

		if (counter == 0) {
			unique_numbers[unique_num] = num;
			unique_num++;
		}
	}

	for (int i = 0; i < unique_num; i++) { // запись цифр без повтора во второй файл
		fprintf_s(fileB, "%d ", unique_numbers[i]);
	}

	printf("Программа выполнена успешно");

	fclose(fileA); // закрытие 1 файла
	fclose(fileB); // закрытие 2 файла

	return 0;
}