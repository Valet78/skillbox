#pragma once

#include <iostream>
#include <string>
#include <map>


// Глобальные переменные
std::map<std::string, std::string> phDirectory;

// Функции
void inValueToMap();                           // Предварительное заполнение справочника
bool validNum(std::string &);                   // Проверка целого числа
std::string inputText(std::wstring);            // Ввод текста и проверка на пустую строку