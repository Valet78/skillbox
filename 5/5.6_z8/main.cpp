/*
Задание 5.6.8. Грустное совершеннолетие

Посетитель пришёл в бар и попросил кружку пива. Напишите программу для бармена, который не умеет
считать, чтобы по заданной дате рождения посетителя и текущей дате определить, можно ему продавать
алкоголь или нет. 
Программа должна попросить ввести сегодняшнюю дату и дату рождения покупателя, после чего ответить:
«можно» или «нельзя».

Учтите, что в день 18-летия алкоголь продавать посетителю ещё нельзя, а вот на следующий день после
этого — уже можно.
Как обычно, постарайтесь сделать свою программу по возможности лаконичнее.

Советы и рекомендации
Программа должна работать с любым годом и не должна быть привязана к определённой дате.
*/

#include <iostream>
#include <ctime>
using namespace std;

// Проверка ввода числа
int ValidInt (string inTxt){
  int result = 0;
  cout << inTxt;
  while(!(cin >> result) || result <= 0){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа больше нуля !" << endl;
    cout << inTxt; 
  }    
  return result;
}
// Проверка год високосный ?
bool YearLeap(int inYear){
  bool res = false;
  if (inYear % 4 == 0 && !(inYear % 100 == 0 && inYear % 400 != 0)) {
    res = true;
  }  
  return res;
}
// Проверка ввода даты
bool ValidDate(int inYear, int inMonth, int inDay){
  bool res = false;  
  bool yearLeap = YearLeap (inYear);
  if (inMonth <= 12){
    if (inMonth == 2){
      if (yearLeap && (inDay >=1 && inDay <= 29)){
        res = true;
      } else if (inDay >=1 && inDay <= 28){
        res = true;
      }
    } else if ((inMonth == 1 || inMonth == 3 || inMonth == 5 
        || inMonth == 7 ||inMonth == 8 || inMonth == 10 || inMonth == 12) 
        && (inDay >= 1 && inDay <= 31)){
      res = true;
    } else if (inDay >= 1 && inDay <= 30) {
      res = true;
    }      
  }   
  return res;
}

int main() {
  // Ввод текущей даты
  cout << "Программа посчитает Ваш возраст." << endl;
  cout << "Введите текущие" << endl;
  int currentYear = ValidInt("\tгод: ");  
  int currentMonth = ValidInt("\tмесяц: ");
  int currentDay = ValidInt("\tдень: ");
  bool valid = ValidDate(currentYear, currentMonth, currentDay);
  cout << "----------------------------" << endl;
    
  while(!valid){    
    cout << "Введены некорректные данные!!!" << valid << endl;
    cout << "Введите текущие" << endl;
    currentYear = ValidInt("\tгод: ");
    currentMonth = ValidInt("\tмесяц: ");
    currentDay = ValidInt("\tдень: ");
    valid = ValidDate(currentYear, currentMonth, currentDay);  
    cout << "----------------------------" << endl;
  }
  // Ввод дня рождения
  cout << "Введите дату рождения" << endl;
  int birthYear = ValidInt("\tгод: ");  
  int birthMonth = ValidInt("\tмесяц: ");
  int birthDay = ValidInt("\tдень: ");
  valid = ValidDate(birthYear, birthMonth, birthDay);
  cout << "----------------------------" << endl;
  
  while(!valid){    
    cout << "Введены некорректные данные!!!" << valid << endl;
    cout << "Введите дату рождения" << endl;
    birthYear = ValidInt("\tгод: ");  
    birthMonth = ValidInt("\tмесяц: ");
    birthDay = ValidInt("\tдень: ");
    valid = ValidDate(birthYear, birthMonth, birthDay);  
    cout << "----------------------------" << endl;
  }

  // if (currentYear > birthYear + 18){
  //   cout << "По нашим подсчётам клиент старше 18 лет." << endl;
  // } else if (currentYear == birthYear + 18){
  //   if (birthMonth < currentMonth){
  //     cout << "По нашим подсчётам клиент старше 18 лет." << endl;
  //   } else if (birthMonth == currentMonth && birthDay < currentDay){
  //     cout << "По нашим подсчётам клиент старше 18 лет." << endl;      
  //   } else {
  //     cout << "Клиенту не исполнилось 18 лет!!!" << endl;
  //   }
  // } else {
  //   cout << "Клиенту не исполнилось 18 лет!!!" << endl;
  // }

  if ((currentYear - birthYear < 18) || ((currentYear - birthYear == 18)
   && !(birthMonth == currentMonth && birthDay < currentDay))){
    cout << "Клиенту не исполнилось 18 лет!!!" << endl;
   } else {
    cout << "По нашим подсчётам клиент старше 18 лет." << endl;
   }
  
  return 0;
}