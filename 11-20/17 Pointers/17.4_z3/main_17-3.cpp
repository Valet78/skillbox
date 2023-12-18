// Задание 17.4.3. Работа с char с применением указателей

#include<iostream>
#include<cstring>

bool chekSubstr(const char*, const char*);

int main() {
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

    std::cout.setf(std::cout.boolalpha);    // Вывод "true" и "false" вместо "1" и "0" соответственно 
    std::cout << std::endl << chekSubstr(a, b) << " " << chekSubstr(a, c) << std::endl << std::endl;

    return 0;
}

bool chekSubstr(const char* inOne, const char* inTwo) {
    int i = 0, k = 0; 
    bool res = true;    

    while(*(inOne + i) != '\0') {

        if(*(inOne + i) == *(inTwo + k)) {

            while(*(inTwo + k) != '\0') {
                res &= (*(inOne + i + k) != '\0' && *(inOne + i + k) == *(inTwo + k)) ? true : false;
                k++;                
            }

            if(res) {
                return true;

            } else {
                k = 0;
                i = i + k;
                res = true;
            }
        }

        i++;
    }

    return false;
}