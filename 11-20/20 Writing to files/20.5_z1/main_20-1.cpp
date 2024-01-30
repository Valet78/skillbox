// Задание 20.5.1. Запись в ведомость учёта
#include<iostream>
#include<fstream>

std::string inputNameComp (std::string);    // Ввод именных компонентов
std::string inputDate (std::string);        // Ввод даты
std::string inputPay (std::string);         // Ввод суммы выплат
bool validDigit (std::string);              // Проверка валидности чисел

int main () {
    std::string fileName = "vedomost.txt";
    setlocale(LC_ALL, "ru_RU.utf8");
    std::ofstream file;  

    std::string firstName = "", lastName = "", dateTxt = "", payments = "";
    
   
    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
        file.open(fileName, std::ios::out | std::ios::binary | std::ios::app);

        file << firstName << lastName << dateTxt << payments << '\n';


        file.close();
    }
    catch(const std::ofstream::failure & e)
    {
        std::cerr << "Error (code: " << e.code() << ")! " << e.what() << std::endl;
        std::cerr << "Error opening a file or writing data to a file! The program will be closed." << std::endl;
    }

    return 0;
}


// ********************************

// Ввод именных компонентов
std::string inputNameComp (std::string) {

}

// Ввод даты
std::string inputDate (std::string) {

}

// Ввод суммы выплат
std::string inputPay (std::string) {


} 

// Проверка валидности чисел
bool validDigit (std::string) {


} 

