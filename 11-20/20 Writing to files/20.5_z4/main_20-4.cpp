// Задание 20.5.4. Симуляция работы банкомата
#include "main_20-4.h"

int main() {
    std::string askTxt = "", tmp = "";
    std::srand(std::time(nullptr));     // Для генерации случайных чисел
    setlocale(LC_ALL, "Russian");
    bool fValid = true;

    if (!std::filesystem::exists(fileDataName)) {
        // Создаем новый файл при его отсутствии
        if (!saveDataToFile()) {  // Запись в файл
            errToStat();
            system("pause");
            return -1;
        }
    } else {
        if (!loadDataFromFile()) {
            errToStat();
            system("pause");
            return -1;
        }
    }

    statTxt = "The program is running. Available: " + std::to_string(moneySum());
    saveStatToFile(statTxt);

    do {
        system("CLS");
        std::wcout << std::endl << L"\t*** Симулятор работы банкомата ***" << std::endl;
        sumMon = moneySum();
        std::wcout << L"Доступно: " << convWStr.from_bytes(std::to_string(sumMon)) << L" руб." << std::endl;
        askTxt = selectAction();

        // Выбираем дальнейшие действия
        if (askTxt == "+") {

            fValid = randDataFile(); // Загрузка банкомата банкнотами
            if (!fValid) {
                errToStat();
                system("pause");
                return -1;
            } else {
                std::wcout << L"Банкомат пополнен банкнотами и готов к работе." << std::endl;
            }
            statTxt = "The ATM has been topped up. Available: " + std::to_string(sumMon);
            saveStatToFile(statTxt);

        } else if (askTxt == "-" && sumMon > 0) {
            int withdrawSum = withdrawMoney();

            if (withdrawSum == -1) {
                std::wcerr << std::endl << L"Ошибка! Не удалось записать данные в файл \""
                           << convWStr.from_bytes(fileDataName)
                           << L"\"! Программа будет закрыта." << std::endl;
                errToStat();
                system("pause");
                return -1;
            } else if (withdrawSum == 0) {
                std::wcerr << std::endl << L"Была снята вся имеющаяся наличность.Пополните банкомат!" << std::endl;
                system("pause");
            }

            statTxt = "Money withdrawal has been made. Available: " + std::to_string(sumMon);
            saveStatToFile(statTxt);

        } else if (askTxt == "-" && sumMon == 0) {
            std::wcerr << std::endl << L"Необходимо пополнить банкомат купюрами!" << std::endl;
            system("pause");

        } else if (askTxt == "exit") {
            std::wcerr << std::endl << L"Симулятор банкомата был остановлен. Ждём вас снова." << std::endl;
            statTxt = "The program has been terminated. Available: " + std::to_string(sumMon);
            saveStatToFile(statTxt);
        }

    } while (askTxt != "exit");


    system("pause");
    return 0;
}

// **************************

// Сумма в банкомате
int moneySum() {
    int res = 0;
    for (int i = 1; i < std::size(data); i++) {
        res += std::stoi(strData[i - 1]) * data[i];
    }
    return res;
}

// Получение текущей даты и времени
std::string dateNow() {
    std::string res = "";
    std::time_t curTime = time(0);
    std::string tt = ctime(&curTime);

    res = "<" + tt.substr(8, 2) + " " + tt.substr(4, 3) + " " +
          tt.substr(20, 4) + " " + tt.substr(11, 8) + "> ";

    return res;
}

// Выбор действия
std::string selectAction() {
    std::string resTxt = "";

    do {
        std::wcout << std::endl << L"Укажите действие с банкоматом:" << std::endl;
        std::wcout << L"\"+\" - заполнение банкомата;" << std::endl;
        std::wcout << L"\"-\" - снять деньги со счета;" << std::endl;
        std::wcout << L"\"exit\" - завершение работы симулятора" << std::endl;
        std::wcout << L"**************************************" << std::endl;
        std::wcout << L"Ваш выбор: ";
        std::getline(std::cin, resTxt);
        // Обрежем "случайные" пробелы до и после слова
        resTxt = truncSpaces(resTxt);

        if (resTxt.empty()) {
            std::wcerr << std::endl << L"Вы забыли сделать выбор! Попробуйте снова." << std::endl;
        } else if (resTxt != "+" && resTxt != "-" && resTxt != "exit") {
            std::wcerr << std::endl << L"Сделайте выбор из предложенных вариантов!" << std::endl;
        }

    } while (!(resTxt == "+" || resTxt == "-" || resTxt == "exit"));

    return resTxt;
}

