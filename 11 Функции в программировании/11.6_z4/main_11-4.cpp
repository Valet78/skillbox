// Задание 11.6.4. Оценка результатов игры в крестики-нолики

#include <iostream>

std::string InputTxt(std::string); // Проверка ввода строки и пустого ввода
bool ValidSimv(std::string); // Проверка правильности введенных символов
char SimvToStr (std::string, int, int); // Получение символа по координатам
bool WomLine(int, int, char, std::string, char); // Определение выигрышной линии
void print(std::string); // вывод таблицы
int NumSimv(std::string, char); // Счёт количества символов 



int main(){
    bool xWinG = true, xWinV = true, yWinG = true, yWinV = true;

    std::cout << "Evaluation of the results of the tic-tac-toe game." << std::endl;
    std::string gameTable = InputTxt("Enter the first row of the table: ");
    gameTable += InputTxt("Enter the second row of the table: ");
    gameTable += InputTxt("Enter the third row of the table: ");
    std::cout << "--------------------------------------" << std::endl;
   

    // bool valid = (gameTable.length() == 9 && ValidSimv(gameTable)); 
    if(gameTable.length() == 9 && ValidSimv(gameTable)){

      print(gameTable);
      
      // горизонтали или вертикали
      for(int k = 0; k < 3; k++){
        xWinG = WomLine(k, -1, 'X', gameTable, 'G');
        xWinV = WomLine(-1, k, 'X', gameTable, 'V');
        if(xWinG || xWinV){
          break;
        }
      }
      
      for(int k = 0; k < 3; k++){
        yWinG = WomLine(k, -1, 'O', gameTable, 'G');
        yWinV = WomLine(-1, k, 'O', gameTable, 'V');
        if(yWinG || yWinV){
          break;
        }
      }

      // диагонали
      bool xWinD1 = WomLine(0, 0, 'X', gameTable, 'D');
      bool xWinD2 = WomLine(2, 0, 'X', gameTable, 'D');
      bool yWinD1 = WomLine(0, 0, 'O', gameTable, 'D');
      bool yWinD2 = WomLine(2, 0, 'O', gameTable, 'D');
      bool noWin = !xWinG & !xWinV & !yWinG & !yWinV & !xWinD1 &
                  !xWinD2 & !yWinD1 & !yWinD2;
      
      // Посчитаем количество крестиков и ноликов
      int numX = NumSimv(gameTable, 'X');
      int numO = NumSimv(gameTable, 'O');

      if(abs(numX - numO) <= 1){

        if (((numX < 3 || numO < 3) && noWin) || ((numX + numO == 9) && noWin)){
          std::cout << "\tNobody." << std::endl;
          return 0;
        } else if (((xWinG || xWinV) || (xWinD1 || xWinD2)) && (numX > numO)){
          std::cout << "\tPetya won." << std::endl;
          return 0;
        } else if(((yWinG || yWinV) || (yWinD1 || yWinD2) && (numX < numO))){
          std::cout << "\tVanya won." << std::endl;
          return 0;
        } else {
          std::cout << "\tIncorrect." << std::endl << std::endl;
          return 0;
        }
        
      } else {
        std::cout << "\tIncorrect." << std::endl << std::endl;
        return 0;
      }

    } else {
        std::cout << "\tIncorrect." << std::endl << std::endl;
        return 0;
    }

    return 0;
}

// Проверка ввода строки и пустого ввода
std::string InputTxt(std::string inTxt){
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

// Проверка правильности введенных символов
bool ValidSimv(std::string inTxt){
    bool valid = true;

    for(int i = 0; i < inTxt.length(); i++){
        valid &= (inTxt[i] == 'X' || inTxt[i] == 'O' || inTxt[i] == '.');
    } 
    
    return valid;
}

// Получение символа по координатам
char SimvToStr (std::string inTxt, int inX, int inY){
    int ind = inX + inY * 3;
    return inTxt[ind];
} 

// Счёт количества символов
int NumSimv(std::string inTxt, char inCh){
  int res = 0;

  for(int i = 0; i < inTxt.length(); i++){
    if(inTxt[i] == inCh){
      res++;
    }
  } 
  
  return res;
}

// Определение выигрышной линии
bool WomLine(int inX, int inY, char inCh, std::string inTxt, char dir){
  bool res = true;

  if(dir == 'G' || dir == 'V'){
    for(int i = 0; i < 3; i++){
      if(dir == 'G'){
        res &= SimvToStr(inTxt, inX, i) == inCh;
      } else if(dir == 'V'){
        res &= SimvToStr(inTxt, i, inY) == inCh;
      }
    }
  } else if(dir == 'D'){    
    for(int i = 0; i < 3; i++){
      if(inX == 0){
        res &= SimvToStr(inTxt, i, i) == inCh;
      } else if(inX == 2){
        res &= SimvToStr(inTxt, i, 2 - i) == inCh;
      }
    
    }
  } 
  return res;
}

// вывод таблицы
void print(std::string inTxt){
  for(int i = 0; i < 3; i++){
    for(int k = 0; k < 3; k++){
      std::cout << SimvToStr(inTxt, k, i) << " ";
    } 
    std::cout << std::endl;    
  }
}