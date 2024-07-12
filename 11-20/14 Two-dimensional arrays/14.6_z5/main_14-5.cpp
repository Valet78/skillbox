// Задание 14.6.5. Пупырка

#include<iostream>

template<int rc>
void InitializationMass(bool (&)[rc][rc]);     // Инициализация массива
template<int rc, typename nT>
void PrintMatrix(nT (&)[rc][rc]);          // Вывод матриц
bool ValidNum(std::string);                // Проверка валидности ввода
int InNum(std::string);                    // Ввод числа и проверка валидности  
template<int rc, typename nT>
int BurstBubbles(nT (&)[rc][rc], int, int, int, int);   // Процесс "лопания" пузырей



int main(){
    bool mass[12][12];
    InitializationMass(mass);
    system("cls");
    std::cout << "A program to simulate the process of \"bursting\" bubbles of a special film." << std::endl;
    int size = 144, upp_r = 0, upp_c = 0, low_r = 0, low_c = 0;

    do{
        std::cout << std::endl << " Current state of the film:" << std::endl;
        PrintMatrix(mass);
        
        std::cout << "Specify the coordinates of the rectangular area where the bubbles should \"burst\"." << std::endl;
        upp_r = InNum("row (top corner): ") - 1;
        upp_c = InNum("column (top corner): ") - 1;
        low_r = InNum("row (bottom corner): ") - 1;
        low_c = InNum("column (bottom corner): ") - 1;

        if((upp_r < 0 || upp_r > 11) || (upp_c < 0 || upp_c > 11) || 
           (low_r < 0 || low_r > 11) || (low_c < 0 || low_c > 11)){            
            std::cout << "The coordinates of the area are specified incorrectly! Try again." << std::endl;
        } else {
            size -= BurstBubbles(mass, upp_r, upp_c, low_r, low_c);
        }
         
        system("pause");
        system("cls");
        
    } while(size > 0);

    std::cout << "You have \"burst\" all the bubbles on the film!" << std::endl;
    PrintMatrix(mass);

    system("pause");
    return 0;
}


// Инициализация массива
template<int rc>
void InitializationMass(bool (&inMass)[rc][rc]){
    for (int i = 0; i < rc; i++)    {
        for (int k = 0; k < rc; k++) {
            inMass[i][k] = true;
        }        
    }    
}

// Вывод матриц
template<int rc, typename nT>
void PrintMatrix(nT (&inMatr)[rc][rc]){
    std::string text = "";
    std::cout << "\t  1   2   3   4   5   6   7   8   9   10  11  12" << std::endl;
    for(int i = 0; i < rc; i++){
        std::cout << "\t-------------------------------------------------" << std::endl;
        std::cout << " " << std::to_string(i + 1) << "\t| ";
        for(int k = 0; k < rc; k++){
            text = (inMatr[i][k]) ? "o": "x";
            std::cout << text << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "\t-------------------------------------------------" << std::endl;
}       

// Проверка валидности ввода
bool ValidNum(std::string inTxt){                    
    bool res = (inTxt.empty()) ? false: true;    
    
    for(int i = 0; i < inTxt.length(); i++){        
        res &= inTxt[i] >= '0' && inTxt[i] <= '9';
    }

    return res;
}

// Ввод числа и проверка валидности 
int InNum(std::string inTxt){         
    bool valid = true;
    std::string resTxt = "";
    
    do{
        std::cout << inTxt;        
        getline(std::cin, resTxt);
        valid = ValidNum(resTxt);
        if(!valid) {
            std::cout << "Incorrect data has been entered! Try again." << std::endl;            
        } 

    } while(!valid); 

    return std::stoi(resTxt);
}

// Процесс "лопания" пузырей
template<int rc, typename nT>
int BurstBubbles(nT (&inMatr)[rc][rc], int ur, int uc, int lr, int lc){
    int bubbles = 0;
    int start_i = (ur < lr) ? ur: lr;
    int start_k = (uc < lc) ? uc: lc;
    int end_i = (ur > lr) ? ur: lr; 
    int end_k = (uc > lc) ? uc: lc;

    // std::cout << "i=" << i << " end_i=" << end_i << "\nk=" << k << " end_k=" << end_k << std::endl; 


    for(int i = start_i; i <= end_i; i++){
        for(int k = start_k; k <= end_k; k++){
            if(inMatr[i][k]){
                inMatr[i][k] = false;
                bubbles++;
                std::cout << "Pop! ";
            }
        }
    }
    std::cout << std::endl;
    return bubbles;
}          