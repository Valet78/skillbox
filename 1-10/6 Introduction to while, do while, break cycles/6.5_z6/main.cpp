/*
Задание 6.5.6. Вклады

Вклад в банке составляет X рублей. Ежегодно он увеличивается на P процентов, после чего
дробная часть копеек отбрасывается. Определите, через сколько лет вклад составит не менее 
Y рублей. Напишите программу, которая по данным числам X, Y, P определяет, сколько лет
пройдёт, прежде чем сумма достигнет значения Y.

Пример выполнения   Введите размер вклада: 100 
                    Введите процентную ставку: 10 
                    Введите желаемую сумму: 200 
                    Придётся подождать: 8 лет

Рекомендации по выполнению
Расчёты проводятся в целых числах.
У вклада есть капитализация процентов (проценты начисляются на весь остаток на счёте).
Что оценивается
Программа аварийно не завершается и не зависает при подсчёте вклада.
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
    if (int(inTxt[i]) >= 48 && int(inTxt[i] <= 57)){
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
      if (result > 0){
        err = false;
      } else {
        cout << "Введите число больше нуля!" << endl;
      }
    } else {
      cout << "Введите число больше нуля!" << endl;
    }  
  } while (err);

  return result;
}

int main() {
  int year = 0;
  cout << "Программа расчёта срока достижения указанного значения депозита." << endl;
  int deposit = ValidNum("Введите сумму начального вклада: ");
  int percent = ValidNum("Укажите значение процентной ставки: ");
  int request = ValidNum("Какую сумму Вы планируете получить: ");
  cout << "-------------------------------------------" << endl;

  while (deposit < request){
    deposit += (deposit * percent) / 100;
    year++;    
  }
  cout << "Придётся подождать: " << year << " лет"<< endl;  
  
  return 0;
}