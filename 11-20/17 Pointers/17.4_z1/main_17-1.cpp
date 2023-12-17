// Задание 17.4.1. Работа с указателями

# include <iostream>

void swapInt(int*, int*);

int main(){

    int a = 10, b = 20;
    
    swapInt(&a, &b);

    std::cout << "A = " << a << " B = " << b << std::endl;

    return 0;
}

void swapInt(int* inA, int* inB){    
    std::swap(*inA, *inB);
}