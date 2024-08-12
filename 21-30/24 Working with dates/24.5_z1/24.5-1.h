#pragma once

#include <iostream>
#include <locale>
#include <codecvt>  // Для конвертации строк в wstring
#include <ctime>
#include <vector>

#define  HEADING { \
    system("cls");               \
    std::wcout << L"Программа учёта времени." << std::endl << std::endl; \
    std::wcout << L"Выберите действие из ниже перечисленных:" << std::endl; \
    std::wcout << L"\"begin\" (\"начать\")  - отслеживание новой задачи;" << std::endl; \
    std::wcout << L"\"end\" (\"стоп\")      - закончить отслеживание текущей задачи;" << std::endl; \
    std::wcout << L"\"status\" (\"статус\") - выводит на экран информацию о всех законченных задачах и времени," << std::endl; \
    std::wcout << L"                      которое было на них потрачено;" << std::endl; \
    std::wcout << L"\"exit\" (\"выход\")    - выход из программы." << std::endl; \
}


// Глобальные переменные
int numTask = 0;
std::wstring wStart{}, wStop{}, wTime{}, wTask{};
std::time_t startTask = 0, stopTask = 0, timeTask;
//double timeTask;
std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convWStr;   // Для конвертации строк в wstring
std::vector<std::vector<std::wstring>> listTask;

// Функции
std::wstring inputText(std::wstring &&);            // Ввод текста и проверка на пустую строку
std::wstring calcTime(std::time_t);                 // Вычисление длительности задачи
void stopTaskFun();                                 // Останавливаем задачу