/*
Задание 8.6.7. Друзья Оушена* (дополнительное задание)

Банковский сейф оборудован механическим кодовым замком, состоящим из N крутящихся ручек, каждая из
которых имеет K положений. Существует только одна комбинация положений всех N ручек, которая открывает
сейф. Чтобы его открыть, достаточно перебрать все существующие комбинации. На проверку одной комбинации
уходит в среднем T секунд, где T — вещественное число. Напишите программу, которая по заданным N, K и T
определяет время, которое потребуется для перебора всех комбинаций и гарантированного открытия сейфа. 
Не используйте циклы. Обеспечьте контроль ввода.

Рекомендации по выполнению
Для решения этого задания нужно вспомнить комбинаторику.

Что оценивается
Правильно определяется количество комбинаций.
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

// Проверка ввода числа и вывод его
int ValidNum(std::string request){
  int result = 0;
  std::string numTxt = "";
  bool err = true;

  do {
    numTxt = InputTxt(request);
    if (IsDigit(numTxt)){
      result = std::stoi(numTxt);
      if (result <= 0) {
        std::cout << "Введите значение больше нуля!" << std::endl;
      } else { 
        err = false;
      }
    } else {
      std::cout << "Введите целое число! Попробуйте снова." << std::endl;
    }  
  } while (err);
  
  return result;
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
      if (result <= 0) {
        std::cout << "Введите значение больше нуля!" << std::endl;
      } else { 
        err = false;
      }
    } else {
      std::cout << "Введите вещественное число! Попробуйте снова." << std::endl;
    }  
  } while (err);
  
  return result;
}

int main() {
  std::cout << "Программа расчёта времени открытия сейфа." << std::endl;
  int num_N = ValidNum ("Укажите количество вращающихся ручек на сейфе: ");
  int num_K = ValidNum ("Сколько положений может принять каждая ручка : ");
  float time = ValidNumFloat("Сколько времени требуется на проверку комбинации (с):  ");
  std::cout << "---------------------------------------------------------" << std::endl;

  int comb = std::pow(num_K, num_N);
  float sumTime = std::round(comb * time);
  std::cout << "Для перебора " << comb << " комбинаций потребуется " <<
    sumTime << " сек." << std::endl;
  
  if (sumTime > 60) {
    std::cout << "То есть ";

    if (sumTime >= 3600){
        int sumHour = sumTime / 3600;
        sumTime -= sumHour * 3600;
        std::cout << sumHour << " ч. ";
    } 
    if (sumTime >= 60) {
        int sumMin = sumTime / 60;
        sumTime -= sumMin * 60;
        std::cout << sumMin << " мин. ";
    } 
    
    std::cout << sumTime << " сек. " << std::endl;
  }  
  
  return 0;
}
