// Задание 22.6.2. Регистратура
#include "22.6-2.h"

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    std::wstring ask;

//    testMap();

    do {
        ask = choosingAnAction();                        // Выбор действия
        std::cout << std::endl;

        if (ask == L"Exit" || ask == L"exit" || ask == L"Выход" || ask == L"выход") {
            std::wcout << L"Уже уходите?. Всего Вам хорошего." << std::endl;
            break;

        } else if (ask == L"Next" || ask == L"next" || ask == L"Следующий" || ask == L"следующий") {

            if (surnameCount.empty()) {
                std::wcout << L"Очередь пока пуста." << std::endl;

            } else {
                int num = surnameCount.begin()->second;
                std::wcout << L"Приглашается " << surnameCount.begin()->first << L"\tnum = " << num << std::endl;

                if (num > 1) {
                    surnameCount.begin()->second -= 1;

                } else {
                    surnameCount.erase(surnameCount.begin());
                }
            }

        } else {

            if (surnameCount.find(ask) == surnameCount.end()) {
                surnameCount.insert({ask, 1});

            } else {
                surnameCount.find(ask)->second += 1;
            }

            std::wcout << ask << L" успешно добавлен в очередь." << std::endl;
        }

//        printMap();

        std::cout << std::endl;
        system("pause");
    } while (ask != L"Exit");


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

// Выбор действия
std::wstring choosingAnAction() {

    system("cls");
    std::wcout << L"Программа «Регистратура»" << std::endl << std::endl;
    std::wcout << L"Введите свою фамилию для постановки в очередь или следующие значения:" << std::endl;
    std::wcout << L"\"Next\"    - для вызова следующего в очереди;" << std::endl;
    std::wcout << L"\"Exit\"    - для выхода из программы." << std::endl << std::endl;
    return inputText(L"Ваш выбор: ");
}

// Вывод содержимого
void printMap() {

    for (auto &soc: surnameCount) {
        std::wcout << soc.first << L": " << soc.second << std::endl;
    }
    std::cout << std::endl;

}

// Тестовое заполнение
void testMap() {

    surnameCount.insert({L"Ivanov", 2});
    surnameCount.insert({L"Tihonov", 2});
    surnameCount.insert({L"Smirnov", 1});
    surnameCount.insert({L"Bubnov", 1});
    surnameCount.insert({L"Nikolayev", 1});

}