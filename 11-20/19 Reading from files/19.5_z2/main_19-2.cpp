// Задание 19.5.2. Разработка просмотрщика текстовых файлов

#include<iostream>
#include<fstream>
#include<vector>

std::string inFilePath(std::string);                    // Ввод пути и названия файла
void readFile(std::vector<std::vector<std::string>> &, const std::string &); // Чтение данных из файла
void printVec(std::vector<std::vector<std::string>> const &); // Печать вектора

int main () {
    char buff[150];
    int num = 0;
    
    std::cout << std::endl << "A text file viewer." << std::endl;
    std::string pathFile = inFilePath("Specify the path to the file: "); 

    std::ifstream file (pathFile, std::ios::in | std::ios::binary);

    if (!file) {
        std::cerr << std::endl << "The file was not found! The program will be closed." << std::endl;
        file.close();
        system("pause");
        return -1;
    }

    std::cout << std::endl << "******* This text from file *********" << std::endl << std::endl;

    while (!file.eof()) {   
        num = sizeof(buff) + 1;
        file.read(buff, num - 1);

        if (file.eof()) {
            num = file.gcount();
            char temp [num];
            memcpy(temp, buff, num);
            temp[num] = '\0';
            std::cout << temp;

        } else {

            buff[num] = '\0';                
            std::cout << buff;
        }    
    }

    std::cout << std::endl << std::endl << "*************************************" << std::endl;

    system("pause");
    return 0;
}

// **************************

// Ввод пути и названия файла
std::string inFilePath(std::string inTxt) {
    std::string resTxt = "", tmpTxt = "";
    bool openFile = true;

    do {        
        std::cout << std::endl << inTxt;
        getline(std::cin, tmpTxt);

        if(tmpTxt.empty()) {
            std::cout << std::endl << "You forgot to enter the value! Try again." <<  std::endl;
             
        } else {

            if (tmpTxt.find((char)92) || tmpTxt.find((char)47)) {

                for(int i = 0; i < tmpTxt.size(); i++) {
                    if(tmpTxt[i] == (char)92) {
                        resTxt.push_back((char)92);
                        resTxt.push_back((char)92);           
                    } else {
                        resTxt.push_back(tmpTxt[i]);
                    }
                } 
            }             
        }               

    } while(tmpTxt.empty());    

    return resTxt;
}
