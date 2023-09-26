/*
Задача 6.3.3. Кожаный мешок.

На этот раз нужно написать фрагмент кода для прошивки робота. Как мы знаем, роботы понимают только
нули и единицы, других цифр для них не существует. Напишите программу, которая проверяет, состоит 
ли число только из нулей и единиц.
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
string ValidInCode(string inTxt){  
  int valid = 0;
  string resultTxt = InputTxt(inTxt);
      
    for(int i = 0; i < resultTxt.length(); i++){      
      if (!(resultTxt[i] == '0' || resultTxt[i] == '1')){      
        valid = -1;
        cout << "Введены некорректные данные! Попробуйте снова." << endl;
        break;
      }       
    }  
    if (valid == -1){
      resultTxt = ValidInCode(inTxt);
    }  
  return resultTxt;
}

int main() {

  cout << "Программа распознавания фрагмента кода прошивки робота." << endl;  
  string validBin = ValidInCode("Введите числовой код, состоящий из \"0\" и \"1\": ");
  cout << "--------------------------------" << endl;
  cout << "Была введена следующая команда: " << validBin << endl;
  
  return 0;
}