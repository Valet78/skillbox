/*
Задача 4. Барберы (необязательная).

В небольшом городке проживает 18 000 взрослых человек: 9 000 мужчин и 9 000 женщин. 
Согласно традиции этого городка все мужчины обязаны носить бороду. Один предприимчивый житель открыл
сеть барбершопов, чтобы помочь мужчинам ухаживать за их бородами. Однако он никак не может посчитать
сколько всего специалистов-барберов для этого того нужно. Вам нужно написать программу которая будет
рассчитывать сколько мужчин можно постричь во всех барбершопах исходя из следующих данных:

* каждый из 9000 мужчин посещает барбершоп раз в месяц (30 дней)
* один барбер способен обслужить одного клиента за 1 час
* смена барбера — 8 часов

Программа должна спросить сколько мужчин проживает в городе и сколько всего барберов уже работает во всех барбершопах, 
и посчитать сколько барберов нужно, и если их недостаточно — выдать сообщение об этом. Если барберов достаточно — сказать и об этом.
*/

#include <iostream>
using namespace std;

int main() {
  int timePerClient = 1, workTime = 8;
  int manCount = 0, barberCount = 0, result = 0;

  cout << "Программа расчитает потребность в специалистах-барберов в Вашем городе." << endl;
  cout << "Укажите количество мужчин, проживающих в городе: ";
  cin >> manCount;
  cout << "Укажите количество имеющихся в городе специалистов-барберов: ";
  cin >> barberCount;

  result = 1 + manCount / (timePerClient * workTime * 30);
  
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