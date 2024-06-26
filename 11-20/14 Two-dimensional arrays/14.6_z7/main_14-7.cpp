// Задание 14.6.7. Почти MainCraft

#include<iostream>

bool ValidNum(std::string);                // Проверка валидности ввода
std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
int InputNumber(std::string);               // Ввод числа
template<int rows, int hit, typename nT>
void InputMatrix(nT (&)[rows][rows][hit], int, int, int);      // Ввод матрицы трёхмерной
template<int rows, typename nT>
void PrintSlice(nT (&)[rows][rows]);      // Вывод матрицы двумерной
template<int rows, int hit, typename nT>
void InitSlice(nT (&)[rows][rows], nT (&)[rows][rows][hit], int); // Заполнение "среза"

int main(){
    int landscape[5][5][10];
    int slice[5][5];
    int inNum = 0;
    std::string tempTxt = "";
    std::cout << "A program for building a \"landscape\" on a 5x5 field." << std::endl;
    std::cout << "Specify the height of the block in the position" << std::endl;

    for(int i = 0; i < 5; i++){
        for(int k = 0; k < 5; k++){
            tempTxt = "\t(" + std::to_string(i) + ", " + std::to_string(k) + "): ";
            inNum = InputNumber(tempTxt);
            InputMatrix(landscape, i, k, inNum);            
        }
    }

    int numSlice = 0;
    std::string request = "";
    do{    
        numSlice = InputNumber("\nSpecify the level of the slice: ") - 1;
        std::cout << std::endl;

        InitSlice(slice, landscape, numSlice);    
        PrintSlice(slice);
        std::cout << "Do you wish to continue? If you want to get out, type \"no\". ";
        getline(std::cin, request);
    } while(request != "no");

    system("pause");
    return 0;
}

// *********************


// Проверка валидности ввода
bool ValidNum(std::string inTxt){                    
    bool res = (inTxt.empty()) ? false: true;    
    
    for(int i = 0; i < inTxt.length(); i++){       
        res &= inTxt[i] >= '0' && inTxt[i] <= '9';
    }

    return res;
}

// Проверка ввода строки и пустого ввода
std::string CheckInputOfEmpty(std::string inTxt){
  std::string result = "";
   do{
    std::cout << inTxt;
    getline(std::cin, result);
    if (result == ""){
      std::cout << "You forgot to enter the value! Try again." << std::endl;
    } 
  } while(result == ""); 
  return result;
}

// Ввод числа
int InputNumber(std::string inTxt){
    std::string resTxt = "";
    int res = 0;   
    
    do {
        resTxt = CheckInputOfEmpty(inTxt);
        res = (ValidNum(resTxt)) ? std::stoi(resTxt): -1;
        res = (res >= 1 && res <= 10) ? res: -1;

        if(res == -1){
            std::cout << "Incorrect data has been entered! Try again." << std::endl;
        }

    } while (res == -1);
    
    return res;
} 

    
// Ввод матрицы трёхмерной
template<int rows, int hit, typename nT>
void InputMatrix(nT (&inMatr)[rows][rows][hit], int numR, int numC, int numZ){     

    for(int i = 0; i < 10; i++){
        if(i < numZ){    
            inMatr[numR][numC][i] = 1;
        } else {
            inMatr[numR][numC][i] = 0;
        }
    }   
}

// Вывод матрицы двумерной
template<int rows, typename nT>
void PrintSlice(nT (&inMatr)[rows][rows]){     
    for(int i = 0; i < rows; i++){
        std::cout << "| ";
        for(int k = 0; k < rows; k++){
            std::cout << inMatr[i][k];
            if(k != rows - 1) {
                std::cout << " \t";
            }
        }
        std::cout << " | " << std::endl;
    }
}

// Заполнение "среза"
template<int rows, int hit, typename nT>
void InitSlice(nT (&inSl)[rows][rows], nT (&inLand)[rows][rows][hit], int numSl){

    for(int i = 0; i < 5; i++){
        for(int k = 0; k < 5; k++){
            inSl[i][k] = inLand[i][k][numSl];
        }
    }
} 