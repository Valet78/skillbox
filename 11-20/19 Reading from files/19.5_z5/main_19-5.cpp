// Задание 19.5.5. Реализация игры «Что? Где? Когда?»

#include<iostream>
#include<fstream>

std::string getCurrPath(std::string);               // Получение текущего адреса директории
bool fileExist(const std::string &, const std::string &);  // Проверка наличия файла
bool validDigit(std::string);                       // Проверка правильности ввода числа
int selectSector(int, std::string);                 // Выбор сектора
std::string serchText(const std::string, int);      // Поиск текста в файле
bool outOffGame[13] {false};                        // Статус секторов

int main(int argc, char* argv[]) {
    std::string ansTxt = "", questTxt = "", ansExpert = ""; 
    // С указанием полного адреса
    // const std::string currentPath = getCurrPath(argv[0]);    
    // std::ifstream file_1(currentPath + "answers.txt"), file_2 (currentPath + "questions.txt"); 
    
    // Относительная адресация    
    std::ifstream file_1("answers.txt"), file_2 ("questions.txt"); 
    
    bool valid = file_1.is_open() & file_2.is_open();
    file_1.close();
    file_2.close();         
    setlocale(LC_ALL, "ru_RU.utf8");
    

    // Если файлы отсутсвуют или их невозможно открыть
    if(!valid){
        std::cerr << std::endl << "Two files are required for the program to work: answers.txt and questions.txt" << std::endl;
        std::cerr << "The specified files were not found or were read with an error! The program will be closed." << std::endl << std::endl;
        system("pause");
        return -1;
        } 
    
    int scoreAudience = 0, scorePlayers = 0;
    int curSec = 0, round = 1;
    
    std::cout << std::endl << "The program of the game \"What? Where? When?\"" << std::endl << std::endl; 

    do {
        system("cls");
        std::cout << std::endl << "***** Round " << round << " *****" << std::endl;
        std::cout << "Score (players/spectators): " << scorePlayers << " / " << scoreAudience << std::endl;

        curSec = selectSector(curSec, "How many sectors should the top turn? ");
        std::cout << "Sector " << std::to_string(curSec + 1) << std::endl;

        // std::cout << "Status = { ";
        // for (bool itn : outOffGame) {
        //     std::cout << std::boolalpha << itn << " ";
        // }
        // std::cout << "}" << std::endl << std::endl;
        
        // questTxt = serchText(currentPath + "questions.txt", curSec + 1);
        questTxt = serchText("questions.txt", curSec + 1);

        if (questTxt == "Error! The file cannot be opened.") {
            std::cout << std::endl << questTxt  << " The program will be closed." << std::endl;
            return -1;
        }
        
        std::cout << "Question: " << questTxt;       
        // ansTxt = serchText(currentPath + "answers.txt", curSec + 1);
        ansTxt = serchText("answers.txt", curSec + 1);
        
        if (ansTxt == "Error! The file cannot be opened.") {
            std::cerr << std::endl << ansTxt  << " The program will be closed." << std::endl;
            return -1;
        }

        // std::cout << std::endl << "Right answer: " << ansTxt <<std::endl;

        do {
            std::cout << "Your answer, experts: ";
            std::getline (std::cin, ansExpert);            
            ansTxt.pop_back();              // Это для среды Windows удаляем \r\n
            ansTxt.pop_back();
            if (ansExpert.empty()) {
                std::cerr << "You forgot to enter the answer! Try again." << std::endl;
            }
            
            if (ansTxt == ansExpert) {
                scorePlayers++; 

            } else if (ansTxt != ansExpert) {
                scoreAudience++;
                
            } else {
                std::cout << "Incorrect data has been entered. Try again." << std::endl;
            }            
            
        } while (ansExpert.empty());
        
        round++;

    } while((scoreAudience != 6 || scorePlayers != 6) || (scoreAudience + scorePlayers) < 12);

    if (scorePlayers > scoreAudience) {
        std::cout << "The winner of the game was the audience!" << std::endl;
    } else {
        std::cout << "The experts became the winner of the game!" << std::endl;
    }
    
    system("pause");
    return 0;
}

// *******************

// Получение текущего адреса директории
std::string getCurrPath(std::string inTxt) {
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

// Проверка наличия файла
bool fileExist(const std::string &inPath, const std::string &inName) {
    std::ifstream file (inPath + inName);
    if(!file.is_open()) {
       file.close();
       return false;
    }
    file.close();
    return true;
}

// Выбор сектора
int selectSector(int inCurSec, std::string inTxt) {
    std::string numSecTxt = "";
    bool valid = true;
    
    do {
        std::cout << std::endl << inTxt;
        std::getline(std::cin, numSecTxt);
        valid = true;

        if(numSecTxt.empty()) {
            valid &= false;
            std::cerr << "You forgot to specify the number! Try again." << std::endl; 
        
        } else if(!validDigit(numSecTxt)){
            valid &= false;
            std::cerr << "Incorrect data has been entered! Try again." << std::endl; 
        } 

    } while (!valid);
    
    int numSec = (std::stoi(numSecTxt) % 13 + inCurSec) % 13;

    while (outOffGame[numSec]) {
        numSec = (numSec + 1) % 13;
    }
    outOffGame[numSec] = true;
    
    return numSec;
}      

// Проверка правильности ввода числа
bool validDigit(std::string inNum) {
    bool res = true;

    for(char num : inNum){        
        res &= ((int)(num - '0') >= 0 && (int)(num - '0') <= 9); 
    }
    return res;
}

// Поиск текста в файле
std::string serchText(const std::string fileName, int inSect) {    
    std::string resTxt = "", tempTxt = "", serchTxt = "";
    std::ifstream file(fileName, std::ios::in);    

    if (!file.is_open()) {
        return "Error! The file cannot be opened.";
    }     

    while (std::getline(file, tempTxt)) {
        serchTxt = "<Question " + std::to_string(inSect) + ">\r";
          
        if (tempTxt.find(serchTxt) != std::string::npos) {
            
            while (std::getline(file, tempTxt)) {
                serchTxt = "<Question " + std::to_string(inSect + 1) + ">\r";
                if (tempTxt.find(serchTxt) != std::string::npos) {
                    break; 
                } else {
                    resTxt += tempTxt;
                    if (tempTxt.find(' ') != std::string::npos){
                        resTxt += "\n\t";
                    }                    
                }
            }           
        }
        tempTxt = "";
    }

    file.close();
    return resTxt;
}  
