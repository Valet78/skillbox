/*
Задача 6.2.6. Сумма чисел.

У бухгалтера сломались счеты. Напишите программу, которая считала бы сумму вводимых чисел.
В начале у бухгалтера спрашивают, сколько чисел тот хочет сложить, затем нужное количество 
раз просят ввести число и в конце выводят получившуюся сумму.
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
float ValidInNumber(string inTxt){
  float result = 0; 
  int valid = 1;
  string resultTxt = "";
  do {
    valid = 1;
    resultTxt = InputTxt(inTxt);
    for(int i = 0; i < resultTxt.length(); i++){
      // Проверка отрицательных чисел
      if (resultTxt[0] == '-' || resultTxt[i] == '.'){
        continue;
      }
      valid *= isdigit(resultTxt[i]); 
    }  
    if (valid == 0){
      cout << "Введённое значение не число! Попробуйте снова." << endl;      
    } else {
      result = stof(resultTxt);
    }
    // if (result <= 0){
    //   cout << "Введите число больше нуля!" << endl;
    // }
  } while (valid == 0);
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
    if (result <= 0){
      cout << "Введите число больше нуля!" << endl;
    }
  } while (valid == 0 || result <= 0);
  
  return result;
}

int main() {
  float sum = 0;
  cout << "Программа-счёты. Сложение N чисел." << endl;
  int numCount = ValidPozitiveInt("Введите ожидаемое количество чисел для сложения: ");

  for (int i = 0; i < numCount; i++){
    sum = float(sum) + ValidInNumber("ведите " + to_string(i + 1) + " число: ");
  }
  cout << "----------------------------" << endl;
  cout << "Сумма введённых чисел: " << sum << endl;
  
  return 0;
}