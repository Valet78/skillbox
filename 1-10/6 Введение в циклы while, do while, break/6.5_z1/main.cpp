/*
Задание 6.5.1. Кукушка

Напишите программу, которая имитировала бы часы с кукушкой. В начале работы она спрашивает, который 
час, а затем нужное количество раз пишет «Ку-ку!». При выполнении задания необходимо обеспечить 
контроль ввода (например, количество часов не может быть отрицательным).

Пример выполнения   Введите, который час: 2 
                    Ку-ку! 
                    Ку-ку!
Рекомендации по выполнению
Обратите внимание, если вы захотите использовать 24-часовой формат, в котором часы имеют значения 
0–23, то кукушка не сможет вас оповестить о полночи (нулевой час).

Что оценивается
Есть проверка входных значений. Количество выведенных на консоль фраз равно количеству часов.
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

// Извлекаем положительное натуральное число из строки
int ValidPozitiveInt(string inTxt){
  int result = 1, valid = 1;
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
      cout << "Введённое значение не число! Попробуйте снова." << endl;     } else {
      result = stoi(resultTxt);
    }    
    if (result < 0 || result > 12){
      cout << "Введите число в дапазоне от 0 до 12!" << endl;
    }
  } while (valid == 0 || !(result >= 0 && result <= 12));
  
  return result;
}

int main() {

  cout << "Программа-имитатор часов \"Кукушка\"." << endl;
  int hour = ValidPozitiveInt("Укажите, который час [0..12]: ");

  int inHour = (hour == 0) ? 12: hour;
  for (int i = 0; i < inHour; i++){
    cout << "\tКу-ку!" << endl;
  }
  
  return 0;
}