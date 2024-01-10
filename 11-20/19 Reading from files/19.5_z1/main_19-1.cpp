// Задание 19.5.1. Разработка программы поиска слов в файле

#include<iostream>
#include<fstream>
#include<vector>
#include<filesystem>

std::string getPath(std::string);   // Получение полного пути (с преобразованием) к папке с файлами
std::string inText(std::string);    // Ввод искомого текста, слова

int main(int argc, char* argv[]) {
    std::string pathFull = getPath(argv[0]) + "words.txt";       // Полный путь к исполняемому файлу
    std::string txt = "";
    int count = 0;

    std::ifstream file(pathFull, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "The file was not found! The program will be closed." << std::endl;
        file.close();
        system("pause");
        return -1;
    }    
   
    std::string searchWord = inText("Enter the meaning of the word you are looking for: "); 
    std::cout << std::endl;

    while (!file.eof()) {        
        file >> txt;

        if (txt == searchWord) {
            count++;
        }
    } 

    std::cout << "The required text \"" << searchWord << "\" occurs " << count << 
        " times in the file." << std::endl << std::endl; 

    file.close();
    system("pause");
    return 0;
}
// *************************

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

// Ввод искомого текста, слова
std::string inText(std::string inTxt) {
    std::string resTxt = "";

    do {
        std::cout << std::endl << inTxt;
        std::getline(std::cin, resTxt);

        if(resTxt.empty()) {
            std::cout << std::endl << "You forgot to enter the value! Try again." <<  std::endl;
        }
    } while(resTxt.empty());

    return resTxt;
}