// Отсечение пробелов в строке с двух сторон
std::string truncSpaces(std::string inTxt) {
    inTxt = std::regex_replace(inTxt, std::regex("^\\s+"), "");
    inTxt = std::regex_replace(inTxt, std::regex("\\s+$"), "");
    return inTxt;
}

// Генерируем случайное число в диапазоне
int randNum(int inStart, int inStop) {
    return inStart + std::rand() % (inStart - inStop + 1);
}

// Загрузка банкомата банкнотами
bool randDataFile() {
    int numTmp = 1000 - data[0], numRand = 0, numAll = 0;
    int sizeData = std::size(data);

    for (int i = 1; i < sizeData - 1; i++) {
        numRand = numTmp * randNum(40, 60) / 100;

        data[i] = (data[i] <= numRand) ? numRand : data[i];
        numAll += data[i];
        data[i] = (numAll > 1000) ? -(1000 - numAll) : data[i];
        numTmp -= data[i];
    }
    data[sizeData - 1] = (numAll <= 1000) ? 1000 - numAll : numTmp;
    numTmp = 0;

    for (int r = 1; r < sizeData; r++) {
        numTmp += data[r];
    }
    data[0] = numTmp;

    return saveDataToFile();
}

// Снятие денег со счета
int withdrawMoney() {
    int resSum = 0;
    bool valNum = true;
    std::string askTxt = "";

    do {
        std::wcout << std::endl << L"Укажите сумму для вывода средств:";
        std::getline(std::cin, askTxt);
        askTxt = truncSpaces(askTxt);
        if (!askTxt.empty()) {
            valNum = validNum(askTxt);
            resSum = (valNum) ? std::stoi(askTxt) : -1;

            if (resSum == -1) {
                return -1;
            } else if (resSum > sumMon) {
                std::wcerr << L"Банкомат не сможет выдать вам такую сумму!" << std::endl;
                valNum = false;
            } else if (resSum % 100 != 0) {
                std::wcerr << L"Банкомат может выдавать только "
                           << convWStr.from_bytes(std::to_string((resSum / 100) * 100)) << L" руб." << std::endl;
                valNum = false;
            } else {
                int numTmp = 0, bill = 0;

                for (int i = 1; i < std::size(data); i++) {
                    numTmp = std::stoi(strData[i - 1]);
                    if (resSum >= numTmp) {
                        bill = resSum / numTmp;
                        data[0] -= bill;
                        data[i] -= bill;
                        resSum %= numTmp;
                    }
                }
                valNum = true;
            }

        } else {
            std::wcerr << L"Вы забыли ввести значение! Попробуйте снова." << std::endl;
            valNum = false;
        }

    } while (!valNum);
    resSum = moneySum();
    resSum = (resSum > 0) ? resSum : 0;
    resSum = (saveDataToFile()) ? resSum : -1;
    return resSum;
}

// Запись в файл данных Data[]
bool saveDataToFile() {
    std::ofstream file;

    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try {
        file.open(fileDataName, std::ios::out | std::ios::binary | std::ios::trunc);
        file.write((char *) data, sizeof(data));

    } catch (const std::ofstream::failure &e) {
        file.close();
        std::wcout << L"Не удалось создать/записать файл! Программа будет закрыта." << std::endl;
        return false;
    }
    file.close();
    return true;
}

// Загружаем данные из файла с данными
bool loadDataFromFile() {
    std::ifstream file;

    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try {
        file.open(fileDataName, std::ios::in | std::ios::binary);
        file.read((char *) data, sizeof(data));

    } catch (const std::ifstream::failure &e) {
        file.close();
        std::wcout << L"Ошибка чтения данных из файла! Программа будет закрыта." << std::endl;
        return false;
    }
    file.close();
    return true;
}

// Запись в файл статистики
void saveStatToFile(std::string &inTxt) {
    std::ofstream file;

    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try {
        file.open(fileStatName, std::ios::out | std::ios::app);
        file << dateNow() << inTxt << "\n";

    } catch (const std::ofstream::failure &e) {
        file.close();
        std::wcout << L"Ошибка записи файла статистики! Программа будет закрыта." << std::endl;
        system("pause");
    }
    file.close();
}

// Проверим значения в файле
bool validNum(std::string &inTxt) {
    bool res = true;

    for (char ch: inTxt) {
        res &= (ch >= '0' && ch <= '9') ? true : false;
    }

    return res;
}

void errToStat() {
    statTxt = "Emergency shutdown of the program!";
    saveStatToFile(statTxt);
};