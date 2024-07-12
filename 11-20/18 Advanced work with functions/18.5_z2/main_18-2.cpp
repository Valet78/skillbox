// Задание 18.5.2

#include<iostream>

int n = 3, k = 2;
int jamp(int inN, int inK = 3);

int main() {
    int res = 0;

    if((k <= 0 || k > 3) || n <= 0 || n < k) {
        std::cout << std::endl << "Incorrect data has been entered!" << std::endl;
        std::cout << "The rabbit must jump and cannot jump more than 3 steps." << std::endl;
        return -1;
    }

    std::cout << std::endl;

    res = jamp(n, k);    
    // res = jamp(n);
    
    std::cout << res << std::endl;

    return 0;
}

int jamp(int inN, int inK) {
    static int* defK = &inK;
        
    // if(inN == 0) {
    //     return 1;
    // } else if(inN < 0 || inK < 1) {
    //     return 0;
    // } 
    
    // return jamp(inN - inK, *defK) + jamp(inN, inK - 1);
    
    return (inN == 0) ? 1 : (inN < 0 || inK < 1) ? 0 : jamp(inN - inK, *defK) + jamp(inN, inK - 1);    
}

