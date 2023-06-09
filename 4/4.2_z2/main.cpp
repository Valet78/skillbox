/*
Задача 2. Автомобиль.

Автомобиль выехал из Москвы в Рязань. Напишите программу, которая вычисляет сумеет ли
добраться автомобиль до Рязани за два часа с заданной пользователем средней скоростью
движения. Программа должна выводить вычисленное расстояние, а если автомобиль сумеет 
добраться до Рязани, - сообщение “Вы приехали”. Расстояние между городами - 200 км.
*/
  
#include <iostream>
using namespace std;

int main() {
  int speedMidle = 0, dist = 0;

  cout << "Автомобиль выехал из Москвы в Рязань.\nРасстояние между городами - 200 км.\n";
  cout << "Для определения расстояния, которое преодолеет автомобиль за 2 часа" << endl;
  cout << "введите среднюю скорость автомобиля (км/ч): ";
  cin >> speedMidle;

  dist = speedMidle * 2;

  if(dist >= 200){
    cout << "С указанной скоростью автомобиль успеет добраться до Рязани." << endl;
  } else {
    cout << "Автомобиль за 2 часа, двигаясь с указанной скоростью, преодолеет " << dist << " км." << endl;
  }
  
  return 0;
}