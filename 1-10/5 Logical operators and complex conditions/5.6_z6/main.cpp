/*
Задание 5.6.6. Усложнение задачи про кирпич

На видео мы с вами писали программу для проверки, удастся ли засунуть кирпич определённых
размеров в определённое прямоугольное отверстие. Теперь представьте, что у вас имеется
коробка размером AxBxC и другая коробка размером MxNxK. Напишите программу, которая по 
шести данным числам A, B, C, M, N, K проверяет, можно ли первую коробку положить внутрь
второй. Разумеется, коробки можно как угодно переворачивать, но одна коробка должна
помещаться в другую целиком. Как обычно, постарайтесь сделать свою программу по в
озможности лаконичнее.

Советы и рекомендации
Одна коробка в другую должна помещаться по всем трём измерениям.
Постарайтесь не делать слишком сложный алгоритм для этой задачи.
*/


#include <iostream>
using namespace std;

int ValidInt (string inTxt){
  int result = 0;
  cout << inTxt;
  while(!(cin >> result) || result <= 0){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа больше нуля !" << endl;
    cout << inTxt; 
  }    
  return result;
}

int main() {
  cout << "Программа проверяет, поместится одна коробка в другую." << endl;
  cout << "Укажите параметры первой коробки:" << endl;
  int in_A = ValidInt("Длина стороны A = ");
  int in_B = ValidInt("Длина стороны B = ");
  int in_C = ValidInt("Длина стороны C = ");
  cout << "Укажите параметры второй коробки:" << endl;
  int in_M = ValidInt("Длина стороны M = ");
  int in_N = ValidInt("Длина стороны N = ");
  int in_K = ValidInt("Длина стороны K = ");
  cout << "--------------------------" << endl;
  
  if  ((in_A < in_M && in_B < in_N && in_C < in_K)
    || (in_A < in_M && in_B < in_K && in_C < in_N)
    || (in_A < in_N && in_B < in_K && in_C < in_M)
    || (in_A < in_N && in_B < in_M && in_C < in_K)
    || (in_A < in_K && in_B < in_M && in_C < in_N)
    || (in_A < in_K && in_B < in_N && in_C < in_M)){
      cout << "Первая коробка поместится внутри второй." << endl;
    } else if ((in_A == in_M && in_B == in_N && in_C == in_K)
    || (in_A == in_M && in_B == in_K && in_C == in_N)
    || (in_A == in_N && in_B == in_K && in_C == in_M)
    || (in_A == in_N && in_B == in_M && in_C == in_K)
    || (in_A == in_K && in_B == in_M && in_C == in_N)
    || (in_A == in_K && in_B == in_N && in_C == in_M)){
      cout << "Коробки одинаковые, поместить одну в другую не получится." << endl;
    } else {
      cout << "Первая коробка не поместится внутри второй!" << endl;
    }  

  return 0;
}