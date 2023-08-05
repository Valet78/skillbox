// Задание 11.6.2. Программа оценки корректности ввода E-mail адреса

#include <iostream>


std::string InputTxt(std::string); // Проверка ввода строки и пустого ввода
bool isLatAndNum(char);  // Проверяем символ, является ли он символом латиницы или числом
bool ValidPart(std::string, std::string);  // Проверка ввода первой и второй частей адреса
int SearchDog(std::string ); // Возвращаем индекс символа '@'

int main(){
    std::string partOne = "", partTwo = "";    

    std::cout << "Program for evaluating the correctness of entering an E-mail address" << std::endl;
    std::string inEmail = InputTxt("Enter your email address: ");
    int indDog = SearchDog(inEmail);    
    
    if(indDog != -1){
      partOne = inEmail.substr(0, indDog);
      partTwo = inEmail.substr(indDog + 1, inEmail.length() - indDog);

      bool validOne = partOne.length() >= 1 && partOne.length() <= 64 && ValidPart(partOne, "-.!#$%&'*+-/=?^_`{|}~");
      bool validTwo = partTwo.length() >= 1 && partTwo.length() <= 63 && ValidPart(partTwo, "-.");

      std::cout << std::endl;
      
      if(validOne && validTwo)  {
        std::cout << "\tYes." << std::endl;
      } else {
        std::cout << "\tNo." << std::endl;
      }
    } else {
      std::cout << std::endl;
      std::cout << "\tNo." << std::endl;
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

// Проверяем символ, является ли он символом латиницы или числом
bool isLatAndNum(char inChar){
    return ((inChar >= 'A' && inChar <= 'Z') || (inChar >= 'a' && inChar <= 'z') ||
            (inChar >= '0' && inChar <= '9'));
}

// Возвращаем индекс символа '@'
int SearchDog(std::string inTxt){
    int ind = 0;
    for(int i = 0; i < inTxt.length(); i++){
      if(ind != 0 && inTxt[i] == '@'){
        ind = -1;
      } else if (inTxt[i] == '@') {
        ind = i;
      }
    }
    return ind;
}

// Проверка ввода первой и второй частей адреса
bool ValidPart(std::string inTxt, std::string simv){
  bool valid = true;

  valid &= !(inTxt.find("..") < inTxt.length()); // Проверка наличия повторяющейся точки

  for(int i = 0; i < inTxt.length(); i++){
    valid &= !((i == 0 || i == inTxt.length() - 1) && inTxt[i] == '.');
    valid &= (isLatAndNum(inTxt[i]) || (simv.find(inTxt[i]) < simv.length()));
  }

  return valid;
}
