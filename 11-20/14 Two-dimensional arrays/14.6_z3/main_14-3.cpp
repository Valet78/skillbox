// Задание 14.6.3. Матрицы

#include<iostream>

bool ValidNum(std::string);                // Проверка валидности ввода
int InNum(std::string);                    // Ввод числа и проверка валидности  
template<int rows, int col>
void InputMatrix(int (&)[rows][col], std::string);    // Ввод матриц
template<int rows, int col>
void PrintMatrix(int (&)[rows][col]);                 // Вывод матриц
template<int rowsA, int colA, int rowsB, int colB>
bool CompareMatrix(int (&)[rowsA][colA], int (&)[rowsB][colB]); // Сравнение матриц   
template<int rows, int col>   
void TrasMatrixDiag(int (&)[rows][col]);        // Преобразование матрицы в диагональную


int main(){
    int matr_A[4][4], matr_B [4][4];
    // int matr_A[4][4] = {{1, 2, 3, 6}, {11, 12, 13, 14}, {21, 22, 23, 24}, {31, 32, 33, 34}};
    // int matr_B[4][4] = {{1, 2, 3, 4}, {11, 12, 13, 14}, {21, 22, 23, 24}, {31, 32, 33, 34}};
    system("cls");
    std::cout << "A program for comparing two 4x4 matrices." << std::endl;    
    InputMatrix(matr_A, "A");
    InputMatrix(matr_B, "B");
    system("cls");
    std::cout << "We have the original matrices" << std::endl;
    std::cout << "\t the matrix \"A\":" << std::endl;
    PrintMatrix(matr_A);
    std::cout << "\t the matrix \"B\":" << std::endl;
    PrintMatrix(matr_B);
    std::cout << std::endl << "Let's compare these matrices:" << std::endl;
    
    if(!CompareMatrix(matr_A, matr_B)){
        std::cout << "These matrices are not equal!" << std::endl;
        system("pause");
        return 0;
    } 
    
    std::cout << "These matrices are equal." << std::endl << std::endl;
    std::cout << "Let's transform one of them into a \"diagonal\" one:" << std::endl;
    TrasMatrixDiag(matr_A);
    PrintMatrix(matr_A);

    system("pause");
    return 0;
}


// Ввод матриц
template<int rows, int col>
void InputMatrix(int (&inMatr)[rows][col], std::string nameM){     
        
    std::cout << "Enter the matrix \"" << nameM << "\" elements. " << std::endl;
    for(int i = 0; i < rows; i++){
        for(int k = 0; k < col; k++){
            inMatr[i][k] = InNum(nameM + "[" + std::to_string(i) + ", " + std::to_string(k) + "] = ");
        }       
    }

}

// Вывод матриц
template<int rows, int col>
void PrintMatrix(int (&inMatr)[rows][col]){     
    for(int i = 0; i < rows; i++){
        for(int k = 0; k < col; k++){
            std::cout << inMatr[i][k] << "\t";
        }
        std::cout << std::endl;
    }
}

// Проверка валидности ввода
bool ValidNum(std::string inTxt){                    
    bool res = (inTxt.empty()) ? false: true;
    
    for(int i = 0; i < inTxt.length(); i++){
        if(i == 0 && inTxt[i] == '-'){
            res = true;
            continue;
        }
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
        std::cin.clear();
        getline(std::cin, resTxt);
        valid = ValidNum(resTxt);
        if(!valid) {
            std::cout << "Incorrect data has been entered! Try again." << std::endl;            
        } 

    } while(!valid); 

    return std::stoi(resTxt);
}

// Сравнение матриц
template<int rowsA, int colA, int rowsB, int colB>
bool CompareMatrix(int (&inMA)[rowsA][colA], int (&inMB)[rowsB][colB]){
    if(rowsA == rowsB && colA == colB){
        for(int i = 0; i < rowsA; i++){
            for(int k = 0; k < colA; k++){
                if(inMA[i][k] != inMB[i][k]){
                    return false;
                }
            }    
        }
        return true;
    } else {
        return false;
    }    
} 

// Преобразование матрицы в диагональную
template<int rows, int col>   
void TrasMatrixDiag(int (&inMatr)[rows][col]){
    for(int i = 0; i < rows; i++){
        for(int k = 0; k < col; k++){
            if(i != k){
                inMatr[i][k] = 0;
            }
        }
    }
}