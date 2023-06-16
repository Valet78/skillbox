/*
Задание6.5.4. Счастливый билетик
В старину, когда даже в столице билеты в общественном транспорте выдавали контролёры, существовало
поверье: если на билете сумма первых трёх цифр в номере билета равна сумме трёх последних, то это 
к удаче. Напишите программу, которая получала бы на вход шестизначный номер билета и выводила, 
счастливый это билет или нет. К примеру, билеты 666 666 и 252 135 — счастливые, а 123 456 — нет.

Пример выполнения   Введите номер билета: 123060 
                    Билет счастливый! 
                    Введите номер билета: 123040 
                    Повезёт в следующий раз!

Рекомендации по выполнению
Программу необходимо сделать так, чтобы можно было увеличить количество цифр в билете без особых
изменений в коде.
Для получения младшего разряда числа (самой правой цифры) используйте выражение: 
one_digit = digits % 10.
Используйте циклы для подсчёта суммы цифр в номере билета. 
Что оценивается
Программа корректно определяет, является ли билет счастливым.
Для подсчёта суммы цифр в билете используются циклы.
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
  int point = 0;
  int ind = 0;
  while(inTxt[ind] != '\0'){
    if (inTxt[0] == '-'){
      ind++;
    } else if (inTxt[ind] == '.' && point == 0){
      ind++;
      point++;
    } else if(int(inTxt[ind]) >= 48 && int(inTxt[ind]) <= 57){
      ind++;
    } else{
      ind--;
    }
  }
  cout << ind << " - " << inTxt.length() << endl;
  // if (ind == inTxt.length()){
  //   return true;
  // }  

  return false;
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
    if (result <= 0){
      cout << "Введите число в диапазоне [1...1 000 000]!" << endl;
    }
  } while (valid == 0 || result <= 0 || result > 1000000);
  
  return result;
}

int main() {
  
  IsDigit("2d65");
  
  return 0;
}