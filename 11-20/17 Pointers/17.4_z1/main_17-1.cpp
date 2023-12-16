// Задание 17.4.1. Работа с указателями

# include <iostream>

void SwapInt(int*, int*);

int main(){

    int a = 10, b = 20;
    
    SwapInt(&a, &b);

    std::cout << "A = " << a << " B = " << b << std::endl;

    return 0;
}

void SwapInt(int* inA, int* inB){    
    std::swap(*inA, *inB);
}