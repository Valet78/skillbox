// Задание 19.5.4. Разработка детектора PNG-файла

#include<iostream>
#include<fstream>

std::string inputFilePath(std::string);         // Запрос и обработка пути к файлу
void validFilePNG(std::string);                 // Проверка соответствия файла формату PNG

int main(){
    std::cout << "The program checks the compliance of the specified file with the PNG format." << std::endl;
    std::string filePath = inputFilePath("Specify the path to the PNG file: ");
    std::cout << std::endl;

    if(filePath == "Error!") {
        std::cout << "The specified file does not exist or cannot be opened! The program will be closed." << std::endl;
        system("pause");
        return -1; 
    }
    
    validFilePNG(filePath);
    system("pause");
    return 0;
}

// **********************

// Запрос и обработка пути к файлу
std::string inputFilePath(std::string inTxt) {
    std::string tmpTxt = "";

    do {
        std::cout << std::endl << inTxt; 
        std::getline(std::cin, tmpTxt);

        if(tmpTxt.empty()) {
            std::cout << "You forgot to specify the path to the PNG file! Try again." << std::endl;              
        
        } else {
            int indSlash = tmpTxt.find_last_of('.');
            std::string extension = (indSlash > 0 && indSlash < tmpTxt.length()) ? tmpTxt.substr(indSlash + 1, 3) : "";

            if(extension != "png" || extension == "") {
                std::cout << "The file does not have a PNG extension! Try again." << std::endl;
                tmpTxt = "";

            } 
        }

    } while (tmpTxt.empty());

    // Форматируем адрес
    std::string resTxt = ""; 
    for(int i = 0; i < tmpTxt.size(); i++) {
            if(tmpTxt[i] == (char)92) {
                resTxt.push_back((char)92);
                resTxt.push_back((char)92);           
            } else {
                resTxt.push_back(tmpTxt[i]);
            }
        }
    
    // Проверим наличие файла
    std::ifstream file (resTxt);
    resTxt = (file.is_open()) ? resTxt : "Error!";       
    file.close();    

    return resTxt;
}

// Проверка соответствия файла формату PNG
void validFilePNG(std::string inTxt) {
    char readBuff[5];
    std::string text = "";
    int value = 0;
    std::ifstream file (inTxt, std::ios::binary);
    file.seekg(0);    
    file.get(readBuff, sizeof(readBuff));    
    file.close();

    if((int) readBuff[0] == -119 && (int) readBuff[1] == 80 && (int) readBuff[2] == 78 && (int) readBuff[3] == 71) {
        std::cout << "The specified file corresponds to the PNG format." << std::endl << std::endl;
    } else {
        std::cout << "The specified file does not match the PNG format!" << std::endl << std::endl;
    }
    
}