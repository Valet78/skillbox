// Задание 19.5.5. Реализация игры «Что? Где? Когда?»

#include<iostream>
#include<fstream>

enum sector {
    FIRST = 1, SECOND = 2, THIRD = 4, FOURTH = 8,
    FIFTH = 16, SIXTH = 32, SEVENTH = 64, EIGHTH = 128,
    NINTH = 256,  TENTH = 512, ELEVENTH = 1024, TWELFTH = 2048,
    THIRTEENTH = 4096
};

std::string getCurrPath(std::string);           // Получение текущего адреса директории
bool fileExist(const std::string &, const std::string &);  // Проверка наличия файла
bool validDigit(std::string);                   // Проверка правильности ввода числа
int selectSector(int, std::string, int &);     // Выбор сектора
std::string serchText(const std::string, int);    // Поиск текста в файле


int main() {    
    const std::string currentPath = getCurrPath(__FILE__);
    std::string ansTxt = "", questTxt = "";
    bool valid = fileExist(currentPath, "answers.txt") & fileExist(currentPath, "questions.txt");
    int scoreAudience = 0, scorePlayers = 0;
    int curSec = 0, stateSec = 8191, round = 1;


    if(!valid){
        std::cout << std::endl << "Two files are required for the program to work: answers.txt and questions.txt" << std::endl;
        std::cout << "The specified files were not found or were read with an error! The program will be closed." << std::endl << std::endl;
        return -1;
    } 

    std::cout << std::endl << "The program of the game \"What? Where? When?\"" << std::endl << std::endl; 

    do {
        std::cout << std::endl << "***** Round " << round << " *****" << std::endl;
        std::cout << "Score (players/spectators): " << scorePlayers << " / " << scoreAudience << std::endl;

        curSec = selectSector(curSec, "How many sectors should the top turn? ", stateSec);
        std::cout << "Sector " << std::to_string(curSec + 1) << std::endl;
        
        questTxt = serchText(currentPath + "questions.txt", curSec + 1);
        std::cout << "Question: "  << questTxt;

        system("pause");

        ansTxt = serchText(currentPath + "answers.txt", curSec + 1);
        std::cout << std::endl << "Right answer: " << ansTxt;

        do {
            std::cout << "Should I count the answer (yes/no)? ";
            std::getline (std::cin, ansTxt);

            if (ansTxt == "yes") {
                scorePlayers++;
            } else if (ansTxt =="no") {
                scoreAudience++;
            } else {
                std::cout << "Incorrect data has been entered. Try again." << std::endl;
            }

        } while (!(ansTxt == "yes" || ansTxt =="no"));
        
        round++;
    } while(scoreAudience != 6 && scorePlayers != 6 && round < 12);


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
int selectSector(int inCurSec, std::string inTxt, int &stateSector) {
    std::string numSecTxt = "";
    bool valid = true;
    
    do {
        std::cout << std::endl << inTxt;
        std::getline(std::cin, numSecTxt);
        
        if(numSecTxt.empty()) {
            valid &= false;
            std::cout << "You forgot to specify the number! Try again." << std::endl; 
        
        } else if(!validDigit(numSecTxt)){
            valid &= false;
            std::cout << "Incorrect data has been entered! Try again." << std::endl; 
        } 

    } while (!valid);
    
    int numSec = (std::stoi(numSecTxt) % 13 + inCurSec) % 13;
    int ind = 0;

    do {
        valid = true;
        ind = (1 << numSec);
        
        switch (ind) {
            case FIRST:
                if(!(stateSector & FIRST)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~FIRST;
                }
                break;
            
            case SECOND:
                if(!(stateSector & SECOND)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~SECOND;
                }
                break;

            case THIRD:
                if(!(stateSector & THIRD)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~THIRD;
                }
                break;
                
            case FOURTH:
                if(!(stateSector & FOURTH)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~FOURTH;
                }
                break;

            case FIFTH:
                if(!(stateSector & FIFTH)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~FIFTH;
                }
                break;

            case SIXTH:
                if(!(stateSector & SIXTH)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~SIXTH;
                }
                break;                
                
            case SEVENTH:
                if(!(stateSector & SEVENTH)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~SEVENTH;
                }
                break;

            case EIGHTH:
               if(!(stateSector & EIGHTH)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~EIGHTH;
                }
                break;

            case NINTH:
                if(!(stateSector & NINTH)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~NINTH;
                }
                break;
                
            case TENTH:
                if(!(stateSector & TENTH)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~TENTH;
                }
                break;
                
            case ELEVENTH:
                if(!(stateSector & ELEVENTH)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~ELEVENTH;
                }
                break;
                
            case TWELFTH:
                if(!(stateSector & TWELFTH)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~TWELFTH;
                }
                break;
                
            case THIRTEENTH:
                if(!(stateSector & THIRTEENTH)) {
                    numSec = (numSec + 1) % 13;
                    valid &= false;
                } else {
                    stateSector &= ~THIRTEENTH;
                }
                break;
                
            } 
            
    } while(!valid);

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
    std::string resTxt = "", tempTxt;     

    std::ifstream file(fileName);
    
    while (std::getline(file, tempTxt)) {

        if (tempTxt.find("Question " + std::to_string(inSect)) != std::string::npos) {
            
            while (std::getline(file, tempTxt)) {
                if (tempTxt.find("Question " + std::to_string(inSect + 1)) != std::string::npos) {
                    break; 
                } else {
                    resTxt += tempTxt;
                    resTxt += "\n\t";
                }
            }           
        }
    }

    return resTxt;
}  



