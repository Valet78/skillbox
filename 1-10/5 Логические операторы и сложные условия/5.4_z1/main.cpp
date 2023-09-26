/*
Задача 5.4.1. Военкомат.
Для отбора летчиков устанавливаются жесткие критерии.
Напишите программу, проверяющую, подходит ли призывник. 
Его рост должен быть не меньше 145см и не больше 165см, вес не меньше 45кг и 
не больше 65кг, а количество рук и ног должно обязательно совпадать (мы не знаем, 
зачем, но так требует инструкция). При этом берут любого человека, налетавшего на 
самолетах больше 100 часов.

Дополнительно.
А еще зеленоглазых в летчики тоже не берут, поэтому проверьте и цвет их глаз.

Подсказка: для цвета глаз используйте строковый тип данных. Проверять строки 
на равенство можно так:
if (eyeColor == “серо-буро-малиновый”) { … }
*/

#include <iostream>
using namespace std;

int ValidInt (string inTxt){
  int result = 0;
  cout << inTxt;
  while(!(cin >> result) || result < 0){    // Ввод с валидацией
    cin.clear();
    cin.ignore(123, '\n');    
    cout << "Программа ожидает ввода числа!" << endl;
    cout << inTxt; 
  }    
  return result;
}

string ValidEyeColor (string inTxt){
  int selColor = 0;  
  
  cout << inTxt << endl;
  cout << "1. Карие." << endl;
  cout << "2. Светло-карие." << endl;
  cout << "3. Тёмно-карие." << endl;
  cout << "4. Зелёные." << endl;
  cout << "5. Светло-зелёные." << endl;
  cout << "6. Тёмно-зелёные." << endl;
  cout << "7. Серые." << endl;
  cout << "8. Светло-серые." << endl;
  cout << "9. Тёмно-серые." << endl;
  cout << "10. Голубые." << endl;
  cout << "Ваш выбор [1..10]: ";
 
  while (!(cin >> selColor) || selColor <= 0 || selColor >10){
    cout << "Вы ввели некоректное значение! Попробуем снова." << endl;
    cout << "Ваш выбор [1..10]: ";      
  }

  string colorTxt = "";
  switch (selColor){
    case 1: colorTxt = "Карие";
      break;
    case 2: colorTxt = "Голубые";
      break;
    case 3: colorTxt = "Зелёные";
      break;
    case 4: colorTxt = "Серые";
      break;
    case 5: colorTxt = "Чёрные";
      break;
    case 6: colorTxt = "Светло-зелёные";
      break;
    case 7: colorTxt = "Тёмно-зелёные";
      break;
    case 8: colorTxt = "Светло-карие";
      break;
    case 9: colorTxt = "Тёмно-карие";
      break;
    case 10: colorTxt = "Инного цвета";
      break;
  }  
  return colorTxt;
}

string ValidApproval(string inTxt){
  string resTxt = "";
  cout << inTxt;
  // cin >> resTxt;
  
  while(!(cin >> resTxt) || !(resTxt.compare("да") == 0 || resTxt.compare("нет") == 0)) {
    cin.clear();
    cin.ignore(123, '\n');   
    cout << "Введите указанные значения да/нет." << endl;
    cout << inTxt;    
  }
  return resTxt;
}

int main() {
  
  cout << "Программа отбора кандидатов в лётчики." << endl;
  string answer = ValidApproval("Имеется ли инвалидность [да/нет]: ");
  if(answer.compare("нет") == 0){
    
    int exper = ValidInt("Если есть опыт, укажите количество часов: ");
    if(exper < 100){
    
      int height = ValidInt("Введите рост кандидата : ");
      int weight = ValidInt("Введите вес кандидата: ");    
      string color = ValidEyeColor("Укажите цвет глаз кандидата: ");
      cout <<  "---------------------------------------------" << endl;
        
      if ((height > 144 || height < 166) && (weight > 44 || weight < 66)
         && !(color.compare("Зелёные") == 0 || color.compare("Светло-зелёные") == 0 
         || color.compare("Тёмно-зелёные") == 0)) {
          cout << "Кандидат здоров и соответствует требованиям!" << endl;
          cout << "Данный кандидат нам подходит." << endl;
      } else {
          cout << "Кандидат не соответствует требованиям!" << endl;
          cout << "Данный кандидат нам не подходит." << endl;
      }           
    } else{
      cout << "Кандидат здоров и имеет достаточный опыт!" << endl;
      cout << "Данный кандидат нам подходит." << endl;
    }    
  } else {
    cout << "--------------------------------" << endl;
    cout << "Кандидат должен быть здоров!" << endl;
    cout << "Данный кандидат нам не подходит." << endl;
  }
  return 0;
}