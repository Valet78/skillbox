// Задание 23.4.2. Вывод времени года
#include "23.4-2.h"

#ifdef SPRING, SUMMER, AUTUMN, WINTER
#undef SPRING
#undef SUMMER
#undef AUTUMN
#undef WINTER
#endif

#ifndef SPRING, SUMMER, AUTUMN, WINTER
#define SPRING L"Весна"
#define SUMMER L"Лето"
#define AUTUMN L"Осень"
#define WINTER L"Зима"
#endif


int main() {
    std::setlocale(LC_ALL, "Russian_Russia.1251");

#if (1)
    std::wcout << SUMMER << std::endl;
#endif

    system("pause");
    return 0;
}

