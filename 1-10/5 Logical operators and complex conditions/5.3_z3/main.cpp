/*
Задача 5.3.3. Треугольник.
У меня есть три деревянных палочки, длины этих палочек равны A, B и C. 
Напишите программу, которая по данным длинам определяет, можно ли из этих трех палочек
сложить треугольник.

Подсказка: треугольник сложить нельзя, если суммарная длина каких-либо двух палочек меньше или равна длины оставшейся палочки.
*/
#include <iostream>
using namespace std;

int ValidInt (string inTxt){
  int result = 0;
  cout << inTxt;
  while(!(cin >> result) || result <= 0){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа больше нуля!" << endl;
    cout << inTxt; 
  }    
  return result;
}

int main() {
  string backTxt = "";
  cout << "Программа проверит возможность сложить треугольник из палочек длиной:" << endl;
  int section_1 = ValidInt("введите длину одной из палочек: ");
  int section_2 = ValidInt("введите длину второй палочки: ");
  int section_3 = ValidInt("введите длину третьей палочки: ");

  int sum_1 = section_1 + section_2;
  int sum_2 = section_1 + section_3;
  int sum_3 = section_2 + section_3;

  if (sum_1 > section_3 && sum_2 > section_2 && sum_3 > section_1) {
    backTxt = "можно сложить треугольник.";
  } else {
    backTxt = "сложить треугольник не получится.";
  }

  cout << "Из палочек длиной " <<  section_1 << ", " << section_2 << " и "
      << section_3 << " см. " << backTxt << endl;
  
  return 0;
}