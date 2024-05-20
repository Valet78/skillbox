// Задание 21.5.1. Ведомость учёта

#include "21.5-1.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::string askAction = "";
    staffer worker{"", "", 0};

    if (!std::filesystem::exists(fileName)) {
        std::wcout << L"Файл с ведомостью не найден. Будет создан новый файл." << std::endl;
        std::ofstream file(fileName, std::ios::out | std::ios::trunc);
        file.close();
    } else {
        if (!readData()) {// Чтение данных из файла в вектор
            return -1;
        }
    }

    do {
        askAction = selectAction();
        if (askAction == "list") {
            printVedomost();
            system("pause");
        } else if (askAction == "add") {
            worker = addAction();
            vecStaff.push_back(worker);    // Добавляем запись в вектор

            if (!saveStaffer(worker)) {
                return -1;
            } else {
                std::wcout << L"Данные внесены в файл успешно." << std::endl;
                system("pause");
            }

        } else {
            std::wcout << L"Программа будет закрыта. До скорой встречи!" << std::endl;
        }

    } while (askAction != "exit");

    system("pause");
    return 0;
}

// *************************************

// Запись данных в файл
bool saveStaffer(staffer &inWorker) {
    std::ofstream file;
    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);

    try {
        file.open(fileName, std::ios::out | std::ios::app);
        file << inWorker.nameStaff << " " << inWorker.dateTxt << " " << inWorker.payments << "\n";
        file.close();
    } catch (const std::ifstream::failure &e) {
        file.close();
        std::wcerr << L"Произошла ошибка записи данных в файл! Программа будет закрыта." << std::endl;
        system("pause");
        return false;
    }
    return true;
}

// Чтение данных из файла
bool readData() {
    std::ifstream file;
    std::string tmpTxt = "";

    int ind = 1;

    file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try {
        file.open(fileName, std::ios::in);

        do {
            staffer tmpStaff;
            std::getline(file, tmpTxt);

            std::cout << ind << ". " << tmpTxt << "\tlength = " << tmpTxt.length() << std::endl;
            ind++;

            if ((char) file.peek() != '\r') {       // Решение проблемы чтения пустой строки
                readLineFile(tmpTxt, tmpStaff);
                vecStaff.push_back(tmpStaff); // добавим в вектор запись о работнике
            }
        } while (!file.eof());
        file.close();

    } catch (const std::ifstream::failure &e) {
        file.close();
        std::wcerr << L"Произошла ошибка чтения данных из файла! Программа будет закрыта." << std::endl;
        std::cout << e.what() << " - " << e.code() << std::endl;
        system("pause");
        return false;
    }

    return true;
}

// Разбор строки из файла в структуру
void readLineFile(std::string &inTxt, staffer &inStaff) {
    int poz = 0;
    std::string tmpTxt = "";

    for (char i: inTxt) {
        if (charIsNum(i)) {
            poz = inTxt.find(i);
            break;
        }
    }

    inStaff.nameStaff = inTxt.substr(0, poz - 1);
    inStaff.dateTxt = inTxt.substr(poz, 10);
    poz += 11;
    inTxt = inTxt.substr(poz, inTxt.length() - poz);
    inStaff.payments = (strIsNum(inTxt)) ? std::stoi(inTxt) : -1;
}

// Проверяем строку, является ли числом
bool strIsNum(std::string &inTxt) {
    bool res = true;

    for (char ch: inTxt) {
        res &= (ch >= '0' && ch <= '9') ? true : false;
    }

    return res;
}

// Проверяем символ, является ли числом
bool charIsNum(char &inChar) {
    return (inChar >= '0' && inChar <= '9') ? true : false;
}

// Отсечение пробелов в строке с двух сторон
std::string truncSpaces(std::string &inTxt) {
    inTxt = std::regex_replace(inTxt, std::regex("^\\s+"), "");
    inTxt = std::regex_replace(inTxt, std::regex("\\s+$"), "");
    return inTxt;
}

