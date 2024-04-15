// Задание 20.5.3. Симуляция игры «Рыбалка»

#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <regex>

std::string fish[] = {"pike", "pikeperch", "carp", "eal", "bream", "trout", "vobla", "sturgeon",
                      "roach", "ruffe", "salmon", "bass", "catfish", "die", "redeye", "smelt"};
int sizeFish = std::size(fish);

bool createRiverTxt();                  // Заполним файл river.txt случайным образом
std::string repRequest(std::string&);   // Запрос повторения программы
std::string fishRequest(std::string&);  // Запрос вида рыбки для ловли
int fishSearchToRiver(std::string&);    // Ищем рыбку в реке
bool fishToBasket(std::string&);        // Складываем рыбку в корзинку

int main () {
    int catchFish = 0;
    setlocale(LC_ALL, "ru_RU.utf8");
    std::srand(std::time(nullptr));
    std::string reqRepeat = "yes", askTxt = "", askFish = "";

    // Очистим файл basket.txt перед заполнением
    std::ofstream fileBasket("basket.txt", std::ios::trunc);
    fileBasket.close();

    do {
        if (!createRiverTxt()) {     // Выходим из программы при ошибке создания/записи в файл river.txt
            system("pause");
            return -1;
        }

        std::cout << std::endl << "Simulation of the game \"Fishing\"!" << std::endl;
        std::cout << "The following fish are found in the river: ";
        for(int i = 0; i < sizeFish; i++) {
                std::cout << fish[i];
                if(i < sizeFish - 1) {
                    std::cout << ", ";
                } else {
                    std::cout << ".";
                }
        }
        std::cout << std::endl;

        askTxt = "\nWhat kind of fish are we going to catch? ";
        askFish = fishRequest(askTxt);       // Спрашиваем, что будем ловить?

        catchFish = fishSearchToRiver (askFish);       // Считаем улов

        if (catchFish == -1) {          // Если не удалось открыть один из файлов, выходим из программы
            return -1;
        } else if (catchFish > 0) {
            std::cout << "Congratulations to you! You were able to catch " << catchFish << " " << askFish << "." <<  std::endl;
        } else if (catchFish == 0) {
            std::cout << "We're sorry, but you didn't manage to catch any fish! I'll be lucky another time." << std::endl;
        }

        askTxt = "\nShall we cast the bait again (yes/no)? ";     // Будем еще рыбачить?
        reqRepeat = repRequest(askTxt);
    } while (reqRepeat == "yes");

    std::cout << std::endl << "Thank you for using the program. We will be glad to see you again." << std::endl;
    system("pause");
    return 0;
}

// *********************************

// Заполним файл river.txt случайным образом
bool createRiverTxt() {
    int numFish = 68 + std::rand() % 33;
    std::string fileName = "river.txt";
    std::ofstream fileRiver;

    fileRiver.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
        {
            fileRiver.open(fileName, std::ios::out | std::ios::binary | std::ios::trunc);
            for(int i = 0; i < numFish; i++) {
                fileRiver << fish[std::rand() % sizeFish];
                if (i < numFish - 1) fileRiver << '\n';
            }

            fileRiver.close();

    } catch(const std::ofstream::failure & e) {
        std::cerr << "Error (code: " << e.code() << ")! " << e.what() << std::endl;
        std::cerr << "Error opening a file or writing data to a file! The program will be closed." << std::endl;
        fileRiver.close();
        return false;
    }

    return true;
}

// Запрос повторения программы
std::string repRequest(std::string& inTxt) {
    std::string tmpTxt = "";
    do {
        std::cout << inTxt;
        std::getline(std::cin, tmpTxt);

        if(tmpTxt.empty()) {
            std::cout << "You haven't answered the question! Try again." << std::endl;
        } else if (!(tmpTxt == "yes" || tmpTxt == "no")) {
            std::cout << "Answer - " << tmpTxt.size() << std::endl;
            std::cout << "Answer only \"yes\" or \"no\"! Try again." << std::endl;
        }

    } while (!(tmpTxt == "yes" || tmpTxt == "no"));

    return tmpTxt;
}

// Запрос вида рыбки для ловли
std::string fishRequest(std::string& inTxt) {
    std::string tmpTxt = "";
    bool validFish = true;

    do {
        std::cout << inTxt;
        std::getline(std::cin, tmpTxt);
        // Обрежем "случайные" пробелы до и после слова
        tmpTxt = std::regex_replace(tmpTxt, std::regex("^\\s+"), "");
        tmpTxt = std::regex_replace(tmpTxt, std::regex("\\s+$"), "");

        if(tmpTxt.empty()) {
            std::cout << "You haven't answered the question! Try again." << std::endl;
            validFish = false;
        } else {

            validFish = (std::find(begin(fish), end(fish), tmpTxt) != end(fish)) ? true : false;
            if(!validFish) {
                std::cout << "Such fish are not found in the river! Choose from the above." << std::endl;
            }
        }

    } while (!validFish);

    return tmpTxt;
}

// Ищем рыбку в реке
int fishSearchToRiver (std::string& inTxt) {
    std::string tmpTxt = "";
    std::string fileName = "river.txt";
    int numCatch = 0;
    std::ifstream fileRiver;


    fileRiver.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
        fileRiver.open(fileName, std::ios::in | std::ios::binary);

        while(!fileRiver.eof()) {
            std::getline(fileRiver, tmpTxt);

            if(tmpTxt == inTxt) {
                if(fishToBasket(tmpTxt)) {
                    numCatch++;
                } else {
                    fileRiver.close();
                    return -1;
                }
            }
        }

        fileRiver.close();

    } catch(const std::ofstream::failure & e) {
        std::cerr << "Error (code: " << e.code() << ")! " << e.what() << std::endl;
        std::cerr << "Error opening a file or reading data from a file! The program will be closed." << std::endl;
        fileRiver.close();
        return -1;
    }

    return numCatch;
}

// Складываем рыбку в корзинку
bool fishToBasket(std::string& inTxt) {
    std::string fileName = "basket.txt";
    std::ofstream fileBasket;

    fileBasket.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
        fileBasket.open(fileName, std::ios::out | std::ios::binary | std::ios::app);
        fileBasket << inTxt << '\n';
        fileBasket.close();

    } catch(const std::ofstream::failure & e) {
        std::cerr << "Error (code: " << e.code() << ")! " << e.what() << std::endl;
        std::cerr << "Error opening a file or writing data to a file! The program will be closed." << std::endl;
        fileBasket.close();
        return false;
    }

    return true;
}
