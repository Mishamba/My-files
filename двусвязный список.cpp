// двусвязный список.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
using namespace std;

struct unit {
	int data;
	unit *prev, *next;
	unit()
	{
		prev = next = nullptr;
	}
}*head, *tail;

void push_back(int value)
{
	unit *elem = new unit;
	elem->data = value;
	if (head == nullptr)
	{
		head = elem;
		tail = head;
		return;
	}
	unit*tmp;
	tmp = tail;
	tail = elem;
	tmp->next = tail;
	tail->prev = tmp;
}

void show()
{
	if (head == nullptr) {
		cout << "nothing to show" << endl;
		return;
	}
	unit *current = head;
	while (current != nullptr)
	{
		cout << current->data << ' ';
		current = current->next;
	}
	cout << endl;
}

void delete_index(int index, int &size)
{
	unit* current = head;
	int end = index;
	if (index > size / 2)
	{
		current = tail;
		end = size - index;
		for (int i = 1; i <= end; i++)
		{
			current = current->prev;
		}
	}
	else {
		for (int i = 1; i < end; i++)
		{
			current = current->next;
		}
	}

		if (current->prev == nullptr) {
			head = current->next;
			delete current;
			head->prev = nullptr;
			size--;
			return;
		}

		if (current->next == nullptr) {
			tail = current->prev;
			delete current;
			tail->next = nullptr;
			size--;
			return;
		}

		current->next->prev = current->prev;
		current->prev->next = current->next;
		delete current;
		size--;
}

void add_elem(int value, int index, int &size) 
{
	if (index > size + 1) {//проверка на размер
		cout << "wrong index" << endl;
		return;
	}
	unit* new_el = new unit;
	new_el->data = value;
	new_el->next = nullptr;
	new_el->prev = nullptr;
	unit* current;
	int end = index;
	if (index > size / 2)
	{
		current = tail;
		end = size - index;
		for (int i = 1; i <= end; i++)
		{
			current = current->prev;
		}
	}
	else {
		current = head;
		for (int i = 1; i < end; i++)
		{
			current = current->next;
		}
	}

	unit* tmp;
	if (current->prev == nullptr) {
		tmp = head;
		head = new_el;
		head->next = tmp;
		tmp->prev - head;
		size++;
		return;
	}

	if (current->next == nullptr) {
		tmp = tail;
		tail = new_el;
		tmp->next = tail;
		tail->prev = tmp;
		size++;
		return;
	}

	current->prev->next = new_el;
	new_el->next = current;
	new_el->prev = current->prev;
	new_el->next = current;
	size++;
}

void del() 
{
	if (head == nullptr) {//сохраняются связи и пропускает это условие
		return;
	}
	unit*current = head, *tmp;
	while (current != nullptr) {
		tmp = current;
		current = current->next;
		delete tmp;
	}
	head = nullptr;//понять, зачем нам это
}

void change(int index,int size, int value)
{
	unit* current;
	int end = index;
	if (index > size / 2)
	{
		end = size - index;
		current = tail;
		for (int i = 1; i <= end; i++)
		{
			current = current->prev;
		}
	}
	else {
		current = head;
		for (int i = 1; i < end; i++)
		{
			current = current->next;
		}
	}
	current->data = value;
}

void find_elem_index(int index, int size)
{
	int end;
	unit* current = head;//начало поиска
	if (index > size) {
		cout << "wrong index" << endl;
		return;
	}
	if (index > size / 2)
	{
		end = size - index;
		current = tail;
		for (int i = 1; i <= end; i++)
		{
			current = current->prev;
		}
	}
	else {
		for (int i = 1; i < index; i++) {//поиск
			current = current->next;
		}
	}
	cout << current->data << endl;
}

void find_elem_data(int val)
{
	int i = 1;
	bool result = false;
	unit* current = head;//начало поиска
	while (current != nullptr)
	{
		if (current->data == val)
		{
			result = true;
			break;
		}
		current = current->next;
		i++;
	}
	if (result)
	{
		cout << i << endl;
	}
	else {
		cout << "wrong data" << endl;
	}
}

int main()
{
	int length, ind, val;
	cin >> length;
	for (int i = 1; i <= length; i++) 
	{
		push_back(i);
	}
	show();
	cout << "del" << endl;
	cin >> ind;
	delete_index(ind, length);
	show();
	cout << "new_el" << endl;
	cin >> ind;
	cin >> val;
	add_elem(val, ind, length);
	show();
	cout << "change" << endl;
	cin >> ind;
	cin >> val;
	change(ind, length, val);
	show();
	cout << "find" << endl;
	cout << "enter index: " << endl;
	cin >> ind;
	find_elem_index(ind, length);
	cout << "enter data: " << endl;
	cin >> val;
	find_elem_data(val);
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
