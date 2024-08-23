// Задание 24.5.2. Реализация программы напоминания о днях рождения
#include "24.5-2.h"

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
//    bool validInputDate;
    std::wstring commTxt;

    do {
        system("cls");
        std::wcout << L"Программа вычисления ближайшего дня рождения друзей." << std::endl;
        std::wcout << L"Выберите действия:" << std::endl;
        std::wcout << L"\t\"add\"    - добавить дату рождения друга;" << std::endl;
        std::wcout << L"\t\"search\" - добавить дату рождения друга;" << std::endl;
        std::wcout << L"\t\"exit\"   - завершение работы программы." << std::endl;

        commTxt = inputText(L"Укажите действие: ");

        if (commTxt == L"exit") {
            std::wcout << L"Жаль, что Вы уже уходите! До свидания." << std::endl;

        } else if (commTxt == L"add") {
            dateBorn *newPeople = new dateBorn;
            newPeople->name = inputText(L"Введите имя друга: "); //commTxt;
            newPeople->birthDay = inputDate(
                    L"Введите дату рождения в формате гггг/мм/дд (год/месяц/день): ");

            year = takeYear(currTime);    // текущий год

            do {                            // вычислим следующую дату ДР в секундах
                nearTime = correctionYear(newPeople->birthDay, year);
                if (nearTime < currTime) year++;
            } while (nearTime < currTime);

            newPeople->nearBDay = nearTime;
            peopleBirthday.push_back(*newPeople);
            delete newPeople;

        } else if (commTxt == L"search") {

            int min = 32000000, ind, diff;

            std::wcout << std::endl << L"Имеются следующие записи: " << std::endl;

            for (int i = 0; i < peopleBirthday.size(); i++) {
                std::wcout << L"\tимя друга: " << peopleBirthday[i].name;
                std::wcout << L" дата рождения: " << convertSecondsToData(peopleBirthday[i].birthDay, L"%Y/%m/%d")
                           << std::endl;
                diff = (int) (peopleBirthday[i].nearBDay - currTime);

                if (min > diff) {
                    min = diff;
                    ind = i;
                }
            }
            std::wcout << std::endl;
            std::wcout << L"Ближайший День рождения у " << peopleBirthday[ind].name << std::endl;

        } else {
            std::wcerr << L"Указывайте действия из указанных выше!" << std::endl;
        }
        system("pause");
    } while (commTxt != L"exit");


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

// Ввод даты в формате год/месяц/день
time_t inputDate(std::wstring &&inTxt) {
    std::wstring dateTxt;
    time_t rawTime;
    bool valid;

    do {
        valid = true;
        std::wcout << inTxt;
        std::getline(std::wcin, dateTxt);

        if (dateTxt.empty()) {
            std::wcerr << L"Забыли ввести данные. Попробуйте снова." << std::endl;
            valid &= false;
        } else {
            valid &= validDate(dateTxt);

            if (!valid) {
                std::wcerr << L"Неверно указана дата или неверный формат даты!" << std::endl;
            } else {
                rawTime = convertDataTimeToSeconds(year, month, day);

                if (rawTime >= currTime) {
                    valid &= false;
                    std::wcerr << L"Ваш друг похоже ещё не родился. Укажите другую дату." << std::endl;
                }
            }
        }
    } while (!valid);
    return rawTime;
}

// Проверка введённой даты
bool validDate(std::wstring &inTxt) {
    bool valid = (inTxt.length() == 10) ? true : false;
    bool visYear;

    for (int i = 0; i < inTxt.length(); i++) {
        if (i == 4 || i == 7) {
            valid &= (inTxt[i] == '/') ? true : false;
        } else {
            valid &= (inTxt[i] >= '0' && inTxt[i] <= '9') ? true : false;
        }
    }

    if (valid) {
        year = std::stoi(inTxt.substr(0, 4));
        month = std::stoi(inTxt.substr(5, 2));
        day = std::stoi(inTxt.substr(8, 2));
    }

    visYear = (year % 4 == 0 &&
               !(year % 100 == 0 && year % 400 != 0)) ? true : false;     // Проверка високосный ли год
    valid &= (year >= 1900 && year <= 2100) ? true : false;
    valid &= (month >= 1 && month <= 12) ? true : false;
    if (month == 2) {
        if (visYear) {
            valid &= (day >= 1 && day <= 29) ? true : false;
        } else {
            valid &= (day >= 1 && day <= 28) ? true : false;
        }

    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        valid &= (day >= 1 && day <= 30) ? true : false;

    } else {
        valid &= (day >= 1 && day <= 31) ? true : false;
    }

    return valid;
}

// Корректируем дату (меняем только год) в секунды
time_t correctionYear(time_t &inTime, int &inYear) {
    struct tm *tm_conv;
    tm_conv = std::localtime(&inTime);      // за основу берём дату и время рождения, помещаем в структуру
    tm_conv->tm_year = inYear - 1900;            // корректируем год
    return mktime(tm_conv);
}

// Функция перевода даты и времени в секунды
time_t convertDataTimeToSeconds(int &inYear, int &inMonth, int &inDay) {
    struct tm *tm_conv;
    tm_conv = std::localtime(&currTime);        // за основу берём текущие дату и время, помещаем в структуру
    tm_conv->tm_year = inYear - 1900;               // корректируем год
    tm_conv->tm_mon = inMonth - 1;                  // корректируем значение месяца,
    tm_conv->tm_mday = inDay;                       // а так же день
    tm_conv->tm_hour = 0;                           // час
    tm_conv->tm_min = 0;                            // минуты
    tm_conv->tm_sec = 0;                            // секунды

    return mktime(tm_conv);                  // из структуры обратно в секунды
}

// Перевод секунд в дату указанного формата
std::wstring convertSecondsToData(time_t &inTime, const wchar_t *&&format) {
    struct tm *tm_conv;
    wchar_t wstr[15];
    tm_conv = std::localtime(&inTime);         // помещаем в структуру
    std::wcsftime(wstr, 15, format, tm_conv);
    return wstr;
}

// Функция получения значения года
int takeYear(time_t &inData) {
    struct tm *tm_conv;
    tm_conv = std::localtime(&inData);
    return tm_conv->tm_year + 1900;
}