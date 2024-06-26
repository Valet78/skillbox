// Задание 15.6.2.Поиск в массиве числа.

#include<iostream>

int main(){
    int a[] {2, 7, 11, 15};
    int ind_i = -1, ind_k = -1, res = 9;

    for(int i = 0; i < std::size(a); i++){
        for(int k = i + 1; k < std::size(a); k++){           
            if(a[i] + a[k] == res){
                ind_i = i;
                ind_k = k;
                break;
            } 
        }
        if(ind_i != -1 || ind_k != -1){
            break;
        }
    }
    
    if(ind_i == -1 || ind_k == -1) {
        std::cerr << std::endl << "No such elements were found!" << std::endl << std::endl;
        system("pause");
        return -1;
    }
    std::cout << std::endl << "Array elements with indexes " << ind_i;
    std::cout << " and " << ind_k << " in total the specified value is given:" << std::endl;
    std::cout << "\t" << a[ind_i] << " + " << a[ind_k] << " = " << res << std::endl;

    system("pause");
    return 0;
}