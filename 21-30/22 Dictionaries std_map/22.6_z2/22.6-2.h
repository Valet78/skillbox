#pragma once

#include <iostream>
#include <string>
#include <map>


// Глобальные переменные
std::multimap<std::string, int> queueOfCustomers;

// Функции
void testMap();                                // Тестовое заполнение
std::string inputText(std::wstring);            // Ввод текста и проверка на пустую строку
void printMap();                                // Вывод содержимого

