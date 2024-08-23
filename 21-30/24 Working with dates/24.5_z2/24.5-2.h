#pragma once

#include <iostream>
#include <locale>
#include <ctime>
#include <iomanip>
#include <vector>

// Глобальные переменные
time_t nearTime, currTime = std::time(nullptr);
int year, month, day;

struct dateBorn {
    std::wstring name;
    time_t birthDay;
    time_t nearBDay;
};

std::vector<dateBorn> peopleBirthday;

// Функции
std::wstring inputText(std::wstring &&);               // Ввод текста и проверка на пустую строку
time_t inputDate(std::wstring &&);                     // Ввод даты в формате год/месяц/день
bool validDate(std::wstring &);                        // Проверка введённой даты
int takeYear(time_t &);                                // Функция получения значения года
time_t correctionYear(time_t &, int &);                // Корректируем дату (меняем только год) в секунды
time_t convertDataTimeToSeconds(int &, int &, int &);  // Функция перевода даты и времени в секунды
std::wstring convertSecondsToData(time_t &, const wchar_t *&&);        // Перевод секунд в дату указанного формата