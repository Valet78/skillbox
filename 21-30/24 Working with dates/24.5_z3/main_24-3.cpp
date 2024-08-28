// Задание 24.5.3. Реализация программы таймера
#include "24.5-3.h"

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    std::wstring comm;

    do {
        system("cls");
        std::wcout << L"Для установки таймера введите \"start\", " << std::endl
                   << L"для выхода из программы - \"exit\"." << std::endl;
        comm = inputText(L"Ваш выбор: ");

        if (comm == L"start") {
//            std::wstring dateTimeFormat{L"%H:%M:%S"};
            comm = inputText(L"Введите время сработки таймера в формате \"ЧЧ:ММ:СС\": ");
            if (validDate(comm)) {

                currTime = std::time(nullptr);
                stopTime = currTime + hour * 3600 + minute * 60 + second;
                timerStart();

            } else {
                std::wcerr << L"Неверный формат данных! Попробуйте снова." << std::endl;
            }

        } else if (comm == L"exit") {
            std::wcout << L"Программа будет завершена. До встречи." << std::endl;

        } else {
            std::wcerr << L"Введите указанные выше команды!" << std::endl;
        }

        system("pause");
    } while (comm != L"exit");

//    system("pause");
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

// Собственно сам таймер
void timerStart() {

    do {
        system("cls");
        currTime = std::time(nullptr);
        std::wcout << L"Вы установили таймер на " << std::to_wstring(hour) << L" час. "
                   << minute << L" мин. " << second << L" сек." << std::endl;
        std::wcout << L"Таймер сработает: " << convertSecondsToData(stopTime, L"%d/%m/%Y %H:%M:%S")
                   << std::endl << std::endl;
        std::wcout << L"Осталось: " << std::to_wstring(stopTime - currTime) << L" сек." << std::endl;

//        system("pause 1000");
        sleep(1);

    } while (currTime != stopTime);

    std::wcout << L"DING!" << std::endl;
    std::wcout << L"DING!" << std::endl;
    std::wcout << L"DING!" << std::endl;
}

// Проверка введённого времени
bool validDate(std::wstring &inTxt) {
    bool valid = (inTxt.length() == 8);
//    01:12:10
    for (int i = 0; i < inTxt.length(); i++) {
        if (i == 2 || i == 5) {
            valid &= (inTxt[i] == ':') ? true : false;
        } else {
            valid &= (inTxt[i] >= '0' && inTxt[i] <= '9') ? true : false;
        }
    }

    if (valid) {
        hour = std::stoi(inTxt.substr(0, 2));
        minute = std::stoi(inTxt.substr(3, 2));
        second = std::stoi(inTxt.substr(6, 2));
    }

    valid &= (hour >= 0 && hour < 24) ? true : false;
    valid &= (minute >= 0 && minute < 60) ? true : false;
    valid &= (second >= 0 && second < 60) ? true : false;

    return valid;
}

// Перевод секунд в дату указанного формата
std::wstring convertSecondsToData(time_t &inTime, const wchar_t *&&format) {
    struct tm *tm_conv;
    wchar_t wstr[20];
    tm_conv = std::localtime(&inTime);         // помещаем в структуру
    std::wcsftime(wstr, 20, format, tm_conv);
    return wstr;
}

