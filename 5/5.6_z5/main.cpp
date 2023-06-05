/*
Задание 5.6.5. Склонение русских слов

Напишите программу для магазина, которая по заданной цене товара дописывает к нему 
слово «рубли» в правильном падеже. Например, если вводится число 2000, то ответ должен 
быть «2000 рублей», если 22 — то «22 рубля», если 51 — то «51 рубль».

Советы и рекомендации
Постарайтесь сделать свою программу по возможности лаконичнее.
Что оценивается
Правильность определения склонения для чисел от 0 до 2000.
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

  cout << "Склонение русских слов..." << endl;
  int inSum = ValidInt("Введите цену товара: ");
  cout << "---------------------" << endl;

  int remains = inSum % 10;
  string outTxt = "";

  if (remains == 1){
    outTxt = " рубль.";
  } else if (remains == 2 || remains == 3 || remains == 4){
    outTxt = " рубля.";
  } else {
    outTxt = " рублей.";
  }
  
  cout << "Цена данного товара " << inSum << outTxt << endl;
  
  return 0;
}