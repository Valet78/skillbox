#pragma once

#include <iostream>
#include <locale>

//#define MONDAY L"1"
//#define TUESDAY L"2"
//#define WEDNESDAY L"3"
//#define THURSDAY L"4"
//#define FRIDAY L"5"
//#define SATURDAY L"6"
//#define SUNDAY L"7"

#define DAY_WEEK ({(numDay == L"1") ? L"понедельник": \
                   (numDay == L"2") ? L"вторник":     \
                   (numDay == L"3") ? L"среда":       \
                   (numDay == L"4") ? L"четверг":     \
                   (numDay == L"5") ? L"пятница":     \
                   (numDay == L"6") ? L"суббота":     \
                   (numDay == L"7") ? L"воскресение": \
                   L"неверные данные";})

//#define DAY ({(numDay == L"1") ? L"MONDAY": \
//                   (numDay == L"2") ? L"TUESDAY":     \
//                   (numDay == L"3") ? L"WEDNESDAY":       \
//                   (numDay == L"4") ? L"THURSDAY":     \
//                   (numDay == L"5") ? L"FRIDAY":     \
//                   (numDay == L"6") ? L"SATURDAY":     \
//                   (numDay == L"7") ? L"SUNDAY": \
//                   L"Error";})



// Глобальные переменные
std::wstring numDay, wer;

// Функции

std::wstring inputText(std::wstring &&);          // Ввод текста и проверка на пустую строку