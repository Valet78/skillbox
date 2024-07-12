/*
Задание 8.6.8. Биолаборатория 2.0* (дополнительное задание)

Благодаря вашей помощи компания «Терран Биотех» вышла на финишную прямую в борьбе
со всемирной эпидемией коринебактерий. Однако прошлая симуляция была недостаточно
точной, да и новая версия антибиотика работает по-другому.

В чашку Петри добавляется W капель воды, D капель чистого антибиотика и подселяется
N коринебактерий. Известно, что каждую минуту количество бактерий изменяется прямо
пропорционально концентрации антибиотика в растворе по формуле 
Nnew = 2 × Nold − Nold × D / W, где Nold — количество коринебактерий минуту назад,
Nnew — их новое количество, а D / W — концентрация действующего антибиотика. 
При этом каждую минуту 20% от всего количества антибиотика разлагается и больше 
не действует.

Напишите программу, которая получает на вход значения W, D и Nold и симулирует 
процесс в течение 20 минут, для каждой минуты выводя на экран текущую концентрацию 
антибиотика и количество живых коринебактерий в чашке Петри. Обеспечьте контроль
ввода.

Что оценивается
Количество измеряется в целых числах.
Ничто не уходит в отрицательные значения.
Цикл не бесконечный.
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
  std::cout << "Программа тестирования антибиотика (V.2.0)." << std::endl;
  int water = ValidNum("Укажите количество воды: ");
  int antibiotic = ValidNum("Введите количество антибиотика: ");
  int bacteria = ValidNum("Введите количество бактерий: ");  
  std::cout << "-----------------------------------" << std::endl;
    
  for (int min = 1; min <=20; min++) {
    bacteria = bacteria * 2 - bacteria * antibiotic / water;
    
    if (bacteria > 0) {      
      std::cout << "По завершении " << min << " мин. бактерий осталось " << bacteria <<                 std::endl;
      // minutes++;
      antibiotic -= antibiotic * 0.2;
    } else if (bacteria <= 0) {
      bacteria = 0;
      std::cout << "По завершении " << min << " мин. бактерий осталось " << bacteria << 
            std::endl;
      break;
    } else if (antibiotic <= 0) {
      std::cout << "По завершении " << min << "  мин. бактерий осталось " << bacteria << 
            std::endl << "Действие антибиотика закончилось!" << std::endl;
      break;
    } 
    std::cout << "bakt = " << bacteria << "\tant = " << antibiotic << std::endl;
  }
  return 0;
}