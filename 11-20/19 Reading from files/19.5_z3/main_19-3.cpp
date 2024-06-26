// Задание 19.5.3. Реализация программы чтения ведомости

#include<iostream>
#include<fstream>
#include <vector>

// std::string getPath(std::string);   // Получение полного пути (с преобразованием) к папке с файлами
bool validNum(std::string);         // Проверка ввода числа

int main(int argc, char* argv[]) {    
    // std::string pathFull = getPath(argv[0]) + "tabl.txt";       // Полный путь к файлу включая его имя    
    std::string pathFull = "tabl.txt";                              // Относительная адресация
    int sumMoney = 0, maxMoney = 0;
    std::string nameFirst = "", nameLast = "", moneyTxt = "", dateTxt = "";
    std::string nameFirstMax = "", nameLastMax = "", moneyTxtMax = "", dateTxtMax = "";

    std::ifstream file(pathFull, std::ios::in | std::ios::binary);
    
    if(!file.is_open()) {
        file.close();
        std::cerr << std::endl << "The file was not found! The program will be closed.";
        std::cout << std::endl << std::endl;
        system("Pause");
        return -1;
    }         

    while (!file.eof()) { 
        file >> nameFirst >> nameLast >> moneyTxt >> dateTxt;
        
        if (validNum(moneyTxt)) {
            sumMoney += stoi(moneyTxt);

            if (stoi(moneyTxt) > maxMoney) {
                nameFirstMax = nameFirst;
                nameLastMax = nameLast;
                moneyTxtMax = moneyTxt;
                dateTxtMax = dateTxt;
                maxMoney = stoi(moneyTxt);
            }        
        } else {
            std::cerr << std::endl << "The data in the file is incorrect! The program will be closed.";
            std::cout << std::endl << std::endl;
            system("Pause");
            return -1;
        }
    }

    file.close();
    std::cout << std::endl << "*****************************************" << std::endl;
    std::cout << "The amount of payments: " << sumMoney << std::endl;
    std::cout << nameFirstMax << " " << nameLastMax << " has the maximum payout: " << moneyTxtMax;
    std::cout << std::endl << std::endl;    
    system("Pause");
    return 0;
}

// ********************************

// // Получение полного пути (с преобразованием) к папке с файлами 
// std::string getPath(std::string inTxt) {
//     std::string resTxt = "";
//     int ind = inTxt.find_last_of((char) 92) + 1;
//     inTxt = inTxt.substr(0, ind);

//     if (inTxt.find((char)92) || inTxt.find((char)47)) {
//         for(int i = 0; i < inTxt.size(); i++) {
//                 if(inTxt[i] == (char)92) {
//                     resTxt.push_back((char)92);
//                     resTxt.push_back((char)92);           
//                 } else {
//                     resTxt.push_back(inTxt[i]);
//                 }
//             }
//     }

//     return resTxt;
// }

// Проверка ввода числа
bool validNum(std::string inTxt) {
    bool res = (inTxt.empty()) ? false: true; 

    for (int i = 0; i < inTxt.size(); i++) {   
        res &= inTxt[i] >= '0' && inTxt[i] <= '9';   
    }

    return res;
} 
