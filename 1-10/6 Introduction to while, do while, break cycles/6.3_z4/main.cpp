/*
Задача 6.3.4. Военное время.

Во времена Второй Мировой в штабах использовались стеклянные доски. С одной их стороны специальные 
люди писали сводки с фронта, а с другой генералы их читали. Как вы понимаете, для генералов текст
выглядел зеркально отраженным, поэтому специальных людей учили писать задом наперед. 
Напишите программу, упрощающую им жизнь: она должна выводить введенное число задом наперед.
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
    if (result <= 0){
      cout << "Введите число больше нуля!" << endl;
    }
  } while (valid == 0 || result <= 0);
  
  return result;
}

// Формируем зеркальное изображение числа
string MirrorImage (int num){
  string res = "", numStr = to_string(num);
  int ind = numStr.length() - 1;
  while (ind >= 0){
    res += numStr[ind];
    ind--;
  }
  return res;
}

int main() {
  cout << "Программа зеркально отобразит введённое число." << endl;
  int inNum = ValidPozitiveInt("Введите число: ");
  cout << "---------------------------" << endl;
  
  cout << "Перевёрнутое число: "<< MirrorImage(inNum) << endl;
  
  return 0;
}