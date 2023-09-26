/*
Задача 6.2.4. Напоминалка.

Василий — очень ответственный менеджер, но очень забывчивый. Иногда он пьет воду несколько
раз подряд, потому что забыл, что только что пил. Напишите для него программу-напоминалку. 
В самом начале программа спрашивает, сколько раз ему напомнить, а затем нужное количество
раз выводит “Вы хотели не забыть о чем-то”.

Усложнение: добавьте возможность ввести фразу-напоминалку, чтобы можно было напоминать о
чем-то конкретном.
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
int ValidInt(string inTxt){
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
      cout << "Введённое значение не число! Попробуйте снова." << endl;      
    } else {
      result = stoi(resultTxt);
    }
    if (result <= 0){
      cout << "Введите число больше нуля!" << endl;
    }
  } while (valid == 0 || result <= 0);
  
  return result;
}

int main() {

  cout << "Программа-напоминалка" << endl;
  int numReturn = ValidInt("Введите количество повторений: ");
  string textRemind = InputTxt("О чём необходимо напомнить: ");
  cout << "--------------------------" << endl;

  for (int i = 0; i < numReturn; i++){
    cout << "Вы хотели не забыть о \"" << textRemind << "\"." << endl;
  }
  
  return 0;
}