/*
Дан текст с информацией о персонаже игры. Напишите программу, которая выводит этот текст. 
Вынесите из текста все числа в переменные, придумайте для них хорошие имена и выведите на экран. 
*/

#include <iostream>

int main(){


  int turnNumber = 4;
  int speedShum = 358;
  int incrementPower = 254, incrementManage = 49;
  int incrementGrip = 93;
  int negativeWind = 21, negativeRain = 17;
  

  std::cout << "===================\n";
  std::cout << "Супер гонки. Круг " << turnNumber << "\n";
  std::cout << "===================\n";
  std::cout << "\nШумахер (" << speedShum << ")\n";
  std::cout << "===================\n";
  std::cout << "Водитель: Шумахер\n";
  std::cout << "Скорость: " << speedShum << "\n";
  std::cout << "-------------------\n";
  std::cout << "Оснащение\n";
  std::cout << "Двигатель: +" << incrementPower << "\n";
  std::cout << "Колеса: +" <<  incrementGrip << "\n";
  std::cout << "Руль: +" << incrementManage << "\n";
  std::cout << "-------------------\n";
  std::cout << "Действия плохой погоды\n";
  std::cout << "Ветер: -" << negativeWind << "\n";
  std::cout << "Дождь: -" << negativeRain << "\n";

  return 0;
}