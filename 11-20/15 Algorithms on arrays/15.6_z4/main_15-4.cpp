// Задание 15.6.4.Сортировка массива с возрсастанием по модулю

#include<iostream>

template<int rc, typename nT>
int SeachPositive(nT (&)[rc]);      // Поиск индекса положительного числа

int main(){
    int mass[] {-100, -50, -5, 1, 10, 15};   
        
    int indPoz = SeachPositive(mass);
    int indNeg = indPoz - 1, num = 0;

    if(indPoz > 0){
        std::cout << std::endl << "mass => {";
        do{   
            if(indPoz < std::size(mass)) {        
                if(abs(mass[indNeg]) > abs(mass[indPoz])){
                    std::cout << mass[indPoz];
                    if(indPoz < std::size(mass)) {
                        indPoz++;
                        num++;
                    }               
                    
                } else {
                    std::cout << mass[indNeg];
                    if(indNeg > 0) {
                        indNeg--;
                        num++;
                    }   
                }  

                if(indPoz <= std::size(mass)){
                    std::cout << ", ";
                } 

            } else {
                if(abs(mass[indNeg]) < abs(mass[indNeg - 1]) && indNeg > 0){
                    std::cout << mass[indNeg] << ", ";
                    if(indNeg > 0) {
                        indNeg--;
                        num++;
                    }        
                } else if(indNeg == 0){
                    std::cout << mass[indNeg];
                    num++;
                }
            } 

        } while (num < std::size(mass));
        std::cout << "}" << std::endl;

    } else {
        std::cerr << std::endl << "The array consists of positive numbers and was previously sorted." << std::endl;  
    }

    system("pause");
    return 0;
}

// *******************

// Поиск индекса положительного числа
template<int rc, typename nT>
int SeachPositive(nT (&inMass)[rc]){
    
    for(int i = 0; i < std::size(inMass); i++){
        if(inMass[i] >= 0){
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