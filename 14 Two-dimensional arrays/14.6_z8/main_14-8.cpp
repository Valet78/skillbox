
#include<iostream>

bool ValidNum(std::string);                // Проверка валидности ввода
std::string CheckInputOfEmpty(std::string); // Проверка ввода строки и пустого ввода
int InputNumber(std::string);               // Ввод числа
template <int rc, typename nT>
void InitFields(nT (&)[rc][rc], nT);        // Инициализация игровых полей
template<int rc, typename nT>
void PrintField(nT (&)[rc][rc], std::string);      // Вывод игрового поля
template<int rc, typename nT>
void  ArrangementShips(nT (&)[rc][rc], std::string);    // Расстановка кораблей
template<int rc, typename nT>
void InstallShips(nT (&)[rc][rc], int, std::string);         // Установка корябля на поле
template<int rc, typename nT>
bool ShotProcessing(nT (&)[rc][rc], int, int);        // Обработка выстрела
template<int rc, typename nT>
bool CheckVictory (nT (&)[rc][rc]);                    // Проверка факта победы



int main(){
    int fieldOne [10][10], fieldTwo [10][10];
    int choice = 0;    
    
    InitFields(fieldOne, 0);
    InitFields(fieldTwo, 0);

    // Для тренировки
    // int fieldOne [10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    //                          {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 1, 0, 1, 1, 0},
    //                          {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    //                          {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}, {0, 1, 1, 1, 1, 0, 1, 0, 0, 0},
    //                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}};
    // int fieldTwo [10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
    //                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 1, 0, 0, 0, 0},
    //                          {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    //                          {0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    //                          {0, 1, 1, 1, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}};

   
    std::cout << "The game \"Sea battle\"." << std::endl << std::endl;
    std::cout << "Follow these three steps:" << std::endl;
    std::cout << "1. The arrangement of the ships of the first player." << std::endl;
    std::cout << "2. The arrangement of the ships of the second player." << std::endl;
    std::cout << "3. Start the game." << std::endl << std::endl;
    std::cout << "Now we will place the ships of the first player on the field." << std::endl;
    system("pause");        
    ArrangementShips(fieldOne, "first");
    system("cls");
    std::cout << std::endl;
    std::cout << "The ships of the first player are placed. \nThen we will continue with the second player." << std::endl;
    PrintField(fieldOne, "open");
    system("pause");

    ArrangementShips(fieldTwo, "second");
    system("cls");
    std::cout << std::endl;
    std::cout << "The ships of the second player are exposed. Let's start the game." << std::endl;
    PrintField(fieldTwo, "open");
    system("pause");
    system("cls");
    
    // Далее сама игра
    bool victory = false, resShot = true;
    std::string gamer = "first", tmpTxt = "";
    int rowShot = 0, colShot = 0;

    do{
        std::cout << "The " << gamer << " player's move." << std::endl << std::endl;
        if(gamer == "first"){
            PrintField(fieldTwo, "hidden");
        } else {
            PrintField(fieldOne, "hidden");
        }

        std::cout << "Specify the coordinates of the shot" << std::endl;
        rowShot = InputNumber("\trow: ");
        colShot = InputNumber("\tcolumn: ");

        if(gamer == "first"){
            resShot = ShotProcessing(fieldTwo, rowShot, colShot);
            tmpTxt = (resShot) ? "The shot hit the target. You have another try." : "Sorry, but you missed."; 
            std::cout << tmpTxt << std::endl << std::endl;

            victory = CheckVictory(fieldTwo);
            gamer = (!resShot && !victory) ? "second" : "first";
            system("pause");
            system("cls");
            
        } else {
            resShot = ShotProcessing(fieldOne, rowShot, colShot);
            tmpTxt = (resShot) ? "The shot hit the target. You have another try." : "Sorry, but you missed."; 
            std::cout << tmpTxt << std::endl << std::endl;

            victory = CheckVictory(fieldOne);
            gamer = (!resShot && !victory) ? "first" : "second";
            system("pause");
            system("cls");
        }

        if(victory){
            std::cout << std::endl << "Congratulations to the " << gamer << " player on the victory!!!" << std::endl;
            if(gamer == "first"){
                PrintField(fieldTwo, "hidden");
            } else {
                PrintField(fieldOne, "hidden");
            }
        }        

    } while (!victory);    

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
        res = (res >= 0 && res <= 9) ? res: -1;

        if(res == -1){
            std::cout << "Incorrect data has been entered! Try again." << std::endl;
        }

    } while (res == -1);
    
    return res;
} 

 // Инициализация полей
template <int rc, typename nT>
void InitFields(nT (&inMatr)[rc][rc], nT value){
    for(int i = 0; i < rc; i++){
        for(int k = 0; k < rc; k++){
            inMatr[i][k] = value;
        }
    }
}       

