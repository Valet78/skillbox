#pragma once

#include <iostream>
#include <string>
#include <map>


// Глобальные переменные
//std::map<int, std::wstring> queueCustomers;
std::map<std::wstring, int> surnameCount;

// Функции
void testMap();                                  // Тестовое заполнение
std::wstring choosingAnAction();                 // Выбор действия
std::wstring inputText(std::wstring &&);            // Ввод текста и проверка на пустую строку
void printMap();                                 // Вывод содержимого

