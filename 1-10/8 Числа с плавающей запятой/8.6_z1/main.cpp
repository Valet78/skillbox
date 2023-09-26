/*
Задание 8.6.1. Космический симулятор

Вы пишете симулятор космических полётов. Ваш звездолёт массой m килограмм включает двигатель с 
силой тяги F ньютонов на t секунд. Напишите программу, которая по заданным F, m и t покажет, на 
каком расстоянии от первоначального положения окажется космический корабль через t секунд. 
Обеспечьте контроль ввода.

Примечание: космический корабль находится в открытом космосе.

Напоминаем, что расстояние можно рассчитать по формуле:
(a*t*t)/2 , где a = F/m

Рекомендации по выполнению
Для операции возведения в степень удобно использовать функцию std::pow.
В расчётах используются переменные типа float.
Что оценивается
Правильно использована формула.
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
        std::cout << "Введите число больше нуля!" << std::endl;
      } else { 
        err = false;
      }
    } else {
      std::cout << "Вы не ввели число! Попробуйте снова." << std::endl;
    }  
  } while (err);

  return result;
}

int main() {
  std::cout << "Программа - симулятор космических полётов для рассчёта " << std::endl;
  std::cout << "преодалённого расстояния от начальной точки за указанное время. " << std::endl;
  int powerValue = ValidNum("Укажите значение силовой тяги двигателя (ньютон): ");
  int weight = ValidNum("Введите зачение массы звездолёта (кг): ");
  int time = ValidNum("Введите время работы силовой установки (сек): ");
  std::cout << "--------------------------------------------------------------------" << std::endl;

  float distanse = (powerValue * std::pow(time, 2)) / (float) (2 * weight);

  std::cout << "При указанных параметрах звездолёт преодолеет " << distanse << " м" << std::endl;
  return 0;
}