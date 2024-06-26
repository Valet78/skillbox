/*
Исправьте код программы так, чтобы значение скорости рассчитывалось автоматически.

 Скорость — это сумма показателей двигателя, колёс и руля минус показатели дождя и ветра.
  */


#include <iostream> 
int main() { 
    int lap = 4; 
    int engine = 254; 
    int wheels = 93; 
    int steerinWheel = 49; 
    int wind = 21; 
    int rain = 17; 
    int speed = engine + wheels + steerinWheel - wind - rain;
        // 358; 
        
    std::cout << "===================\n"; 
    std::cout << "Супер гонки. Круг " << lap << "\n"; 
    std::cout << "===================\n"; 
    std::cout << "Шумахер (" << speed << ")\n"; 
    std::cout << "===================\n"; 
    std::cout << "Водитель: Шумахер\n"; 
    std::cout << "Скорость: " << speed << "\n"; 
    std::cout << "-------------------\n"; 
    std::cout << "Оснащение\n"; 
    std::cout << "Двигатель: +" << engine << "\n"; 
    std::cout << "Колеса: +" << wheels << "\n"; 
    std::cout << "Руль: +" << steerinWheel << "\n"; 
    std::cout << "-------------------\n"; 
    std::cout << "Действия плохой погоды\n"; 
    std::cout << "Ветер: -" << wind << "\n"; 
    std::cout << "Дождь: -" << rain << "\n"; 
    return 0;
}