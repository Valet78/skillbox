/*
Задание 7.5.5. Координатные оси

Модифицируйте пример с координатными осями так, чтобы в точке их пересечения рисовался 
знак «+», на верхнем конце вертикальной оси была стрелка вверх «^», а на правом конце
горизонтальной оси — стрелка вправо «>». Это сделает рисунок более красивым и точным.

Рекомендации по выполнению
Заметьте, что в центре координатных осей есть пересечение.

Что оценивается
Координатные оси рисуются с помощью условных конструкций и циклов.
*/
#include <iostream>

// Проверка ввода строки и пустого ввода
std::string InputTxt(std::string inTxt){
  std::string result = "";
   do{
    std::cout << inTxt;
    getline(std::cin, result);
    if (result == ""){
      std::cout << "Вы забыли ввести значение! Попробуйте снова." << std::endl;
    } 
  } while(result == ""); 
  return result;
}

// Является ли числом
bool IsDigit(std::string inTxt){
  // int point = 0;
  int ind = 0;
  
  for (int i = 0; i < inTxt.length(); i++){
    if (i == 0 && inTxt[0] == '-'){
      ind++;
    } else if (int(inTxt[i]) >= 48 && int(inTxt[i] <= 57)){
      ind++;
    }  else {
      ind--;
    }
  }     
  
  if (ind == inTxt.length()){
    return true;
  }  
  return false;
}

// Проверка ввода числа и вывод его
int ValidNum(std::string request){
  int result = 0;
  std::string numTxt = "";
  bool err = true;

  do {
    numTxt = InputTxt(request);
    if (IsDigit(numTxt)){
      result = std::stoi(numTxt);
      if (result <= 0){
        std::cout << "Введите число, больше нуля!" << std::endl;
      } else { 
        err = false;
      }
    } else {
      std::cout << "Введённое значение не число! Попробуйте снова." << std::endl;
    }  
  } while (err);

  return result;
}

int main() {
  std::cout << "Программа построения оси координат." << std::endl;;
  int size = ValidNum("Укажите размер плоскости: "); 

  for (int y = 0; y < size; y++){
    for (int x = 0; x < size; x++){
      if (x == size/2 && y == size/2){
        std::cout << "+";
      } else if (x == size/2 && y == 0) {
        std::cout << "^";
      } else if (y == size/2 && x == size - 1){
        std::cout << ">";
      } else if (y == size/2 && x >= 0 && x < size) {
        std::cout << "-";
      } else if (x == size/2 && y >= 0 && y < size) {
        std::cout << "|";
      } else {
        std::cout << " ";
      }      
    }
    std::cout << std::endl;
  }

  return 0;
}