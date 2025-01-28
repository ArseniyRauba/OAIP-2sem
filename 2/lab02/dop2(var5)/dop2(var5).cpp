// 1 задание
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	FILE* f, * f2, * f3;

	fopen_s(&f, "001.txt", "r"); // открытие первого файла для чтения

	if (f == NULL) { // проверка файла при открытии
		printf("error of opening first file\n");
		return -1;
	}

	fopen_s(&f2, "002.txt", "r"); // открытие второго файла для чтения

	if (f2 == NULL) { // проверка файла при открытии
		printf("error of opening second file\n");
		return -1;
	}

	int columns, check;

	fscanf_s(f, "%d", &columns); // запись первых чисел в переменные
	fscanf_s(f2, "%d", &check);

	if (check != columns) { // проверка для умножения матриц
		printf("error of multiplication");
		return -1;
	}

	rewind(f); // возвращение указателя
	rewind(f2);

	int matrix1[100][100];
	int matrix2[100][100];

	for (int i = 0; i < columns; i++) { // запись первой матрицы
		for (int j = 0; j < columns; j++) {
			fscanf_s(f, "%d", &matrix1[i][j]);
		}
	}

	for (int i = 0; i < columns; i++) { // запись второй матрицы
		for (int j = 0; j < columns; j++) {
			fscanf_s(f2, "%d", &matrix2[i][j]);
		}
	}

	fclose(f); // закрытие 1 файла
	fclose(f2); // закрытие 1 файла

	int matrix3[100][100];
	matrix3[0][0] = 0;

	for (int i = 0; i < columns; i++) { // вычисление произведения матриц
		for (int j = 0; j < columns; j++) {

			matrix3[i][j] = matrix1[i][j] * matrix1[i][j];

		}
	}

	fopen_s(&f3, "003.txt", "w"); // открытие третьего файла для записи

	if (f3 == NULL) { // проверка файла при открытии
		printf("error of opening last file\n");
		return -1;
	}

	for (int i = 0; i < columns; i++) { // запись произведения матриц
		for (int j = 0; j < columns; j++) {
			fprintf(f3, "%d", matrix3[i][j]);
			fprintf(f3, "  ");
		}
		fprintf(f3, "%c", '\n');
	}

	fclose(f3); // закрытие третьего файла

	printf("program run success");
	return 0;
}

// 2 задание
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {

	FILE* f, * f2;

	fopen_s(&f, "f.txt", "r"); // открытие первого файла для чтения

	if (f == NULL) { //проверка файла при открытиии//
		printf("error of opening first file");
		return -1;
	}

	fopen_s(&f2, "f2.txt", "w"); // открытие первого файла для записи

	if (f2 == NULL) { // проверка файла при открытии
		printf("error of opening second file");
		return -1;
	}

	char str[100];

	while (fgets(str, sizeof(str), f) != NULL) { // чтение файла построчно
		if (str[0] == 'a') {
			fprintf(f2, "%s", str); // запись во второй файл
		}
	}

	fclose(f); // закрытие 1 файла
	fclose(f2); // закрытие 2 файла

	printf("program run success\n");

	return 0;
}
