/*
Задача 6.2.3. Таблица степеней.

Напишите программу, которая выводила бы N первых степеней числа К. Посмотрите, что случится, 
если N или K будут достаточно большими.
*/

#include <iostream>
using namespace std;

// Проверка строки на число
int StrIsInt(string inStr){
  int res = 1;
  for(int i = 0; i < inStr.length(); i++){
    if (inStr[0] == '-'){
      continue;
    } 
    res *= isdigit(inStr[i]);      
  }  
  return res;
}

// проверка ввода строки
int ValidTxt(string inTxt){
  string resStr = "";
  int result = 0, valid = 1;
  
  do{
    cout << inTxt;
    getline(cin, resStr);
    if (resStr == ""){
      cout << "Вы забыли ввести значение! Попробуйте снова." << endl;
    } else {
      valid = StrIsInt(resStr);
      if (valid != 0){
        result = stoi(resStr);
      } else {
        cout << "Введённое значение не число! Попробуйте снова." << endl;
      }     
    }
  } while(resStr == "" || valid == 0); 

  return result;
}

int main() {
  int degree = 1;
  float part = 0.0;
  int in_N = ValidTxt("Введите показатель степени (число N): ");
  int in_K = ValidTxt("Введите основание степени (число K): ");

  if (in_K == 0 && in_N < 0){
    cout << "Решения нет (деление на ноль)!" << endl;
  } else if (in_K == 0 && in_N > 0){
    cout << "В этом случае число K в степени N равно 0" << endl;
  } else if (in_N == 0){
    cout << "В этом случае число K в степени N равно 1" << endl;
  } else {
    if (in_N > 0){      
      cout << "N степеней числа K: ";
      for (int i=0; i < in_N; i++){
        degree *= in_K;
        if (i == in_N - 1){
          cout << degree;
        } else {
          cout << degree << ", ";
        }
      }
    } else if (in_N < 0){
      cout << "N степеней числа K: ";
      for (int i = 0; i > in_N; i--){
        degree *= in_K;
        // part = int((1 / (float)degree) * 1000) / (float)1000;
        part = 1 / (float)degree;
        if (i == in_N + 1){
          cout << part;
        } else {
          cout << part << ", ";
        }
      }       
    }    
  }      
  return 0;
}