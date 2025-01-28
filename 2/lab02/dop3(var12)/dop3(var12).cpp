// 1 задание
#include<stdio.h>
#include<string>	
#include<iostream>
using namespace std;

void main()
{
	int k;
	string gg;

	char row[50];
	FILE* f, * f2;

	fopen_s(&f, "f.txt", "r"); // открытие файла только для чтения
	cout << "num of srt: ";
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		fgets(row, 50, f); // пропуск строк до нужной
	}
	fgets(row, 50, f);


	fopen_s(&f2, "f2.txt", "w"); // открытие файла только для записи
	fprintf(f2, "%s", row);


	fclose(f); // закрытие 1 файла
	fclose(f2); // закрытие 2 файла

	printf("program run success");
}

// 2 задание
#include<iostream>
#include<stdio.h>
using namespace  std;

void main()
{

#include<stdio.h>

	setlocale(LC_ALL, "rus");

	int A[100], B[100], C[100], i, j, size, count, num, min;
	charrow[50];

	FILE* file1, * file2, * file3, * file4;

	fopen_s(&file1, "NameA.bin", "r");
	fopen_s(&file2, "NameB.bin", "r");
	fopen_s(&file3, "NameC.bin", "r");


	fseek(file1, 0L, SEEK_END);
	size = ftell(file1);
	fseek(file1, 0L, SEEK_SET);


	fgets(row, size, file1);
	count = 0;

	for (i = 0; i < size; i++)
	{
		if (row[i] == ' ') { count += 1; }
	}

	count += 1;
	cout << count << endl;

	fseek(file1, 0L, SEEK_SET);

	for (i = 0; i < count; i++)
	{
		fscanf_s(file1, "%d", &num);
		A[i] = num;
	}

	for (i = 0; i < count; i++)
	{
		fscanf_s(file2, "%d", &num);
		B[i] = num;
	}

	for (i = 0; i < count; i++)
	{
		fscanf_s(file3, "%d", &num);
		C[i] = num;
	}

	fclose(file1);
	fclose(file2);
	fclose(file3);

	fopen_s(&file4, "NameD.bin", "w+");

	for (i = 0; i < count; i++)
	{
		min = A[i];
		if (B[i] < min) min = B[i];
		if (C[i] < min) min = C[i];
		fprintf(file4, "%d ", min);
	}

	fclose(file4);

}
