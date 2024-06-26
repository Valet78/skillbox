// Задание 20.5.1. Запись в ведомость учёта
#include <iostream>
#include <fstream>
#include <ctime>


int inputSize (std::string);            // Ввод размеров картинки
bool validDigit (std::string);          // Проверка валидности чисел


int main () {
    std::string fileName = "pic.txt";
    std::ofstream file;
    std::string strPic = "";
    int sizeX = 0, sizeY = 0;
    std::srand(std::time(NULL));
   
    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
        file.open(fileName, std::ios::out | std::ios::binary | std::ios::trunc);
        std::cout << std::endl << "A program for drawing binary paintings." << std::endl;
        sizeX = inputSize("Specify the horizontal size of the painting (pixels):");
        sizeY = inputSize("Specify the height of the painting (pixels):");

        for(int y = 0; y < sizeY; y++) {

            for(int x = 0; x < sizeX; x++) {

                strPic.append(std::to_string(std::rand() % 2));
                strPic.append(" ");
            }
            file << strPic << '\n';
            strPic = "";
        }

        file.close();
        std::cout << "The data has been successfully entered into the file." << std::endl;

    } catch(const std::ofstream::failure & e) {
        std::cerr << "Error (code: " << e.code() << ")! " << e.what() << std::endl;
        std::cerr << "Error opening a file or writing data to a file! The program will be closed." << std::endl;
    }

    return 0;
}

// ********************************

// Ввод размеров картинки
int inputSize (std::string inTxt) {
    std::string tempTxt = "";
    bool valid = true;
    
    do {
        valid = true;
        std::cout << std::endl << inTxt;
        std::getline(std::cin, tempTxt);

        if (tempTxt.empty()) {
            std::cerr << std::endl << "You forgot to enter the data! Try again." << std::endl;
            valid = false;
        } else {
            valid = validDigit(tempTxt);

            if (!valid) {
                std::cerr << std::endl << "An incorrect payment date has been entered! Try again." << std::endl;
            }
        }       

    } while (!valid);
    
    return std::stoi(tempTxt);
} 

// Проверка валидности чисел
bool validDigit (std::string inTxt) {
    bool res = true;

     for (char ch : inTxt) {
        res &= (ch >= '0' && ch <= '9') ? true : false;              
    }

    return res;
}