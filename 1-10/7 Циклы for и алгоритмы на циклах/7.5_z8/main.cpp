/*
Задание 7.5.8. Ёлочка* (дополнительное задание)

Напишите программу, которая выводит на экран равнобедренный треугольник, заполненный
символами решётки «#». Пусть высота треугольника вводится пользователем. 
Обеспечьте контроль ввода.

Пример выполнения   Введите высоту ёлочки: 5                  
                          #
                         ###
                        #####
                       #######
                      #########

Рекомендации по выполнению
Решение можно организовать с помощью двух циклов, один для вывода пробельных символов,
второй для вывода символа решётки.
Что оценивается
Между строкой ввода и верхушкой ёлочки не должно быть пустых строк.
Высота ёлочки соответствует значению, введённому с клавиатуры.
Ёлочка рисуется с помощью циклов.
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
  std::cout << "Программа нарисует ёлочку заданной высоты." << std::endl;
  int height = ValidNum ("Укажите высоту ёлочки: ");

  for (int h = 1; h <= height; h ++){
    for (int b = 0; b < height - h; b ++){
      std::cout << " ";      
    } 
    for (int s = 0; s < h * 2 - 1; s ++){
      std::cout << "#";
    }
    std::cout << std::endl;    
  }   
}