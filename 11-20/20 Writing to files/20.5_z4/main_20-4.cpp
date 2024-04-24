// Задание 20.5.4. Симуляция работы банкомата
#include "main_20-4.h"

int main() {
    std::string askTxt = "", tmp = "";
    std::string fileName = "status.bin";
    std::srand(std::time(nullptr));     // Для генерации случайных чисел

    bool fValid = validReadFile(fileName); // Проверим наличие файла и заполним массив данных
    if (!fValid) {
        std::cerr << "An error in the structure of the \"" << fileName <<
                  "\" file has been detected! The program will be closed." << std::endl;
        system("pause");
        return -1;
    }

    do {
        system("CLS");
        std::cout << std::endl << "\t*** Simulator of ATM operation. ***" << std::endl;
        sumMon = moneySum();
        std::cout << "Available: " << std::to_string(sumMon) << " rub." << std::endl;
        askTxt = selectAction();

        // Выбираем дальнейшие действия
        if (askTxt == "+") {

            fValid = randLoadFile(fileName); // Загрузка банкомата банкнотами
            if (!fValid) {
                std::cerr << std::endl << "The data is incorrect or data could not be written to the \"" << fileName
                          << "\" file! The program will be closed." << std::endl;
                return -1;
            } else {
                std::cout << "The ATM is replenished with banknotes and is ready to work." << std::endl;
            }

        } else if (askTxt == "-") {
            int withdrawSum = withdrawMoney(fileName);

            if (withdrawSum == -1) {
                std::cerr << std::endl << "Error! Data could not be written to the \"" << fileName
                          << "\" file! The program will be closed." << std::endl;
                return -1;
            } else if (withdrawSum == 0) {
                std::cerr << std::endl << "It is necessary to replenish the ATM!" << std::endl;
            } else {
                std::cout << "The ATM is replenished with banknotes and is ready to work." << std::endl;
            }

        } else {
            std::cerr << std::endl << "The ATM simulator has been stopped. We are waiting for you again." << std::endl;
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

// Выбор действия
std::string selectAction() {
    std::string resTxt = "";

    do {
        std::cout << std::endl << "Specify the action with the ATM:" << std::endl;
        std::cout << "\"+\" - add banknotes;" << std::endl;
        std::cout << "\"-\" - withdraw money from the account;" << std::endl;
        std::cout << "\"exit\" - end the session." << std::endl;
        std::cout << "**************************************" << std::endl;
        std::cout << "Your choice:";
        std::getline(std::cin, resTxt);
        // Обрежем "случайные" пробелы до и после слова
        resTxt = truncSpaces(resTxt);

        if (resTxt.empty()) {
            std::cerr << std::endl << "You forgot to make a choice! Try again." << std::endl;
        } else if (resTxt != "+" && resTxt != "-" && resTxt != "exit") {
            std::cerr << std::endl << "Make a choice from the suggested options! Try again." << std::endl;
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

// Открытие файла и проверка
bool validReadFile(std::string &nameFile) {
    bool res = true;
    std::string arg1 = "", arg2 = "";
    int index = 0, numSum = 0;
    std::ifstream file;

    file.exceptions(std::fstream::badbit | std::fstream::failbit);
    try {
        file.open(nameFile, std::ios::binary | std::ios::in);

        while (!file.eof()) {
            file >> arg1 >> arg2;
            if (index == 0) {
                res &= (arg1 == "status" && validNum(arg2));
            } else {
                res &= (std::find(begin(strData), end(strData), arg1) != end(strData) &&
                        validNum(arg2));
            }

            if (res) {
                data[index] = std::stoi(arg2);
            }

            index++;
        }

        for (int i = 1; i < std::size(data); i++) { // Проверка суммарного значения и значения status
            numSum += data[i];
        }

        res &= (numSum == data[0] && numSum >= 0 && numSum <= 1000) ? true : false;

    } catch (const std::ofstream::failure &e) {
//        std::cerr << "Error opening a file or reading data!" << std::endl <<
//                  "Check the file availability \"" << nameFile << "\"." << std::endl <<
//                  "The program will be closed." << std::endl;
        return false;
    }
    return res;
}

// Проверим значения в файле
bool validNum(std::string &inTxt) {
    bool res = true;

    for (char ch: inTxt) {
        res &= (ch >= '0' && ch <= '9') ? true : false;
    }

    return res;
}

// Генерируем случайное число в диапазоне
int randNum(int inStart, int inStop) {
    return inStart + std::rand() % (inStart - inStop + 1);
}

// Загрузка банкомата банкнотами
bool randLoadFile(std::string &inFile) {
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

    return saveToFile(inFile);
}

// Запись в файл
bool saveToFile(std::string &inFile) {
    std::ofstream file;
    int sizeData = std::size(data);

    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try {
        file.open(inFile, std::ios::out | std::ios::binary | std::ios::trunc);
        for (int i = 0; i < sizeData; i++) {

            if (i == 0) {
                file << "status " << data[0] << "\n";
            } else if (i < sizeData - 1) {
                file << strData[i - 1] << " " << data[i] << "\n";
            } else {
                file << strData[i - 1] << " " << data[i];
            }
        }

    } catch (const std::ofstream::failure &e) {
//        std::cerr << "Error (code: " << e.code() << ")! " << e.what() << std::endl;
//        std::cerr << "Error opening a file or writing data to a file! The program will be closed." << std::endl;
        file.close();
        return false;
    }
    file.close();
    return true;
}

// Снятие денег со счета
int withdrawMoney(std::string &inFile) {
    int resSum = 0;
    bool valNum = true;
    std::string askTxt = "";

    do {
        std::cout << std::endl << "Specify the amount to withdraw:";
        std::getline(std::cin, askTxt);
        askTxt = truncSpaces(askTxt);
        if (!askTxt.empty()) {
            valNum = validNum(askTxt);
            resSum = (valNum) ? std::stoi(askTxt) : -1;

            if (resSum == -1) {
                return -1;
            } else if (resSum > sumMon || resSum <= 0) {
                std::cerr << "The ATM will not be able to give you such an amount!" << std::endl;
                return 0;
            } else if (resSum % 100) {
                std::cerr << "The ATM can only issue " << (resSum / 100) * 100 << " rub." << std::endl;
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
            }
            valNum = true;

        } else {
            std::cerr << "You forgot to enter the value! Try again." << std::endl;
            valNum = false;
        }

    } while (!valNum);

    resSum = (saveToFile(inFile)) ? resSum : -1;
    return resSum;
}

