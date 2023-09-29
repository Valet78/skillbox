// Задание 15.6.4.Сортировка массива с возрсастанием по модулю

#include<iostream>

template<int rc, typename nT>
int SeachPositive(nT (&)[rc]);      // Поиск индекса положительного числа
template<int rc, typename nT>
void Print(nT (&)[rc]);              // Вывод массива


int main(){
    int mass[] {-100, -50, -5, 1, 10, 15};    
    bool replace = false;
    int ind = SeachPositive(mass);
    int i = ind;
    
    if(ind > 0){
        for(i; i > 0; i--){
            for(int k = ind; k < std::size(mass); k++){
                if(abs(mass[k - 1]) >= abs(mass[k])){
                    std::swap(mass[k - 1], mass[k]);
                }                 
            } 
            ind = SeachPositive(mass);  
        }  
    } else {
        std::cout << std::endl << "The array consists of positive numbers and was previously sorted." << std::endl;
    }
    
    Print(mass);   

    system("pause");
    return 0;
}

// *******************

// Поиск индекса положительного числа
template<int rc, typename nT>
int SeachPositive(nT (&inMass)[rc]){
    
    for(int i = 0; i < std::size(inMass); i++){
        if(inMass[i] > 0){
            // std::cout << "ind = " << i << std::endl;
            return i;
        }
    }    
    return 0;
}      

// Вывод массива
template<int rc, typename nT>
void Print(nT (&inMass)[rc]){
    std::cout << std::endl << "mass => {" ;
    for(int i = 0; i < std::size(inMass); i++){
        std::cout << inMass[i];
        if(i != std::size(inMass) - 1){
            std::cout << ", "; 
        }
    }
    std::cout << "}" << std::endl;
}