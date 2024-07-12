/*
Задача 2. Обмен местами

Есть код программы с двумя переменными типа int и выводом этих переменных
на экран. 
Напишите программу, которая меняет значения переменных местами, то есть
нужно добиться того, чтобы в переменной a лежит значение b, 
а в b — значение a.
*/
  
#include <iostream>
using namespace std;

int main() {
  int a = 42, b = 153, temp = 0;

  cout << "До замены:" << endl;
  cout << "\ta: " << a << endl; 
  cout << "\tb: " << b << endl;

  temp = b;
  b = a;
  a = temp;

  cout << "После замены:" << endl;
  cout << "\ta: " << a << endl; 
  cout << "\tb: " << b << endl;

  return 0;
}