#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int mail()
{
    vector<int> vct(10); //такая запись выделяет память на 10 элементов и заполняет вектор нулями
    vct.reserve(10); //выделение памяти на 10 элементов 
    int size = vct.size(); //работы с векторами позволяет использовать ф-ию .size() (так что в переменной size смысла нет)
    for(int i =0;i<vct.size();i++)
    {
        vct[i] = i;
    }
    vector<int> cpy_vct(vct); //эта строка создаёт вектор cpy_vct и копирует в него vct
    if(vct == cpy_vct)//пояснение записано в строке
    {
        cout << "таким образом можно сказать, что, чтобы сравнить вектора, надо " <<
        "просто приравнять их \"названия\"" << endl;
    }
    vct.push_back(552);//добавит в конец вектора число 552
    /*      немного функций, которые мне немного впадлу описать

        Функция pop_back() удаляет последний элемент вектора:

        Если необходимо удалить все элементы вектора, то можно использовать функцию clear:

        emplace(pos, value): вставляет элемент value на позицию, на которую указывает итератор pos

        insert(pos, value): вставляет элемент value на позицию, на которую указывает итератор pos, аналогично функции emplace

        insert(pos, n, value): вставляет n элементов value начиная с позиции, на которую указывает итератор pos

        insert(pos, begin, end): вставляет начиная с позиции, на которую указывает итератор pos, элементы из другого контейнера из диапазона между итераторами begin и end

        insert(pos, values): вставляет список значений начиная с позиции, на которую указывает итератор pos 
    */
}
