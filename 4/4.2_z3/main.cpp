/*
Задача 3. Модуль числа.

Напишите программу, которая вычисляет модуль числа.

Подсказка: чтобы обратить знак числа в переменной ‘x’ надо писать вот так: x = - x.
*/

#include <iostream>

int main() {
  int inNum = 0;

  std::cout << "Для определения модуля целого числа" << std::endl;
  std::cout << "укажите его: ";
  std::cin >> inNum;

  if(inNum < 0) inNum = -inNum;

  std::cout << "Модуль числа: " << inNum << std::endl;
  
  return 0;
}