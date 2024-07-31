#pragma once

#include <iostream>

#define MONDAY L"1"
#define TUESDAY L"2"
#define WEDNESDAY L"3"
#define THURSDAY L"4"
#define FRIDAY L"5"
#define SATURDAY L"6"
#define SUNDAY L"7"

#define DAY_WEEK ({(numDay == L"1") ? L"понедельник": \
                   (numDay == L"2") ? L"вторник":     \
                   (numDay == L"3") ? L"среда":       \
                   (numDay == L"4") ? L"четверг":     \
                   (numDay == L"5") ? L"пятница":     \
                   (numDay == L"6") ? L"суббота":     \
                   (numDay == L"7") ? L"воскресение": \
                   L"неверные данные";})

// Глобальные переменные
std::wstring numDay;

// Функции

std::wstring inputText(std::wstring &&);          // Ввод текста и проверка на пустую строку