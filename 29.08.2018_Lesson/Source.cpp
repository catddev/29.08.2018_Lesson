#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;
// case 3
double add(double a, double b) {
	return a + b;
}
double sub(double a, double b) {
	return a - b;
}
double mult(double a, double b) {
	return a * b;
}
double div(double a, double b) {
	return a / b;
}
// case 4
double sq(double a) {
	return a * a;
}
double kub(double a) {
	return a * a * a;
}
double sinus(double a) {
	return sin(a);
}
//case 5
void oper(double a, double b, double(*f)(double, double)) {
	cout << f(a, b);
}
// 15.	***Напишите 2 функции, каждая из которых принимает вещественный параметр и возвращает вещественное значение.
// Пусть первая функция вычисляет y = x^2, а вторая – y = x * 2 + 4, где x – входной параметр y – возвращаемое значение.
// Затем напишите функцию, которая принимает указатель на одну из этих функций,
// а также диапазон значений(от a до b) и выводит на экран 10 точек(координаты x и y) для этого диапазона.
// Напишите меню, которое иллюстрирует работу этих функций
double func1(double x) {
	double y;
	y = x * x;
	return y;
}
double func2(double x) {
	double y;
	y = x * 2 + 4;

	return y;
}
void fp(double(*ff)(double), double a, double b) {

	double dx = (b - a) / 10;
	for (double x=a; x <= b; x+=dx)
	{
		cout << x << ", " << ff(x) << endl;
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{

			double(*f)(double, double) = sub; // указатель на функцию, которая принимает два аргумента и возвращает даббл

			cout << f(5, 6) << endl; // указатель на функцию может служить псевдонимом для функции

			cout << add << endl;
			cout << &add << endl; // эти две записи равносильны - адрес выводит


		}
		break;
		case 2:
		{
			double(*f[4])(double, double) = { add, sub, mult, div }; //можно передавать массив функций
	
				for (int i = 0; i < 4; i++)
					cout << f[i](5, 6) << endl;
		}
		break;
		case 3:
		{
			// 12.	**Реализовать 4 функции на простейшие арифметические операции(+, -, *, / ).
			// Каждая функция должна принимать два вещественных числа и возвращать результат операции в виде вещественного числа.
			// В главной функции создайте массив из 4 - х указателей на эти функции.Добавьте меню,
			//в котором пользователь может выбрать желаемую операцию.Напишите программу без использования операторов if и switch.
			double(*f[4])(double, double) = { add, sub, mult, div };
			int choice;
			while (true)
			{
				cin >> choice;
				if (choice < 0 || choice>3) break;

				cout << f[choice](5, 6) << endl;
			}
		}
		break;
		case 4:
		{
			//13.	**Реализовать 3 функции каждая из которых принимает вещественное число и возвращает вещественное число.
			// Первая функция вычисляет квадратный корень числа, вторая – куб числа, третья – синус числа.
			// В главной функции создайте массив из 3 - х указателей на эти функции. Добавьте меню,
			//в котором пользователь может выбрать желаемую операцию. Напишите программу без использования операторов if и switch.
			double(*f[3])(double) = { sq, kub, sinus };

			int choice;
			while (true)
			{
				cin >> choice;
				if (choice < 0 || choice>2) break;

				cout << f[choice](5) << endl;
			}
		}
		break;
		case 5:
		{
			// 15.	***Напишите 2 функции, каждая из которых принимает вещественный параметр и возвращает вещественное значение.
			// Пусть первая функция вычисляет y = x^2, а вторая – y = x * 2 + 4, где x – входной параметр y – возвращаемое значение.
			// Затем напишите функцию, которая принимает указатель на одну из этих функций,
			// а также диапазон значений(от a до b) и выводит на экран 10 точек(координаты x и y) для этого диапазона.
			// Напишите меню, которое иллюстрирует работу этих функций

			double(*ff[2])(double) = { func1, func2 };

			int choice;
			double a, b;
			cin >> a >> b;

			
			while (true)
			{
				cin >> choice;
				if (choice < 0 || choice>2) break;

				fp(*ff[choice], a, b);
			}
		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}