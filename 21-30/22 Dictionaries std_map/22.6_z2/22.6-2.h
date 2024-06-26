#pragma once

#include <iostream>
#include <string>
#include <map>


// Глобальные переменные
std::map<std::string, int> queueOfCustomers;
std::map<std::string, int> surnameCount;

// Функции
void testMap();                                // Тестовое заполнение
std::string inputText(std::wstring);            // Ввод текста и проверка на пустую строку
void printMap();                                // Вывод содержимого

