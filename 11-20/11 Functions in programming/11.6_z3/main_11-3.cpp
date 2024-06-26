// Программа оценки корректности ввода IP-адреса 
#include <iostream>


std::string InputTxt(std::string); // Проверка ввода строки и пустого ввода
bool isNum(char); // Проверяем символ, является ли он числом
bool ValidDec(std::string); // Проверяем правильность части адресса

int main (){
    std::cout << "A program for evaluating the correctness of entering an IP address." << std::endl;
    std::string inAdress = InputTxt("Enter the IP address: ");
    std::cout << std::endl;
    int indPoint = 0;
    std::string part = "";
    bool valid = !(inAdress.find("..") < inAdress.length()); // Проверка наличия повторяющейся точки

    for(int i = 0; i < 3; i++){
      indPoint = inAdress.find('.');

      if(indPoint > inAdress.length()){
        valid &= false;
        break;
      } 

      part = inAdress.substr(0, indPoint);
      valid &= (ValidDec(part));
      inAdress = inAdress.substr(indPoint + 1, inAdress.length() - indPoint);      
    }

    valid &= !(inAdress.find(".") < inAdress.length());
    valid &= (ValidDec(inAdress));
    
    if(valid) {
      std::cout << "Valid" << std::endl;
    } else {
      std::cout << "Invalid" << std::endl;
    }

    std::cout << std::endl;

    return 0;
}


// Проверка ввода строки и пустого ввода
std::string InputTxt(std::string inTxt){
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

// Проверяем символ, является ли он числом
bool isNum(char inChar){
    return ((inChar >= '0' && inChar <= '9'));
}

// Проверяем правильность части адресса
bool ValidDec(std::string inTxt){
  int len = inTxt.length();
  int value = 0;
  bool validIn = (len > 0 && len < 4);

  validIn &= !(len == 2 && inTxt[0] == '0');
  validIn &= !(len == 3 && (inTxt[0] == '0' || (inTxt[0] == '0' && inTxt[1] == '0')));

  if (validIn){
      
    for(int i  = 0; i < len; i++){
      validIn &= isNum(inTxt[i]);
    }

    value = (validIn) ? std::stoi(inTxt) : -1;
    validIn &= (value >= 0 && value <= 255);
  }
   
  return validIn;
}
