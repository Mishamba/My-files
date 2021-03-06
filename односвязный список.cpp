// односвязный список.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct unit {
	int data;
	unit *next;//указатель на следующую структуру
	unit()
	{
		next = nullptr;
	}
};
unit* head = nullptr;//создание головы

void push_back(int value)
{
	unit *elem = new unit;
	elem->data = value;
	if (head == nullptr)//проверка на наличие элементов в системе
	{
		head = elem;
		return;
	}
		unit* current = head;//откуда начинаем ходить
		while (current->next != nullptr)//проход до последнего
		{
			current = current->next;
		}
		current->next = elem;//добавление нового элемента(новый элемент - elem)
}
void show()
{
	unit* current = head;
	if (head == nullptr) {
		cout << "empty " << endl;
		return;
	}
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl << endl;
}

void delete_index(int index, int &size) 
{
	unit* current = head, *tmp_prev = nullptr, *tmp_del = current, *tmp_next = current->next;
	bool state=false;
	if (index > size) // проверка
	{
		cout << "wrong index" << endl;
		return;
	}

	for(int count=1;count<index;count++) // поиск
	{
		if (index == count + 1) 
		{
			tmp_prev = current;
			tmp_del = current->next;
			tmp_next = current->next->next;
			state = true;
		}
		if (state) break;
		current = current->next;
	}

		if (tmp_prev == nullptr) {
			head = tmp_next;
			delete tmp_del;
		}
		else {
			tmp_prev->next = tmp_next;
			delete tmp_del;
		}

	size--;
}

void del() {
	if (head == nullptr) return;
	unit* current = head;
	unit* tmp;
	while (current != nullptr) {
		tmp = current;
		current = current->next;
		delete tmp;
	}
	head = nullptr;
	cout << endl;
}

void add_elem(int index,int new_data, int &size) {
	unit* new_el = new unit;
	new_el->data = new_data;//запись значения
	if (index > size + 1) {//проверка на размер
		cout << "wrong index" << endl;
		return;
	}
		unit* current = head, *tmp_unit = nullptr;
		for (int i = 1; i < index; i++) {//поиск элемента
			if (i == index - 1) {
				tmp_unit = current;
			}
			current = current->next;
		}

			if (current == head) {//костыльная херь для первого элемента
				tmp_unit = head;
				head = new_el;
				head->next = tmp_unit;
				size++;
				return;
			}

		tmp_unit->next = new_el;
		new_el->next = current;
		size++;
}

void change(int index, int new_data,int size) 
{
	unit* current = head;//начало поиска
	if (index > size) {
		cout << "wrong index" << endl;
		return;
	}
	for (int i = 1; i < index; i++) {//поиск
		current = current->next;
	}
		current->data = new_data;
}

void find_elem_index(int index, int size)
{
	unit* current = head;//начало поиска
	if (index > size) {
		cout << "wrong index" << endl;
		return;
	}
	for (int i = 1; i < index; i++) {//поиск
		current = current->next;
	}
	cout << current->data << endl;
}
 
void find_elem_data(int val)
{
	int i = 1;
	bool result;
	unit* current = head;//начало поиска
	while (current->next != nullptr)
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
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		push_back(i);
	}
	show();
	int ind, val;
	cout << "delete" << endl;
	cout << "enter index: " << endl;
	cin >> ind;
	delete_index(ind, k);
	show();
	cout << "add" << endl;
	cout << "enter index: " << endl;
	cin >> ind;
	cout << "enter data: " << endl;
	cin >> val;
	add_elem(ind, val, k);
	show();
	cout << "change" << endl;
	cout << "enter index: " << endl;
	cin >> ind;
	cout << "enter data: " << endl;
	cin >> val;
	change(ind, val, k);
	show();
	cout << "find" << endl;
	cout << "enter index: " << endl;
	cin >> ind;
	find_elem_index(ind, k);
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
