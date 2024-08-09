// Задание 23.4.2. Вывод времени года
#include "23.4-2.h"


int main() {
    std::setlocale(LC_ALL, "Russian_Russia.1251");
    std::wcout << L"Выбран сезон: ";

#ifdef SPRING
    std::wcout << SPRING << std::endl;
#endif

#ifdef SUMMER
    std::wcout << SUMMER << std::endl;
#endif

#ifdef AUTUMN
    std::wcout << AUTUMN << std::endl;
#endif

#ifdef WINTER
    std::wcout << WINTER << std::endl;
#endif


    system("pause");
    return 0;
}

