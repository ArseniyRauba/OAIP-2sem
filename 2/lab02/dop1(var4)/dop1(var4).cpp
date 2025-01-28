// 1 задание
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//int main() {
//
//	setlocale(LC_ALL, "rus");
//
//	FILE* fileA, * fileB;
//
//	fopen_s(&fileA, "fileA.txt", "r"); // открытие первого файла для чтения
//
//	if (fileA == NULL) { // проверка файла при открытии
//		printf("Ошибка открытия 1 файла\n");
//		return -1;
//	}
//
//	fopen_s(&fileB, "fileB.txt", "w"); // открытие второго файла для чтения
//
//	if (fileB == NULL) { // проверка файла при открытии
//		printf("Ошибка открытия 2 файла\n");
//		return -1;
//	}
//
//	int num, unique_num = 0;
//	int unique_numbers[100];
//
//	while (fscanf_s(fileA, "%d", &num) != EOF) {
//		if (num > 0) { // проверка числа на отрицательность и запись по 2 файл
//			fprintf_s(fileB, "%d ", num);
//		}
//	}
//
//	printf("Программа выполнена успешно");
//
//	fclose(fileA); // закрытие 1 файла
//	fclose(fileB); // закрытие 2 файла
//
//	return 0;
//}

// 2 задание 
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

	int inputNum, num;

	cout << "Введите число: ";
	cin >> inputNum;

	while (fscanf_s(fileA, "%d", &num) != EOF) {
		if (num > inputNum) { // проверка числа и 1 файла с введенным и запись по 2 файл
			fprintf_s(fileB, "%d ", num);
		}
	}

	printf("Программа выполнена успешно");

	fclose(fileA); // закрытие 1 файла
	fclose(fileB); // закрытие 2 файла

	return 0;
}