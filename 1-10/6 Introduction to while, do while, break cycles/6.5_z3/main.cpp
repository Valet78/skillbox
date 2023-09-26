/*
Задание 6.5.3. Коллекторы

Напишите робота для коллекторов. В самом начале он спрашивает имя должника и сумму долга, а затем 
начинает требовать у него погашения долга до тех пор, пока тот не будет погашен полностью. Сумма 
долга должна уменьшаться, если пользователь ввёл сумму, меньшую чем сумма долга. Если пользователь 
внёс большую сумму, чем требуется для погашения, выведите сообщение о том, какой у него остаток на 
счету после такой операции. Обеспечьте контроль ввода.

Рекомендации по выполнению
При полной выплате долга необходимо учитывать остаток на счету, если он имеется.

Что оценивается
Правильно считается остаток после полного погашения долга.
Программа прекращает выполнение после того, как долг полностью погашен.
При задании отрицательного долга программа выводит предупреждение и прекращает выполнение.
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
float ValidInDigit(string inTxt){
  float result = 0; 
  int valid = 1;
  string resultTxt = "";
  do {
    valid = 1;
    resultTxt = InputTxt(inTxt);
    for(int i = 0; i < resultTxt.length(); i++){
      // Проверка отрицательных и нецелых чисел
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
    if (result <= 0){
      cout << "Введите число больше нуля!" << endl;
    }
  } while (valid == 0 || result <= 0);
  
  return result;
}

int main() {
  float repayment = 0;
  float remains = 0;

  cout << "Программа робот-коллектор." << endl;
  string useName = InputTxt("Укажите Ваше имя: ");
  float userDebt = ValidInDigit("Какую сумму Вы должны: ");
  cout << "----------------------------" << endl;
  
  do {
    repayment = ValidInDigit("Введите сумму частичного погашения: ");
    if (repayment == userDebt){
      userDebt = 0;
      cout << useName <<", Вы смогли погасить кредит в полном объёме. Поздравляем Вас!" << endl;
    } else if (repayment > userDebt){
      remains = ((repayment - userDebt)*100) / 100.0;
      userDebt = 0;      
      cout << useName << ", Вы смогли погасить кредит в полном объёме." << endl;
      cout << "Поздравляем Вас! А, ещё у Вас на счёте " << remains << " руб." << endl;
    } else {
      userDebt = ((userDebt - repayment)*100) / 100.0;
      cout << useName << ", Вы погасили часть кредита." << endl;
      cout << "Осталось немного, - " << userDebt << " руб." << endl;
    }
    
  } while (userDebt != 0);

  return 0;
}