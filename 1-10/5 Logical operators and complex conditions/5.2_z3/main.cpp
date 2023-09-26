/*
Задача 5.2.3. Високосный год (необязательная). 
Напишите программу, которая определяет количество дней в году.
Подсказка: номер года должен делиться на 4, однако если он делится на 100, 
но не делится на 400, то год не високосный!
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
  int deyInYear = 0;
  
  cout << "Программа вычисления количества дней в указанном году." << endl;
  int inYear = ValidInt("Введите интересующий Вас год: ");

  if (inYear % 4 == 0 && !(inYear % 100 == 0 && inYear % 400 != 0)){
    deyInYear = 366;
  } else {
    deyInYear = 365;
  }

  // if (inYear % 4 == 0) {
  //   if (inYear % 100 == 0 && inYear % 400 != 0) {
  //       deyInYear = 365; // 2100, 2200, 2300, != 2400
  //   } else {
  //       deyInYear = 366;
  //   }
  // } else {
  //   deyInYear = 365;
  // }

  cout << "В указанном Вами " << inYear << " году " << deyInYear << " дней." << endl;

  return 0;
}
