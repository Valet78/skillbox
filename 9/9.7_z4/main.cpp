/*
9.7.4. «Быки и коровы» (дополнительное задание)

В логической игре «Быки и коровы» первый игрок загадывает четырёхзначное число (оно может начинаться и
с нулей), а второй игрок должен его отгадать. 

Отгадывание происходит так: второй игрок называет любое четырёхзначное число, а первый ему отвечает,
сколько в этом числе «быков» и сколько «коров». 

«Корова» — это цифра, которая совпадает по значению с какой-то из цифр задуманного числа, но не стоит 
на нужном месте. «Бык» — это цифра, совпадающая с цифрой в задуманном числе и по значению, и по 
расположению.

Напишите программу, которая по загаданному числу и по названному вторым игроком числу определяет, 
сколько во втором числе «быков» и сколько «коров». Не забудьте, что числа могут начинаться с нулей!

Примеры выполнения  Введите задуманное число: 5671
                    Введите второе число: 7251
                    Быков: 1, коров: 2
                    Введите задуманное число: 1234
                    Введите второе число: 1234
                    Быков: 4, коров: 0
                    Введите задуманное число: 0023
                    Введите второе число: 2013
                    Быков: 2, коров: 1
                    Введите задуманное число: 2013
                    Введите второе число: 0023
                    Быков: 2, коров: 1
                    Введите задуманное число: 1111
                    Введите второе число: 1111
                    Быков: 4, коров: 0
                    Введите задуманное число: 1222
                    Введите второе число: 2234
                    Быков: 1, коров: 1

Рекомендация по выполнению
Сумма «быков» и «коров» не может быть больше четырёх.

Что оценивается
Использован строковый тип данных для считывания чисел.
Решение на примерах из условия выдаёт правильный результат.
*/


#include <iostream>
#include <string>

// Проверка ввода строки и пустого ввода
std::string InputTxt(std::string inTxt){
  std::string result = "";
   do{
    std::cout << inTxt;
    getline(std::cin, result);
    if (result == ""){
      std::cout << "Вы забыли ввести значение! Попробуйте снова." << std::endl;
    } else if (result.length() != 4) {
      std::cout << "Число должно быть четырёхзначным!" << std::endl;
    }
  } while(result == "" || result.length() != 4); 
  return result;
}

// Проверка ввода числа
bool IsDigit(std::string inTxt){  
  int dig = 0;
  
  for (int i = 0; i < inTxt.length(); i++){
    if (inTxt[i] >= '0' && inTxt[i] <= '9'){
      dig++;
    }  
  }     
  
  if (dig == inTxt.length()){
    return true;
  }  
  return false;
}

// Уникальность чисел в строке
std::string UniqNum (std::string inTxt){
  std::string result = "";

  for (int i =0; i < inTxt.length(); i++){    
      if (inTxt[i] != '*' && result.find(inTxt[i]) == result.npos ){
        result.push_back(inTxt[i]);
      }
  }
  return result;
}


int main() {
  std::cout << "Программа - игра \"Быки и коровы\"" << std::endl;
  
  std::string numOne = InputTxt("Введите задуманное число: ");
  while (!IsDigit(numOne)){
    std::cout << "Введено некорректное значение! Попробуйте снова." << std::endl;
    numOne = InputTxt("Введите задуманное число: ");
  }
  
  std::string numTwo = InputTxt("Введите второе число: ");
  while (!IsDigit(numTwo)){
    std::cout << "Введено некорректное значение! Попробуйте снова." << std::endl;
    numOne = InputTxt("Введите второе число: ");
  }
  
  std::cout << "-----------------------------------" <<  std::endl;
  
  int bull = 0, cow = 0, ind = 0;
  
  for(int i = 0; i < 4; i++){    
    if (numTwo[i] == numOne[i]){
      numTwo[i] = '*';
      numOne[i] = '*';
      bull++;
    }
  }  

  if (bull != 4) {
      std::string uniqOne = UniqNum(numOne);
      std::string uniqTwo = UniqNum(numTwo);
  
      for (int i = 0; i < uniqTwo.length(); i++){
        for (int k = 0; k < uniqOne.length(); k++){
          if (uniqTwo[i] == uniqOne[k]){
            cow ++;
          }
        }
      }
  }  

  std::cout << "Быков: " << bull << ", коров: " << cow << std::endl;
  
  return 0;
}