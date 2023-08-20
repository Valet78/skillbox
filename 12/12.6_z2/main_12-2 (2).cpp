// Задание 12.5.2. Сортировка

#include <iostream>

std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
std::string CheckInputNumber(std::string); // Ввод элемента массива
bool ValidNumber(std::string); // Проверка чисел

int main(){
    std::string inMassive [15];

    std::cout << "A program for sorting an array of floating-point numbers." << std::endl;
    std::string inputTxt = CheckInputOfEmpty("Enter 15 fractional numbers separated by a space: ");

    bool valid = true;
    int indNull = 0, ind = 0;

    do {
        indNull = inputTxt.find(' ');
        inMassive[ind] = inputTxt.substr(0, indNull);
        valid &= (ValidNumber(inMassive[ind]));
        
        inputTxt = inputTxt.substr(indNull + 1, inputTxt.length() - indNull);
        ind++;        
    } while (indNull > 0 && ind < 15);
   
    // Проверка правильности ввода
    if(!valid || ind < 15 || indNull > 0){
        std::cout << std::endl << "Error! The program is waiting for the input of 15 fractional numbers. " << 
                     "The program will be completed." << std::endl << std::endl;
        return 0;
    }
    
    



    


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
    std::string res = "";
    bool valid = true;
    do {
        res = CheckInputOfEmpty(inTxt);
        if (ValidNumber(res)){
            valid = true;
        } else {
            valid = false;
            std::cout << "Incorrect data has been entered! Try again." << std::endl; 
        }
    } while (!valid);
    
    return res;
} 


// Проверка чисел
bool ValidNumber(std::string inTxt){
    bool res = true;
    int point = 0;

    for(int i = 0; i < inTxt.length(); i++){
        point += (inTxt[i] == '.') ? 1 : 0;
        res &= ((inTxt[i] >= '0' && inTxt[i] <= '9') || inTxt[i] == '.');         
    }

    res &= (point == 1);
    
    return res;
} 


