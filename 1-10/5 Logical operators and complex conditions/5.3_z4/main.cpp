/*
Задача 4. Совпадение чисел(необязательная).
Напишите программу, которая по трем введенным числам a, b, c определяет, сколько среди них совпадающих чисел.

Подсказка: Совпадающих может быть 0, 2 или 3. Например, если введены числа 5 1 5, то ответ должен быть “2 совпадающих”, если -1 -2 -3, то ответ должен быть “0 совпадающих”.
  */

#include <iostream>
using namespace std;

int ValidInt (string inTxt){
  int result = 0;
  cout << inTxt;
  while(!(cin >> result)){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа!" << endl;
    cout << inTxt; 
  }    
  return result;
}

int main() {
  int repet = 0;
  
  cout << "Программа из 3-х введённых чисел выводит количество повторяющихся." << endl;
  int numOne = ValidInt("Введите первое число: ");
  int numTwo = ValidInt("Введите второе число: ");
  int numThree = ValidInt("Введите третье число: ");

  if (numOne == numTwo){
    repet ++;
  } 
  if (numOne == numThree) {
    repet ++;
  } 
  if (repet == 0){
    if (numTwo == numThree){
      repet ++;
    }
  }  
  cout << "-------------------------" << endl;
  cout << "Количество совпадений: " << repet << endl;
  
  return 0;
}

/*
// Вариант от преподавателя

#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout << "input A B C:"; cin >> a >> b >> c;
    if(a == b && b == c)
        cout << "3" << endl;
    else if(a == b || b == c || c == a)
        cout << "2" << endl;
    else
        cout << "0" << endl;
    return 0;
}

*/