// Вывод игрового поля
template<int rc, typename nT>
void PrintField(nT (&inMatr)[rc][rc], std::string typePr){
    std::string temp = "";
    std::cout << std::endl;
    std::cout << "\t" << "    0   1   2   3   4   5   6   7   8   9 " << std::endl;
    std::cout << "\t  -----------------------------------------" << std::endl;   
    
    for(int i = 0; i < rc; i++){
        std::cout << "\t" << std::to_string(i) << " |";
        
        for(int k = 0; k < rc; k++){
            if(typePr == "open"){
                temp = (inMatr[i][k] == 1) ? "#" : (inMatr[i][k] == 8) ? "." : " ";
            } else if(typePr == "hidden"){
                temp = (inMatr[i][k] == 2) ? "X" : (inMatr[i][k] == 3) ? "." : " ";
            }            
             
            std::cout << " " << temp << " |";            
        }
        std::cout << std::endl << "\t  -----------------------------------------" << std:: endl;
    }
    std::cout << std::endl;
} 

// Расстановка кораблей
template<int rc, typename nT>
void  ArrangementShips(nT (&inMatr)[rc][rc], std::string inTxt){
    std::string playerTxt = (inTxt == "first") ? "1. The arrangement of the ships of the first player." :
                                                 "2. The arrangement of the ships of the second player." ;
    InstallShips(inMatr, 4, playerTxt + "\nInstall a four-deck ship on the field (vertically/horizontally).");

    for(int i = 0; i < 2; i++){
        InstallShips(inMatr, 3, playerTxt + "\nInstall a three-deck ship on the field (vertically/horizontally).");
    }
    
    for(int i = 0; i < 3; i++){
        InstallShips(inMatr, 2, playerTxt + "\nInstall a two-deck ship on the field (vertically/horizontally).");
    }

    for(int i = 0; i < 4; i++){
        InstallShips(inMatr, 1, playerTxt + "\nInstall a single-deck ship on the field.");
    }
}

// Установка корябля на поле
template<int rc, typename nT>
void InstallShips(nT (&inMatr)[rc][rc], int num, std::string inTxt){
    bool valid = true, goriz = false, vert = false, tmp = false; 
    int cell = 1, row = 0, column = 0;
    int point [num][2];

    do {
        system("cls");
        std::cout << inTxt << std::endl;
        PrintField(inMatr, "open");        
        std::cout << "Coordinates of the point " << std::to_string(cell) << std::endl;
        row = InputNumber("\trow: ");
        column = InputNumber("\tcolumn: ");

        if(cell == 1 && inMatr[row][column] == 0) {
            inMatr[row][column] = 1;
            point[cell - 1][0] = row;
            point[cell - 1][1] = column;
            
            cell++;

        } else if (cell == 2 && inMatr[row][column] == 0){

            vert = (row - 1) >= 0 && inMatr[row - 1][column] == 1;
            vert |= (row + 1) <= 9 && inMatr[row + 1][column] == 1;
            goriz = (column - 1) >= 0 && inMatr[row][column - 1] == 1;
            goriz |= (column + 1) <= 9 && inMatr[row][column + 1] == 1;

            if(vert || goriz){
                inMatr[row][column] = 1;
                point[cell - 1][0] = row;
                point[cell - 1][1] = column;
                cell++;
            } else{
                valid = false;
            }

        } else if(cell > 2  && inMatr[row][column] == 0){

            if (vert) {
                tmp = vert && (row - 1) >= 0 && inMatr[row - 1][column] == 1;
                tmp |= vert && (row + 1) <= 9 && inMatr[row + 1][column] == 1;
            } else if(goriz){
                tmp = goriz && (column - 1) >= 0 && inMatr[row][column - 1] == 1;
                tmp |= goriz && (column + 1) <= 9 && inMatr[row][column + 1] == 1;
            }

            if(tmp){
                inMatr[row][column] = 1;
                point[cell - 1][0] = row;
                point[cell - 1][1] = column;
                cell++;
            } else{
                valid = false;
            }

        } else {
            valid = false;
        }

        if(!valid){            
            std::cout << "Incorrect coordinates of the point " << std::to_string(cell) << " have been entered! Try again." << std::endl;
        } 

        valid = true;
        system("pause");

    } while(cell != num + 1);

    // Заполняем "8" поля вокруг корабля
    int indRowS = 0, indRowF = 0, indColS = 0, indColF = 0;

    for(int cicle = 0; cicle < num; cicle++){
        row = point[cicle][0];
        column = point[cicle][1];

        indRowS = (row - 1 >= 0) ? row - 1 : row;
        indRowF = (row + 1 <= 9) ? row +1 : row;
        indColS = (column - 1 >= 0) ? column - 1 : column;
        indColF = (column + 1 <= 9) ? column + 1 : column;

        for(int i = indRowS; i <= indRowF; i++){
            for(int k = indColS; k <= indColF; k++){
                if (inMatr[i][k] == 0){
                    inMatr[i][k] = 8;
                }
            }
        }        
    }
}       

// Обработка выстрела
template<int rc, typename nT>
bool ShotProcessing(nT (&inMatr)[rc][rc], int inRow, int inCol){
    
    if(inMatr[inRow][inCol] == 1){
        inMatr[inRow][inCol] = 2;
        return true;
    } else {
        inMatr[inRow][inCol] = 3;
        return false;
    }
}    

// Проверка факта победы
template<int rc, typename nT>
bool CheckVictory (nT (&inMatr)[rc][rc]){
    for(int i = 0; i < 10; i++){
        for(int k = 0; k < 10; k++){
            if(inMatr[i][k] == 1){
                return false;
            }
        }
    }
    return true;
}
