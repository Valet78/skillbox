/*
Задание 8.6.6. Маятник

Известно, что амплитуда качающегося маятника с каждым разом затухает на 8,4% от амплитуды 
прошлого колебания. Если качнуть маятник, он, строго говоря, никогда не остановится: 
его амплитуда будет уменьшаться до тех пор, пока мы не сочтём такой маятник остановившимся.
Напишите программу, определяющую, сколько раз качнётся маятник, прежде чем он, по нашему
мнению, остановится. Программа получает на вход начальную амплитуду колебания в сантиметрах
и конечную амплитуду его колебаний, которая считается остановкой маятника. Обеспечьте 
контроль ввода.

Рекомендации по выполнению
Считаем, что затухание происходит на каждое качание.

Что оценивается
Программа правильно считает количество затуханий.
Цикл не бесконечный.
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

// Проверка ввода числа и вывод его (float)
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

int main() {
  std::cout << "Программа расчёта колебаний маятника." << std::endl;
  int startPoz = ValidNum("Укажите начальную амплитуду колебания (см): ");
  int stopPoz = ValidNum("Укажите конечную амплитуду колебания  (см): ");
  std::cout << "-----------------------------------------------" << std::endl;
  float current = (float) startPoz;
  int count = 1;

  while (current != stopPoz){
    current -= current * 0.084;
    if (current > stopPoz){
      count ++;
    } else {
      count --;
      current = (float) stopPoz;
    }    
  }
  std::cout << "Маятник совершит " << count << " колебаний(ия)." << std::endl;

  return 0;
}