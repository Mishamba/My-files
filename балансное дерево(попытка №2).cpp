// балансное дерево(попытка №2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

struct unit {
	int val, height;
	unit *right, *left, *parent;
	unit()
	{
		parent = right = left = nullptr;
		height = 1;
	}
}*root;

int bfactor(unit* current)
{
	int right_height = 0, left_height = 0;
	if (current->right)
		right_height = current->right->height;
	if (current->left)
		left_height = current->left->height;
	return right_height - left_height;
}

void fixheight(unit* current)
{
	int right_height = 0, left_height = 0;
	if (current->right != nullptr)
		right_height = current->right->height;
	if (current->left != nullptr)
		left_height = current->left->height;
	current->height = (left_height > right_height ? left_height : right_height) + 1;
}

void rotateright(unit* current)
{
	unit* left_tree = current->left,
		* parent	= nullptr;
	if (current->parent)
		parent = current->parent;
	if (parent != nullptr)
	{
		if (parent->left)
		{
			if (parent->left->val == current->val)
			{
				parent->left = left_tree;
			}
		}
		if (parent->right)
		{
			if (parent->right->val == current->val)
			{
				parent->right = left_tree;
			}
		}
	}
	left_tree->parent = parent;
	current->parent = left_tree;
	if (left_tree->right)
	{
		current->left = left_tree->right;
		left_tree->right->parent = current;
	}
	else
	{
		current->left = nullptr;
	}
	left_tree->right = current;
	if (!(left_tree->parent))
	{
		root = left_tree;
	}
	while (current != nullptr)
	{
		fixheight(current);
		current = current->parent;
	}
}

void rotateleft(unit* current)
{
	unit* right_tree = current->right,
		* parent	 = nullptr;
	if (current->parent)
		parent = current->parent;
	if (parent != nullptr)
	{
		if (parent->left)
		{
			if (parent->left->val == current->val)
			{
				parent->left = right_tree;
			}
		}
		if (parent->right)
		{
			if (parent->right->val == current->val)
			{
				parent->right = right_tree;
			}
		}
	}
	right_tree->parent = parent;
	current->parent = right_tree;
	if (right_tree->left)
	{
		current->right = right_tree->left;
		right_tree->left->parent = current;
	}
	else
	{
		current->right = nullptr;
	}
	right_tree->left = current;
	if (!(right_tree->parent))
	{
		root = right_tree;
	}
	while (current != nullptr)
	{
		fixheight(current);
		current = current->parent;
	}
}

void balance(unit** current) // балансировка узла current
{
	int need_balance = bfactor(*current);
	if (need_balance == 2)
	{
		if (bfactor((*current)->right) < 0)
			rotateright((*current)->right);
		rotateleft(*current);
	}
	if (need_balance == -2)
	{
		if (bfactor((*current)->left) > 0)
			rotateleft((*current)->left);
		rotateright(*current);
	}
}

void push_back(int val, unit* current)
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
		if (val > current->val)
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
				unit* b_elem = current->parent;
				while (current != nullptr)
				{
					fixheight(current);
					current = current->parent;
				}
				while (b_elem != nullptr)
				{
					balance(&b_elem);
					b_elem = b_elem->parent;
				}
				return;
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
				unit* b_elem = current->parent;
				while (current != nullptr)
				{
					fixheight(current);
					current = current->parent;
				}
				while (b_elem != nullptr)
				{
					balance(&b_elem);
					b_elem = b_elem->parent;
				}
				return;
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
	return nullptr;
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
	if (current == nullptr)
	{
		cout << "no element was found..." << endl;
		return;
	}
	if (current->left == nullptr && current->right == nullptr)	//удаление листа
	{
		unit* b_elem = current->parent;
		unit* fix_h_elem = current->parent;
		del_list(current);
		while (fix_h_elem != nullptr)
		{
			fixheight(fix_h_elem);
			fix_h_elem = fix_h_elem->parent;
		}
		while (b_elem != nullptr)
		{
			balance(&b_elem);
			b_elem = b_elem->parent;
		}
		return;
	}
	//удаление элемента с двумя поддеревьями
	if (!(current->left == nullptr) && !(current->right == nullptr))
	{
		unit* start_balance = current->right;
		while (start_balance->left != nullptr)
		{
			start_balance = start_balance->left;
		}
		start_balance = start_balance->parent;
		del_unit_with_2_trees(current);
		unit* b_elem = start_balance;
		unit* fix_h_elem = start_balance;
		while (fix_h_elem != nullptr)
		{
			fixheight(fix_h_elem);
			fix_h_elem = fix_h_elem->parent;
		}
		while (b_elem != nullptr)
		{
			balance(&b_elem);
			b_elem = b_elem->parent;
		}
		return;
	}
	// удаление элемента с одним поддеревом(левым)
	if (!(current->left == nullptr) && current->right == nullptr)
	{
		unit* b_elem = current->parent;
		unit* fix_h_elem = current->parent;
		del_unit_with_l_tree(current);
		while (fix_h_elem != nullptr)
		{
			fixheight(fix_h_elem);
			fix_h_elem = fix_h_elem->parent;
		}
		while (b_elem != nullptr)
		{
			balance(&b_elem);
			b_elem = b_elem->parent;
		}
		return;
	}
	else//удаление элемента с одним поддеревом(правым)
	{
		unit* b_elem = current->parent;
		unit* fix_h_elem = current->parent;
		del_unit_with_r_tree(current);
		while (fix_h_elem != nullptr)
		{
			fixheight(fix_h_elem);
			fix_h_elem = fix_h_elem->parent;
		}
		while (b_elem != nullptr)
		{
			balance(&b_elem);
			b_elem = b_elem->parent;
		}
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

	if (unit->left)
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
