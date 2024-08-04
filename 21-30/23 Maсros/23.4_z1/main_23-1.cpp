// Задание 23.4.1. Реализация продвинутого ввода и вывода дней недели
#include "23.4-1.h"

int main() {
    std::setlocale(LC_ALL, "Russian_Russia.1251");

    do {
        std::wcout << std::endl << L"Программа выведет наименование дня недели по его порядковому номеру." << std::endl;
        numDay = inputText(L"Укажите порядковый номер дня недели (exit - для выхода): ");

/* Вариант 1 */
//        if (numDay == L"exit") {
//            std::wcout << L"Жаль, что Вы уходите. До встречи." << std::endl;
//        } else {
//            if (numDay == MONDAY) {
//                std::wcout << L"Вы указали 1 день недели, т.е. понедельник." << std::endl;
//            } else if (numDay == TUESDAY) {
//                std::wcout << L"Вы указали 2 день недели, т.е. вторник." << std::endl;
//            } else if (numDay == WEDNESDAY) {
//                std::wcout << L"Вы указали 3 день недели, т.е. среда." << std::endl;
//            } else if (numDay == THURSDAY) {
//                std::wcout << L"Вы указали 4 день недели, т.е. четверг." << std::endl;
//            } else if (numDay == FRIDAY) {
//                std::wcout << L"Вы указали 5 день недели, т.е. пятница." << std::endl;
//            } else if (numDay == SATURDAY) {
//                std::wcout << L"Вы указали 6 день недели, т.е. суббота." << std::endl;
//            } else if (numDay == SUNDAY) {
//                std::wcout << L"Вы указали 7 день недели, т.е. воскресение." << std::endl;
//            } else {
//                std::wcout << L"Вы указали неверные данные! Повторите снова." << std::endl;
//            }
//        }
//
/* Вариант 2 */
        if (numDay == L"exit") {
            std::wcout << L"Жаль, что Вы уходите. До встречи." << std::endl;
        } else {

            if ((int) numDay[0] >= 49 && (int) numDay[0] <= 55) {
                std::wcout << L"Вы указали " << numDay << L" день недели, т.е. " << DAY_WEEK << L"." << std::endl;
            } else {
                std::wcout << L"Вы указали " << DAY_WEEK << L"! Повторите снова." << std::endl;
            }
        }

    } while (numDay != L"exit");


    system("pause");
    return 0;
}

// *************************************

// Ввод текста и проверка на пустую строку
std::wstring inputText(std::wstring &&inTxt) {
    std::wstring resTxt;
    bool valid;

    do {
        valid = true;
        std::wcout << inTxt;
        std::getline(std::wcin, resTxt);

        if (resTxt.empty()) {
            std::wcerr << L"Забыли ввести данные. Попробуйте снова." << std::endl;
            valid = false;
        }
    } while (!valid);

    return resTxt;
}