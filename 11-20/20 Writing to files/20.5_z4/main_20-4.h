#pragma once

#include <iostream>
#include <ctime>
#include <regex>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <codecvt>  // Для конвертации строк в wstring

// Глобальные переменные
int sumMon = 0;
int data[7]{0};
std::string statTxt = "";
std::string fileStatName = "status.txt", fileDataName = "data.bin";
std::string strData[]{"5000", "2000", "1000", "500", "200", "100"};
std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convWStr; // Для конвертации строк в wstring

// Функции
std::string dateNow(); // Получение текущей даты и времени
std::string selectAction(); // Выбор действия
std::string truncSpaces(std::string); // Отсечение пробелов в строке с двух сторон
int moneySum();  // Сумма в банкомате
int randNum(int, int); // Генерируем случайное число в диапазоне
bool saveDataToFile();  // Запись в файл данных Data[]
void saveStatToFile(std::string &);  // Запись в файл статистики
bool loadDataFromFile();    // Загружаем данные из файла с данными
bool randDataFile(); // Загрузка банкомата банкнотами
bool validNum(std::string &);   // Проверим значения в файле
int withdrawMoney();  // Снятие денег со счета
void errToStat();
