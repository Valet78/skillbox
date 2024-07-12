/*
Задание 8. Зарплата (дополнительное задание)
В отделе маркетинга работают три сотрудника. Их зарплаты могут быть как разными, 
так и одинаковыми. Напишите программу, которая вычисляет разницу между самой высокой и 
самой низкой зарплатами сотрудников, а также среднее арифметическое зарплат всех 
сотрудников отдела.

Пример
Введите зарплату первого сотрудника: 45 рублей
Введите зарплату второго сотрудника: 45 рублей
Введите зарплату третьего сотрудника: 45 рублей
-----Считаем-----
Самая высокая зарплата в отделе: 45 рублей
Разница между самой высокой и самой низкой зарплатой в отделе: 0 рублей
Средняя зарплата в отделе: 45 рублей
*/

#include <iostream>
using namespace std;

int ValidInt (string inTxt){
  int result = 0;
  cout << inTxt;
  while(!(cin >> result) || result <= 0){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа больше нуля!" << endl;
    cout << inTxt; 
  }
  return result;
}


int main() {
  
  cout << "Программа вычисления соотношения зарплат сотрудников." << endl;
  int salaryOne = ValidInt("Введите зарплату первого сотрудника: ");
  int salaryTwo = ValidInt("Введите зарплату второго сотрудника: ");
  int salaryThree = ValidInt("Введите зарплату третьего сотрудника: ");
  cout << "----- Считаем -----" << endl;

  int salaryMax = salaryOne;
  if(salaryMax <= salaryTwo) salaryMax = salaryTwo;
  if(salaryMax <= salaryThree) salaryMax = salaryThree;

  int salaryMin = salaryOne;
  if(salaryMin >= salaryTwo) salaryMin = salaryTwo;
  if(salaryMin >= salaryThree) salaryMin = salaryThree;
  
  int differ = salaryMax - salaryMin;
  int average = (salaryOne + salaryTwo + salaryThree) / 3;
    
  cout << "Самая высокая зарплата в отделе: " << salaryMax << " руб." << endl;
  cout << "Разница между самой высокой и самой низкой зарплатой: ";
  cout << differ << " руб." << endl;
  cout << "Средняя зарплата в отделе: " << average << " руб." << endl;
  
  return 0;
}