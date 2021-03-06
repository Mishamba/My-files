// лаба 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <corecrt_math_defines.h>
#include <iomanip>
using namespace std;

typedef double(*uf)(double, double, int &); 

void tabl(double, double, double, double, uf);
double y(double, double, int &);
double s(double, double, int &);

#define a_val -2.5
#define b_val 1.3
#define h_val 0.1
#define eps_val 0.0001

int main()
{
	cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
	tabl(a_val, b_val, h_val, eps_val, y);
	cout << endl;

	cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
	tabl(a_val, b_val, h_val, eps_val, s);
	return 0;
}

void tabl(double a, double b, double h, double eps, uf f)
{
	int k = 0;
	double sum;
	for (double x = a; x < b + h / 2; x += h)
	{
		sum = f(x, eps, k);
		cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
	}
}

double y(double x, double eps, int &k)
{
	int res;
	if (x == 0.)  res = 0;
	if (x > 0.)  res = 1;
	else res = -1;

	double calc = (M_PI * res) / 4;
	return calc;
}

double s(double x, double eps, int &k)
{
	double c = x, sum = 0;
	k = 0;

	while (eps<fabs(c))
	{
		k++;
		c = sin(2*k-1)/(2*k-1)*x;
		sum -= c;
	} 
	return sum;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
