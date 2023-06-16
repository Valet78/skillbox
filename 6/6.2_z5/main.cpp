/*
Задача 6.2.5. Банкомат 3.0.

В банке ПлюсПлюсБанк тестируют новую систему пин-кодов на банкоматы. Теперь вместо
фиксированного пин-кода пользователь должен ввести 4 числа. Если их сумма оказывается 
равна 42, пользователь может продолжать работу. Напишите программу, которая спрашивает
у пользователя 4 числа и отвечает “Ввод корректный”, если их сумма равна 42, и “Ввод
некорректный, попробуйте еще раз” в противном случае. Так повторяется бесконечно.
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
// Извлекаем число из строки *********
int ValidInt(string inTxt){
  int result = 0, valid = 1, i = 0;

  while(i < inTxt.length()){
      valid *= isdigit(inTxt[i]); 
      i++;
    }  
  
  if (valid != 0){
    result = stoi (inTxt); 
  } else {
    result = -1;
  }
  return result;
}

int main() {
  int i = 0, k = 0, resNum = 0, sum = 0;
  string inNum = "";
  cout << "Программа теста ввода пин-кода." << endl;
  string pinTxt = InputTxt("Введите через пробел 4 цифры: ");
  pinTxt += ' ';
  
  while (!(pinTxt.length() == 0)){
    if (pinTxt[i] == ' '){
      pinTxt = pinTxt.substr(1);
    } else {
      
      while (pinTxt[i] != ' '){
        inNum += pinTxt[i];
        i++;
      }
      pinTxt = pinTxt.substr(i);
      resNum = ValidInt(inNum);
      inNum = "";
      k++;
      i = 0;
      
      if (resNum == -1){
        k --;
        break;
      } else {
        sum = sum + resNum;
      }    
    }  
  }  
  if(sum != 42 || k != 4){
    cout << "Ввод некорректный, попробуйте еще раз!" << endl;
    cout << "--------------------------------------" << endl;
    main();
  } else {
    cout << "Ввод корректный" << endl;
  }


  
  return 0;
}