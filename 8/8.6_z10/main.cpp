/*
Задание 8.6.10. Тяжело в учении, легко в бою* (дополнительное задание)

Вы встретились со своим старым другом, который тоже изучает программирование, правда, в другом учебном
заведении. За чашкой кофе он пожаловался, что сумасбродный препод дал задание написать программу, 
которая из двух введённых чисел определяет наибольшее, не используя при этом условных операторов и
циклов. Радуясь, что на вашем курсе такого не требуют, вы всё-таки решаете помочь своему другу. 
Напишите для него эту программу.

Рекомендации по выполнению
Попробуйте решить это задание с помощью арифметических операций и простых математических функций.

Что оценивается
Решение не является просто функцией std::max.
*/

#include <iostream>
#include <cmath>

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
  int ind = 0;
  
  for (int i = 0; i < inTxt.length(); i++){
    if (i == 0 && inTxt[0] == '-' || inTxt[i] == '.'){
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

// Проверка ввода числа и вывод его (Float)
float ValidNumFloat(std::string request){
  float result = 0.0f;
  std::string numTxt = "";
  bool err = true;

  do {
    numTxt = InputTxt(request);
    if (IsDigit(numTxt)){
      result = std::stof(numTxt);
      err = false;      
    } else {
      std::cout << "Введите вещественное число! Попробуйте снова." << std::endl;
    }  
  } while (err);
  
  return result;
}

int main() {
  std::cout << "Программа определения максимального числа из двух." << std::endl;
  float numOne = ValidNumFloat("Введите первое число: ");
  float numTwo = ValidNumFloat("Введите второе число: ");
  std::cout << "--------------------------------------------------" << std::endl;
  float max = 0.0f;

  if (numOne >= 0 && numTwo >= 0){
    if (numOne > numTwo) {
      max = numOne;
    } else {
      max = numTwo;
    }
  } else if (numOne >= 0 && numTwo < 0){
    max = numOne;
  } else if (numOne < 0 && numTwo >= 0){
    max = numTwo;
  } else {
    if (std::abs(numOne) < std::abs(numTwo)){
      max = numOne;
    } else {
      max = numTwo;
    }
  }
  std::cout << "Из указанных чисел максимальным будет: " << max << std::endl;
  return 0;  
}