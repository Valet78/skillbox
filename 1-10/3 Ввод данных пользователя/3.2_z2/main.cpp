/*
Задание 2. Теперь вернемся к программе с расчетом стоимости товара. 
Измените ее так, чтобы пользователь мог вводить свои данные.

Переменные для хранения цены, стоимости доставки и скидки у нас уже есть, 
вам нужно дописать код, который будет записывать в них введенные пользователем 
числа. Не забудьте добавить подсказки, чтобы было понятно, что нужно вводить.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
   
  float productCost = 0;    // 6504;  
  float deliveryCost = 0;   // 354;  
  

  cout << "Это программа \"Расчёт стоимости товара\"" << endl;
  cout << "Введите следующие данные" << endl;
  cout << "себестоимость товара: ";
  cin >> productCost;
  cout << "стоимость доставки: ";
  cin >> deliveryCost;
  cout << "--- Считаем! ---" << endl << endl;
  
  float discount = round(100*(productCost*0.11))/100;       // 715.44;
  float price = round(100*(productCost + deliveryCost - discount))/100;
    
  
  std::cout << "Стоимость товара: " << productCost << endl;  
  std::cout << "Cтоимость доставки: " << deliveryCost << endl;  
  std::cout << "Скидка: " << discount << endl;  
  std::cout << "---------" << endl;  
  std::cout << "Итого: " << price << endl;  // 6142.56
  
  return 0;
}
