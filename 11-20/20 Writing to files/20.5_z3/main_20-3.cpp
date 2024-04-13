// Задание 20.5.3. Симуляция игры «Рыбалка»

#include <iostream>
#include <fstream>
#include <ctime>
//#include <array>

std::string fish[] = {"pike", "pikeperch", "carp", "eal", "bream", "trout", "vobla", "sturgeon",
                      "roach", "ruffe", "salmon", "bass", "catfish", "die", "redeye", "smelt"};


bool createRiverTxt();                  // Заполним файл river.txt случайным образом
std::string repRequest(std::string&);  // Запрос повторения программы
std::string fishRequest(std::string&); // Запрос вида рыбки для ловли

int main () {
    setlocale(LC_ALL, "ru_RU.utf8");
    std::srand(std::time(nullptr));
    std::string reqRepeat = "yes", askTxt = "", askFish = "";

    do {
        if (!createRiverTxt()) {     // Выходим из программы при ошибке создания/записи в файл river.txt
            system("pause");
            return -1;
        }

        std::cout << std::endl << "Simulation of the game \"Fishing\"!" << std::endl;
        // здесь указать виды рыб из массива





        askTxt = "\nWhat kind of fish do you want to catch? ";
        askFish = fishRequest(askTxt);       // Спрашиваем, что будем ловить?


        // Будем еще рыбачить?
        askTxt = "\nWould you like to catch some more fish (yes/no)? ";
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
                fileRiver << fish[std::rand() % std::size(fish)];
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
std::string fishRequest(std::string&) {


    return "122";
}