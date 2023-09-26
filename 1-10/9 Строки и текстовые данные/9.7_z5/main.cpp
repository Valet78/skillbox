/*
9.7.5. Из обычных чисел — в римские (дополнительное задание)

Напишите программу, которая переводит данное пользователем число в римскую запись. Например, 19 в римской записи — XIX.

Римскую запись числа можно получить, если следовать правилам:
- Сначала в ней идут буквы, обозначающие количество тысяч в числе. 
- Затем идут буквы, обозначающие количество сотен, затем буквы, обозначающие количество десятков, и 
  в конце — буквы, обозначающие количество единиц. 
 
Для записи используются следующие буквы: 1 — I, 5 — V, 10 — X, 50 — L, 100 — C, 500 — D и 1000 — M. 
Число получается как сумма значений использованных в нём букв, за тем исключением, что если буква с 
меньшим значением идёт перед буквой с большим значением, то её значение вычитается из значения числа. 
Вычитание используется, только когда надо передать цифру 4 или 9, в остальных случаях используется 
сложение. Например, 9 обозначается как IX, 40 — как XL. 
В числе запрещено писать более трёх одинаковых букв подряд. Таким образом, максимальное число, которое
можно записать по этим правилам, — 3999.
Программе на вход даётся целое число из диапазона от 1 до 3999. Вы можете считывать его как число или как строку, если так удобнее.
Программа должна вывести римскую запись данного числа.

Примеры выполнения  Ввод: 351
                    Вывод: CCCLI
                    Ввод: 449
                    Вывод: CDXLIX
                    Ввод: 1313
                    Вывод: MCCCXIII
                    Ввод: 2020
                    Вывод: MMXX

Рекомендации по выполнению
Решение этого задания похоже на решение задания «Банкомат-2» из модуля 5, только там мы последовательно
отнимали купюры от запрошенной суммы, а здесь последовательно подсчитываем римские числа.
Что оценивается
Программа выдаёт в результате единственно правильный вариант представления в римской записи.
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

// Проверка ввода числа
bool IsDigit(std::string inTxt){  
  int dig = 0, temp = 0;
  bool res = false;
  
  for (int i = 0; i < inTxt.length(); i++){
    if (inTxt[i] >= '0' && inTxt[i] <= '9'){
      dig++;
    }  
  }     
  
  if (dig == inTxt.length()){
    temp = std::stoi(inTxt);     
    if (temp > 0 && temp <= 3999) {
      res = true;      
    }  
  }  
  return res;
}


// Формирование римских цифир
std::string ToRoman (int cnum, int lev){
    std::string res = "";
    char jun = ' ', mid = ' ', eld = ' ';

    if (lev == 1) {
        jun = 'I';
        mid = 'V';
        eld = 'X';
    } else if (lev == 2) {
        jun = 'X';
        mid = 'L';
        eld = 'C';
    } else if (lev == 3) {
        jun = 'C';
        mid = 'D';
        eld = 'M';
    } else if (lev == 4) {
        jun = 'M';
    }

    if (cnum < 4){
      for (int i = 0; i < cnum; i++) {
        res.push_back(jun);
      }      
    } else if (cnum == 4) {
      res.push_back(jun);
      res.push_back(mid);
    } else if (cnum == 5) {
      res.push_back(mid);
    } else if (cnum > 5 && cnum < 9) {
      res.push_back(mid);
      for (int i = 0; i < cnum - 5; i++) {
        res.push_back(jun);
      }      
    } else if (cnum == 9) {
      res.push_back(jun);
      res.push_back(eld);        
    }

    return res;
}


int main() {
  std::cout << "Программа перевода чисел в \"римские\"" << std::endl;
  std::string inNumTxt = InputTxt("Введите число в диапазоне [1...3999]: ");

  while (!IsDigit(inNumTxt)) {
    std::cout << "Введены некорректные данные! Попробуйте снова." << std::endl;
    inNumTxt = InputTxt("Введите число в диапазоне [1...3999]: ");
  }                                 
  std::cout << "------------------------------------------" << std::endl;
  int inNum = std::stoi(inNumTxt);
  int count = 0;
  std::string result = "";

  int num_m = inNum / 1000;
  inNum %= 1000; 
  int num_c = inNum / 100;
  inNum %= 100;
  int num_x = inNum / 10;
  int num_i = inNum %= 10;

  result += ToRoman(num_m, 4);
  result += ToRoman(num_c, 3);
  result += ToRoman(num_x, 2);
  result += ToRoman(num_i, 1);
  
  
  std::cout << "Результат: " << result << std::endl;

  return 0;
}