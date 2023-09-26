/*
Задача 6.3.2. Кадастровые проблемы.

В столице программистов на квадратные участки дается скидка. А так как работать с целыми числами
программисты начинают раньше, то и участки, площадь которых является точным квадратом (например, 
25 или 49), являются самыми востребованными. Напишите программу, которая проверяет, является ли 
введенная площадь участка точным квадратом. 
Самый большой участок в городе имеет площадь в 1 000 000 м2.
*/
#include <iostream>
using namespace std;

// Проверка ввода строки и пустого ввода
string InputTxt(string inTxt){
  string result = "";
   do{
    cout << inTxt;
    getline(cin, result);
    if (result == ""){
      cout << "Вы забыли ввести значение! Попробуйте снова." << endl;
    } 
  } while(result == ""); 
  return result;
}

// Извлекаем число из строки
long ValidInDigit(string inTxt){
  long result = 0; 
  int valid = 1;
  string resultTxt = "";
  do {
    valid = 1;
    resultTxt = InputTxt(inTxt);
    for(int i = 0; i < resultTxt.length(); i++){
      // Проверка отрицательных чисел
      if (resultTxt[0] == '-'){
        continue;
      }
      valid *= isdigit(resultTxt[i]); 
    }  
    if (valid == 0){
      cout << "Введённое значение не число! Попробуйте снова." << endl;      
    } else {
      result = stol(resultTxt);
    }
    if (result <= 0 || result > 1000000){
      cout << "Введите число в диапазоне [1...1 000 000]!" << endl;
    }
  } while (valid == 0 || result <= 0 || result > 1000000);
  
  return result;
}

int main() {
  int num = 1;
  long res = 0;
  cout << "Программа проверки участка, является ли его форма \"точным квадратом\"." << endl;
  long square = ValidInDigit("Укажите площадь земельного участка: ");

  while (res < square) {      
      res = num * num;
      num++;
  } 
  cout << "----------------------------------------------------" << endl; 
  num--;
  if (res == square){
    cout << "Да, участок квадратной формы с площадью " << square << " кв.м." << endl;
    cout << "является \"точным квадратом\" со сторонами " << num << " м." << endl;
  } else {
    cout << "Нет, участок квадратной формы с площадью " << square << " кв.м." << endl;
    cout << "не является \"точным квадратом\"!" << endl;
  }
  
  return 0;
}