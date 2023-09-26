// Задание 15.6.4.Сортировка массива с возрсастанием по модулю

#include<iostream>
template<int rc, typename nT>
void SortVec(nT (&)[rc]);   // Сортировка массива, передача по ссылке
template<int rc, typename nT>
void Print(nT (&)[rc]);              // Вывод массива


int main(){
    int mass[] {-100,-50, -5, 1, 10, 15};

    SortVec(mass);
    Print(mass);    

    return 0;
}

// *******************

// Сортировка массива, передача по ссылке
template<int rc, typename nT>
void SortVec(nT (&inMass)[rc]){ 
    
    for(int i = 0; i < std::size(inMass); i++){
        for(int k = 0; k < std::size(inMass) - i - 1; k++){
            if(abs(inMass[k]) > abs(inMass[k + 1])) {
                std::swap(inMass[k], inMass[k + 1]);
            }
        }
    }
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