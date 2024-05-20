#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <regex>

//#include <ctime>
//
//#include <string>
//#include <algorithm>


// Глобальные переменные
struct staffer {
    std::string nameStaff = "unknown";
    std::string dateTxt = "01.01.2000";
    int payments = 0;
};
std::vector<staffer> vecStaff;
std::string fileName = "vedomost.txt";


// Функции
bool saveStaffer(staffer &);                    // Запись данных в файл
bool readData();                                // Чтение данных из файла
void readLineFile(std::string &, staffer &);    // Разбор строки из файла в структуру
bool charIsNum(char &);                         // Проверяем символ, является ли числом
bool strIsNum(std::string &);                   // Проверяем строку, является ли числом
std::string truncSpaces(std::string &);         // Отсечение пробелов в строке с двух сторон
std::string selectAction();                     // Выбор действия
void printVedomost();                           // Вывод ведомости на экран
staffer addAction();                           // Добавление записи
std::string askAdd(std::wstring);               // Обработка запроса ввода
bool validDate(std::string &);                  // Проверка вводимой даты