/*
Задача 5.2.1. Координатная плоскость.

Напишите программу, которая принимает на вход координаты X, Y некоторой точки на плоскости 
и отвечает, в какой четверти плоскости лежит эта точка (а если она лежит на границе двух
четвертей — то так и отвечает “на границе”). 
Напомним, что четверти на плоскости нумеруются так: 
первая четверть — если обе координаты положительны, 
вторая — если X отрицателен, а Y положителен, 
третья — если обе координаты отрицательны, 
четвертая — если X положителен, а Y отрицателен. 
Точка лежит на границе четвертей, если хотя бы какая-то из ее координат равна нулю.
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
  string quarter = " ";  
  
  cout << "Программа определения четверти плоскости координат для точки с координатами" << endl;
  int inX = ValidInt("Введите значение X: ");
  int inY = ValidInt("Введите значение Y: ");

  if (inX != 0 && inY !=0){
    if (inY > 0){
      if (inX > 0) {
        quarter = "в I четверти.";
      } else {
        quarter = "во II четверти.";
      }
    } else {
      if (inX > 0) {
        quarter = "в IV четверти.";
      } else {
        quarter = "в III четверти.";  
      }    
    }    
  } else {
    quarter = "на границе четвертей.";
  }

  cout << "Точка с координатами (" << inX << ", " << inY << ") находится " << quarter << endl;
  
  return 0;
}