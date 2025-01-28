//#include <iostream>
//using namespace std;
//
//long long pluus(int n, int m) { // функция для сложения
//	if (m == 0) {
//		return n;
//	}
//	else {
//		return pluus(n + 1, m - 1);
//	}
//}
//
//long long miinus(int n, int m) { // функция для вычитания
//	if (m == 0) {
//		return n;
//	}
//	else {
//		return miinus(n - 1, m - 1);
//	}
//}
//
//long long multi(int n, int m) { // функция для умножения
//	if (m == 0) {
//		return 0;
//	}
//	else {
//		if (m == 1) {
//			return n;
//		}
//		else {
//			return pluus(multi(n, m - 1), n);
//		}
//	}
//}
//
//long long power(int n, int m) { // функция для возведения в степень
//	if (m == 0) {
//		return 1;
//	}
//	else {
//		return multi(n,power(n,m-1));
//	}
//}
//
//int main() {
//
//	int n, m;
//	cout << "Enter n,m:";
//	cin >> n >> m;
//
//	if (n < 0 || m < 0) {
//		return 1;
//	}
//
//	long result1 = pluus(n, m); // вычисление
//	long result2 = miinus(n, m);
//	long result3 = multi(n, m);
//	long result4 = power(n, m);
//
//	cout << "sum: " << result1 << endl; // вывод
//	cout << "dif: " << result2 << endl;
//	cout << "multi: " << result3 << endl;
//	cout << "power: " << result4 << endl;
//}



#include <iostream>
using namespace std;

long double pol(int n, int x) { // функция для вычисления значения полиномов
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 2*x;
	}
	if (n > 1) {
		return ((2 * n) / (n - 1)) * pol(n - 1, x) + ((n - 1) / (2 * n)) * pol(n - 2, x);
	}
}

int main() {
	int n, x;
	cout << "enter n,x:";
	cin >> n >> x;

	double result = pol(n, x); // вычисление

	cout << "result: " << result; // вывод
}