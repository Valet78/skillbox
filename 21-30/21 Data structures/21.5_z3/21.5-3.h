#pragma once

#include <iostream>
#include <cmath>
#include <regex>
#include <codecvt>
#include <iomanip>

// Глобальные переменные
std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convWStr; // Для конвертации строк в wstring
struct coord {
    float x = 0.0f, y = 0.0f, z = 0.0f;
};

// Функции
std::string truncSpaces(std::string &);         // Отсечение пробелов в строке с двух сторон
bool validFloat(std::string &);                 // Проверка валидности чисел
std::string inputText(std::wstring);            // Ввод текста и проверка на пустую строку
float askFloatNum(std::wstring);                // запрос координат точки
std::string selectAction();                     // Меню выбора
coord askCoordinate(std::wstring);              // Запрос координат вектора
coord sumVector(coord &, coord &);              // Сумма двух векторов
coord subtractVector(coord &, coord &);         // Разность двух векторов
coord scaleVector(coord &, float &);            // Произведение вектора на скаляр
float lengthVector(coord &);                    // Вычисление длины вектора
coord normVector(coord &, float &);             // Нормализация вектора


