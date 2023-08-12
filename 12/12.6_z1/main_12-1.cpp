// Задание 12.5.1. Многоквартирный дом

#include <iostream> 

std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
std::string CheckInputLastName(std::string); // Ввод фамилий жильцов 
std::string CheckInputNumber(std::string); // Ввод номера квартиры
bool ValidLastName (std::string); // Проверка ввода фамилии
bool ValidNumber(std::string); // Проверка чисел

int main (){
    
    std::string lastName[10];
    std::cout << "Enter the names of the tenants of the house in order:" << std::endl;
    
    for(int i = 0; i < 10; i++){
        lastName[i] = CheckInputLastName (std::to_string(i + 1) + ". ");    
    } 

    // std::string lastName[10] = {"SidorovA", "IvanovA", "PetrovA", "SidorovB", "IvanovB", 
                                // "PetrovB", "SidorovC", "IvanovC", "PetrovC", "SidorovD"}; 
    
    std::cout << "-----------------------------------------------------" << std::endl;

    std::cout << "You can get information about the residents of three apartments." << std::endl;
    
    std::string numTxt = "";
    int k = 0, num = 0;
    bool valid = true;

    do{
        numTxt = CheckInputNumber("Enter the apartment numbers: ");
        num = std::stoi(numTxt);
        if(num > 0 && num <= 10){
            std::cout << lastName[num - 1] << std::endl;
            k++;
            valid = true;
        } else {
            std::cout << "Incorrect data has been entered! Try again." << std::endl;
            valid = false;
        }



    } while(k < 3 || !valid);

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

// Ввод фамилиё жильцов с проверкой
std::string CheckInputLastName(std::string inTxt){
    std::string res = "";
    bool valid = true;
    do {
        res = CheckInputOfEmpty(inTxt);
        if (ValidLastName(res)){
            valid = true;
        } else {
            valid = false;
            std::cout << "Incorrect data has been entered! Try again." << std::endl; 
        }
    } while (!valid);
    
    return res;
}

// Ввод номера квартиры
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

// Проверка ввода фамилии
bool ValidLastName (std::string inTxt){
    bool res = true;

    for(int i = 0; i < inTxt.length(); i++){
        res &= (inTxt[i] >= 'A' && inTxt[i] <= 'Z') ||
               (inTxt[i] >= 'a' && inTxt[i] <= 'z');
    }
    
    return res;
} 

// Проверка чисел
bool ValidNumber(std::string inTxt){
    bool res = true;

    for(int i = 0; i < inTxt.length(); i++){
        res &= (inTxt[i] >= '0' && inTxt[i] <= '9');
    }
    
    return res;
} 
