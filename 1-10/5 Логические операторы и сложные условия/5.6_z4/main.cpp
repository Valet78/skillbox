/*
Задание 5.6.4. Майские — усложнение

Добавьте возможность начать месяц с любого дня недели. Для этого вводится число — номер дня недели, 
с которого начинается месяц. Убедитесь, что введённое число корректно.

Советы и рекомендации
Для начала стоит сделать третье задание.
Постарайтесь не проверять каждый вариант месяца отдельно. Некоторые условия можно объединить.
Что оценивается
Правильность определения дня недели.
Количество условий.
*/

#include <iostream>
using namespace std;

int ValidInt (string inTxt){
  int result = 0;
  cout << inTxt;
  while(!(cin >> result) || !(result > 0 && result < 32)){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа [1..31] !" << endl;
    cout << inTxt; 
  }    
  return result;
}

int ValidWeek (string inTxt){
  int result = 0;
  cout << "Укажите, 1 мая какой это день недели [1..7]:" << endl;
  cout << "1. Понедельник." << endl;
  cout << "2. Вторник." << endl;
  cout << "3. Среда." << endl;
  cout << "4. Четверг." << endl;
  cout << "5. Пятница." << endl;
  cout << "6. Суббота." << endl;
  cout << "7. Воскресение." << endl;
  cout << "*** "<< inTxt;
  while(!(cin >> result) || !(result > 0 && result < 8)){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа [1..7] !" << endl;
    cout << inTxt; 
  }    
  return result;
}

int main() {
  cout << "Программа - календарь (май месяц)." << endl;
  int dayOnManth = ValidInt("Укажите интересующую Вас дату: ");
  int dayOnWeek = ValidWeek("Ваш выбор: ");
  cout << "---------------------------" << endl; 
  int day = dayOnManth + dayOnWeek - 1;
  if ((day >= 1 && day <=5) || (day >=8 && day <=10)) {
    cout << "Указанная дата, " << dayOnManth << " мая - это праздничный день!" << endl;
  } else if ((day + 1) % 7 == 0 || day % 7 ==0) {
    cout << "Указанная дата, " << dayOnManth << " мая - это выходной день!" << endl;
  } else {
    cout << "Указанная дата, " << dayOnManth << " мая - это рабочий день!" << endl;
  }

  return 0;
}