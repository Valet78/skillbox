// Задание 13.6.3. Работа с вектором, заполнение со смещением.

#include<iostream>
#include<vector>

std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
std::string CheckInputNumber(std::string); // Проверка на ввод числа
bool ValidNumber(std::string); // Проверка чисел
void PrintVector(std::vector<int>, int); // Вывод вектора на экран


int main(){
    std::vector<int> db(20);
    std::string inNumTxt = "";
    int inNum = 0, ind = 0;

    std::cout << "A program for filling a vector of limited size." << std::endl;
    std::cout << "Enter natural values to write to memory." << std::endl;
    std::cout << "To output data, enter \"-1\", to complete the program, enter \"-2\"." << std::endl;



    do {
        inNumTxt = CheckInputNumber("input number: ");
        inNum = stoi(inNumTxt);

        if(inNum == -2){
            return 0;
        } else if(inNum == -1){
            std::cout << "output: ";
            PrintVector(db, ind);                
        } else if(inNum >= 0){
            db[ind % 20] = inNum;
            ind++;
        } else{
            std::cout << "Incorrect data has been entered! Try again." << std::endl;
        }
    } while (inNum != -2);

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

// Проверка на ввод числа
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

// Вывод вектора на экран
void PrintVector(std::vector<int> inVect, int inStart){
    int ind = inStart % 20;

    if (inStart < 20){
        for(int i = 0; i < inVect.size(); i++){
            std::cout << std::to_string(inVect[i]) << " ";
        }

    } else {
        
        for(int i = ind; i < inVect.size(); i++){
        std::cout << std::to_string(inVect[i]) << " ";
        }

        for(int i = 0; i < ind; i++){
            std::cout << std::to_string(inVect[i]) << " ";
        }        
    }
    std::cout << std::endl;    
} 