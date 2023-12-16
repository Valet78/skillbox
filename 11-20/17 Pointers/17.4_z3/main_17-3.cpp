// Задание 17.4.3. Работа с char с применением указателей

#include<iostream>
#include<cstring>

bool ChekSubstr(const char*, const char*);

int main(){
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

    std::cout.setf(std::cout.boolalpha);    // Вывод "true" и "false" вместо "1" и "0" соответственно 
    std::cout << std::endl << ChekSubstr(a, b) << " " << ChekSubstr(a, c) << std::endl;

    return 0;
}

bool ChekSubstr(const char* inOne, const char* inTwo){
    return (strstr(inOne, inTwo)) ? true: false;
}