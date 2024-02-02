// Задание 20.5.1. Запись в ведомость учёта
#include<iostream>
#include<fstream>

std::string inputNameComp (std::string);    // Ввод именных компонентов
std::string inputDate (std::string);        // Ввод даты
std::string inputPay (std::string);         // Ввод суммы выплат
bool validDigit (std::string);              // Проверка валидности чисел
bool validDate(std::string);                // Проверка вводимой даты

int main () {
    std::string fileName = "vedomost.txt", request = "yes";
    // setlocale(LC_ALL, "ru_RU.utf8");
    setlocale(LC_ALL, "RUS");
    std::ofstream file;  

    std::string firstName = "", lastName = "", dateTxt = "", payments = "";
    
   
    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
        do {
            if (request == "yes"){
                file.open(fileName, std::ios::out | std::ios::binary | std::ios::app);
                std::cout << std::endl;
                firstName = inputNameComp("Enter the employee's name: ");
                lastName = inputNameComp("Enter the employee's last name: ");
                dateTxt = inputDate("Enter the payment accrual date (DD.MM.YYYY): ");
                payments = inputPay("Specify the amount of payments: ");

                file << firstName << " " << lastName << " " << dateTxt << " " << payments << '\n';
                file.close();
                std::cout << "The data has been successfully entered into the file." << std::endl << std::endl;
            } 
            do {
                std::cout << "Would you like to add more data (yes/no)? ";
                std::getline(std::cin, request);
                if (request.empty() || !(request == "yes" || request == "no")) {
                    std::cerr << std::endl <<  "The answer is incorrect! Specify." <<std::endl << std::endl;
                }
            } while (request.empty() || !(request == "yes" || request == "no")); 

        } while (request == "yes");
    
    } catch(const std::ofstream::failure & e) {
        std::cerr << "Error (code: " << e.code() << ")! " << e.what() << std::endl;
        std::cerr << "Error opening a file or writing data to a file! The program will be closed." << std::endl;
    }

    return 0;
}


// ********************************

// Ввод именных компонентов
std::string inputNameComp (std::string inTxt) {
    std::string tempTxt = "";
    
    do {
        std::cout << inTxt;
        std::getline(std::cin, tempTxt);

        if (tempTxt.empty()) {
            std::cout << "You forgot to enter the data! Try again." << std::endl;
        }

    } while (tempTxt.empty());

    return tempTxt;
}

// Ввод даты
std::string inputDate (std::string inTxt) {
    std::string tempTxt = "";
    bool valid = true;
    
    do {
        valid = true;
        std::cout << inTxt;
        std::getline(std::cin, tempTxt);

        if (tempTxt.empty()) {
            std::cerr << "You forgot to enter the data! Try again." << std::endl;
            valid = false;
        } else {
            valid = validDate(tempTxt);

            if (!valid) {
                std::cerr << "An incorrect payment date has been entered! Try again." << std::endl;
            }
        }       

    } while (!valid);
    
    return tempTxt;
}

// Ввод суммы выплат
std::string inputPay (std::string inTxt) {
std::string tempTxt = "";
    bool valid = true;
    
    do {
        valid = true;
        std::cout << inTxt;
        std::getline(std::cin, tempTxt);

        if (tempTxt.empty()) {
            std::cerr << "You forgot to enter the data! Try again." << std::endl;
            valid = false;
        } else {
            valid = validDigit(tempTxt);

            if (!valid) {
                std::cerr << "An incorrect payment date has been entered! Try again." << std::endl;
            }
        }       

    } while (!valid);
    
    return tempTxt;
} 

// Проверка валидности чисел
bool validDigit (std::string inTxt) {
    bool res = true;

     for (char ch : inTxt) {
        res &= (ch >= '0' && ch <= '9') ? true : false;              
    }

    return res;
} 

// Проверка вводимой даты
bool validDate(std::string inTxt) {
    bool res = (inTxt.length() == 10) ? true : false;
    int poz = 0;
    
    for (char ch : inTxt) {

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
        bool visYear = (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0)) ? true : false;     // Проверка високосный ли год

        if (manth == 1 || manth == 3 || manth == 5 || manth == 7 || manth == 8 || manth == 10 || manth == 12) {
            res &= (day >= 1 && day <=31) ? true : false;
        
        } else if (manth == 4 || manth == 6 || manth == 9 || manth == 11) {
            res &= (day >= 1 && day <=30) ? true : false;
            
        } else if (manth == 2 && visYear) {
            res &= (day >= 1 && day <=29) ? true : false;
            
        } else if (manth == 2 && !visYear) {
            res &= (day >= 1 && day <=28) ? true : false;
            
        } else {
            res = false;
        }
    }

    return res;
}