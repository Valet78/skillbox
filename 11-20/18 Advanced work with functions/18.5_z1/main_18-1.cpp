// Задание 18.5.1

#include<iostream>
#include<vector>

std::vector<int> swapVec(std::vector<int>, int*);
template<typename T>
void print(T);



int main() {

    std::vector<int> a = {1, 2, 3, 4};
    int b[] = {2, 4, 6, 8};
    
    a = swapVec(a, b);
    print(a);
    print(b);
   
    return 0;
}

std::vector<int> swapVec(std::vector<int> inA, int* inB) {
    int temp = 0;

    for(int i = 0; i < 4; i++) {
        temp = inA[i];
        inA[i] = *(inB + i);
        *(inB + i) = temp;
    }
    
    return inA;
}

template<typename T>
void print(T inVal) {
    
    std::cout << std::endl;
    
    for(int i = 0; i < 4; i++) {
        std::cout << inVal[i];
        if(i < 3) {
            std::cout << ", "; 
        }
    }

    std::cout << std::endl;
}