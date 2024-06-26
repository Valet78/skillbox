/*
Задание 6.5.2. Слишком большие числа

У неудачливого бухгалтера всё опять идёт наперекосяк: ему приносят такие большие счета, что числа 
не помещаются на бумаге. Напишите программу, которая считала бы для него, сколько цифр (знаков) 
во вводимом числе.
Пример выполнения   Введите число: 10 
                    Цифр в числе: 2
Рекомендации по выполнению
Тип int вмещает в себя не больше десяти цифр (предположим, что у бухгалтера очень маленькие 
листы бумаги). Проверьте, как программа будет себя вести на отрицательных числах и нуле.
Что оценивается
В числе ноль программа определяет одну цифру. Количество цифр определяется правильно.
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

// Проверям является числом
string ValidInDigit(string inTxt){
  string result = ""; 
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
      result = resultTxt;
    }
    
  } while (valid == 0);  
  
  return result;
}

int main() {
  cout << "Программа подсчета количества цифр в вводимом числе." << endl;
  string inNumTxt = ValidInDigit("Введите число: ");
  
  if (inNumTxt[0] == '-'){
    cout << "Цифр в числе: " << inNumTxt.length() - 1 << endl;
  } else {
    cout << "Цифр в числе: " << inNumTxt.length() << endl;
  }
  
  return 0;
}