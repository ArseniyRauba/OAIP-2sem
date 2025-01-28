#include <iostream>
using namespace std;

int GetRoot1() //функция для вычисления корня первого уравнения
{
	setlocale(LC_ALL, "rus");
	double a = -100, b = 100, e = 0.001, x;
	cout << "Введите а:";
	cin >> a;
	cout << "Введите b:";
	cin >> b;

	//вычисления для метода дихотомии
	while ((abs(a - b)) > 2 * e)
	{
		x = (a + b) / 2;

		if ((pow(x, 3) + x - 4) * (pow(a, 3) + a - 4) <= 0) // подстановка уравнения
		{
			b = x;
		}
		else a = x;
	} 

	cout << "Корень уравнения " << x << endl;
	return 0;
}

int GetRoot2() //функция для вычисления корня второго уравнения
{
	setlocale(LC_ALL, "rus");
	double a = -100, b = 100, e = 0.001, x;
	cout << "Введите а:";
	cin >> a;
	cout << "Введите b:";
	cin >> b;

	//вычисления для метода дихотомии
	while ((abs(a - b)) > 2 * e)
	{
		x = (a + b) / 2;

		if (((1-pow(x,2)) * (1-pow(a,2))) <= 0) // подстановка уравнения
		{
			b = x;
		}
		else a = x;
	} 

	cout << "Корень уравнения " << x << endl;
	return 0;
}

//функция указателя
void ShowResults(int(*pointer)())
{
	cout << pointer() << endl;
}

//использование указателя для выбора уравнения
void main()
{
	ShowResults(GetRoot2);
}