// Выбор действия
std::string selectAction() {
    std::string resTxt = "";

    do {
        system("cls");
        std::wcout << L"* Ведомость учёта выплат сотрудникам (записей - ";
        std::cout << std::to_string(vecStaff.size()) << ") *" << std::endl;

        std::wcout << L"Укажите действие с ведомостью:" << std::endl;
        std::wcout << L"  \"list\" - вывод содержимого ведомости;" << std::endl;
        std::wcout << L"  \"add\"  - добавить запись;" << std::endl;
        std::wcout << L"  \"exit\" - завершение работы программы" << std::endl;
        std::wcout << L"**************************************" << std::endl;
        std::wcout << L"Ваш выбор: ";
        std::getline(std::cin, resTxt);
        // Обрежем "случайные" пробелы до и после слова
        resTxt = truncSpaces(resTxt);

        if (resTxt.empty()) {
            std::wcerr << std::endl << L"Вы забыли сделать выбор! Попробуйте снова." << std::endl;
            system("pause");
        } else if (resTxt != "list" && resTxt != "add" && resTxt != "exit") {
            std::wcerr << std::endl << L"Сделайте выбор из предложенных вариантов!" << std::endl;
            system("pause");
        }

    } while (!(resTxt == "list" || resTxt == "add" || resTxt == "exit"));

    return resTxt;
}

// Вывод ведомости на экран
void printVedomost() {
    std::wcout << std::endl << L"Ведомость учёта выплат сотрудникам:" << std::endl;
    for (auto i: vecStaff) {
        std::cout << i.nameStaff << "\t" << i.dateTxt << "\t" << std::to_string(i.payments) << std::endl;
    }
}

// Добавление записи
staffer addAction() {
    bool res = true;
    std::string nameTxt = "", askName = "", askDate = "", askPay = "";

    do {
        res = true;
        askName = askAdd(L"Укажите именные компоненты (ФИО) сотрудника: ");
        askDate = askAdd(L"Укажите дату платежа (в вормате ДД.ММ.ГГГГ): ");
        if (!validDate(askDate)) {
            std::wcerr << L"Ошибка формата вводимой даты! Попробуйте снова." << std::endl;
            res = false;
        } else {
            askPay = askAdd(L"Укажите сумму платежа: ");
            if (!strIsNum(askPay)) {
                std::wcerr << L"Указанное значение не является целым числом! Попробуйте снова." << std::endl;
                res = false;
            }
        }

    } while (!res);

    return {askName, askDate, std::stoi(askPay)};
}

// Обработка запроса ввода
std::string askAdd(std::wstring inTxt) {
    std::string askTxt = "";
    bool res = true;

    do {
        std::wcout << inTxt;
        std::getline(std::cin, askTxt);
        askTxt = truncSpaces(askTxt);

        if (askTxt.empty()) {
            std::wcerr << L"Вы забыли ввести данные! Попробуйте снова." << std::endl;
            res = false;
        } else {
            res = true;
        }

    } while (!res);

    return askTxt;
}

// Проверка вводимой даты
bool validDate(std::string &inTxt) {
    bool res = (inTxt.length() == 10) ? true : false;
    int poz = 0;

    for (char ch: inTxt) {

        if (poz == 2 || poz == 5) {
            res &= (ch == '.') ? true : res;

        } else {
            res &= (ch >= '0' && ch <= '9') ? true : false;
        }

        poz++;
    }

    if (res) {
        int day = std::stoi(inTxt.substr(0, 2));
        int manth = std::stoi(inTxt.substr(3, 2));
        int year = std::stoi(inTxt.substr(6, 4));
        bool visYear = (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0)) ? true
                                                                                : false;     // Проверка високосный ли год

        if (manth == 1 || manth == 3 || manth == 5 || manth == 7 || manth == 8 || manth == 10 || manth == 12) {
            res &= (day >= 1 && day <= 31) ? true : false;

        } else if (manth == 4 || manth == 6 || manth == 9 || manth == 11) {
            res &= (day >= 1 && day <= 30) ? true : false;

        } else if (manth == 2 && visYear) {
            res &= (day >= 1 && day <= 29) ? true : false;

        } else if (manth == 2 && !visYear) {
            res &= (day >= 1 && day <= 28) ? true : false;

        } else {
            res = false;
        }
    }

    if (!res) {

    }

    return res;
}