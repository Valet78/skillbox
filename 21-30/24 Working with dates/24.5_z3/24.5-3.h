#pragma once

#include <iostream>
#include <locale>
#include <ctime>
#include <unistd.h>

// Глобальные переменные
time_t currTime, stopTime;
int hour, minute, second;

// Функции
std::wstring inputText(std::wstring &&);            // Ввод текста и проверка на пустую строку
bool validDate(std::wstring &);                     // Проверка введённого времени
void timerStart();                                  // Собственно сам таймер
std::wstring convertSecondsToData(time_t &, const wchar_t *&&); // Перевод секунд в дату указанного формата