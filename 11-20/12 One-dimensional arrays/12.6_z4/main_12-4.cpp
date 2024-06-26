// Задание 12.5.4. Ряд чисел

#include<iostream>

int main(){
    int numbers[] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int x = 105, sumSequence = 0, sumReference = 0, delta = 0;

    for(int i = 0; i < std::size(numbers); i++){
        sumReference += (i < 14) ? x + i : 0;
        sumSequence += numbers[i];
    }

    if(sumReference < sumSequence) {
        delta = sumSequence - sumReference;
        
        std::cout << "A repeating number: " << sumSequence - sumReference << std::endl;
    } else {
        std::cout << "No repetitions found." << std::endl;
    }

    return 0;
}

