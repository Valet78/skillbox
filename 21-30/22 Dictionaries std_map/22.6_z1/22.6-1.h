#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

// Глобальные переменные
std::map<std::wstring, std::wstring> phDirectory;
std::map<std::wstring, std::vector<std::wstring>> surnameToNumber;

// Функции
std::wstring choosingAnAction();                        // Выбор действия
void inValueToMap();                                    // Предварительное заполнение справочника
bool validNum(std::wstring &);                          // Проверка целого числа
std::wstring inputText(const std::wstring &);           // Ввод текста и проверка на пустую строку
void deleteNum(std::vector<std::wstring> &, std::wstring &); // Удаление элемента из вектора