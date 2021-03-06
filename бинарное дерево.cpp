// бинарное дерево.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

struct unit {
	int val;
	unit *right, *left, *parent;
	unit()
	{
		parent = right = left = nullptr;
	}
}*root;

void push_back(int val,unit* current)
{
	if (root == nullptr)
	{
		root = new unit;
		root->val = val;
		root->left = nullptr;
		root->right = nullptr;
		root->parent = nullptr;
		return;
	}
	else {
		if (val > current->val ) 
		{
			if (current->right != nullptr)
			{
				push_back(val, current->right);
				return;
			}
			else {
				unit* new_unit = new unit;
				current->right = new_unit;
				new_unit->parent = current;
				new_unit->val = val;
			}
		}
		if (val < current->val)
		{
			if (current->left != nullptr)
			{
				push_back(val, current->left);
				return;
			}
			else {
				unit* new_unit = new unit;
				current->left = new_unit;
				new_unit->parent = current;
				new_unit->val = val;
			}
		}
	}
}

unit* find(int value) 
{
	if (root == nullptr)
	{
		cout << "Empty" << endl;
		return nullptr;
	}
	unit* current = root;
	while (current != nullptr) 
	{
		if (current->val == value)
		{
			cout << "we got it!" << endl;
			return current;
		}
		if (current->val > value)
		{
			current = current->left;
		}
		else 
		{
			current = current->right;
		}
	}
}

void del_list(unit* current) //функции для удаления
{
	unit* parent = current->parent;
	if (parent->left != nullptr)
	{
		if (parent->left->val == current->val)
		{
			delete current;
			parent->left = nullptr;
			cout << "unit deleted..." << endl;
			return;
		}
	}
	if (parent->right != nullptr)
	{
		if (parent->right->val == current->val)
		{
			delete current;
			parent->right = nullptr;
			cout << "unit deleted..." << endl;
			return;
		}
	}
}

void del_unit_with_l_tree(unit* current)
{
	unit* parent = current->parent;
	if (parent->left != nullptr)
	{
		if (parent->left->val == current->val)
		{
			parent->left = current->left;
			delete current;
			cout << "unit deleted..." << endl;
			return;
		}
	}
	if (parent->right != nullptr)
	{
		if (parent->right->val == current->val)
		{
			parent->right = current->left;
			delete current;
			cout << "unit deleted..." << endl;
			return;
		}
	}
}

void del_unit_with_r_tree(unit* current)
{
	unit* parent = current->parent;
	if (parent->left != nullptr)
	{
		if (parent->left->val == current->val)
		{
			parent->left = current->right;
			delete current;
			cout << "unit deleted..." << endl;
			return;
		}
	}
	if (parent->right != nullptr)
	{
		if (parent->right->val == current->val)
		{
			parent->right = current->right;
			delete current;
			cout << "unit deleted..." << endl;
			return;
		}
	}
}

void del_unit_with_2_trees(unit* current)
{
	unit* move_el = current->right;
	while (move_el->left != nullptr)
	{
		move_el = move_el->left;
	}
	current->val = move_el->val;
	unit** tmp = (&move_el->parent);
	if (move_el->right == nullptr)
	{
		if (*tmp == current)
			(*tmp)->right = nullptr;
		else
			(*tmp)->left = nullptr;
		delete move_el;
	}
	else
	{
		(*tmp)->left = move_el->right;
		move_el->right->parent = (*tmp);
		delete move_el;
	}
}

void del_elem(int val)
{
	unit* current = find(val);
	if (current->left == nullptr && current->right == nullptr)	//удаление листа
	{
		del_list(current);
		return;
	}
	//удаление элемента с двумя поддеревьями
	if (!(current->left == nullptr) && !(current->right == nullptr))
	{
		del_unit_with_2_trees(current);
		return;
	}
	// удаление элемента с одним поддеревом(левым)
	if (!(current->left == nullptr) && current->right == nullptr)
	{
		del_unit_with_l_tree(current);
		return;
	}
	else//удаление элемента с одним поддеревом(правым)
	{
		del_unit_with_r_tree(current);
		return;
	}
	
}

void show(unit* tree)
{
	if (NULL == tree) //Если дерева нет, выходим
		return;    

	show(tree->left); //Обошли левое поддерево 
	cout << tree->val << endl; //Посетили узел
	show(tree->right); //Обошли правое поддерево   
}

void del_all_tree(unit* unit) 
{
	if (NULL == root)
	{
		cout << "no tree to delete..." << endl;
		return;
	}

	if(unit->left) 
		del_all_tree(unit->left);

	if (unit->right)
		del_all_tree(unit->right);

	delete unit;
}

int main()
{
	unit* current;
	int val;
	cout << "0 => exit... " << endl;
	while (true)
	{
		cin >> val;
		if (!val)
		{
			break;
		}
		push_back(val, root);
	}
	cin >> val;
	cout << endl;
	show(root);
	cout << endl;
	del_elem(val);
	cout << endl;
	show(root);
	del_all_tree(root);
	root = NULL;
	show(root);
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
