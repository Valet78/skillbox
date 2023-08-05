/*
Задание 8.6.9. Яйца* (дополнительное задание)

В рамках программы колонизации Марса компания «Спейс Инжиниринг» вывела особую породу черепах, которые
должны размножаться, откладывая яйца в марсианском грунте. Откладывать яйца слишком близко к поверхности
опасно из-за радиации, а слишком глубоко опасно из-за давления грунта и недостатка кислорода. 
Вообще, факторов много, но специалисты проделали большую работу и предположили, что уровень опасности
для черепашьих яиц рассчитывается по формуле D = x^3 − 3x^2 − 12x + 10, где x — глубина кладки в метрах,
а D — уровень опасности в условных единицах. Для тестирования гипотезы нужно взять пробу грунта на
безопасной, согласно формуле, глубине.

Напишите программу, находящую такое значение глубины х, при котором уровень опасности наиболее близок 
к нулю, учитывая допустимое отклонение. На вход программе подаётся максимально допустимое отклонение
уровня опасности от нуля, а программа должна рассчитать приблизительное значение х, удовлетворяющее
этому отклонению. Известно, что глубина точно больше нуля и меньше четырёх метров.
Обеспечьте контроль ввода.

Пример выполнения   Введите максимально допустимый уровень опасности: 0,01
                    Вывод: Приблизительная глубина безопасной кладки: 0,732422 метра

Рекомендации по выполнению
Отрицательный уровень опасности — это тоже плохо. Нужно найти наиболее близкий к нулю уровень опасности.
Здесь не обязательно считать корни кубического уравнения. Достаточно найти решение на отрезке от 0 до 4.
Что оценивается
Для поиска решения не используется полный перебор.
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

// Проверка ввода числа и вывод его (Float)
float ValidNumFloat(std::string request){
  float result = 0.0f;
  std::string numTxt = "";
  bool err = true;

  do {
    numTxt = InputTxt(request);
    if (IsDigit(numTxt)){
      result = std::stof(numTxt);
      if (result <= 0 || result > 1) {
        std::cout << "Введите число в дипазоне (0..1]!" << std::endl;
      } else { 
        err = false;
      }
    } else {
      std::cout << "Введите вещественное число! Попробуйте снова." << std::endl;
    }  
  } while (err);
  
  return result;
}

int main() {
  std::cout << "Программа расчёта глубины закладки яиц черепахи в марсианский грунт" << std::endl <<
    "для минимизации уровня опасности с учётом допустимого отклонения." << std::endl;
  float levelMax = ValidNumFloat("Введите максимально допустимый уровень опасности: ");
  float start = 0.0f, stop = 4.0f;
  float midl = 0.0f, delta = 0.0f, levelDelta = 0.0f;

  do {
    midl = start + (stop - start) / 2.0f;
    delta = std::pow(midl, 3) - 3 * std::pow(midl, 2) - 12 * midl + 10;

    if (delta < 0){
      stop = midl;
    } else {
      start = midl;
    }
    
    levelDelta = levelMax - std::abs(delta);    
  } while (levelDelta < 0);

  std::cout << "Приблизительная глубина безопасной кладки: " << midl << " м." << std::endl;

  return 0;
}