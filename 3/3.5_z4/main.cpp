/*
Задача 4 (дополнительная). Повышаем градус сложности*
Что нужно сделать
Вернитесь к задаче про обмен местами значений переменных и попробуйте решить её без использования третьей переменной (упс, спойлер, но ничего страшного!). Догадайтесь, в каких случаях новый способ может не работать и какие у него преимущества.

Советы и рекомендации
Используйте только две исходные переменные!!!
Используйте арифметические операции для обмена.
*/

#include <iostream>
using namespace std;

int main() {
  int a = 42, b = 153;

  cout << "До замены:" << endl;
  cout << "\ta: " << a << endl; 
  cout << "\tb: " << b << endl;

  a += b;
  b = a - b;
  a = a - b;

  cout << "После замены:" << endl;
  cout << "\ta: " << a << endl; 
  cout << "\tb: " << b << endl;

  return 0;
}