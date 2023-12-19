// Задание 19.5.1. Разработка программы поиска слов в файле

#include<iostream>
#include<fstream>
#include<vector>

std::string inText(std::string);    // Ввод искомого текста, слова
void readFile(std::vector<std::string> &, const std::string &);    // Заполнение ветора из файла
void printVec(std::vector<std::string> &);        // Вывод вектора данных
int searchText(const std::vector<std::string> &, const std::string);    // Поиск слова 

int main() {
    std::vector<std::string> vecFromFile;
    std::string fileName = "L:\\Users\\Fantik\\YandexDisk\\Project C++\\Skiilbox\\11-20\\19 Reading from files\\19.5_z1\\words.txt";

    std::string searchWord = inText("Enter the meaning of the word you are looking for: "); 
    std::cout << std::endl;
    readFile(vecFromFile, fileName);
    
    // std::cout << "Data from the file: "; 
    // printVec(vecFromFile);

    std::cout << "The required text \"" << searchWord << "\" occurs " << searchText(vecFromFile, searchWord) << 
        " times in the file." << std::endl; 
    
    return 0;
}
// *************************

// Ввод искомого текста, слова
std::string inText(std::string inTxt) {
    std::string resTxt = "";

    do {
        std::cout << std::endl << inTxt;
        getline(std::cin, resTxt);

        if(resTxt.empty()) {
            std::cout << std::endl << "You forgot to enter the value! Try again." <<  std::endl;
        }
    } while(resTxt.empty());

    return resTxt;
}

// Заполнение ветора из файла
void readFile(std::vector<std::string> &inVec, const std::string &nameFile) {
    std::string tempTxt = "";
    std::ifstream words;
    words.open(nameFile); //, std::ios::binary);

    while(!words.eof()) {
        words >> tempTxt;
        inVec.push_back(tempTxt);
    }

    words.close();
} 

// Вывод вектора данных
void printVec(std::vector<std::string> &inVec) {
    std::cout << " {";

    for(int i = 0; i < inVec.size(); i++) {
        std::cout << inVec[i];

        if(i < inVec.size() - 1){
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl << std::endl;
}

// Поиск слова
int searchText(const std::vector<std::string> &inVec, const std::string schTxt) {
    int count = 0;

    for(int i = 0; i < inVec.size(); i++) {
        count += (inVec[i] == schTxt) ? 1 : 0; 
    }
    return count;
}    
