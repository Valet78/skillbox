// Задание 13.6.1. Работа свекторами

#include <iostream>
#include <vector>

std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
std::string CheckInputNumber(std::string); // Проверка на ввод числа
bool ValidNumber(std::string); // Проверка чисел
int InputDigit(std::string, bool);    // Ввоод и получения одного положительного числа
std::vector<std::string> GetArrayStrings(std::string);   // Получение вектора строк из строки
std::vector<int> RemovingNumberFromVector(std::vector<int>, int); // Удаление числа из вектора


int main(){
    std::cout << "The program removes the specified number from the vector." << std::endl;
    std::string inNumNTxt = "";
    int inNumN = InputDigit("Specify the number of elements: ", true);
    
    
    std::cout << "Enter the specified number of numbers separated by a space." << std::endl;
    std::vector<std::string> inputVecTxt;
    
    do{
        inputVecTxt = GetArrayStrings(CheckInputOfEmpty("Specify the sequence of numbers: "));
        if(inputVecTxt.size() != inNumN){
            std::cout << "Incorrect number of digits entered! Try again." << std::endl;
        }
    } while (inputVecTxt.size() != inNumN);
    
    std::vector <int> vecNum(inNumN);

    for(int i = 0; i < inNumN; i++){
        if(ValidNumber(inputVecTxt[i])){
            vecNum[i] = std::stoi(inputVecTxt[i]);
        } else{
            std::cout << "The sequence is incorrect! The program will be completed." << std::endl;
            return -1;
        }
    }
    
    int inNumDel = InputDigit("Specify the number to remove from the vector: ", false);
    vecNum = RemovingNumberFromVector(vecNum, inNumDel);
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Result of deleting a number: ";

    // вывод вектора
    for(int i = 0; i < vecNum.size(); i++){
        std::cout << vecNum[i] << " ";
    }
    std::cout << std::endl << std::endl;

    return 0;
}


// Проверка ввода строки и пустого ввода
std::string CheckInputOfEmpty(std::string inTxt){
  std::string result = "";

   do{
    std::cout << inTxt;
    getline(std::cin, result);
    if (result == ""){
      std::cout << "You forgot to enter the value! Try again." << std::endl;
    } 
  } while(result == ""); 

  return result;
}

// Ввод элемента массива
std::string CheckInputNumber(std::string inTxt){
    std::string resTxt = "";    
    bool valid = true;

    do {
        resTxt = CheckInputOfEmpty(inTxt);
        if (ValidNumber(resTxt)){
            valid = true;
        } else {
            valid = false;
            std::cout << "Incorrect data has been entered! Try again." << std::endl; 
        }
    } while (!valid);
    
    return resTxt;
} 


// Проверка чисел
bool ValidNumber(std::string inTxt){
    bool res = true;

    if(inTxt.length() == 1 && inTxt[0] == '0'){
        res = true;
    } else {
        for(int i = 0; i < inTxt.length(); i++){
            res &= ((inTxt[i] >= '0' && inTxt[i] <= '9') || inTxt[0] == '-');         
        }
    }        
    return res;
} 

// Получения числа
int InputDigit(std::string inTxt, bool gtZero){
    std::string resTxt = "";
    int res = 0;

    do{
        resTxt = CheckInputNumber(inTxt);
        res = std::stoi(resTxt);
        if(gtZero && res <= 0) {
            std::cout << "Incorrect data has been entered! Try again." << std::endl;
        }
    } while(gtZero && res <= 0);
    return res;
}    

// Получение вектора строк из строки
std::vector<std::string> GetArrayStrings(std::string inTxt){
    std::vector <std::string> resVec;
    int indNull = 0;        

    do {
        indNull = inTxt.find(' ');
        resVec.push_back(inTxt.substr(0, indNull));                   
        inTxt = inTxt.substr(indNull + 1, inTxt.length() - indNull);            
    } while (indNull > 0);    

    return resVec;
}  

// Удаление числа из вектора
std::vector<int> RemovingNumberFromVector(std::vector<int> inVec, int inNum){
    std::vector<int> resVect; 
    int real = resVect.size();   
    
    for(int i = 0; i < inVec.size(); i++){
        if(inVec[i] != inNum){
           resVect.push_back(inVec[i]);            
        }
    }

    return resVect;
}