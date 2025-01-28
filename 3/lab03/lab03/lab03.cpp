//zadanie1
// 
//#include <iostream>
//#include <fstream>
//#include <Windows.h>
//#include <string>
//using namespace std;
//
//int main() {
//
//	setlocale(LC_ALL, "rus");
//
//	int n1, n2, counter = 0, num = 0;
//	string str;
//
//	cout << "Введите номер строки N1: ";
//	cin >> n1;
//	cout << "Введите номер строки N2: ";
//	cin >> n2;
//
//	ifstream fileF1; // инициализация файла для чтения
//	ofstream fileF2; // инициализация файла для записи
//
//	fileF1.open("fileF1.txt"); // открытие 1 файла
//	fileF2.open("fileF2.txt"); // открытие 2 файла
//
//	if (!fileF1.is_open() || !fileF2.is_open()) {  // проверка на ошибку открытия файлов
//		cout << "Ошибка открытия файла!" << endl;
//		return 1;
//	}
//
//	while (getline(fileF1, str)) {
//		if (num >= n1 && num <= n2) // условие проверки строк номера которых между n1 и n2
//		{
//			if (str[0] == 'C' || str[0] == 'c') // проверка строк на начаотную букву
//			{
//				fileF2 << str << '\n'; // запись строки во 2 файл 
//				for (int i = 0; i < str.length(); i++) // подсчет слов в записанной строке
//				{
//					if (str[i] == ' ')
//					{
//						counter++;
//					}
//				}
//			}
//		}
//		num++;
//	}
//	cout << "В первой строке второго файла " << counter - 1 << " слова.\n";
//	fileF1.close(); // закрытие файлов
//	fileF2.close();
//}

//zadanie 2

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

void fileOut(string* pStrOut)
{
	ofstream fileF1("fileF1.txt"); // открытие файла для записи
	fileF1 << *pStrOut;
	fileF1.close(); // закрытие файла

}

void fileIn(string* pStrIn)
{
	
	char StrIn[50],min[50];
	int counter = 1, SequenceNum = 0, a = 0, minimum = 999;
	ifstream fileF2("fileF1.txt"); // открытие файла для чтения

	fileF2.getline(StrIn, 50);
	for (int i = 0; i < strlen(StrIn); i++) {

		if (StrIn[i] == ' ') {

			if (i-a < minimum){ // нахождение минимального слова
				minimum = i - a;
				SequenceNum = counter;
				a = i;
			}
		counter++;
		}
	}
	
		cout << "Порядковый номер самого короткого слова: " << SequenceNum << '\n';
		fileF2.close(); // закрытие файла
}

int main()
{
	setlocale(LC_ALL, "ru");
	string strOut, strIn;
	string* pStrOut = &strOut, * pStrIn = &strIn;
	cout << "Введите слова, разделенные пробелом:\n";
	getline(cin, strOut); // запись строки
	fileOut(pStrOut); // вызов функций
	fileIn(pStrIn);
}


