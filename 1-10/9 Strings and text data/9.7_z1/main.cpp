/*
9.7.1. Время в пути

Поезд отправляется в AA часов BB минут и прибывает в пункт назначения в CC часов DD минут.
Сколько часов и минут он находится в пути?

Напишите программу, которая принимает от пользователя две строки — время отправления и 
время прибытия поезда. Время задаётся строкой из пяти символов в формате HH:MM. 
Обеспечьте контроль ввода, убедитесь также, что время корректно.

Программа должна ответить, сколько часов и минут поезд находится в пути. Если время 
отправления больше времени прибытия, считайте, что поезд прибывает в пункт назначения 
на следующий день.

Примеры выполнения    Введите время отправления (HH:MM): 09:20
                      Введите время прибытия (HH:MM): 10:20
                      Поездка составила 1 ч. 0 мин.
                      Введите время отправления (HH:MM): 09:20
                      Введите время прибытия (HH:MM): 08:40
                      Поездка составила 23 ч. 20 мин.

Что оценивается
Программа корректно считает и время в течение суток, и время поездки с прибытием 
на следующий день.
Обеспечен контроль ввода и по длине строк, и по вводимым символам.
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

// Проверка формата ввода времени
std::string InTimeTxt(std::string inTxt){  
  std::string result = "";
  bool err;

  do  {
    result = InputTxt(inTxt);
    if (result.length() == 5){
      if ((((result[0] == '0' || result[0] == '1') && (result[1] >= '0' && result[1] <= '9'))
          || (result[0] == '2' && (result[1] >= '0' && result[1] < '4')))
          && (result[2] == ':')
          && ((result[3] >= '0' && result[3] < '6') && (result[4] >= '0' && result[4] <= '9'))) {
        err = false;
      } else {
        err = true;
        std::cout << "Введены некорректные данные! Попробуйте снова." << std::endl;
      }
    } else {
      err = true;
      std::cout << "Введены некорректные данные! Попробуйте снова." << std::endl;
    }
    
  } while (err);
  
  return result;
}

// Вычисляем числа из 2 чар
int CharToInt (char numOne, char numTwo){
  std::string resTxt(1, numOne);
  resTxt.push_back(numTwo);
  return std::stoi(resTxt);
}


int main() {

  std::string inTimeStart = InTimeTxt("Введите время отправления (HH:MM): "); 
  std::string inTimeStop = InTimeTxt("Введите время прибытия    (HH:MM): ");  
  std::cout << "----------------------------------------" << std::endl;

  int hourStart = CharToInt(inTimeStart[0], inTimeStart[1]);
  int minStart = CharToInt(inTimeStart[3], inTimeStart[4]);
  int hourStop = CharToInt(inTimeStop[0], inTimeStop[1]);
  int minStop = CharToInt(inTimeStop[3], inTimeStop[4]);
  int hour = 0, minutes = 0;
  int timeStart = hourStart * 60 + minStart;
  int timeStop = hourStop * 60 + minStop;

  if (timeStart <= timeStop){
    hour = (timeStop - timeStart) / 60;
    minutes = (timeStop - timeStart) % 60;
    
  } else {
    hour = (1440 - timeStart + timeStop) / 60;
    minutes = (1440 - timeStart + timeStop) % 60;    
  }  

  std::cout << "Поездка составила " << hour << " ч. " << minutes << " мин." << std::endl;  

  return 0;
}