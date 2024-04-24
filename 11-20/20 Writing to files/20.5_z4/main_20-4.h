#pragma once

#include <iostream>
#include <ctime>
#include <regex>
#include <fstream>
#include <algorithm>

// Глобальные переменные
int sumMon = 0;
int data[7]{0};
std::string strData[]{"5000", "2000", "1000", "500", "200", "100"};

int moneySum();  // Сумма в банкомате
std::string selectAction(); // Выбор действия
bool validReadFile(std::string &); // Открытие файла и проверка
std::string truncSpaces(std::string); // Отсечение пробелов в строке с двух сторон
bool validNum(std::string &);   // Проверим значения в файле
// bool addBanknotes(); // Добавляем банкноты
int randNum(int, int); // Генерируем случайное число в диапазоне
bool randLoadFile(std::string &); // Загрузка банкомата банкнотами
bool saveToFile(std::string &);  // Запись в файл
int withdrawMoney(std::string &);  // Снятие денег со счета
