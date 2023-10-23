// Задание 15.6.4.Сортировка массива с возрсастанием по модулю

#include<iostream>

template<int rc, typename nT>
int SeachPositive(nT (&)[rc]);      // Поиск индекса положительного числа

int main(){
    int mass[] {-100, -50, -5, 1, 10, 15};   
    // int mass[] {-8, -7, -6, -5, 1, 10, 15};  
    
    int indPoz = SeachPositive(mass);
    int indNeg = indPoz - 1, num = 0;

    if(indPoz > 0){
        std::cout << std::endl << "mass => {";
        do{   
            if(indNeg >= 0 && indPoz < std::size(mass)){

                if(abs(mass[indNeg]) > abs(mass[indPoz])){
                    std::cout << mass[indPoz];
                    indPoz++;
                    num++;                                  
                    
                } else {
                    std::cout << mass[indNeg];
                    indNeg--;
                    num++;   
                } 

            } else if(indNeg < 0 && indPoz < std::size(mass)){
                
                std::cout << mass[indPoz];
                indPoz++;
                num++; 

            } else if(indPoz == std::size(mass) && indNeg >= 0){
                
                std::cout << mass[indNeg];
                indNeg--;
                num++; 

            }

            if(num < std::size(mass)){
                    std::cout << ", ";
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