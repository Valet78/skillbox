// Задание 19.5.2. Разработка просмотрщика текстовых файлов

#include<iostream>
#include<fstream>
#include<vector>

std::string inFilePath(std::string);                    // Ввод пути и названия файла
void readFile(std::vector<std::vector<std::string>> &, const std::string &); // Чтение данных из файла
void printVec(std::vector<std::vector<std::string>> const &); // Печать вектора

int main() {
    std::vector<std::vector<std::string>> vecDataFile;

    std::cout << std::endl << "A text file viewer." << std::endl;
    std::string pathFile = inFilePath("Specify the path to the file: "); 

    readFile(vecDataFile, pathFile);
    printVec(vecDataFile);

    return 0;
}

// Ввод пути и названия файла
std::string inFilePath(std::string inTxt) {
    std::string resTxt = "", tmpTxt = "";
    bool openFile = true;

    do {        
        std::cout << std::endl << inTxt;
        getline(std::cin, tmpTxt);

        if(tmpTxt.empty()) {
            std::cout << std::endl << "You forgot to enter the value! Try again." <<  std::endl;
        }

        for(int i = 0; i < tmpTxt.size(); i++) {
            if(tmpTxt[i] == (char)92) {
                resTxt.push_back((char)92);
                resTxt.push_back((char)92);           
            } else {
                resTxt.push_back(tmpTxt[i]);
            }
        }

        std::ifstream file (resTxt);      
        
        if(!file.is_open()) {
            std::cout << "The file was not found! Try to specify a different path." << std::endl;
            openFile = false;
            tmpTxt = "";
            resTxt = "";
        } else {
            openFile = true;
        }

        file.close();

    } while(tmpTxt.empty() || !openFile);    

    return resTxt;
}

// Чтение данных из файла
void readFile(std::vector<std::vector<std::string>> &inVec, const std::string &inFileName) {
    int str = 0;
    std::vector <std::string> tmpVec;
    std::string tmpTxt = ""; 
    std::fstream fileData;
    fileData.open(inFileName);

    while(!fileData.eof()){
        getline(fileData,tmpTxt);
        tmpVec.push_back(tmpTxt);
        inVec.push_back(tmpVec);
    }

    fileData.close();
}

// Печать вектора
void printVec(std::vector<std::vector<std::string>> const &inVec) {
    
    for (std::vector<std::vector<std::string>> row: inVec)
    {
        for (std::vector<std::string> val: row) {
            std::cout << val << "\n";
        }
        std::cout << std::endl;
    }
} 
