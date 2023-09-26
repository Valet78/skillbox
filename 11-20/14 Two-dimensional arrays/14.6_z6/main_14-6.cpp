// Задание 14.6.6. Проход змейкой
#include<iostream>

template<int rc, typename nT>
void PrintMatrix(nT (&)[rc][rc]);          // Вывод матриц
template<int rc, typename nT>
void InitializationMass(nT (&)[rc][rc]);     // Инициализация массива

int main(){
    int mass[5][5];
    InitializationMass(mass);
    system("cls");
    PrintMatrix(mass);

    system("pause");
    return 0;
}


// Вывод матриц
template<int rc, typename nT>
void PrintMatrix(nT (&inMatr)[rc][rc]){
    std::cout << std::endl;
    for(int i = 0; i < rc; i++){
        std::cout << "\t";
        for(int k = 0; k < rc; k++){
            std::cout << std::to_string(inMatr[i][k]) << "\t";
        }
        std::cout << std::endl;
    }    
}       

// Инициализация массива
template<int rc, typename nT>
void InitializationMass(nT (&inMass)[rc][rc]){
    int num = 0, mult = 1, ind = 0;
    for (int i = 0; i < rc; i++)    {
        for (int k = 0; k < rc; k++) {
            ind = (i%2) * (rc - 1) + mult * k;
            inMass[i][ind] = num;
            num++;
        }        
        mult *= -1;
    }    
}
