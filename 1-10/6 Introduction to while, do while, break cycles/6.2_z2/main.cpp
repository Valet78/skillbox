/*
Задача 6.2.2. Купи слона.
Напишите программу-дразнилку “Купи слона”. Она спрашивает у пользователя, как его зовут, 
затем отвечает “%username%, купи слона!”. Дальше, что бы он ни говорил, она передразнивает: 
Все говорят “...”, а ты купи слона! Так повторяется бесконечно.

Пример
- Хорошо, давай куплю.
- Все говорят “Хорошо, давай куплю.”, а ты купи слона!
*/

#include <iostream>
using namespace std;

string ValidTxt(string inTxt){
  string result = "";

  do{
    cout << inTxt;
    getline(cin, result);
    if (result == ""){
      cout << "Вы забыли представиться! Попробуйте снова." << endl;
    }
  } while(result == ""); 

  return result;
}

int main() {
  string userTxt = "";
  
  cout << "Программа-дразнилка \"Купи слона\"" << endl;
  string userName = ValidTxt("Подскажита,  как Вас зовут: ");
  cout << userName << ", купи слона!" << endl;
  
  do{    
    getline(cin, userTxt);
    cout << "Все говорят \"" << userTxt << "\", а ты купи слона!" << endl;
  } while (true);
  
  return 0;
}