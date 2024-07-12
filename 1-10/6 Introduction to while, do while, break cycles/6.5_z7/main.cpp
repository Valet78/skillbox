/*
Задание 6.5.7. Сокращение дроби* (дополнительное задание)

Пользователь вводит числа M и N. Напишите программу, которая преобразует дробь M/N к несократимому 
виду и выдаёт получившийся результат. Обеспечьте контроль ввода.

Пример выполнения   Введите числитель: 4 
                    Введите знаменатель: 6 
                    Результат: 2 / 3 
                    Введите числитель: 25 
                    Введите знаменатель: 40> 
                    Результат: 5 / 8 
                    Введите числитель: −6 
                    Введите знаменатель: 12 
                    Результат: −1 / 2 
(При вводе отрицательных чисел в выводе должен быть только один ведущий минус. 
Неправильный вывод программы: 1/−2, −1/−2.) 
                    Введите числитель: 896 
                    Введите знаменатель: 3584 
                    Результат: 1 / 4

Рекомендации по выполнению
Не забывайте о правилах деления чисел. Программа должна работать корректно и не должна «падать».

Что оценивается
Алгоритм оптимальный, не бесконечный и не очень большой. Программа не зависает.
Правильно определены критерии начала и конца цикла.
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

// Является ли числом
bool IsDigit(string inTxt){
  // int point = 0;
  int ind = 0;
  
  for (int i = 0; i < inTxt.length(); i++){
    if (i == 0 && inTxt[0] == '-'){
      ind++;
    } else if (int(inTxt[i]) >= 48 && int(inTxt[i] <= 57)){
      ind++;
    }  else {
      ind--;
    }
  }     
  
  if (ind == inTxt.length()){
    return true;
  }  
  return false;
}

// Проверка ввода числа и вывод его
int ValidNum(string request){
  int result = 0;
  string numTxt = "";
  bool err = true;

  do {
    numTxt = InputTxt(request);
    if (IsDigit(numTxt)){
      result = stoi(numTxt);
      if (result == 0){
        cout << "Введите число, неравное нулю!" << endl;
      } else { 
        err = false;
      }
    } else {
      cout << "Вы не ввели число! Попробуйте снова." << endl;
    }  
  } while (err);

  return result;
}

int main() {

  cout << "Программа сокращения дробей." << endl;
  int numerals = ValidNum("Введите числитель: ");
  int denominator = ValidNum("Введите знаменатель: ");
  cout << "------------------------" << endl;
  if (numerals < 0 && denominator < 0){
    numerals *= -1;
    denominator *= -1;
    cout << "Результат: ";
  } else if (numerals < 0) {
    numerals *= -1;
    cout << "Результат: -";
  } else if (denominator < 0){
    denominator *= -1;
    cout << "Результат: -";
  } else {
    cout << "Результат: ";
  }

  int nod = 1;
  int num1 = numerals, num2 = denominator;  

  for (int k = 1; k <= num2; k++){
    for (int l = 2; l <= num1; l++){
      if (num1 % l == 0 && num2 % l == 0){
        num1 /= l;
        num2 /= l;    
        nod *= l;
        break;
      }
    }      
  }
  cout << numerals / nod << "/" << denominator / nod << endl;
  
  return 0;
}