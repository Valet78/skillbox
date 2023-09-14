// Задание 14.6.4. Умножение матрицы на вектор

#include<iostream>

bool ValidNum(std::string);                // Проверка валидности ввода
float InNum(std::string);                    // Ввод числа и проверка валидности  
template<int rows, int col>
void InputMatrix(float (&)[rows][col]);      // Ввод матрицы двумерной
template<int rows, int col>
void PrintMatrixVec(float (&)[rows][col], float (&)[rows]);      // Вывод матрицы двумерной и вектора
template<int rows>
void InputVector(float (&)[rows]);      // Ввод матрицы двумерной
template<int rows>
void PrintVector(float (&)[rows]);      // Вывод матрицы двумерной
template<int rows, int col, typename name_t>
void MultiplicatMatrixVector(name_t (&)[rows][col], name_t (&)[rows]); // Перемножение матрицы и вектора

int main(){
    float matr[4][4], vec[4];
    // float matr[4][4] = {{1.1, 1.2, 1.3, 1.4}, {2.1, 2.2, 2.3, 2.4}, {3.1, 3.2, 3.3, 3.4}, {4.1, 4.2, 4.3, 4.4}};
    // float vec[4] = {2.3, 4.1, 2.9, 8.2};

    std::cout << "A program for multiplying a matrix by a vector." << std::endl;
    std::cout << std::endl << "Enter integer values and fill in the 4x4 matrix." << std::endl;
    InputMatrix(matr);
    std::cout << std::endl << "Enter integer values and a vector of 4 elements." << std::endl;
    InputVector(vec);
    system("cls");
    std::cout << std::endl << "The result of multiplying the matrix \"a\" by a vector \"b\"" << std::endl;
    PrintMatrixVec(matr, vec);
    MultiplicatMatrixVector(matr, vec);
    std::cout << std::endl << "will be the following vector:" << std::endl;
    PrintVector(vec);    

    system("pause");
    return 0;
}


// Ввод матрицы двумерной
template<int rows, int col>
void InputMatrix(float (&inMatr)[rows][col]){     
        
    std::cout << "Enter the matrix elements. " << std::endl;
    for(int i = 0; i < rows; i++){
        for(int k = 0; k < col; k++){
            inMatr[i][k] = InNum("a[" + std::to_string(i) + ", " + std::to_string(k) + "] = ");
        }       
    }
}

// Вывод матрицы двумерной и вектора
template<int rows, int col>
void PrintMatrixVec(float (&inMatr)[rows][col], float (&inVec)[rows]){     
    for(int i = 0; i < rows; i++){
        std::cout << "| ";
        for(int k = 0; k < col; k++){
            std::cout << inMatr[i][k];
            if(k != col -1) {
                std::cout << "\t";
            }
        }
        std::cout << " |\t\t| " << inVec[i] << " |" << std::endl;
    }
}

// Проверка валидности ввода
bool ValidNum(std::string inTxt){                    
    bool res = (inTxt.empty()) ? false: true;
    int point = 0;
    
    for(int i = 0; i < inTxt.length(); i++){
        if(i == 0 && inTxt[i] == '-'){
            res &= true;
            continue;
        } else if(inTxt[i] == '.' && i != 0 && point == 0){
            res &= true;
            point++;
            continue;
        }
        
        res &= inTxt[i] >= '0' && inTxt[i] <= '9';
    }

    return res;
}

// Ввод числа и проверка валидности 
float InNum(std::string inTxt){         
    bool valid = true;
    std::string resTxt = "";
    
    do{
        std::cout << inTxt;
        std::cin.clear();
        getline(std::cin, resTxt);
        valid = ValidNum(resTxt);
        if(!valid) {
            std::cout << "Incorrect data has been entered! Try again." << std::endl;            
        } 

    } while(!valid); 

    return std::stof(resTxt);
}

// Ввод матрицы двумерной
template<int rows>
void InputVector(float (&inVec)[rows]){
    
    std::cout << "Enter the vector elements. " << std::endl;
    for(int i = 0; i < rows; i++){
         inVec[i]= InNum("b[" + std::to_string(i) + "] = ");
    }
}      

// Вывод матрицы двумерной
template<int rows>
void PrintVector(float (&inVec)[rows]){
    for(int i = 0; i < rows; i++){
        std::cout << "\t\t\t\t\t| " << inVec[i] << " |" << std::endl;
    }
}      
            
// Перемножение матрицы и вектора
template<int rows, int col, typename name_t>
void MultiplicatMatrixVector(name_t (&inMatr)[rows][col], name_t (&inVec)[rows]){
    name_t res[rows]{0, 0, 0, 0};
    for(int i = 0; i < rows; i++){
        for(int k = 0; k < col; k++){
            res[i] += inMatr[i][k] * inVec[k];
        }
    }
    std::swap(res, inVec);
}