// Задание 22.6.2. Регистратура
#include "22.6-2.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::string ask = "";
    int seqNumber = 1;

//    testMap();

    do {
        system("cls");
        std::wcout << L"Программа «Регистратура»" << std::endl << std::endl;
        std::wcout << L"Введите свою фамилию для постановки в очередь или следующие значения:" << std::endl;
        std::wcout << L"\"Next\"    - для вызова следующего в очереди;" << std::endl;
        std::wcout << L"\"Exit\"    - для выхода из программы." << std::endl << std::endl;
        ask = inputText(L"Ваш выбор: ");

        std::cout << std::endl;

        if (ask == "Exit" || ask == "exit") {
            std::wcout << L"Уже уходите?. Всего Вам хорошего." << std::endl;
            break;
        } else if (ask == "Next" || ask == "next") {

            if (queueOfCustomers.empty()) {
                std::wcout << L"Очередь пока пуста." << std::endl;

            } else {
//                printMap();
                std::wcout << L"Приглашается ";
                std::cout << queueOfCustomers.begin()->first << std::endl;
                queueOfCustomers.erase(queueOfCustomers.begin());

            }

        } else {
            queueOfCustomers.insert(std::pair<std::string, int>(ask, seqNumber));
            std::cout << ask;
            std::wcout << L" успешно добавлен в очередь." << std::endl;
            seqNumber++;

        }

        std::cout << std::endl;
        system("pause");
    } while (ask != "Exit");


    system("pause");
    return 0;
}

// *************************************

// Ввод текста и проверка на пустую строку
std::string inputText(std::wstring inTxt) {
    std::string resTxt = "";
    bool valid = true;

    do {
        valid = true;
        std::wcout << inTxt;
        std::getline(std::cin, resTxt);

        if (resTxt.empty()) {
            std::wcerr << L"Забыли ввести данные. Попробуйте снова." << std::endl;
            valid = false;
        }
    } while (!valid);

    return resTxt;
}

// Вывод содержимого
void printMap() {
    for (auto &qoc: queueOfCustomers) {
        std::cout << qoc.first << ": " << qoc.second << std::endl;
    }
}

// Тестовое заполнение
void testMap() {
    queueOfCustomers.insert(std::pair<std::string, int>("IvanovN", 1));
    queueOfCustomers.insert(std::pair<std::string, int>("Smirnov", 2));
    queueOfCustomers.insert(std::pair<std::string, int>("Tihonov", 23));
    queueOfCustomers.insert(std::pair<std::string, int>("IvanovA", 4));
    queueOfCustomers.insert(std::pair<std::string, int>("Aliyev", 5));
    queueOfCustomers.insert(std::pair<std::string, int>("Bubnov", 16));
    queueOfCustomers.insert(std::pair<std::string, int>("Nikolayev", 7));
}