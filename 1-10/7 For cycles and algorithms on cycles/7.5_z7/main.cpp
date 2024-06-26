/*
Задание 7.5.7. Биолаборатория* (дополнительное задание)

В борьбе со всемирной эпидемией коринебактерий исследователи компании «Терран Биотех»
открыли новый антибиотик. Напишите программу, помогающую протестировать его.

В чашку Петри исследователи кладут N бактерий и добавляют X капель антибиотика. 
Известно, что число коринебактерий в чашке Петри увеличивается в два раза каждый час, 
а каждая капля антибиотика в первый час убивает 10 бактерий, во второй час — 9 бактерий, 
в следующий — 8 и так далее, пока антибиотик не перестанет действовать. 
Заметьте, что сначала число коринебактерий увеличивается, а затем действует антибиотик.
Пользователь вашей программы вводит N и X, а программа печатает на экране, сколько бактерий
останется в чашке Петри в конце каждого часа, до тех пор, пока не закончатся бактерии или
антибиотик не перестанет действовать. Судьба человечества — в ваших руках. 
Обеспечьте контроль ввода.

Пример выполнения   Введите количество бактерий: 12 
                    Введите количество антибиотика: 1 
                    После 1 часа бактерий осталось 14 
                    После 2 часа бактерий осталось 19 
                    После 3 часа бактерий осталось 30
                    После 4 часа бактерий осталось 53 
                    …
Что оценивается
Цикл не бесконечный.
Количество бактерий и антибиотика не становится отрицательным.
После того как количество антибиотики или бактерий становиться равным нулю выполнение программы должно быть завершено.
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
  std::cout << "Программа тестирования антибиотика." << std::endl;
  int bacteria = ValidNum("Введите количество бактерий: ");
  int antibiotic = ValidNum("Введите количество антибиотика: ");
  std::cout << "-----------------------------------" << std::endl;
  int hour = 1, kill = 10;
  bool end = false;  
  
  while (!end) {
    bacteria = bacteria * 2 - antibiotic * kill;
    
    if (bacteria > 0 && kill > 0) {      
      std::cout << "По завершении " << hour << " часа бактерий осталось " << bacteria << std::endl;
      hour++;
      kill--;
    } else if (bacteria <= 0) {
      bacteria = 0;
      std::cout << "По завершении " << hour << " часа бактерий осталось " << bacteria << 
            std::endl;
      end = true;
    } else if ( kill == 0) {
      std::cout << "По завершении " << hour << " часа бактерий осталось " << bacteria << 
            std::endl << "Действие антибиотика закончилось!" << std::endl;
      end = true;
    } 
  }
  return 0;
}