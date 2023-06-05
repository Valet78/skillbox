/*
Задание 5.6.2. Полёт нормальный!

Напишите программу для аэропорта, проверяющую, правильным ли эшелоном летит самолёт. Его скорость должна быть в диапазоне от 750 до 850 км/ч, а высота — в диапазоне от 9000 до 9500 метров.
*/

#include <iostream>
using namespace std;

int ValidInt (string inTxt){
  int result = 0;
  cout << inTxt;
  while(!(cin >> result) || result < 0){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа больше нуля !" << endl;
    cout << inTxt; 
  }    
  return result;
}

int main() {
  cout << "Программа проверки нахождения самолёта в заданном эшелоне." << endl;
  int speed = ValidInt("Укажите скорость: ");
  int height = ValidInt("Укажите высоту: ");
  cout << "-----------------------------" << endl;

  if((speed >= 750 && speed <= 850) && (height >= 9000 && height <= 9500)){
    cout <<  "Самолёт находится в заданном эшелоне." << endl;
  } else {
    cout <<  "Самолёту необходимо откорректировать свой курс." << endl;
  }

  return 0;
}