// Заданеи 15.6.1. Работа с массивами

#include<iostream>

int main(){
    int a[] {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ind_i = 0, ind_k = 0, sum = 0, sumMax = -2147483647;

    for(int i = 0; i < std::size(a); i++){
        sum = a[i];
        for(int k = i + 1; k < std::size(a); k++){
            sum += a[k];
            if(sum > sumMax){
                sumMax = sum;
                ind_i = i;
                ind_k = k;
            }
        }        
    }

    std::cout << std::endl << "The maximum sum of sequence {";

    for(int i = ind_i; i <= ind_k; i++){
        std::cout << a[i];
        if(i != ind_k) {
            std::cout <<  ", ";
        }
    }
    
    std::cout << "} elements with indexes from " << ind_i << " to " << ind_k << " equal to " << sumMax << "." << std::endl;
    return 0;
} 