// Задание 17.4.2. Применение указателей

#include <iostream>

void ReversVolum (int *);
void PrintVolum (int *);

int main(){
    int volum[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    ReversVolum(volum);
    PrintVolum (volum);

    return 0;
}

void ReversVolum (int *inVol){
    
    for(int i = 0; i < 5; i++){
        std::swap(*(inVol + i), *(inVol + (9 - i)));
    }
    
}

void PrintVolum (int *inVol){
    std::cout << std::endl << "Volum[] = {";

    for(int i = 0; i < 10; i++){
        std::cout << *(inVol + i);
        if(i < 9){
            std::cout << ", ";
        } 
    }

    std::cout << "}" << std::endl;
}