// Задание 14.6.2 Крестики-нолики

#include<iostream>


std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
int InputNumber(std::string);               // Ввод числа



// Функция вывода матрицы (для контроля действий)
template <int rows, int col, typename type_m>
void PrintMass(type_m (&inMass)[rows][col]){
    
    std::cout << "r\\c" << "\t   1     2     3" << std::endl  << std::endl;
    std::cout << "\t-------------------" << std::endl;    
    
    for(int r = 0; r < rows; r++){
        std::cout << std::to_string(r + 1) << "\t|  ";
        
        for(int k = 0; k < col; k++){                             
            std::cout << inMass[r][k] << "  |  ";                  
        }               
        std::cout << std::endl << "\t-------------------" << std::endl;
        // std::cout << std::endl;
    }
    std::cout << std::endl; 
}

int main(){
    char gamer_name = 'X';
    char field [3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool place [3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};   
    int step = 1, num_x = 0, num_y = 0;
    bool victory = false, valid = false;    

    do{
        system("cls");
        std::cout << "The game \"tic-tac-toe\". Player's move \"" << gamer_name << "\"" << std::endl<< std::endl; 
        
        PrintMass(field);
        do{
            std::cout << "Motion " << step << ". Enter the coordinates" << std::endl;
            num_x = InputNumber("\t row: ") - 1;
            num_y = InputNumber("\t col: ") - 1;
            valid = place[num_x][num_y];
            if(valid){
                std::cout << "The specified cell is occupied!" << std::endl;
            }
        } while(valid);
        
        place[num_x][num_y] = true;
        field[num_x][num_y] = gamer_name;

        // Тут проверка на выигрыш
        bool x1 = true, x2 = true, x3 = true, y1 = true, y2 = true, y3 = true;
        bool x11 = true, x31 = true; 
        for(int i = 0; i < 3; i++){
            x1 &= field[0][i] == gamer_name;
            x2 &= field[1][i] == gamer_name;
            x3 &= field[2][i] == gamer_name;
            y1 &= field[i][0] == gamer_name;
            y2 &= field[i][1] == gamer_name;
            y3 &= field[i][2] == gamer_name;
            x11 &= field[i][i] == gamer_name;
            x31 &= field[2 - i][i] == gamer_name;
        }

        if(x1 || x2 || x3 || y1 || y2 || y3 || x11 || x31){
            std::cout << "\nThe player \"" << gamer_name << "\" became the winner!" << std::endl;
            PrintMass(field);
            system("pause");
            return 0;
        }

        if (gamer_name == 'X') {
                gamer_name = 'O'; 
        } else { 
                gamer_name = 'X';
        }

        step ++ ;
        
       
    } while (step != 10);

    std::cout << "We have a \"draw\". Thanks for playing." << std::endl;
    system("pause");
    
    return 0;
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

// Ввод Ввод числа
int InputNumber(std::string inTxt){
    std::string res = "";
    bool valid = true;
    char inCr = ' ';
    do {
        res = CheckInputOfEmpty(inTxt);
        inCr = res[0];
        if(res.size() == 1 && inCr >= '1' && inCr <= '3'){
            valid = true;
        } else {
            valid = false;
            std::cout << "Incorrect data has been entered! Try again." << std::endl; 
        }
    } while (!valid);
    
    return std::stoi(res);
} 
