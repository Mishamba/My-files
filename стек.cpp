// стек.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct stack
{
	int data;
	stack* next_unit;
}
*root = NULL;

void push_back(int data)
{
	if (!root)
	{
		root = new stack;
		root->data = data;
		root->next_unit = nullptr;
		return;
	}
	else
	{
		stack* unit;
		unit = root;
		root = nullptr;
		root = new stack;
		root->data = data;
		root->next_unit = unit;
	}
}

void nature_sort()
{
	stack* unit;
	unit = root;
	if (unit == root && root->data >= 0 && unit->data <= 10) //удаление корня
	{
		if (unit->next_unit) 
		{
			root = unit->next_unit;
		}
		else 
		{
			delete root;
			root = nullptr;
			return;
		}
		delete unit;
		unit = root;
	}
	if (!(unit->next_unit->next_unit) && unit->next_unit->data <= 10 && unit->next_unit->data >= 0)//удаление последнего элемента
	{
		delete unit->next_unit;
		unit->next_unit = NULL;
	}
	if (unit->next_unit->next_unit && unit->next_unit->data <= 10 && unit->next_unit->data >= 0)//удаление промежуточного элемента
	{
		stack* tmp_unit = unit->next_unit->next_unit;
		delete unit->next_unit;
		unit->next_unit = tmp_unit;
	}
}

void del()
{
	stack* unit = root, *tmp_unit;
	if (!root)
	{
		cout << "no stack to delete... " << endl;
		return;
	}
	while (unit)
	{
		tmp_unit = unit->next_unit;
		delete unit;
		unit = tmp_unit;
	}
	cout << "stack is clear..." << endl;
}

void show()
{
	stack* unit = root;
	while (unit)
	{
		cout << unit->data << ' ';
		unit = unit->next_unit;
	}
	cout << endl << endl;
	return;
}

int main()
{
	int data;
	char status;
	do
	{
		cout << "enter data: ";
		cin >> data;
		push_back(data);
		cout << "one more? ";
		cin >> status;
		cout << endl;
	} while (status == 'y');
	nature_sort();
	show();
	del();
	return 0;
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
