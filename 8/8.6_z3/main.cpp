/*
Задание 8.6.3. Игрушечная история

Вы решили открыть бизнес по производству игровых деревянных кубиков для детей. Вы узнали,
что лучше всего продаются кубики со стороной 5 см в наборах по несколько штук, причём 
кубиков в наборе должно быть достаточно, чтобы сложить из них один большой куб. Для 
изготовления кубиков к вам в мастерскую поступают деревянные бруски в форме прямоугольных 
параллелепипедов любых размеров.

Для оптимизации бизнес-процессов напишите программу, которая по заданным размерам исходного
бруска определяет, сколько кубиков из него можно изготовить, можно ли из них составить набор
для продажи и если можно, то максимальное число кубиков в этом наборе. Все кубики должны 
быть из цельного дерева без использования клея. Размеры бруска — вещественные числа. 
Обеспечьте контроль ввода.

Например: Из бруска 20x35x5 можно изготовить 28 кубиков.
          Из 28 кубиков можно собрать набор из 27 кубиков.

Пример выполнения   Введите размеры бруска:
                    X: 5
                    Y: 35,76
                    Z: 35,05
                    Вывод: Из этого бруска можно изготовить 49 кубиков.
                    Из них можно составить набор из 27 кубиков.

Рекомендации по выполнению
Кубики изготавливаются только цельными, не из нескольких частей бруска. 
Минимальный размер бруска — 5x5x5 см. Подумайте как проще разбить брусок на такие кубики.
Минимальный размер набора — 2x2x2 = 8 кубиков.
Что оценивается
Правильно считается количество кубиков, которое можно получить из бруска.
Количество кубиков в наборе не превышает количество кубиков, полученное из бруска.
*/


#include <iostream>
#include <cmath>

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
  int ind = 0;
  
  for (int i = 0; i < inTxt.length(); i++){
    if (i == 0 && inTxt[0] == '-' || inTxt[i] == '.'){
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

// Проверка ввода числа и вывод его (float)
float ValidNumFloat(std::string request){
  float result = 0.0f;
  std::string numTxt = "";
  bool err = true;

  do {
    numTxt = InputTxt(request);
    if (IsDigit(numTxt)){
      result = std::stof(numTxt);
      if (result < 5) {
        std::cout << "Минимальное значение размера 5 см!" << std::endl;
      } else { 
        err = false;
      }
    } else {
      std::cout << "Вы не ввели число! Попробуйте снова." << std::endl;
    }  
  } while (err);
  
  return (float) result;
}

// Расчет количества с учётом распила
int NumberCubesSawed(float inNum){
  int result = 0, sawed = 0;
  float sum = 0.0f;
  
  if (inNum == 5) {
    result ++;
  } else {
    result = inNum / 5;
    sawed = result - 1;
    sum = result * 5 + sawed * 0.3;
    if (sum > inNum){
      result --;
    }    
  }  
  return result;
}

// Расчет количества без учёта распила
int NumberCubes(float inNum){  
  return (int)inNum / 5;
}

int main() {
  std::cout << "Программа расчёта количества кубиков из бруса." << std::endl;
  std::cout << "Укажите размеры бруса (доски), из которого планируете" << std::endl;
  std::cout << "напилить кубики со стороной 5 см. Минимальный размер 5 см." << std::endl;
  float height = ValidNumFloat("\tвысота: ");
  float width = ValidNumFloat("\tширина: ");
  float length = ValidNumFloat("\tдлина: ");  
  std::cout << "----------------------------------------------------------" << std::endl;
  // 
  int hNum = NumberCubes(height);
  int wNum = NumberCubes(width);
  int lNum = NumberCubes(length);
  int sumCubes = hNum * wNum * lNum;  
  std::cout << "Вывод: из этой доски можно изготовить " << sumCubes << " кубиков." <<           std::endl;
  if (sumCubes > 8) {
    int cubes = 2, naborNum = 0;
    int remains = 0, powCub = std::pow(cubes, 3);
    std::cout << "Из них можно составить следующие наборы:" << std::endl;
    while ( powCub <= sumCubes){        
        naborNum = sumCubes / powCub;
        remains = sumCubes % powCub;      
        std::cout << "\t" << naborNum << " шт. из " << cubes << " кубиков \tостанется "
          << remains << " кубик(а/ов)." << std::endl;
        cubes++;
        powCub = std::pow(cubes, 3);
    }
    
  } else {
    std::cout << "Из этого количества не получится ниодного набора!" << std::endl;
  } 
  return 0;
}