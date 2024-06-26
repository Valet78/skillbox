/*
Задание 7.5.4. Рамка

Напишите программу, которая рисует с помощью символьной графики прямоугольную рамку. 
Для вертикальных линий используйте символ вертикального штриха «|», 
а для горизонтальных — дефис «-». Пусть пользователь вводит ширину и высоту рамки.

Пример выполнения  6 — ширина, 4 — высота:
                  |----|
                  |    |
                  |    |
                  |----|

Что оценивается
Рамка рисуется в соответствии с заданными размерами и с помощью условных конструкций
и циклов.
*/

#include <iostream>


// Проверка ввода строки и пустого ввода
std::string InputTxt(std::string inTxt){
  std::string result = "";
   do{
    std::cout << inTxt;
    getline(std::cin, result);
    if (result == ""){
      std::cout << "Вы забыли ввести значение! Попробуйте снова." << std::endl;
    } 
  } while(result == ""); 
  return result;
}

// Является ли числом
bool IsDigit(std::string inTxt){
  // int point = 0;
  int ind = 0;
  
  for (int i = 0; i < inTxt.length(); i++){
    if (i == 0 && inTxt[0] == '-'){
      ind++;
    } else if (int(inTxt[i]) >= 48 && int(inTxt[i] <= 57)){
      ind++;
    }  else {
      ind--;
    }
  }     
  
  if (ind == inTxt.length()){
    return true;
  }  
  return false;
}

// Проверка ввода числа и вывод его
int ValidNum(std::string request){
  int result = 0;
  std::string numTxt = "";
  bool err = true;

  do {
    numTxt = InputTxt(request);
    if (IsDigit(numTxt)){
      result = std::stoi(numTxt);
      if (result <= 0){
        std::cout << "Введите число, больше нуля!" << std::endl;
      } else { 
        err = false;
      }
    } else {
      std::cout << "Введённое значение не число! Попробуйте снова." << std::endl;
    }  
  } while (err);

  return result;
}

int main() {
  std::cout << "Программа построения рамки по Вашим размерам." << std::endl;
  int width = ValidNum("\tукажите ширину: ");
  int height = ValidNum("\tукажите высоту: ");

  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      if (w == 0 || w == width - 1) {
        std::cout << "|";
      } else if ((h == 0 || h == height - 1) && (w  > 0 && w < width)) {
        std::cout << "-";
      } else {
        std::cout << " ";
      }
      
    }
  std::cout << std::endl;
  }    
  
  return 0;
}