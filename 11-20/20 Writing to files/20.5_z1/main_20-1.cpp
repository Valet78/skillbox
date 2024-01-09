// Задание 20.5.1. Запись в ведомость учёта
#include<iostream>
#include<fstream>


std::string getPath(std::string);   // Получение полного пути (с преобразованием) к папке с файлами

int main () {
    std::string pathFull = getPath(__FILE__);       // Полный путь к исполняемому файлу
    
    std::ofstream file (pathFull + "vedomost.txt", std::ios::binary);    

    if (file.is_open()) {
        file << "hjgdfskjdhg  lsdh дл цуацуаилоицу " << std::endl;
    } else {
        std::cout << "Error write!" << std::endl; 
    }
    
    file.close();



    return 0;
}


// ********************************

// Получение полного пути (с преобразованием) к папке с файлами 
std::string getPath(std::string inTxt) {
    std::string resTxt = "";
    int ind = inTxt.find_last_of((char) 92) + 1;
    inTxt = inTxt.substr(0, ind);

    for(int i = 0; i < inTxt.size(); i++) {
            if(inTxt[i] == (char)92) {
                resTxt.push_back((char)92);
                resTxt.push_back((char)92);           
            } else {
                resTxt.push_back(inTxt[i]);
            }
        }

    return resTxt;
}





/*
// Задание 19.5.3. Реализация программы чтения ведомости


#include <vector>


bool fileExist(std::string);        // Проверяет наличие файла
void vecFillData(const std::string &, std::vector<std::vector<std::string>> &); // Заполнение вектора данными
void printVec(std::vector<std::vector<std::string>> const &);      // Печать вектора

int main() {
    std::vector <std::vector<std::string>> vecData;
    
    std::string fileName = "tabl.txt";
    pathFull += fileName;
    int sumMoney = 0, maxMoney = 0, indMax = 0, tmp = 0;

    if(!fileExist(pathFull)) {
        std::cout << std::endl;
        std::cout << "The file \"" << fileName << "\" was not found! The program will be closed.";
        std::cout << std::endl << std::endl;
        system("Pause");
        return -1;

    } else {
                
        vecFillData(pathFull, vecData);

        for(int i = 0; i < vecData.size(); i++) {
            tmp = std::stoi(vecData[i][2]);
            sumMoney += tmp;

            if(tmp > maxMoney) {
                indMax = i;
                maxMoney = tmp;
            }
        }    
        
        std::cout << "*****************************************" << std::endl;
        std::cout << "The amount of payments: " << sumMoney << std::endl;
        std::cout << vecData[indMax][0] << " " << vecData[indMax][1] << " has the maximum payout: " << maxMoney;
        std::cout << std::endl << std::endl;

        // printVec(vecData);

    }    
    
    system("Pause");
    return 0;
}

// Проверяет наличие файла
bool fileExist(std::string inPath) {    
    std::ifstream file (inPath);   
    bool res = (file.is_open()) ? true : false;       
    file.close();
    return res;
}

// Заполнение вектора данными
void vecFillData(const std::string &inFileName, std::vector<std::vector<std::string>> &inVec) {
    std::vector <std::string> tmpVec;
    std::string fName = "", sName = "", uDate = "", uMoney = "";
        
    std::fstream file;
    file.open(inFileName);
    std::cout << std::endl;

    while (!file.eof()) {
        file >> fName >> sName >> uMoney >> uDate;
        tmpVec.push_back(fName);
        tmpVec.push_back(sName);
        tmpVec.push_back(uMoney);
        tmpVec.push_back(uDate);
        inVec.push_back(tmpVec);
        tmpVec.clear();
    }

    file.close();
}

// Печать вектора
void printVec(std::vector<std::vector<std::string>> const &inVec) {
    std::cout << std::endl << "******* This text from file *********" << std::endl << std::endl;

    for (auto rv = inVec.begin(); rv != inVec.end(); rv++) {

        for (const auto &col: *rv) {
            std::cout << col;
        }
        std::cout << std::endl;
    }
                
    std::cout << std::endl << "*************************************" << std::endl;
} 



*/