/*
3.3 Задание 1
Напишите программу, в которой пользователю нужно ввести имя персонажа и расу, 
а программа выводит приветствие.
Например, если пользователь выбирает имя Солнышко, а расу Орк, программа должна 
написать: “Родился новый Орк, его зовут Солнышко. Добро пожаловать в этот суровый мир!”.
*/

#include <iostream>
using namespace std;

int main() {
  string personName = "", raceName = "";
  setlocale(LC_ALL, "ru");      // адаптация к Кирилице

  cout << "Для создания персонажа введите" << endl;
  cout << "имя персонажа: ";
  cin >> personName;
  cout << "какой расе он будет принадлежать: ";
  cin >> raceName;
  cout << endl;
  cout << "Родился новый " << raceName << ", его зовут " << personName << "." << endl;
  cout <<"Добро пожаловать в этот суровый мир!" << endl;
  
  return 0;
}