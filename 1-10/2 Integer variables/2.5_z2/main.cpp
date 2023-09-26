/*
Напишите калькулятор для расчёта полной стоимости товара. 
Она рассчитывается так: стоимость товара  + стоимость доставки – скидка. 
Все значения сохраните в переменные и выводите в нужных местах, имитируя ввод данных (речь про cout).
*/

#include <iostream>
#include <math.h>

int main(){
  float deliveryPrice = 356.5;
  float productPrice = 5640.87;
  float discount = round(productPrice * 0.12 * 100) / 100;  // скидка 12%
  float productCost = productPrice + deliveryPrice - discount;

  std::cout << "Полная стоимость товара: " << productCost << " руб. \n";
  std::cout << "  из которых:\n";
  std::cout << "    цена товара: " << productPrice << " руб. \n";
  std::cout << "    доставка:    " << deliveryPrice << " руб. \n";
  std::cout << "    скидка:      " << discount << " руб. \n";

  return 0;
}