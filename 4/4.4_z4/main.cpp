/*
Задание 4. Калькулятор опыта

Напишите программу, которая определяет уровень персонажа в компьютерной игре. 
Пользователь вводит число «очков опыта», а программа вычисляет уровень. 
Новый уровень даётся при достижении 1000, 2500 и 5000 «очков опыта». 
Начальный уровень равен 1.

Пример
Введите число очков опыта: 2000 
-----Считаем----- 
Ваш уровень: 2

Советы и рекомендации
Программа должна выводить текущий уровень персонажа для любого количества очков.
Обработка некорректного ввода приветствуется.
Чтобы сократить количество проверок, используйте оператор else if.
Что оценивается
Правильное определение текущего уровня персонажа.
Отсутствие лишних и дублирующих проверок.


*/
#include <iostream>
using namespace std;

int main() {
  int exper = 0, level = 0;  

  cout << "Программа определяет уровень персонажа в компьютерной игре." << endl;
  cout << "Введите число очков опыта: ";
  
  while(!(cin >> exper)){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа!" << endl;
    cout << "Введите число очков опыта: ";    
  }

  if(exper > 0){
  if (exper >= 5000) level = 4;
  else if (exper >= 2500) level = 3;
  else if (exper >= 1000) level = 2;
  else level = 1;
  
  cout << "-----Считаем-----" << endl;
  cout << "Ваш уровень: " <<  level << endl;
  } else cout << "Опыт персонажа не может быть отрицательным или равным \"0\"!" << endl;
  
  return 0;
}