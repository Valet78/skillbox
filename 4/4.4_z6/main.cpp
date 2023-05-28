/*
Задание 6. Улучшим барберов
Помните задачу про барберов из видео 4.3? Кстати, именно оператор % мог помочь нам с
барберами. Перепишите программу про них с его использованием для проверки на проблему 
с целочисленным делением.

Напишите программу, которая отвечает на вопрос хватает ли барберов в данном
городе если задано число людей и число барберов, а так же указано, что
один барбер работает 8 часов в день, на одного клиента тратит 1 час, 
а каждый клиент приходит раз в месяц. Воспользуйтесь для решения проблемы
целочисленного деления оператором %
*/

#include <iostream>
using namespace std;

int ValidInt (string inTxt){
  int result = 0;
  cout << inTxt;
  while(!(cin >> result)){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа!" << endl;
    cout << inTxt; 
  }
  return result;
}

int main() {
  int timePerClient = 1, workTime = 8;
  int manCount = 0, barberCount = 0;

  cout << "Программа расчитает потребность в специалистах-барберов в Вашем городе." << endl;
  manCount = ValidInt("Укажите количество мужчин, проживающих в городе: ");
  barberCount = ValidInt("Укажите количество имеющихся в городе специалистов-барберов: ");

  int clientsOnBarber = timePerClient * workTime * 30;

  int result = manCount / clientsOnBarber;
  if (manCount % clientsOnBarber != 0) result++;
  
  if (result > barberCount) {
    cout << "Городу не хватает " << result - barberCount << " специалистов." 
      << endl;    
  } 
  if(result < barberCount) {
    cout << "В городе лишние специалисты: " <<
      barberCount - result << " человек." << endl; 
  } 
  if(result == barberCount) {
    cout << "В городе имеются необходимое количество специалистов. " << endl;
  }
    
  return 0;
}